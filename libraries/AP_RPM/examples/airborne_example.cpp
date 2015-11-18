
#include <AP_HAL/AP_HAL.h>
#include <AP_Common/AP_Common.h>
#include <AP_Progmem/AP_Progmem.h>
#include <AP_Param/AP_Param.h>
#include <StorageManager/StorageManager.h>
#include <AP_Math/AP_Math.h>

#include <AP_HAL_Linux/AP_HAL_Linux.h>
#include <AP_RPM/AP_RPM.h>

const AP_HAL::HAL& hal = AP_HAL_BOARD_DRIVER;
static AP_RPM ap_rpm;

static AP_SerialManager manager;

void setup() {


	hal.console->println_P(PSTR("Airborne Projects setup"));
	manager.init();
	ap_rpm.init(manager);

}
void loop() {
    ap_rpm.update();

}

AP_HAL_MAIN();

