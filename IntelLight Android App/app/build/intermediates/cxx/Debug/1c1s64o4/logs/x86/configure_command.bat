@echo off
"C:\\Users\\maxim\\AppData\\Local\\Android\\Sdk\\cmake\\3.22.1\\bin\\cmake.exe" ^
  "-HC:\\Users\\maxim\\OneDrive - insa-toulouse.fr\\INSA\\Cours\\4A - AE\\Langage C++\\BECppObjetsConnectes\\IntelLight Android App\\app\\src\\main\\cpp" ^
  "-DCMAKE_SYSTEM_NAME=Android" ^
  "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON" ^
  "-DCMAKE_SYSTEM_VERSION=26" ^
  "-DANDROID_PLATFORM=android-26" ^
  "-DANDROID_ABI=x86" ^
  "-DCMAKE_ANDROID_ARCH_ABI=x86" ^
  "-DANDROID_NDK=C:\\Users\\maxim\\AppData\\Local\\Android\\Sdk\\ndk\\25.1.8937393" ^
  "-DCMAKE_ANDROID_NDK=C:\\Users\\maxim\\AppData\\Local\\Android\\Sdk\\ndk\\25.1.8937393" ^
  "-DCMAKE_TOOLCHAIN_FILE=C:\\Users\\maxim\\AppData\\Local\\Android\\Sdk\\ndk\\25.1.8937393\\build\\cmake\\android.toolchain.cmake" ^
  "-DCMAKE_MAKE_PROGRAM=C:\\Users\\maxim\\AppData\\Local\\Android\\Sdk\\cmake\\3.22.1\\bin\\ninja.exe" ^
  "-DCMAKE_CXX_FLAGS=-std=c++17" ^
  "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=C:\\Users\\maxim\\OneDrive - insa-toulouse.fr\\INSA\\Cours\\4A - AE\\Langage C++\\BECppObjetsConnectes\\IntelLight Android App\\app\\build\\intermediates\\cxx\\Debug\\1c1s64o4\\obj\\x86" ^
  "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=C:\\Users\\maxim\\OneDrive - insa-toulouse.fr\\INSA\\Cours\\4A - AE\\Langage C++\\BECppObjetsConnectes\\IntelLight Android App\\app\\build\\intermediates\\cxx\\Debug\\1c1s64o4\\obj\\x86" ^
  "-DCMAKE_BUILD_TYPE=Debug" ^
  "-BC:\\Users\\maxim\\OneDrive - insa-toulouse.fr\\INSA\\Cours\\4A - AE\\Langage C++\\BECppObjetsConnectes\\IntelLight Android App\\app\\.cxx\\Debug\\1c1s64o4\\x86" ^
  -GNinja
