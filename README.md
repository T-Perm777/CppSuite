# CppSuite - A Suite of Helpful C++ Tools
## Getting Started

Follow these steps to build and use these C++ tools.

### Prerequisites

- CMake
- C++ 17 or higher
- (Optional) VSCode (or any other text editor, like Notepad++, Vim, or nano) to look through the files

### Building

#### If you want the precompiled binaries (executable files), go [here](https://github.com/T-Perm777/CppSuite/releases).

Run:
```bash
git clone https://github.com/T-Perm777/CppSuite.git
cd CppSuite
mkdir build && cd build
cmake ..
cmake --build .
```
The executables will be found in build. Copy them wherever you like.

#### **Optional, but rccommended**

- Add the file path (ie, C:\Tools\OSInfo) to your system's PATH.

## Usage

- For `OSInfo`, just type in the name of your compiled exe to run it. I haven't added any flags [yet!]
- For RandomPassGen (also called PassGen), run the command, and follow the prompts on screen. To generate a password with default setting, run it with the -f flag. to output to a file, use the -o flag, followed by the file name (either something like password.txt or C:\Passwords\password.txt).


#### If you have ideas for new features or tools, submit a pull request! Learn how [here](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests), and look [here](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request) on how to create one.


### THIS SOFTWARE IS PROTECTED UNDER THE MIT LICENSE

- **Check the LICENSE file for the full licensing and permissions.**

# TODO

- Add extra functionality to `osinfo`
- Make `osinfo` cross-platform for Linux
- Scientific calculator
- Likely split this repo into multiple, with this being the website and directory for others.