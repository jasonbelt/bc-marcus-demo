#ifndef __sb_AADL_TempSensor_i_types__H
#define __sb_AADL_TempSensor_i_types__H

#include <sb_proc_types.h>

bool sb_currentTemp_write(const union_art_DataContent * sb_currentTemp);

bool sb_tempChanged_enqueue(void);

#endif // __sb_AADL_TempSensor_i_types__H
