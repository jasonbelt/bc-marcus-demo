cmake_minimum_required(VERSION 3.8.2)

project (tcp C)

add_definitions(-DCAMKES)

includeGlobalComponents()

execute_process(COMMAND bash -c "${CMAKE_CURRENT_LIST_DIR}/bin/compile-hamr-lib.sh")

set(HAMR_LIB_BuildingControlDemo_i_Instance_tcp_tempSensor ${CMAKE_CURRENT_LIST_DIR}/hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/sel4-build/libmain.a)

set(HAMR_INCLUDES_BuildingControlDemo_i_Instance_tcp_tempSensor
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/ext
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/runtime
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/org/sireum
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc/BuildingControlDemo_i_Instance_tcp_tempSensor
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc/BuildingControl
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc/BuildingControl/TempUnit
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc/BuildingControl/TempSensor_i_Bridge
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc/BuildingControl/FanCmd
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc/BuildingControl/FanAck
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/bc/Base_Types
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/art
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/art/Bridge
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/art/PortMode
  hamr/BuildingControlDemo_i_Instance_tcp_tempSensor/library/art/DispatchPropertyProtocol
)

set(HAMR_LIB_BuildingControlDemo_i_Instance_tcp_tempControl ${CMAKE_CURRENT_LIST_DIR}/hamr/BuildingControlDemo_i_Instance_tcp_tempControl/sel4-build/libmain.a)

set(HAMR_INCLUDES_BuildingControlDemo_i_Instance_tcp_tempControl
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/ext
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/runtime
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/org/sireum
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/org/sireum/ops
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc/BuildingControl
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc/BuildingControl/TempUnit
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc/BuildingControl/FanCmd
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc/BuildingControl/FanAck
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc/BuildingControl/TempControl_i_Bridge
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc/BuildingControlDemo_i_Instance_tcp_tempControl
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/bc/Base_Types
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/art
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/art/Bridge
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/art/PortMode
  hamr/BuildingControlDemo_i_Instance_tcp_tempControl/library/art/DispatchPropertyProtocol
)

set(HAMR_LIB_BuildingControlDemo_i_Instance_tcp_fan ${CMAKE_CURRENT_LIST_DIR}/hamr/BuildingControlDemo_i_Instance_tcp_fan/sel4-build/libmain.a)

set(HAMR_INCLUDES_BuildingControlDemo_i_Instance_tcp_fan
  hamr/BuildingControlDemo_i_Instance_tcp_fan/ext
  hamr/BuildingControlDemo_i_Instance_tcp_fan/runtime
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/org/sireum
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/org/sireum/ops
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc/BuildingControl
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc/BuildingControl/TempUnit
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc/BuildingControl/FanCmd
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc/BuildingControl/FanAck
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc/BuildingControl/Fan_i_Bridge
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc/BuildingControlDemo_i_Instance_tcp_fan
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/bc/Base_Types
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/art
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/art/Bridge
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/art/PortMode
  hamr/BuildingControlDemo_i_Instance_tcp_fan/library/art/DispatchPropertyProtocol
)

set(HAMR_LIB_SlangTypeLibrary ${CMAKE_CURRENT_LIST_DIR}/hamr/SlangTypeLibrary/sel4-build/libmain.a)

set(HAMR_INCLUDES_SlangTypeLibrary
  hamr/SlangTypeLibrary/runtime
  hamr/SlangTypeLibrary/library/org/sireum
  hamr/SlangTypeLibrary/library/bc
  hamr/SlangTypeLibrary/library/bc/BuildingControl
  hamr/SlangTypeLibrary/library/bc/BuildingControl/TempUnit
  hamr/SlangTypeLibrary/library/bc/BuildingControl/FanCmd
  hamr/SlangTypeLibrary/library/bc/BuildingControl/FanAck
  hamr/SlangTypeLibrary/library/bc/Base_Types
  hamr/SlangTypeLibrary/library/bc/SlangTypeLibrary
  hamr/SlangTypeLibrary/library/art
)

DeclareCAmkESComponent(TempSensor_i
  SOURCES components/TempSensor_i/src/sb_TempSensor_i.c
  INCLUDES ${HAMR_INCLUDES_BuildingControlDemo_i_Instance_tcp_tempSensor} components/TempSensor_i/includes/ includes
  LIBS ${HAMR_LIB_BuildingControlDemo_i_Instance_tcp_tempSensor}
)

DeclareCAmkESComponent(TempControl_i
  SOURCES components/TempControl_i/src/sb_TempControl_i.c
  INCLUDES ${HAMR_INCLUDES_BuildingControlDemo_i_Instance_tcp_tempControl} components/TempControl_i/includes/ includes
  LIBS ${HAMR_LIB_BuildingControlDemo_i_Instance_tcp_tempControl}
)

DeclareCAmkESComponent(Fan_i
  SOURCES components/Fan_i/src/sb_Fan_i.c
  INCLUDES ${HAMR_INCLUDES_BuildingControlDemo_i_Instance_tcp_fan} components/Fan_i/includes/ includes
  LIBS ${HAMR_LIB_BuildingControlDemo_i_Instance_tcp_fan}
)

DeclareCAmkESComponent(dispatch_periodic
  SOURCES components/dispatch_periodic/src/sb_dispatch_periodic.c
  INCLUDES ${HAMR_INCLUDES_SlangTypeLibrary} includes
  LIBS ${HAMR_LIB_SlangTypeLibrary}
)

DeclareCAmkESComponent(sb_fan_fanCmd_Monitor
  SOURCES components/sb_Monitors/sb_fan_fanCmd_Monitor/src/sb_fan_fanCmd_Monitor.c
  INCLUDES ${HAMR_INCLUDES_SlangTypeLibrary} components/sb_Monitors/sb_fan_fanCmd_Monitor/includes/ includes
  LIBS ${HAMR_LIB_SlangTypeLibrary}
)

DeclareCAmkESComponent(sb_tempControl_currentTemp_Monitor
  SOURCES components/sb_Monitors/sb_tempControl_currentTemp_Monitor/src/sb_tempControl_currentTemp_Monitor.c
  INCLUDES ${HAMR_INCLUDES_SlangTypeLibrary} components/sb_Monitors/sb_tempControl_currentTemp_Monitor/includes/ includes
  LIBS ${HAMR_LIB_SlangTypeLibrary}
)

DeclareCAmkESComponent(sb_tempControl_fanAck_Monitor
  SOURCES components/sb_Monitors/sb_tempControl_fanAck_Monitor/src/sb_tempControl_fanAck_Monitor.c
  INCLUDES ${HAMR_INCLUDES_SlangTypeLibrary} components/sb_Monitors/sb_tempControl_fanAck_Monitor/includes/ includes
  LIBS ${HAMR_LIB_SlangTypeLibrary}
)

DeclareCAmkESComponent(sb_tempControl_tempChanged_Monitor
  SOURCES components/sb_Monitors/sb_tempControl_tempChanged_Monitor/src/sb_tempControl_tempChanged_Monitor.c
  INCLUDES ${HAMR_INCLUDES_SlangTypeLibrary} components/sb_Monitors/sb_tempControl_tempChanged_Monitor/includes/ includes
  LIBS ${HAMR_LIB_SlangTypeLibrary}
)

DeclareCAmkESRootserver(tcp.camkes)
