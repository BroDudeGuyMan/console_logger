# console_logger
console_logger is a small, dependency free C++ logging library with ANSI color support. It's designed to be an include-and-use logger that helps to create uniform output for you and your users. No objects are created, meaning that logging is as simple as:
```cpp
logger::input("Please enter a file path");
logger::info("File created successfuly!");
```
No global state and no configuration to get started.

[Documentation](docs/index.md)

## Requirements
- C++17 or newer
- CMake ≥ 3.2
- ANSI-capable terminal (using the `logger::init()` function will set up the terminal for colors or disable them if the terminal does not support colors)

## Installation
### Option 1: Install system-wide with Cmake
```bash
gh repo clone BroDudeGuyMan/console_logger
cd console_logger
mkdir build && cd build
cmake ..
cmake --build .
sudo cmake --install .
```
This installs:
- headers to `/usr/local/include`
- the library to `/usr/local/lib`
- CMake config files to `/usr/local/lib/cmake/console_logger`

### Option 2: Use as a subproject.
This helps larger projects track dependencies.
Add it to your project:
```bash
git submodule add https://github.con/BroDudeGuyMan/console_logger.git
```
Then in `CMakeLists.txt`
```cmake
add_subdirectory(external/console_logger)
target_Link_libraries(<your_target> console_logger::console_logger)
```
This way, there is no install step.
### Windows + Visual Studio
#### Requirements
- Windows 10 or newer
- Visual Studio 2019 or 2022
- "Desktop development with C++" workload
- CMake support enabled (should be on by default for VS)

#### Option 1: Use as a subproject
This avoids install paths and permissions. It also helps with dependencies.
```
MyProject/
├── CMakeLists.txt
├── src/
└── external/
    └── console_logger/
```
```cmake
add_subdirectory(external/console_logger)
target_link_libraries(<executable_name> PRIVATE console_logger::console_logger)
```
Open the project folder in VS and it should configure and build automatically.

#### Option 2: Install system-wide
From a **Developer Command Prompt for Visual Studio**:
```bat
git clone https://github.com/<your-username>/console_logger.git
cd console_logger
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
cmake --install .
```
Then in your project:
```cmake
find_package(console_logger REQUIRED)
target_link_libraries(<executable_name> PRIVATE console_logger::console_logger)
```

**ANSI Color Support on Windows**

The logger by default will use colors, and Linux machines should have no issues with colors. Windows command prompts may have issues with ANSI codes, so using `logger::init()` may be useful. It will check whether the current Windows command prompt has support for colors, and if not will disable them.

## Usage with CMake (`find_package`)
After installation:
```cmake
find_package(console_logger REQUIRED)
target_link_libraries(<your_target> PRIVATE console_logger::console_logger)
```
You **do not** need to manually add include directories.

## Usage in Code
Include the header:
```cpp
#include <console/logger/console_logger.h>
```
Log from anywhere:
```cpp
logger::info("Application started");
logger::warning("Low memory");
logger::error("Failed to open file");
```

## ANSI color support
- Colors are enabled by default on Linux and MacOS
- Windows has patchy support
 - `logger::init()' automatically detects color support for terminals and is safe to call on all platforms.
 - Colors are autamatically disabled if support is not detected
 - Colors remain on if supported by the console

### Guaranteed Behavior
- Never prints raw ANSI codes when color is disabled
- Never fails if colors are not supported
- Never requires global objects or macros
- Safe for projects of any kind: other libraries, tools, and small utilities
