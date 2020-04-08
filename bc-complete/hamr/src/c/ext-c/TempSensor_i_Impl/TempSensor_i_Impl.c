#include <TempSensor_i_Impl_api.h>
#include <ext.h>


static int last_temp = 0;
static int delta = 4;

// forward declaration
void currentTempGet(bc_BuildingControl_Temperature_i result);

Unit bc_BuildingControl_TempSensor_i_Impl_initialise_(
        STACK_FRAME
        bc_BuildingControl_TempSensor_i_Impl this) {
    // do nothing
}

Unit bc_BuildingControl_TempSensor_i_Impl_finalise_(
        STACK_FRAME
        bc_BuildingControl_TempSensor_i_Impl this) {
    // do nothing
}

Unit bc_BuildingControl_TempSensor_i_Impl_timeTriggered_(
        STACK_FRAME
        bc_BuildingControl_TempSensor_i_Impl this) {
    DeclNewbc_BuildingControl_Temperature_i(value);
    currentTempGet(&value);

    api_send_currentTemp__bc_BuildingControl_TempSensor_i_Impl(this, &value);
    api_send_tempChanged__bc_BuildingControl_TempSensor_i_Impl(this);

    DeclNewString(msg);
    String__append((String) &msg, string("Sensed temperature: "));
    bc_BuildingControl_Temperature_i_string_((String) &msg, &value);

    api_logInfo__bc_BuildingControl_TempSensor_i_Impl(this, (String) &msg);
}

void currentTempGet(bc_BuildingControl_Temperature_i result) {
    if (last_temp == 0) {
        last_temp = MIN_TEMP;
    }
    last_temp += delta;
    if (last_temp < MIN_TEMP) delta = 4;
    else if (last_temp > MAX_TEMP) delta = -4;
    result->degrees = (F32) last_temp;
    result->unit = bc_BuildingControl_TempUnit_Type_Fahrenheit;
}
