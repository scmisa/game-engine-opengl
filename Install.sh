#!/bin/bash

# Set the path to vcpkg
VCPKG_ROOT="$HOME/vcpkg"

# Check if vcpkg is installed
if [ ! -f "$VCPKG_ROOT/vcpkg" ]; then
    echo "Cloning vcpkg repository..."
    git clone https://github.com/microsoft/vcpkg.git "$VCPKG_ROOT"
    echo "Bootstrapping vcpkg..."
    cd "$VCPKG_ROOT"
    ./bootstrap-vcpkg.sh
    cd -
fi

# Install necessary libraries
echo "Installing necessary libraries..."
"$VCPKG_ROOT/vcpkg" install glfw3:x64-linux
"$VCPKG_ROOT/vcpkg" install glad:x64-linux

echo "Dependencies installation complete."