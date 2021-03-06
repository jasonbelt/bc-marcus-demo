#!/usr/bin/env bash
#
# This file is autogenerated.  Do not edit
#
set -e

if [ -z "${SIREUM_HOME}" ]; then
  echo "SIREUM_HOME not set. Refer to https://github.com/sireum/kekinian/#installing"
  exit 1
fi

SCRIPT_HOME=$( cd "$( dirname "$0" )" &> /dev/null && pwd )

PATH_SEP=":"
if [ -n "$COMSPEC" -a -x "$COMSPEC" ]; then
  PATH_SEP=";"
fi

OUTPUT_DIR="${SCRIPT_HOME}/../src/c/CAmkES-seL4/hamr/BuildingControlDemo_i_Instance_tcp_tempSensor"

${SIREUM_HOME}/bin/sireum slang transpilers c \
  --sourcepath "${SCRIPT_HOME}/../src/main/bridge${PATH_SEP}${SCRIPT_HOME}/../src/main/component${PATH_SEP}${SCRIPT_HOME}/../src/main/seL4Nix/bc/BuildingControl${PATH_SEP}${SCRIPT_HOME}/../src/main/art${PATH_SEP}${SCRIPT_HOME}/../src/main/data${PATH_SEP}${SCRIPT_HOME}/../src/main/seL4Nix/bc/BuildingControlDemo_i_Instance_tcp_tempSensor" \
  --output-dir "${OUTPUT_DIR}" \
  --name "main" \
  --apps "bc.BuildingControlDemo_i_Instance_tcp_tempSensor.tempSensor" \
  --fingerprint 3 \
  --bits 64 \
  --string-size 256 \
  --sequence-size 5 \
  --sequence "MS[Z,art.Bridge]=1;MS[Z,MOption[art.Bridge]]=1;IS[Z,art.UPort]=2;IS[Z,art.UConnection]=1" \
  --constants "art.Art.maxComponents=1;art.Art.maxPorts=2" \
  --forward "art.ArtNative=bc.BuildingControlDemo_i_Instance_tcp_tempSensor.tempSensor" \
  --stack-size "65536" \
  --stable-type-id \
  --exts "${SCRIPT_HOME}/../src/c/ext-c/ext.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/ext.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/TempSensor_i_Impl/TempSensor_i_Impl_api.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/TempSensor_i_Impl/TempSensor_i_Impl_api.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/TempSensor_i_Impl/TempSensor_i_Impl.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/adapters/BuildingControlDemo_i_Instance_tcp_tempSensor/TempSensor_i_adapter.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/adapters/BuildingControlDemo_i_Instance_tcp_tempSensor/TempSensor_i_adapter.c" \
  --exclude-build "bc.BuildingControl.TempSensor_i_Impl,bc.BuildingControl.Fan_i_Impl,bc.BuildingControl.TempControl_i_Impl" \
  --lib-only \
  --verbose

FILE=${OUTPUT_DIR}/CMakeLists.txt
echo -e "\n\nadd_definitions(-DCAMKES)" >> $FILE

OUTPUT_DIR="${SCRIPT_HOME}/../src/c/CAmkES-seL4/hamr/BuildingControlDemo_i_Instance_tcp_fan"

${SIREUM_HOME}/bin/sireum slang transpilers c \
  --sourcepath "${SCRIPT_HOME}/../src/main/bridge${PATH_SEP}${SCRIPT_HOME}/../src/main/component${PATH_SEP}${SCRIPT_HOME}/../src/main/seL4Nix/bc/BuildingControl${PATH_SEP}${SCRIPT_HOME}/../src/main/art${PATH_SEP}${SCRIPT_HOME}/../src/main/data${PATH_SEP}${SCRIPT_HOME}/../src/main/seL4Nix/bc/BuildingControlDemo_i_Instance_tcp_fan" \
  --output-dir "${OUTPUT_DIR}" \
  --name "main" \
  --apps "bc.BuildingControlDemo_i_Instance_tcp_fan.fan" \
  --fingerprint 3 \
  --bits 64 \
  --string-size 256 \
  --sequence-size 5 \
  --sequence "MS[Z,art.Bridge]=1;MS[Z,MOption[art.Bridge]]=1;IS[Z,art.UPort]=2;IS[Z,art.UConnection]=1" \
  --constants "art.Art.maxComponents=1;art.Art.maxPorts=2" \
  --forward "art.ArtNative=bc.BuildingControlDemo_i_Instance_tcp_fan.fan" \
  --stack-size "65536" \
  --stable-type-id \
  --exts "${SCRIPT_HOME}/../src/c/ext-c/ext.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/ext.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/Fan_i_Impl/Fan_i_Impl_api.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/Fan_i_Impl/Fan_i_Impl_api.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/Fan_i_Impl/Fan_i_Impl.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/adapters/BuildingControlDemo_i_Instance_tcp_fan/Fan_i_adapter.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/adapters/BuildingControlDemo_i_Instance_tcp_fan/Fan_i_adapter.c" \
  --exclude-build "bc.BuildingControl.TempSensor_i_Impl,bc.BuildingControl.Fan_i_Impl,bc.BuildingControl.TempControl_i_Impl" \
  --lib-only \
  --verbose

