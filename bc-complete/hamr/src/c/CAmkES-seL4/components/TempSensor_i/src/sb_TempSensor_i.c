#include "../includes/sb_TempSensor_i.h"
#include <TempSensor_i_adapter.h>
#include <string.h>
#include <camkes.h>

static bool sb_occurred_periodic_dispatcher;
static int64_t sb_time_periodic_dispatcher;

/************************************************************************
 * periodic_dispatcher_write_int64_t
 * Invoked from remote periodic dispatch thread.
 *
 * This function records the current time and triggers the active thread
 * dispatch from a periodic event.  Note that the periodic dispatch
 * thread is the *only* thread that triggers a dispatch, so we do not
 * mutex lock the function.
 *
 ************************************************************************/

bool periodic_dispatcher_write_int64_t(const int64_t * arg) {
    sb_occurred_periodic_dispatcher = true;
    sb_time_periodic_dispatcher = *arg;
    MUTEXOP(sb_dispatch_sem_post());
    return true;
}

void sb_periodic_dispatch_notification_callback(void *_ UNUSED) {
   // we want time in microseconds, not nanoseconds, so we divide by 1000.
   int64_t sb_time_periodic_dispatcher = 0; // sb_timer_time() / 1000LL -- timer connection disabled;
   (void)periodic_dispatcher_write_int64_t(&sb_time_periodic_dispatcher);
   CALLBACKOP(sb_periodic_dispatch_notification_reg_callback(sb_periodic_dispatch_notification_callback, NULL));
}


/************************************************************************
 * sb_currentTemp_write:
 * Invoked from user code in the local thread.
 *
 * This is the function invoked by the local thread to make a
 * call to write to a remote data port.
 *
 * XXX: When simulating fan out, the caller of this function will only
 * receive a positive response when all enqueues are successful. When a
 * negative response is received it only indicates that at least one
 * enqueue attempt failed.
 *
 ************************************************************************/
bool sb_currentTemp_write(const union_art_DataContent * sb_currentTemp){
  bool sb_result = true;
  sb_result &= sb_currentTemp0_write((union_art_DataContent *) sb_currentTemp);
  return sb_result;
}

/************************************************************************
 * sb_tempChanged_enqueue
 * Invoked from user code in the local thread.
 *
 * This is the function invoked by the local thread to make a
 * call to send to a remote event port.
 *
 ************************************************************************/
bool sb_tempChanged_enqueue(void) {
  sb_tempChanged0_enqueue();
  return true;
}


// send currentTemp: Out DataPort BuildingControl__Temperature_i
Unit bc_BuildingControl_TempSensor_i_seL4Nix_currentTemp_Send(STACK_FRAME 
  art_DataContent d) {
  sb_currentTemp_write(d);
}

// send tempChanged: Out EventPort
Unit bc_BuildingControl_TempSensor_i_seL4Nix_tempChanged_Send(STACK_FRAME 
  art_DataContent d) {

  // event port - can ignore the Slang Empty payload
  art_Empty payload = (art_Empty) d;

  // send event via CAmkES
  sb_tempChanged_enqueue();
}

void pre_init(void) {

  // initialise slang-embedded components/ports
  bc_BuildingControl_TempSensor_i_adapter_initialiseArchitecture(SF_LAST);

  // call the component's initialise entrypoint
  bc_BuildingControl_TempSensor_i_adapter_initialiseEntryPoint(SF_LAST);

}


/************************************************************************
 * int run(void)
 * Main active thread function.
 ************************************************************************/
int run(void) {
  CALLBACKOP(sb_periodic_dispatch_notification_reg_callback(sb_periodic_dispatch_notification_callback, NULL));
  // Initial lock to await dispatch input.
  MUTEXOP(sb_dispatch_sem_wait())
  for(;;) {
    MUTEXOP(sb_dispatch_sem_wait())

    // call the component's compute entrypoint
    bc_BuildingControl_TempSensor_i_adapter_computeEntryPoint(SF_LAST);
  }
  return 0;
}
