# OpenGL Mini Project

This project is my journey through learning a OpenGL Graphics API

## Requirements

- Windows OS
- Visual Studio Code (version 1.60 or later)
- Microsoft Visual Studio Build Tools (version 2019 or later)
- vcpkg package manager (latest version)

## Setup Instructions

1. **Install Visual Studio Build Tools**:
   - Download and install [Microsoft Visual Studio Build Tools](https://visualstudio.microsoft.com/visual-cpp-build-tools/).

2. **Install vcpkg**:
   - Follow the instructions to install vcpkg from the [vcpkg GitHub repository](https://github.com/microsoft/vcpkg).

3. **Install FreeGLUT using vcpkg**:
   - Open a terminal and navigate to the vcpkg directory.
   - Run the following command to install FreeGLUT:
     ```sh
     .\vcpkg install freeglut:x64-windows
     ```

4. **Configure Visual Studio Code**:
   - Create a [.vscode](http://_vscodecontentref_/1) directory in your project folder.
   - Create a `tasks.json` file in the [.vscode](http://_vscodecontentref_/2) directory with the following content:
     ```json
     {
       "version": "2.0.0",
       "tasks": [
         {
           "label": "build",
           "type": "shell",
           "command": "cl.exe",
           "args": [
             "/EHsc",
             "/I",
             "C:/Users/kuba-/vcpkg/installed/x64-windows/include",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/ucrt",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/shared",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/um",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/winrt",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/cppwinrt",
             "/I",
             "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.41.34120/include",
             "/machine:x64",
             "${file}",
             "/link",
             "/LIBPATH:C:/Users/kuba-/vcpkg/installed/x64-windows/lib",
             "freeglut.lib",
             "opengl32.lib",
             "glu32.lib",
             "/OUT:${fileDirname}/${fileBasenameNoExtension}.exe",
             "/machine:x64"
           ],
           "group": {
             "kind": "build",
             "isDefault": true
           },
           "problemMatcher": ["$msCompile"]
         },
         {
           "label": "build-release",
           "type": "shell",
           "command": "cl.exe",
           "args": [
             "/EHsc",
             "/O2", // Optimization flag for release build
             "/I",
             "C:/Users/kuba-/vcpkg/installed/x64-windows/include",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/ucrt",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/shared",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/um",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/winrt",
             "/I",
             "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/cppwinrt",
             "/I",
             "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.41.34120/include",
             "/machine:x64",
             "${file}",
             "/link",
             "/LIBPATH:C:/Users/kuba-/vcpkg/installed/x64-windows/lib",
             "freeglut.lib",
             "opengl32.lib",
             "glu32.lib",
             "/OUT:${fileDirname}/${fileBasenameNoExtension}.exe",
             "/machine:x64"
           ],
           "group": {
             "kind": "build",
             "isDefault": false
           },
           "problemMatcher": ["$msCompile"]
         }
       ]
     }
     ```

5. **Copy Required DLLs**:
   - Copy [freeglut.dll](http://_vscodecontentref_/3) from `C:/Users/kuba-/vcpkg/installed/x64-windows/bin` to the directory where your executable (`main.exe`) is located.

6. **Write Your OpenGL Code**

7. **Build and Run**:
   - Open Visual Studio Code.
   - Open the terminal in Visual Studio Code and run the build task by pressing `Ctrl+Shift+B`.
   - Run the generated executable (`main.exe`).

## License

This project is licensed under the MIT License.
