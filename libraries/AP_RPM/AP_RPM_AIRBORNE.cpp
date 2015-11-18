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

#include "GCS_MAVLink/GCS_MAVLink.h"

extern const AP_HAL::HAL& hal;
/*
   The constructor is basically a shell to a static class...mega sub optimal and there are no exceptions.. :(
 */
AP_RPM_AIRBORNE::AP_RPM_AIRBORNE(const AP_SerialManager& serial_manager) :
_sensor_rpms{0},
_buffer{0},
_port{serial_manager.find_serial(AP_SerialManager::SerialProtocol_RPM_Airborne, 0)}
{
}

void AP_RPM_AIRBORNE::update() {
  if (_port == NULL || !_port->available()) {
    return;
  }

  int16_t c = _port->read();
  if (c > -1) {
    mavlink_message_t message = {};
    mavlink_status_t mav_status = {};
    if (mavlink_parse_char(MAVLINK_COMM_0, c, &message, &mav_status)) {
      switch(message.msgid){
      case MAVLINK_MSG_ID_AIRBORNE_RPM:
        mavlink_msg_airborne_rpm_get_RPM(&message, _sensor_rpms);
        hal.console->printf("status:%d :%d %d %d %d %d %d %d, %d\n", (uint8_t)c, _sensor_rpms[0], _sensor_rpms[1],
          _sensor_rpms[2], _sensor_rpms[3], _sensor_rpms[4], _sensor_rpms[5], _sensor_rpms[6],
          _sensor_rpms[7]);
        break;
      default:
        hal.console->printf("Wrong message received in RPM sensor %d", message.msgid);
        break;
      }
    }
  }
}

AP_RPM_AIRBORNE::~AP_RPM_AIRBORNE()
{
}

uint16_t AP_RPM_AIRBORNE::getRPM(const uint8_t& instance_index) {
  return _sensor_rpms[instance_index];
}


AP_RPM_AIRBORNE_HELPER::AP_RPM_AIRBORNE_HELPER(AP_RPM &_ap_rpm, AP_RPM::RPM_State& _state,
  uint8_t instance_index, AP_RPM_AIRBORNE** existing_driver, const AP_SerialManager& serial_manager) :
  AP_RPM_Backend(_ap_rpm, instance_index, _state),
  _instance_index(instance_index),
  _driver(NULL)
  {

  _driver = existing_driver;
  if (existing_driver != NULL && *existing_driver == NULL) {
    *_driver = new AP_RPM_AIRBORNE(serial_manager);
  }
}

AP_RPM_AIRBORNE_HELPER::~AP_RPM_AIRBORNE_HELPER() {
  if (*_driver != NULL) {
    delete *_driver;
    *_driver = NULL;
  }
}

void AP_RPM_AIRBORNE_HELPER::update() {
  (*_driver)->update();
  state.rate_rpm = (*_driver)->getRPM(_instance_index);
  state.last_reading_ms = hal.scheduler->millis();
}