FILE=${OUTPUT_DIR}/CMakeLists.txt
echo -e "\n\nadd_definitions(-DCAMKES)" >> $FILE

OUTPUT_DIR="${SCRIPT_HOME}/../src/c/CAmkES-seL4/hamr/BuildingControlDemo_i_Instance_tcp_tempControl"

${SIREUM_HOME}/bin/sireum slang transpilers c \
  --sourcepath "${SCRIPT_HOME}/../src/main/bridge${PATH_SEP}${SCRIPT_HOME}/../src/main/component${PATH_SEP}${SCRIPT_HOME}/../src/main/seL4Nix/bc/BuildingControl${PATH_SEP}${SCRIPT_HOME}/../src/main/art${PATH_SEP}${SCRIPT_HOME}/../src/main/data${PATH_SEP}${SCRIPT_HOME}/../src/main/seL4Nix/bc/BuildingControlDemo_i_Instance_tcp_tempControl" \
  --output-dir "${OUTPUT_DIR}" \
  --name "main" \
  --apps "bc.BuildingControlDemo_i_Instance_tcp_tempControl.tempControl" \
  --fingerprint 3 \
  --bits 64 \
  --string-size 256 \
  --sequence-size 5 \
  --sequence "MS[Z,art.Bridge]=1;MS[Z,MOption[art.Bridge]]=1;IS[Z,art.UPort]=5;IS[Z,art.UConnection]=1" \
  --constants "art.Art.maxComponents=1;art.Art.maxPorts=5" \
  --forward "art.ArtNative=bc.BuildingControlDemo_i_Instance_tcp_tempControl.tempControl" \
  --stack-size "65536" \
  --stable-type-id \
  --exts "${SCRIPT_HOME}/../src/c/ext-c/ext.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/ext.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/TempControl_i_Impl/TempControl_i_Impl_api.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/TempControl_i_Impl/TempControl_i_Impl_api.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/TempControl_i_Impl/TempControl_i_Impl.c${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/adapters/BuildingControlDemo_i_Instance_tcp_tempControl/TempControl_i_adapter.h${PATH_SEP}${SCRIPT_HOME}/../src/c/ext-c/adapters/BuildingControlDemo_i_Instance_tcp_tempControl/TempControl_i_adapter.c" \
  --exclude-build "bc.BuildingControl.TempSensor_i_Impl,bc.BuildingControl.Fan_i_Impl,bc.BuildingControl.TempControl_i_Impl" \
  --lib-only \
  --verbose

FILE=${OUTPUT_DIR}/CMakeLists.txt
echo -e "\n\nadd_definitions(-DCAMKES)" >> $FILE

OUTPUT_DIR="${SCRIPT_HOME}/../src/c/CAmkES-seL4/hamr/SlangTypeLibrary"

${SIREUM_HOME}/bin/sireum slang transpilers c \
  --sourcepath "${SCRIPT_HOME}/../src/main/art${PATH_SEP}${SCRIPT_HOME}/../src/main/data${PATH_SEP}${SCRIPT_HOME}/../src/main/seL4Nix/bc/SlangTypeLibrary" \
  --output-dir "${OUTPUT_DIR}" \
  --name "main" \
  --apps "bc.SlangTypeLibrary.SlangTypeLibrary" \
  --fingerprint 3 \
  --bits 64 \
  --string-size 256 \
  --sequence-size 5 \
  --forward "art.ArtNative=bc.SlangTypeLibrary.SlangTypeLibrary" \
  --stack-size "16777216" \
  --stable-type-id \
  --lib-only \
  --verbose

FILE=${OUTPUT_DIR}/CMakeLists.txt
echo -e "\n\nadd_definitions(-DCAMKES)" >> $FILE