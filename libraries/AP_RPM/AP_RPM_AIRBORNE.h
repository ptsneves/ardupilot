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

#ifndef AP_RPM_AIRBORNE_H
#define AP_RPM_AIRBORNE_H

#include <AP_SerialManager/AP_SerialManager.h>

#include "AP_RPM.h"
#include "RPM_Backend.h"

#define AP_RPM_AIRBORNEPROJECTS_BUFFER_SIZE 128

class AP_RPM_AIRBORNE
{
public:
    // constructor
    AP_RPM_AIRBORNE(const AP_SerialManager& serial_manager);

    // destructor
    ~AP_RPM_AIRBORNE(void);

    // update state
    void update();
    uint16_t getRPM(const uint8_t& instance_index);
private:
    uint16_t _sensor_rpms[8];
    uint8_t _buffer[AP_RPM_AIRBORNEPROJECTS_BUFFER_SIZE];
    AP_HAL::UARTDriver *_port;
};

class AP_RPM_AIRBORNE_HELPER : public AP_RPM_Backend
{
public:
    AP_RPM_AIRBORNE_HELPER(AP_RPM &_ap_rpm, AP_RPM::RPM_State& _state, uint8_t instance_index,
        AP_RPM_AIRBORNE** existing_driver, const AP_SerialManager& serial_manager);
    ~AP_RPM_AIRBORNE_HELPER();
    void update();
private:
    uint8_t _instance_index;
    AP_RPM_AIRBORNE** _driver;
};

#endif // AP_RPM_AIRBORNE_H
