#ifndef TEMPSENSOR_I_IMPL_API_H
#define TEMPSENSOR_I_IMPL_API_H

#include <all.h>

Unit api_send_currentTemp__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  bc_BuildingControl_Temperature_i value);

Unit api_send_tempChanged__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this);

Unit api_logInfo__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  String str);

Unit api_logDebug__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  String str);

Unit api_logError__bc_BuildingControl_TempSensor_i_Impl(
  bc_BuildingControl_TempSensor_i_Impl this,
  String str);

#endif
