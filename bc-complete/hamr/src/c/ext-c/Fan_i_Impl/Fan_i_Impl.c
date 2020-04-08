#include <Fan_i_Impl_api.h>
#include <ext.h>

// forward declaration -- could be provided by an hardware device
bc_BuildingControl_FanAck_Type
fanCmdActuate(bc_BuildingControl_FanCmd_Type value);

Unit bc_BuildingControl_Fan_i_Impl_initialise_(
  STACK_FRAME
  bc_BuildingControl_Fan_i_Impl this) {
 // do nothing
}

Unit bc_BuildingControl_Fan_i_Impl_finalise_(
  STACK_FRAME
  bc_BuildingControl_Fan_i_Impl this) {
  // do nothing
}

Unit bc_BuildingControl_Fan_i_Impl_handlefanCmd_(
  STACK_FRAME
  bc_BuildingControl_Fan_i_Impl this,
  bc_BuildingControl_FanCmd_Type value) {

    DeclNewString(msg1);
    String__append((String) &msg1, string("Received fanCmd: "));
    bc_BuildingControl_FanCmd_Type_string_(SF (String) &msg1, value);
    api_logInfo__bc_BuildingControl_Fan_i_Impl(this, (String) &msg1);

    bc_BuildingControl_FanAck_Type ack = fanCmdActuate(value);

    api_send_fanAck__bc_BuildingControl_Fan_i_Impl(this, ack);

    DeclNewString(msg2);
    String__append((String) &msg2, string("Actuation result: "));
    bc_BuildingControl_FanAck_Type_string_(SF (String) &msg2, ack);
    api_logInfo__bc_BuildingControl_Fan_i_Impl(this, (String) &msg2);
}

bc_BuildingControl_FanAck_Type fanCmdActuate(bc_BuildingControl_FanCmd_Type value) {
    // assume fan is always able to fulfill the request from the temp controller
    return bc_BuildingControl_FanAck_Type_Ok;
}
