#!/usr/bin/env bash

CODE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

mkdir -p ${CODE_DIR}/../build
pushd ${CODE_DIR}/../build > /dev/null
g++ -ggdb -o handmade ${CODE_DIR}/handmade.cpp
popd > /dev/null
