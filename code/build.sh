#!/usr/bin/env bash

CODE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

mkdir -p ${CODE_DIR}/../build
pushd ${CODE_DIR}/../build > /dev/null
# g++ `pkg-config --cflags glfw3` -ggdb -o handmade ${CODE_DIR}/handmade.cpp `pkg-config --static --libs glfw3`
g++ `pkg-config --cflags glfw3` -ggdb -o handmade ${CODE_DIR}/handmade.cpp `pkg-config --libs glfw3` -framework OpenGL
popd > /dev/null
