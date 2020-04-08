#ifndef __sb_AADL_TempControl_i_types__H
#define __sb_AADL_TempControl_i_types__H

#include <sb_proc_types.h>

bool sb_currentTemp_read(union_art_DataContent * sb_currentTemp);

bool sb_fanAck_dequeue(union_art_DataContent * sb_fanAck);

bool sb_setPoint_dequeue(union_art_DataContent * sb_setPoint);

bool sb_fanCmd_enqueue(const union_art_DataContent * sb_fanCmd);

bool sb_tempChanged_dequeue(void);

#endif // __sb_AADL_TempControl_i_types__H
