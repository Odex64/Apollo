Set-Location -Path ".."

if (Test-Path -Path "deps") {
    Remove-Item -Path "deps/*" -Recurse -Force
}

New-Item -ItemType Directory -Path "deps/include"
New-Item -ItemType Directory -Path "deps/lib"
New-Item -ItemType Directory -Path "deps/debug/lib"

# Build raylib in debug
cmake -S raylib -B deps/temp -DCMAKE_BUILD_TYPE=Debug -DBUILD_EXAMPLES=OFF
cmake --build deps/temp --config Debug
Copy-Item -Path "deps/temp/raylib/Debug/raylib.lib" -Destination "deps/debug/lib"
Remove-Item -Path "deps/temp" -Recurse -Force

# Build raylib in release
cmake -S raylib -B deps/temp -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=OFF
cmake --build deps/temp --config Release
Copy-Item -Path "deps/temp/raylib/Release/raylib.lib" -Destination "deps/lib"

# Copy raylib headers
Copy-Item -Path "deps/temp/raylib/include/*" -Destination "deps/include"
Remove-Item -Path "deps/temp" -Recurse -Force

# Copy raygui single header library
Copy-Item -Path "raygui/src/raygui.h" -Destination "deps/include"