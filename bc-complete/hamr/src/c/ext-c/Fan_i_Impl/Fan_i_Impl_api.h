#ifndef FAN_I_IMPL_API_H
#define FAN_I_IMPL_API_H

#include <all.h>

B api_get_fanCmd__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  bc_BuildingControl_FanCmd_Type *value);

Unit api_send_fanAck__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  bc_BuildingControl_FanAck_Type value);

Unit api_logInfo__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  String str);

Unit api_logDebug__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  String str);

Unit api_logError__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  String str);

#endif
