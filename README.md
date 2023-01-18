# Über das Spiel

- Dieses Spiel ist Teil einer Gruppenarbeit für das Fach "Programmierung mit C++ 1".
- Für die Umsetzung wurde [Raylib](https://www.raylib.com) genutzt.

# Gameplay

Nach dem starten wird das Haupmenü aufgerufen, dort wird die Steuerung erläutert.

![main menu9](https://user-images.githubusercontent.com/115210873/213310343-14126373-2c6a-4857-a83a-fb283209bf2e.png)

Nach dem Hauptmenü kommt das eigentliche Gameplay, welches auch Pausiert werden kann.

![gameplay4](https://user-images.githubusercontent.com/115210873/213310403-123c51b4-7d14-404c-a5cc-8c6369941928.png)
![pasue](https://user-images.githubusercontent.com/115210873/213310532-639e4366-8329-418d-8a9f-9136deeadc62.png)

Wenn ein Teromino außerhalb des Spielfeldes ragt, wird zum Game Over Menü weitergeleitet, wo der Score einsehbar ist und zum Hauptmenü fortfahren werden kann.

![game over](https://user-images.githubusercontent.com/115210873/213310498-efa95bdb-7b03-46ea-8f9f-fca62612f0b3.png)

# Selber spielen

Unter Releases sind Ausführbare Datein für Linux, macOS und Windows zu finden, diese sind ohne raylib ausführbar und müssen nicht selber kompelliert werden.


# Kompilieren

Anweisungen um das Projekt unter Linux, macOS und Windows selber zu kompilieren

## Linux / macOS

### Vorbereitung

Für das Kompilieren ist Raylib zwingend benötigt, unter Linux und macOS kann diese Bibliothek über einen Paketmanager installiert werden. 
Diese [Konfiguration](https://github.com/SjDuque/Raylib-CMake) wurde für die CMakeLists.txt genutzt.

### Spiel kompilieren

```
git clone https://github.com/paulweber-fhswf/CPP1-Gruppenarbeit
cd CPP1-Gruppenarbeit
mkdir build
cd build
cmake ..
make
```
Das Spiel ist die ausführbare Datei `Tetris`, diese kann mit `./Tetris` aufgerufen werden

## Windows (10/11)
Neben Raylib wird ein folgender Compiler benötigt [UCRT-Runtime-MinGW-W64](https://github.com/brechtsanders/winlibs_mingw/releases/download/12.2.0-15.0.6-10.0.0-ucrt-r3/winlibs-x86_64-posix-seh-gcc-12.2.0-llvm-15.0.6-mingw-w64ucrt-10.0.0-r3.7z). Andere Compiler können auch funktionieren, wurden von uns aber nicht getestet.
Für das Kompilieren unter Windows hat sich das folgende [Konfigurationstemplate von SasLuca](https://github.com/SasLuca/raylib-cmake-template) bewährt. In diesem werden die Source-Dateien von unserem Projekt in den "sources"-Ordner kopiert.
