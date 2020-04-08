#include <sb_proc_types.h>
#include "../includes/sb_tempControl_currentTemp_Monitor.h"

int monsig_emit(void);

static union_art_DataContent contents;
bool receivedData = false;

bool mon_is_empty() {
  return !receivedData;
}

bool mon_read(union_art_DataContent * m) {
  *m = contents;
  return receivedData;
}

bool mon_write(const union_art_DataContent * m) {
  receivedData = true;
  contents = *m;
  monsig_emit();
  return receivedData;
}