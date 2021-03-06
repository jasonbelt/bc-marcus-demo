#!/usr/bin/env bash
#
# This file is autogenerated.  Do not edit
#
set -e
export SCRIPT_HOME=$( cd "$( dirname "$0" )" &> /dev/null && pwd )
export PROJECT_HOME=$( cd "$( dirname "$0" )/.." &> /dev/null && pwd )

cd "${PROJECT_HOME}/hamr/BuildingControlDemo_i_Instance_tcp_tempSensor"
mkdir -p sel4-build
cd sel4-build
cmake ..
make $MAKE_ARGS


cd "${PROJECT_HOME}/hamr/BuildingControlDemo_i_Instance_tcp_fan"
mkdir -p sel4-build
cd sel4-build
cmake ..
make $MAKE_ARGS


cd "${PROJECT_HOME}/hamr/BuildingControlDemo_i_Instance_tcp_tempControl"
mkdir -p sel4-build
cd sel4-build
cmake ..
make $MAKE_ARGS


cd "${PROJECT_HOME}/hamr/SlangTypeLibrary"
mkdir -p sel4-build
cd sel4-build
cmake ..
make $MAKE_ARGS

