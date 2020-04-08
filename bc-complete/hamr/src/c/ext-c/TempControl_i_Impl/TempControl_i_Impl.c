#include <TempControl_i_Impl_api.h>
#include <ext.h>


struct bc_BuildingControl_SetPoint_i setPoint;

bc_BuildingControl_TempUnit_Type Fahrenheit = bc_BuildingControl_TempUnit_Type_Fahrenheit;
bc_BuildingControl_FanCmd_Type FanCmd_On = bc_BuildingControl_FanCmd_Type_On;
bc_BuildingControl_FanCmd_Type FanCmd_Off = bc_BuildingControl_FanCmd_Type_Off;


Unit bc_BuildingControl_TempControl_i_Impl_initialise_(
        STACK_FRAME
        bc_BuildingControl_TempControl_i_Impl this) {

    DeclNewbc_BuildingControl_Temperature_i(low);
    bc_BuildingControl_Temperature_i_apply(SF &low, MIN_TEMP, Fahrenheit);

    DeclNewbc_BuildingControl_Temperature_i(high);
    bc_BuildingControl_Temperature_i_apply(SF &high, MAX_TEMP, Fahrenheit);

    bc_BuildingControl_SetPoint_i_apply(SF &setPoint, &low, &high);
}

Unit bc_BuildingControl_TempControl_i_Impl_finalise_(
        STACK_FRAME
        bc_BuildingControl_TempControl_i_Impl this) {
    // do nothing
}

Unit bc_BuildingControl_TempControl_i_Impl_handlefanAck_(
        STACK_FRAME
        bc_BuildingControl_TempControl_i_Impl this,
        bc_BuildingControl_FanAck_Type value) {

    DeclNewString(msg);
    String__append((String) &msg, string("Received fanAck: "));
    bc_BuildingControl_FanAck_Type_string_(SF (String) &msg, value);
    api_logInfo__bc_BuildingControl_TempControl_i_Impl(this, (String) &msg);

    if (value == bc_BuildingControl_FanAck_Type_Error) {
        // mitigate
        api_logInfo__bc_BuildingControl_TempControl_i_Impl(this, string("Actuation failed!"));
    } else {
        api_logInfo__bc_BuildingControl_TempControl_i_Impl(this, string("Actuation worked!"));
    }
}

Unit bc_BuildingControl_TempControl_i_Impl_handlesetPoint_(
        STACK_FRAME
        bc_BuildingControl_TempControl_i_Impl this,
        bc_BuildingControl_SetPoint_i value) {

    setPoint = *value;
}

Unit bc_BuildingControl_TempControl_i_Impl_handletempChanged_(
        STACK_FRAME
        bc_BuildingControl_TempControl_i_Impl this) {

    DeclNewString(msg);
    struct bc_BuildingControl_Temperature_i currentTemp;
    if (api_get_currentTemp__bc_BuildingControl_TempControl_i_Impl(this, &currentTemp)) {
        struct bc_BuildingControl_Temperature_i tempInF = toFahrenheit(currentTemp);

        if (tempInF.degrees > setPoint.high.degrees) {
            api_send_fanCmd__bc_BuildingControl_TempControl_i_Impl(this, FanCmd_On);

            String__append((String) &msg, string("Sent fan command: "));
            bc_BuildingControl_FanCmd_Type_string_((String) &msg, FanCmd_On);
        }
        else if (tempInF.degrees < setPoint.low.degrees) {
            api_send_fanCmd__bc_BuildingControl_TempControl_i_Impl(this, FanCmd_Off);

            String__append((String) &msg, string("Sent fan command: "));
            bc_BuildingControl_FanCmd_Type_string_((String) &msg, FanCmd_Off);
        }
        else {
            String__append((String) &msg, string("Temperature ok:"));
        }
        String__append((String) &msg, string(" - "));
        bc_BuildingControl_Temperature_i_string_((String) &msg, &currentTemp);

        api_logInfo__bc_BuildingControl_TempControl_i_Impl(this, (String) &msg);
    } else {
        printf("Unexpected: tempSensor should have also sent something on its currentTemp port\n");
    }
}