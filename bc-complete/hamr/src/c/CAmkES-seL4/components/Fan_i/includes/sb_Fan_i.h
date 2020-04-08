#ifndef __sb_AADL_Fan_i_types__H
#define __sb_AADL_Fan_i_types__H

#include <sb_proc_types.h>

bool sb_fanCmd_dequeue(union_art_DataContent * sb_fanCmd);

bool sb_fanAck_enqueue(const union_art_DataContent * sb_fanAck);

#endif // __sb_AADL_Fan_i_types__H
