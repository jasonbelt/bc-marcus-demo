#include <all.h>
#include <ext.h>

struct bc_BuildingControl_Temperature_i toFahrenheit(
        struct bc_BuildingControl_Temperature_i value) {
    bc_BuildingControl_TempUnit_Type Fahrenheit = bc_BuildingControl_TempUnit_Type_Fahrenheit;
    bc_BuildingControl_TempUnit_Type Celsius = bc_BuildingControl_TempUnit_Type_Celsius;

    if (value.unit == Fahrenheit) {
        return value;
    } else if (value.unit == Celsius) {
        value.degrees = value.degrees * 9.0 / 5.0 + 32.0;
        value.unit = Fahrenheit;
        return value;
    } else {
        value.degrees = value.degrees * 9.0 / 5.0 - 459.67;
        value.unit = Fahrenheit;
        return value;
    }
}