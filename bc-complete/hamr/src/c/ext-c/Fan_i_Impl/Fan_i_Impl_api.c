#include <Fan_i_Impl_api.h>

B api_get_fanCmd__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  bc_BuildingControl_FanCmd_Type *value){
  // Option_E725B6 = Option[bc.BuildingControl.FanCmd.Type]
  // Some_339726 = Some[bc.BuildingControl.FanCmd.Type]
  DeclNewOption_E725B6(t_0);
  bc_BuildingControl_Fan_i_Bridge_Api_getfanCmd_(
    SF
    (Option_E725B6) &t_0,
    bc_BuildingControl_Fan_i_Impl_api_(this));

  if(t_0.type == TSome_339726){
    Type_assign(value, &t_0.Some_339726.value, sizeof(bc_BuildingControl_FanCmd_Type));
    return T;
  } else {
    return F;
  }
}

Unit api_send_fanAck__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  bc_BuildingControl_FanAck_Type value) {

  bc_BuildingControl_Fan_i_Bridge_Api_sendfanAck_(
    bc_BuildingControl_Fan_i_Impl_api_(this),
    value);
}

Unit api_logInfo__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  String str) {
  bc_BuildingControl_Fan_i_Bridge_Api_logInfo_(
    SF
    bc_BuildingControl_Fan_i_Impl_api_(this),
    str);
}

Unit api_logDebug__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  String str) {
  bc_BuildingControl_Fan_i_Bridge_Api_logDebug_(
    SF
    bc_BuildingControl_Fan_i_Impl_api_(this),
    str);
}

Unit api_logError__bc_BuildingControl_Fan_i_Impl(
  bc_BuildingControl_Fan_i_Impl this,
  String str) {
  bc_BuildingControl_Fan_i_Bridge_Api_logError_(
    SF
    bc_BuildingControl_Fan_i_Impl_api_(this),
    str);
}
