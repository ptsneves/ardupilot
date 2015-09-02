// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <AP_HAL/AP_HAL.h>

#include "AP_RPM_AIRBORNE.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <termios.h>


#include "include/airborneRPM/mavlink.h"

extern const AP_HAL::HAL& hal;

uint8_t AP_RPM_AIRBORNE::sensor_attributed_count = 0;
int AP_RPM_AIRBORNE::_fd = -1;
uint8_t AP_RPM_AIRBORNE::_buffer[_buffer_size] = {0};
uint16_t AP_RPM_AIRBORNE::_sensor_rpms[8] = {0};

#define DEVICE_PATH "/dev/ttyUSB0"
/*
   The constructor is basically a shell to a static class...mega sub optimal and there are no exceptions.. :(
 */
AP_RPM_AIRBORNE::AP_RPM_AIRBORNE(AP_RPM &_ap_rpm, uint8_t instance, AP_RPM::RPM_State& _state) :
                				AP_RPM_Backend(_ap_rpm, instance, _state),
	instance_sensor_index{sensor_attributed_count++} {

		if (_fd == -1) {
			_fd = open(DEVICE_PATH, O_RDONLY | O_NOCTTY | O_NONBLOCK | O_NDELAY);
			// O_NDELAY: The open will return without waiting for the device to be
			//           ready or available; subsequent behavior of the device is device specific.
			// O_RDWR:  Open for reading and writing.
			// O_RDWR: If set and the file is a terminal, the terminal will not be allocated
			//         as the calling process's controlling terminal.
			termios terminal_io_setting;
			tcgetattr(_fd, &terminal_io_setting);


			// Input flags - Turn off input processing
			// convert break to null byte, no CR to NL translation,
			// no NL to CR translation, don't mark parity errors or breaks
			// no input parity check, don't strip high bit off,
			// no XON/XOFF software flow control
			//
			terminal_io_setting.c_iflag &= ~(IGNCR | IGNBRK | BRKINT | ICRNL | INLCR
							| PARMRK | INPCK | ISTRIP | IXON | ICRNL | IXON | IXOFF | IXANY);

			//
			// Output flags - Turn off output processing
			// no CR to NL translation, no NL to CR-NL translation,
			// no NL to CR translation, no column 0 CR suppression,
			// no Ctrl-D suppression, no fill characters, no case mapping,
			// no local output processing
			terminal_io_setting.c_oflag &= ~(OCRNL | ONLCR | ONLRET | ONOCR | OFILL | OPOST);

			//
			// No line processing:
			// echo off, echo newline off, canonical mode off,
			// extended input processing off, signal chars off
			//
			terminal_io_setting.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG | ECHOE );

			//
			// Turn off character processing
			// clear current char size mask, no parity checking,
			// no output processing, force 8 bit input
			// Disable hangup on close to avoid reset
			//

			terminal_io_setting.c_cflag |= (CS8 | CREAD | CLOCAL);
			terminal_io_setting.c_cflag &= ~(CSIZE | PARENB | CSTOPB | CRTSCTS /*| HUPCL*/);
			//
			// One input byte is enough to return from read()
			// Inter-character timer off
			//
			terminal_io_setting.c_cc[VMIN] = 1;
			//terminal_io_setting.c_cc[VTIME] = 0; // was 0

			cfmakeraw(&terminal_io_setting);

			cfsetispeed(&terminal_io_setting, B1000000);

			cfsetospeed(&terminal_io_setting, B1000000);
			/* commit the serial port settings */
			tcsetattr(_fd, TCSANOW, &terminal_io_setting);
			if (_fd == -1) {
				hal.console->printf("Unable to open %s\n", DEVICE_PATH);
			}
		}
	}

void AP_RPM_AIRBORNE::update() {
	if (_fd == -1) {

		return;
	}

	ssize_t status = ::read(_fd, _buffer, sizeof(_buffer));
	if (status > 0) {
		mavlink_message_t message = {};
		mavlink_status_t mav_status = {};
		for (uint8_t index = 0; index < status; index++) {
			if (mavlink_parse_char(MAVLINK_COMM_0, _buffer[index], &message, &mav_status)) {
				switch(message.msgid){
				case MAVLINK_MSG_ID_HEARTBEAT:
					mavlink_msg_heartbeat_get_RPM(&message, _sensor_rpms);
					break;
				default:
					break;
				}
			}
		}
		//should we memset 0?
	}
	else if (status == -1 && errno != EAGAIN && errno != EWOULDBLOCK) {
		hal.console->printf("IO error");
		return;
	}
	state.rate_rpm = _sensor_rpms[instance_sensor_index];
	state.last_reading_ms = hal.scheduler->millis();
}

/*
close the file descriptor
 */
AP_RPM_AIRBORNE::~AP_RPM_AIRBORNE()
{
	if (_fd != -1) {
		close(_fd);
		_fd = -1;
	}
}
