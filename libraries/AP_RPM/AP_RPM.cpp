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

#include "AP_RPM.h"
#include "RPM_PX4_PWM.h"
#include "AP_RPM_AIRBORNE.h"

extern const AP_HAL::HAL& hal;

// table of user settable parameters
const AP_Param::GroupInfo AP_RPM::var_info[] PROGMEM = {
    // @Param: _TYPE
    // @DisplayName: RPM type
    // @Description: What type of RPM sensor is connected
    // @Values: 0:None,1:PX4-PWM,2:Airborne
    AP_GROUPINFO("0_TYPE",    0, AP_RPM, _type[0], RPM_TYPE_AIRBORNE),

    // @Param: _SCALING
    // @DisplayName: RPM scaling
    // @Description: Scaling factor between sensor reading and RPM.
    // @Increment: 0.001
    AP_GROUPINFO("0_SCALING", 1, AP_RPM, _scaling[0], 1.0f),


#define RPM_SENSOR_PARAMS(PARAM_N) \
    AP_GROUPINFO(#PARAM_N"_TYPE",    PARAM_N * 2, AP_RPM, _type[PARAM_N], RPM_TYPE_AIRBORNE), \
    AP_GROUPINFO(#PARAM_N"_SCALING", ( PARAM_N*2 )+1, AP_RPM, _scaling[PARAM_N], 1.0f)

    RPM_SENSOR_PARAMS(1),

    RPM_SENSOR_PARAMS(2),

    RPM_SENSOR_PARAMS(3),

    RPM_SENSOR_PARAMS(4),

    RPM_SENSOR_PARAMS(5),

    RPM_SENSOR_PARAMS(6),

    RPM_SENSOR_PARAMS(7),
    AP_GROUPEND
};

AP_RPM::AP_RPM(void) :
    num_instances(0)
{
    AP_Param::setup_object_defaults(this, var_info);

    // init state and drivers
    memset(state,0,sizeof(state));
    memset(drivers,0,sizeof(drivers));
}

/*
  initialise the AP_RPM class. 
 */
void AP_RPM::init(void)
{
    if (num_instances != 0) {
        // init called a 2nd time?
        return;
    }
    for (uint8_t i=0; i<RPM_MAX_INSTANCES; i++) {
        uint8_t type = _type[i];
        uint8_t instance = num_instances;

#if CONFIG_HAL_BOARD == HAL_BOARD_LINUX
        if (type == RPM_TYPE_AIRBORNE) {
            state[instance].instance = instance;
            drivers[instance] = new AP_RPM_AIRBORNE(*this, instance, state[instance]);
        }
#elif CONFIG_HAL_BOARD == HAL_BOARD_PX4  || CONFIG_HAL_BOARD == HAL_BOARD_VRBRAIN
        if (type == RPM_TYPE_PX4_PWM) {
            state[instance].instance = instance;
            drivers[instance] = new AP_RPM_PX4_PWM(*this, instance, state[instance]);
        }
#endif

        if (drivers[i] != NULL) {
            // we loaded a driver for this instance, so it must be
            // present (although it may not be healthy)
            num_instances++;
        }
    }
}

/*
  update RPM state for all instances. This should be called by main loop
 */
void AP_RPM::update(void)
{
    for (uint8_t i=0; i<num_instances; i++) {
        if (drivers[i] != NULL) {
            if (_type[i] == RPM_TYPE_NONE) {
                // allow user to disable a RPM sensor at runtime
                continue;
            }
            drivers[i]->update();
        }
    }
}
    
/*
  check if an instance is healthy
 */
bool AP_RPM::healthy(uint8_t instance) const
{
    if (instance >= num_instances) {
        return false;
    }
    // assume we get readings at at least 1Hz
    if (hal.scheduler->millis() - state[instance].last_reading_ms > 1000) {
        return false;
    }
    return true;
}
