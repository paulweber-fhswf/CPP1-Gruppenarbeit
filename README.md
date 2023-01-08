# Dies ist eine Gruppen Arbeit für das Fach "Programmierung mit C++ 1"


## Raylib
Dieses Projekt benutzt [Raylib](https://www.raylib.com). Zum Kompilieren, muss dies installiert sein.
Diese [Konfiguration](https://github.com/SjDuque/Raylib-CMake) wurde für die CMakeLists.txt genutzt.

## Konfiguration unter Windows (10/11)
Neben Raylib wird ein folgender Compiler benötigt [UCRT-Runtime-MinGW-W64](https://github.com/brechtsanders/winlibs_mingw/releases/download/12.2.0-15.0.6-10.0.0-ucrt-r3/winlibs-x86_64-posix-seh-gcc-12.2.0-llvm-15.0.6-mingw-w64ucrt-10.0.0-r3.7z). Andere Compiler können auch funktionieren, wurden von uns aber nicht getestet.
Für das Kompilieren unter Windows hat sich das folgende [Konfigurationstemplate von SasLuca](https://github.com/SasLuca/raylib-cmake-template) bewährt. In diesem werden die Source-Dateien von unserem Projekt in den "sources"-Ordner kopiert.
