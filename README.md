# OpenGL Mini Project

This project is my journey through learning a OpenGL Graphics API. Building and trying to build game engine.

## Requirements

- Windows or Linux OS
- Visual Studio Code (version 1.60 or later)
- Microsoft Visual Studio Build Tools (version 2019 or later) for Windows
- vcpkg package manager (latest version)

## Setup Instructions

### Windows

1. **Install Visual Studio Build Tools**:
   - Download and install [Microsoft Visual Studio Build Tools](https://visualstudio.microsoft.com/visual-cpp-build-tools/).

2. **Install vcpkg, GLFW, and GLAD**:
   - Run the provided `install.bat` script to install vcpkg, GLFW, and GLAD:

     ```sh
     .\install.bat
     ```

3. **Add Required Paths to Environment Variables**:
   - Depending on your installed versions of Visual Studio, Windows Kits, and MSVC, you need to add the appropriate paths to your `PATH` environment variable. Here are some examples:

     - For Visual Studio 2022 Community:
       - `C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\<version>\bin\Hostx64\x64`
       - `C:\Program Files (x86)\Windows Kits\10\bin\<version>\x64`
       - `C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCPackages`

     - For Visual Studio 2019 Build Tools:
       - `C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\<version>\bin\Hostx64\x64`
       - `C:\Program Files (x86)\Windows Kits\10\bin\<version>\x64`
       - `C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\IDE\VC\VCPackages`

     - For vcpkg:
       - `C:\Users\<your-username>\vcpkg\installed\x64-windows\bin`

     Replace `<version>` with the actual version numbers installed on your system. You can find these versions by navigating to the respective directories.

4. **Start Visual Studio Code through Developer PowerShell/Console**:
   - Open Developer PowerShell or Developer Command Prompt for Visual Studio.
   - Navigate to your project directory and start Visual Studio Code:

     ```sh
     code .
     ```

5. **Configure Visual Studio Code**:
   - The [.vscode](http://_vscodecontentref_/1) directory and its configuration files are already provided in the project.

6. **Copy Required DLLs**:
   - Copy [glfw3.dll](http://_vscodecontentref_/2) from `C:/Users/<your-username>/vcpkg/installed/x64-windows/bin` to the directory where your executable (`main.exe`) is located.

7. **Write Your OpenGL Code**

8. **Build and Run**:
   - Open Visual Studio Code.
   - Open the terminal in Visual Studio Code and run the build task by pressing `Ctrl+Shift+B`.
   - Run the generated executable (`main.exe`).

### Linux

1. **Install vcpkg, GLFW, and GLAD**:
   - Run the provided [install.sh](http://_vscodecontentref_/3) script to install vcpkg, GLFW, and GLAD:

     ```sh
     ./install.sh
     ```

2. **Configure Visual Studio Code**:
   - The [.vscode](http://_vscodecontentref_/4) directory and its configuration files are already provided in the project.

3. **Write Your OpenGL Code**

4. **Build and Run**:
   - You can use the provided [build.makefile](http://_vscodecontentref_/5) to build and install the project:
     - Open a terminal and navigate to your project directory.
     - Run the following commands:

       ```sh
       make -f build.makefile build
       ```

   - Open Visual Studio Code.
   - Open the terminal in Visual Studio Code and run the build task by pressing `Ctrl+Shift+B`.
   - Run the generated executable (`main`).

## License

This project is licensed under the MIT License.