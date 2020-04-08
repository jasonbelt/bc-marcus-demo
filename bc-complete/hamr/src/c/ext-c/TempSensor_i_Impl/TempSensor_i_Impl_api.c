#include <TempSensor_i_Impl_api.h>

Unit api_send_currentTemp__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  bc_BuildingControl_Temperature_i value) {

  bc_BuildingControl_TempSensor_i_Bridge_Api_setcurrentTemp_(
    bc_BuildingControl_TempSensor_i_Impl_api_(this),
    value);
}

Unit api_send_tempChanged__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this) {

  bc_BuildingControl_TempSensor_i_Bridge_Api_sendtempChanged_(
    bc_BuildingControl_TempSensor_i_Impl_api_(this));
}

Unit api_logInfo__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  String str) {
  bc_BuildingControl_TempSensor_i_Bridge_Api_logInfo_(
    SF
    bc_BuildingControl_TempSensor_i_Impl_api_(this),
    str);
}

Unit api_logDebug__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  String str) {
  bc_BuildingControl_TempSensor_i_Bridge_Api_logDebug_(
    SF
    bc_BuildingControl_TempSensor_i_Impl_api_(this),
    str);
}

Unit api_logError__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  String str) {
  bc_BuildingControl_TempSensor_i_Bridge_Api_logError_(
    SF
    bc_BuildingControl_TempSensor_i_Impl_api_(this),
    str);
}
