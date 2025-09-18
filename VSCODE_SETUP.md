# VS Code Setup Guide for SnakeGame-C

## 🚀 Quick Start

### 1. Open Project in VS Code
```bash
cd /Users/nandiu/Desktop/SnakeGame-C
code .
```

### 2. Install Recommended Extensions
When you open the project, VS Code will automatically suggest installing recommended extensions. Click **"Install All"** or install them manually:

**Essential Extensions:**
- **C/C++** (`ms-vscode.cpptools`) - IntelliSense, debugging, and code browsing
- **CMake Tools** (`ms-vscode.cmake-tools`) - CMake integration
- **C/C++ Extension Pack** (`ms-vscode.cpptools-extension-pack`) - Complete C++ toolchain

**Optional but Recommended:**
- **CodeLLDB** (`vadimcn.vscode-lldb`) - Enhanced debugging for macOS
- **Code Runner** (`formulahendry.code-runner`) - Quick code execution
- **Todo Tree** (`gruntfuggly.todo-tree`) - View TODO comments

## 🔧 How to Build and Run

### Method 1: Using Tasks (Recommended)
1. **Open Command Palette**: `Cmd+Shift+P`
2. **Type**: `Tasks: Run Task`
3. **Select one of**:
   - `CMake: Build Debug` - Build with debug symbols
   - `CMake: Build Release` - Build optimized version
   - `Run SnakeGame` - Build and run the game
   - `Clean Build` - Clean build directory

### Method 2: Using Keyboard Shortcuts
- **Build**: `Cmd+Shift+P` → `Tasks: Run Build Task` (or `Cmd+Shift+B`)
- **Run**: `F5` (Debug) or `Ctrl+F5` (Run without debugging)

### Method 3: Using Terminal
- **Open Terminal**: `Ctrl+`` (backtick)
- **Build**:
  ```bash
  mkdir -p build && cd build
  cmake .. -DCMAKE_BUILD_TYPE=Debug
  make -j4
  ```
- **Run**:
  ```bash
  ./build/SnakeGame
  ```

## 🐛 Debugging

### Start Debugging
1. **Set Breakpoints**: Click left margin next to line numbers
2. **Start Debug Session**: 
   - Press `F5`
   - Or go to **Run and Debug** sidebar (`Cmd+Shift+D`)
   - Select **"Debug SnakeGame"** and click play button

### Debug Features Available
- **Step Over**: `F10`
- **Step Into**: `F11`
- **Step Out**: `Shift+F11`
- **Continue**: `F5`
- **Stop**: `Shift+F5`
- **Watch Variables**: Add to Watch panel
- **Call Stack**: View function call hierarchy

## 📝 IntelliSense Features

### What Works
- ✅ **Code Completion** - Autocomplete for SDL2, C++17 features
- ✅ **Error Highlighting** - Real-time syntax and semantic errors
- ✅ **Go to Definition** - `Cmd+Click` or `F12`
- ✅ **Find References** - `Shift+F12`
- ✅ **Code Navigation** - Jump between headers and implementations
- ✅ **Hover Info** - Function documentation and type info

### Code Formatting
- **Format Document**: `Shift+Option+F`
- **Format on Save**: Enabled by default
- **Settings**: 2-space indentation, insert spaces (not tabs)

## 🎮 Running the Game

### From VS Code
1. **Quick Run**: `Cmd+Shift+P` → `Tasks: Run Task` → `Run SnakeGame`
2. **Debug Run**: Press `F5` → Select "Debug SnakeGame"
3. **Release Run**: Press `F5` → Select "Run SnakeGame (No Debug)"

### Game Controls (Reminder)
- **Arrow Keys**: Move snake
- **Spacebar**: Pause/Resume
- **R**: Restart (when game over)
- **ESC**: Quit (from pause/game over)

## 🔧 Customization

### Workspace Settings
Edit `.vscode/settings.json` to customize:
- Code formatting preferences
- Build configurations
- Terminal settings
- Editor behavior

### Build Configurations
Available in `.vscode/tasks.json`:
- **Debug Build**: Includes debug symbols, no optimization
- **Release Build**: Optimized for performance
- **Clean Build**: Remove all build artifacts

## 🚨 Troubleshooting

### Common Issues

#### 1. "SDL.h not found"
**Solution**: Make sure SDL2 is installed:
```bash
brew install sdl2 sdl2_mixer
```

#### 2. "CMake not found"
**Solution**: Install CMake:
```bash
brew install cmake
```

#### 3. IntelliSense not working
**Solutions**:
- Reload VS Code: `Cmd+Shift+P` → `Developer: Reload Window`
- Rebuild IntelliSense: `Cmd+Shift+P` → `C/C++: Reset IntelliSense Database`
- Check C++ extension is installed and enabled

#### 4. Debugger not starting
**Solutions**:
- Ensure project builds successfully first
- Check that lldb is available: `which lldb` in terminal
- Try the "Run SnakeGame (No Debug)" configuration instead

### Build Errors
- **Check Terminal Output**: Build errors will show in the Terminal panel
- **Problem Panel**: `Cmd+Shift+M` to see parsed errors and warnings
- **Clean and Rebuild**: Use "Clean Build" task, then rebuild

## 📁 Project Structure in VS Code

```
SnakeGame-C/
├── .vscode/              # VS Code configuration
│   ├── settings.json     # Workspace settings
│   ├── tasks.json        # Build and run tasks
│   ├── launch.json       # Debug configurations
│   ├── c_cpp_properties.json # IntelliSense config
│   └── extensions.json   # Recommended extensions
├── src/                  # Source code
├── cmake/                # CMake modules
├── build/                # Build output (generated)
├── CMakeLists.txt        # Build configuration
└── README.md             # Project documentation
```

---

**Happy Coding!** 🎉 Your SnakeGame-C project is now fully configured for professional C++ development in VS Code!