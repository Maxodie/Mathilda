cd ./Mathilda && mkdir build
cd ../ && mkdir bin
mkdir lib

cmake -G "MinGW Makefiles" -DMAKE_C_COMPILER=gcc -DMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug -S./ -B./Mathilda/build -DCMAKE_INSTALL_PREFIX=./
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S./ -B./Mathilda/build

mingw32-make -C Mathilda/build
mingw32-make -C Mathilda/build install
PAUSE
