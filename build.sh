#!/bin/bash

# Build script for GameEngineOpenGL

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Path to vcpkg
VCPKG_PATH="/home/$USER/vcpkg"
TOOLCHAIN_FILE="$VCPKG_PATH/scripts/buildsystems/vcpkg.cmake"

# Check if vcpkg exists
if [ ! -f "$TOOLCHAIN_FILE" ]; then
    echo -e "${RED}Error: vcpkg toolchain file not found at $TOOLCHAIN_FILE${NC}"
    exit 1
fi

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    echo -e "${GREEN}Creating build directory...${NC}"
    mkdir build
fi

cd build

# Configure with CMake
echo -e "${GREEN}Configuring with CMake...${NC}"
cmake -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
      -DCMAKE_BUILD_TYPE=Release \
      ..

if [ $? -ne 0 ]; then
    echo -e "${RED}CMake configuration failed!${NC}"
    exit 1
fi

# Build
echo -e "${GREEN}Building project...${NC}"
cmake --build . -j$(nproc)

if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi

echo -e "${GREEN}Build successful! Executable: build/bin/GameEngineOpenGL${NC}"
echo -e "${GREEN}Run with: ./build/bin/GameEngineOpenGL${NC}"
