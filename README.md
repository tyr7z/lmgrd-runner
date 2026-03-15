```bash
mkdir build
cd build

# For MSVC (Visual Studio)
# "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cmake -G Ninja -DCMAKE_C_COMPILER=cl ..

# For MinGW
cmake -G Ninja -DCMAKE_C_COMPILER=gcc ..

# For Clang
cmake -G Ninja -DCMAKE_C_COMPILER=clang ..

ninja
```
