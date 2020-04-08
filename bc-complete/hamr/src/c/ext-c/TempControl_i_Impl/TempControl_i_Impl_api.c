#include <TempControl_i_Impl_api.h>

B api_get_currentTemp__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_Temperature_i value){
  // Option_A43075 = Option[bc.BuildingControl.Temperature_i]
  // Some_F9F426 = Some[bc.BuildingControl.Temperature_i]
  DeclNewOption_A43075(t_0);
  bc_BuildingControl_TempControl_i_Bridge_Api_getcurrentTemp_(
    SF
    (Option_A43075) &t_0,
    bc_BuildingControl_TempControl_i_Impl_api_(this));

  if(t_0.type == TSome_F9F426){
    Type_assign(value, &t_0.Some_F9F426.value, sizeof(struct bc_BuildingControl_Temperature_i));
    return T;
  } else {
    return F;
  }
}

B api_get_fanAck__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_FanAck_Type *value){
  // Option_F8ACC2 = Option[bc.BuildingControl.FanAck.Type]
  // Some_E422EA = Some[bc.BuildingControl.FanAck.Type]
  DeclNewOption_F8ACC2(t_0);
  bc_BuildingControl_TempControl_i_Bridge_Api_getfanAck_(
    SF
    (Option_F8ACC2) &t_0,
    bc_BuildingControl_TempControl_i_Impl_api_(this));

  if(t_0.type == TSome_E422EA){
    Type_assign(value, &t_0.Some_E422EA.value, sizeof(bc_BuildingControl_FanAck_Type));
    return T;
  } else {
    return F;
  }
}

B api_get_setPoint__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_SetPoint_i value){
  // Option_B7192D = Option[bc.BuildingControl.SetPoint_i]
  // Some_B3C944 = Some[bc.BuildingControl.SetPoint_i]
  DeclNewOption_B7192D(t_0);
  bc_BuildingControl_TempControl_i_Bridge_Api_getsetPoint_(
    SF
    (Option_B7192D) &t_0,
    bc_BuildingControl_TempControl_i_Impl_api_(this));

  if(t_0.type == TSome_B3C944){
    Type_assign(value, &t_0.Some_B3C944.value, sizeof(struct bc_BuildingControl_SetPoint_i));
    return T;
  } else {
    return F;
  }
}

Unit api_send_fanCmd__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  bc_BuildingControl_FanCmd_Type value) {

  bc_BuildingControl_TempControl_i_Bridge_Api_sendfanCmd_(
    bc_BuildingControl_TempControl_i_Impl_api_(this),
    value);
}

B api_get_tempChanged__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  art_Empty value){
  // Option_C622DB = Option[art.Empty]
  // Some_4782C6 = Some[art.Empty]
  DeclNewOption_C622DB(t_0);
  bc_BuildingControl_TempControl_i_Bridge_Api_gettempChanged_(
    SF
    (Option_C622DB) &t_0,
    bc_BuildingControl_TempControl_i_Impl_api_(this));

  if(t_0.type == TSome_4782C6){
    Type_assign(value, &t_0.Some_4782C6.value, sizeof(struct art_Empty));
    return T;
  } else {
    return F;
  }
}

Unit api_logInfo__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  String str) {
  bc_BuildingControl_TempControl_i_Bridge_Api_logInfo_(
    SF
    bc_BuildingControl_TempControl_i_Impl_api_(this),
    str);
}

Unit api_logDebug__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  String str) {
  bc_BuildingControl_TempControl_i_Bridge_Api_logDebug_(
    SF
    bc_BuildingControl_TempControl_i_Impl_api_(this),
    str);
}

Unit api_logError__bc_BuildingControl_TempControl_i_Impl(
  bc_BuildingControl_TempControl_i_Impl this,
  String str) {
  bc_BuildingControl_TempControl_i_Bridge_Api_logError_(
    SF
    bc_BuildingControl_TempControl_i_Impl_api_(this),
    str);
}
