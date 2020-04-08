#include "../includes/sb_Fan_i.h"
#include <Fan_i_adapter.h>
#include <string.h>
#include <camkes.h>

static void sb_fanCmd_notification_handler(void * unused) {
  MUTEXOP(sb_dispatch_sem_post())
  CALLBACKOP(sb_fanCmd_notification_reg_callback(sb_fanCmd_notification_handler, NULL));
}

/************************************************************************
 * sb_fanAck_enqueue:
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
bool sb_fanAck_enqueue(const union_art_DataContent * sb_fanAck){
  bool sb_result = true;
  sb_result &= sb_fanAck0_enqueue((union_art_DataContent *) sb_fanAck);
  return sb_result;
}

// send fanAck: Out EventDataPort BuildingControl__FanAck
Unit bc_BuildingControl_Fan_i_seL4Nix_fanAck_Send(STACK_FRAME 
  art_DataContent d) {
  sb_fanAck_enqueue(d);
}

B bc_BuildingControl_Fan_i_seL4Nix_fanCmd_IsEmpty(STACK_FRAME_ONLY) {
  return sb_fanCmd_is_empty();
}

// receive fanCmd: In EventDataPort union_art_DataContent
Unit bc_BuildingControl_Fan_i_seL4Nix_fanCmd_Receive(STACK_FRAME
  Option_8E9F45 result) {
  union_art_DataContent val;
  if(sb_fanCmd_dequeue((union_art_DataContent *) &val)) {
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


void pre_init(void) {
  CALLBACKOP(sb_fanCmd_notification_reg_callback(sb_fanCmd_notification_handler, NULL));

  // initialise slang-embedded components/ports
  bc_BuildingControl_Fan_i_adapter_initialiseArchitecture(SF_LAST);

  // call the component's initialise entrypoint
  bc_BuildingControl_Fan_i_adapter_initialiseEntryPoint(SF_LAST);

}


/************************************************************************
 * int run(void)
 * Main active thread function.
 ************************************************************************/
int run(void) {

  for(;;) {
    MUTEXOP(sb_dispatch_sem_wait())

    // call the component's compute entrypoint
    bc_BuildingControl_Fan_i_adapter_computeEntryPoint(SF_LAST);
  }
  return 0;
}
