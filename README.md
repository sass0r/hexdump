
# hexdump 🔍

> A lightweight C++ console utility for viewing binary files in hexadecimal format.

## About

**hexdump** is a simple command-line tool inspired by the classic Unix `hexdump` utility. It allows you to:

- View any binary file in a human-readable hexadecimal format
- Search for specific ASCII strings within binary data
- Run as a lightweight console application with minimal dependencies

Perfect for reverse engineering, debugging, file analysis, or educational purposes.

## Features

- Classic hex dump output (offset + hex bytes + ASCII representation)
- String search functionality within binary files
- Clean, readable console output
- No external dependencies — pure C++ standard library

## 📖 Usage

### Basic hex dump
```bash
# Display hex content of a file
./hexdump
file path:<full path of your file>
```

**Example output:**
```
00000000  4d 5a 90 00 03 00 00 00  04 00 00 00 ff ff 00 00  |MZ..............|
00000010  b8 00 00 00 00 00 00 00  40 00 00 00 00 00 00 00  |........@.......|
```
