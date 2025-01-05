#!/bin/bash

# Navigate to the parent directory
cd ..

# Remove existing "deps" directory contents if it exists
if [ -d "deps" ]; then
    rm -rf deps/*
fi

# Create necessary directories
mkdir -p deps/include deps/lib deps/debug/lib

# Build raylib in debug mode
cmake -S raylib -B deps/temp -DCMAKE_BUILD_TYPE=Debug -DBUILD_EXAMPLES=OFF
cmake --build deps/temp --config Debug
cp deps/temp/raylib/libraylib.a deps/debug/lib/
rm -rf deps/temp

# Build raylib in release mode
cmake -S raylib -B deps/temp -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=OFF
cmake --build deps/temp --config Release
cp deps/temp/raylib/libraylib.a deps/lib/

# Copy raylib headers
cp -r deps/temp/raylib/include/* deps/include/
rm -rf deps/temp

# Copy raygui single header library
cp raygui/src/raygui.h deps/include