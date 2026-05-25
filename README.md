
# hexdump-search_for_string 🔍

> A lightweight C++ console utility for viewing binary files in hexadecimal format and searching for ASCII strings within them.

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat&logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey?style=flat)
![License](https://img.shields.io/github/license/sass0r/hexdump?style=flat)

## 📋 About

**hexdump-search_for_string** is a simple command-line tool inspired by the classic Unix `hexdump` utility. It allows you to:

- 📄 View any binary file in a human-readable hexadecimal format
- 🔎 Search for specific ASCII strings within binary data
- 💻 Run as a lightweight console application with minimal dependencies

Perfect for reverse engineering, debugging, file analysis, or educational purposes.

## 🚀 Features

- ✅ Classic hex dump output (offset + hex bytes + ASCII representation)
- ✅ String search functionality within binary files
- ✅ Clean, readable console output
- ✅ No external dependencies — pure C++ standard library
- ✅ Cross-platform (Windows/Linux compatible)

## 🛠️ Building from Source

### Prerequisites
- C++17 compatible compiler (MSVC, GCC, or Clang)
- CMake or Visual Studio 2022+ (optional, for IDE users)

### Using Visual Studio (Windows)
```bash
# Clone the repository
git clone https://github.com/sass0r/hexdump.git
cd hexdump

# Open the solution file
hexdump-search_for_string.slnx
```

Then press **F5** to build and run.

### Using Command Line (Cross-platform)
```bash
# Clone and navigate
git clone https://github.com/sass0r/hexdump.git
cd hexdump

# Compile with g++
g++ -std=c++17 -O2 -o hexdump main.cpp

# Run the utility
./hexdump <filename> [search_string]
```

## 📖 Usage

### Basic hex dump
```bash
# Display hex content of a file
./hexdump myfile.bin
```

**Example output:**
```
00000000  4d 5a 90 00 03 00 00 00  04 00 00 00 ff ff 00 00  |MZ..............|
00000010  b8 00 00 00 00 00 00 00  40 00 00 00 00 00 00 00  |........@.......|
```

### Output format
```
[OFFSET]  [HEX BYTES]                 [ASCII VIEW]
00000000  48 65 6c 6c 6f 20 57 6f    |Hello Wo|
```

## ⚙️ Technical Details

| Feature | Implementation |
|---------|---------------|
| **Language** | C++17 |
| **Standard Library** | `<iostream>`, `<fstream>`, `<iomanip>`, `<string>`, `<vector>` |
| **File I/O** | Binary mode (`std::ios::binary`) |
| **Hex Formatting** | `std::hex`, `std::setw`, `std::setfill` |
| **String Search** | Linear scan with `std::string::find` |

## 🤝 Contributing

Contributions are welcome! Feel free to:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -m 'Add useful feature'`)
4. Push and open a Pull Request
