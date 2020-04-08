#ifndef TEMPCONTROL_I_IMPL_API_H
#define TEMPCONTROL_I_IMPL_API_H

#include <all.h>

B api_get_currentTemp__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_Temperature_i value);

B api_get_fanAck__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_FanAck_Type *value);

B api_get_setPoint__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_SetPoint_i value);

Unit api_send_fanCmd__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_FanCmd_Type value);

B api_get_tempChanged__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  art_Empty value);

Unit api_logInfo__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  String str);

Unit api_logDebug__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  String str);

Unit api_logError__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  String str);

#endif
