#ifndef EXT_H
#define EXT_H

#define MIN_TEMP 55.0
#define MAX_TEMP 100.0

struct bc_BuildingControl_Temperature_i toFahrenheit(
        struct bc_BuildingControl_Temperature_i value);

#endif