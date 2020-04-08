#include "../includes/sb_TempControl_i.h"
#include <TempControl_i_adapter.h>
#include <string.h>
#include <camkes.h>

static void sb_fanAck_notification_handler(void * unused) {
  MUTEXOP(sb_dispatch_sem_post())
  CALLBACKOP(sb_fanAck_notification_reg_callback(sb_fanAck_notification_handler, NULL));
}

/************************************************************************
 * sb_fanCmd_enqueue:
 * Invoked from user code in the local thread.
 *
 * This is the function invoked by the local thread to make a
 * call to write to a remote event data port.
 *
 * XXX: When simulating fan out, the caller of this function will only
 * receive a positive response when all enqueues are successful. When a
 * negative response is received it only indicates that at least one
 * enqueue attempt failed.
 *
 ************************************************************************/
bool sb_fanCmd_enqueue(const union_art_DataContent * sb_fanCmd){
  bool sb_result = true;
  sb_result &= sb_fanCmd0_enqueue((union_art_DataContent *) sb_fanCmd);
  return sb_result;
}

/************************************************************************
 * sb_tempChanged_handler:
 * Invoked by: seL4 notification callback
 *
 * This is the function invoked by an seL4 notification callback that  
 * dispatches the active-thread due to the arrival of an event on 
 * its tempChanged event port
 *
 ************************************************************************/
static void sb_tempChanged_handler(void *_ UNUSED){
  MUTEXOP(sb_dispatch_sem_post());
  CALLBACKOP(sb_tempChanged_notification_reg_callback(sb_tempChanged_handler, NULL));
}

// send fanCmd: Out EventDataPort BuildingControl__FanCmd
Unit bc_BuildingControl_TempControl_i_seL4Nix_fanCmd_Send(STACK_FRAME 
  art_DataContent d) {
  sb_fanCmd_enqueue(d);
}

B bc_BuildingControl_TempControl_i_seL4Nix_currentTemp_IsEmpty(STACK_FRAME_ONLY) {
  return sb_currentTemp_is_empty();
}

// receive currentTemp: In DataPort union_art_DataContent
Unit bc_BuildingControl_TempControl_i_seL4Nix_currentTemp_Receive(STACK_FRAME
  Option_8E9F45 result) {
  union_art_DataContent val;
  if(sb_currentTemp_read((union_art_DataContent *) &val)) {
    // wrap payload in Some and place in result
    DeclNewSome_D29615(some);
    Some_D29615_apply(STACK_FRAME &some, (art_DataContent) &val);
    Type_assign(result, &some, sizeof(union Option_8E9F45));
  } else {
    // put None in result
    DeclNewNone_964667(none);
    Type_assign(result, &none, sizeof(union Option_8E9F45));
  }
}


B bc_BuildingControl_TempControl_i_seL4Nix_fanAck_IsEmpty(STACK_FRAME_ONLY) {
  return sb_fanAck_is_empty();
}

// receive fanAck: In EventDataPort union_art_DataContent
Unit bc_BuildingControl_TempControl_i_seL4Nix_fanAck_Receive(STACK_FRAME
  Option_8E9F45 result) {
  union_art_DataContent val;
  if(sb_fanAck_dequeue((union_art_DataContent *) &val)) {
    // wrap payload in Some and place in result
    DeclNewSome_D29615(some);
    Some_D29615_apply(STACK_FRAME &some, (art_DataContent) &val);
    Type_assign(result, &some, sizeof(union Option_8E9F45));
  } else {
    // put None in result
    DeclNewNone_964667(none);
    Type_assign(result, &none, sizeof(union Option_8E9F45));
  }
}


B bc_BuildingControl_TempControl_i_seL4Nix_tempChanged_IsEmpty(STACK_FRAME_ONLY) {
  return sb_tempChanged_is_empty();
}

// receive tempChanged: In EventPort
Unit bc_BuildingControl_TempControl_i_seL4Nix_tempChanged_Receive(STACK_FRAME
  Option_8E9F45 result) {
  if(sb_tempChanged_dequeue()) {
    // event port - ART requires an Empty payload be sent
    DeclNewart_Empty(payload);

    // wrap it in Some and place in result
    DeclNewSome_D29615(some);
    Some_D29615_apply(STACK_FRAME &some, (art_DataContent) &payload);
    Type_assign(result, &some, sizeof(union Option_8E9F45));
  } else {
    // put None in result
    DeclNewNone_964667(none);
    Type_assign(result, &none, sizeof(union Option_8E9F45));
  }
} 

// FIXME: dummy implementation for unconnected incoming port
B bc_BuildingControl_TempControl_i_seL4Nix_setPoint_IsEmpty(STACK_FRAME_ONLY) {
  return T;
}

// FIXME: dummy implementation for unconnected incoming port
Unit bc_BuildingControl_TempControl_i_seL4Nix_setPoint_Receive(STACK_FRAME
  Option_8E9F45 result) {
  // FIXME: dummy implementation

  // put None in result
  DeclNewNone_964667(none);
  Type_assign(result, &none, sizeof(union Option_8E9F45));
}

void pre_init(void) {
  CALLBACKOP(sb_fanAck_notification_reg_callback(sb_fanAck_notification_handler, NULL));
  CALLBACKOP(sb_tempChanged_notification_reg_callback(sb_tempChanged_handler, NULL));

  // initialise slang-embedded components/ports
  bc_BuildingControl_TempControl_i_adapter_initialiseArchitecture(SF_LAST);

  // call the component's initialise entrypoint
  bc_BuildingControl_TempControl_i_adapter_initialiseEntryPoint(SF_LAST);

}


/************************************************************************
 * int run(void)
 * Main active thread function.
 ************************************************************************/
int run(void) {

  for(;;) {
    MUTEXOP(sb_dispatch_sem_wait())

    // call the component's compute entrypoint
    bc_BuildingControl_TempControl_i_adapter_computeEntryPoint(SF_LAST);
  }
  return 0;
}
