## HOW TO COMPILE

mkddir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=Toolchain-arm-gcc.cmake
make -j