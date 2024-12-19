# OpenGL Mini Project

This project demonstrates a simple OpenGL application using FreeGLUT to render a rotating triangle.

## Requirements

- Windows OS
- Visual Studio Code
- Microsoft Visual Studio Build Tools
- vcpkg package manager

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
   - Create a [.vscode](http://_vscodecontentref_/7) directory in your project folder.
   - Create a [tasks.json](http://_vscodecontentref_/8) file in the [.vscode](http://_vscodecontentref_/9) directory with the following content:
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
         }
       ]
     }
     ```

5. **Copy Required DLLs**:
   - Copy [freeglut.dll](http://_vscodecontentref_/10) from `C:/Users/kuba-/vcpkg/installed/x64-windows/bin` to the directory where your executable (`main.exe`) is located.

6. **Write Your OpenGL Code**:
   - Create a [main.cpp](http://_vscodecontentref_/11) file with the following content:
     ```cpp
     #include <windows.h>
     #include <GL/glut.h>
     #include <iostream>

     using namespace std;

     float angle = 0.0;

     void display()
     {
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         glLoadIdentity();
         glTranslatef(0.0f, 0.0f, -5.0f);
         glRotatef(angle, 0.0f, 1.0f, 0.0f);

         glBegin(GL_TRIANGLES);
         glColor3f(1.0f, 0.0f, 0.0f);
         glVertex3f(-1.0f, -1.0f, 0.0f);
         glColor3f(0.0f, 1.0f, 0.0f);
         glVertex3f(1.0f, -1.0f, 0.0f);
         glColor3f(0.0f, 0.0f, 1.0f);
         glVertex3f(0.0f, 1.0f, 0.0f);
         glEnd();

         glutSwapBuffers();
         angle += 0.1f;
         glutPostRedisplay(); // Ensure continuous rendering
     }

     void init()
     {
         glEnable(GL_DEPTH_TEST);
         glViewport(0, 0, 800, 600); // Set the viewport
         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();
         gluPerspective(45.0, 800.0 / 600.0, 1.0, 100.0);
         glMatrixMode(GL_MODELVIEW);
     }

     int main(int argc, char **argv)
     {
         glutInit(&argc, argv);
         glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
         glutInitWindowSize(800, 600);
         glutCreateWindow("OpenGL Test");
         init();
         glutDisplayFunc(display);
         glutMainLoop();
         return 0;
     }
     ```

7. **Build and Run**:
   - Open Visual Studio Code.
   - Open the terminal in Visual Studio Code and run the build task by pressing `Ctrl+Shift+B`.
   - Run the generated executable (`main.exe`).

## License

This project is licensed under the MIT License.