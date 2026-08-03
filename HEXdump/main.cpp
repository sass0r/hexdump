#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <filesystem>
#include <Windows.h>

int main(){	
	setlocale(LC_ALL, "");
	SetConsoleCP(65001);
	std::cout << GetConsoleCP() << std::endl;

	std::string   filepath;	
	unsigned char buffer[16];
	size_t        offset = 0;
	
	while (true) {
		std::cout << "file path:";
		std::getline(std::cin, filepath);

		for (unsigned char c : filepath) std::cout << std::hex << (int)c << " ";
		std::cout << std::dec << std::endl;

		for (int i = 0; i < filepath.size(); i++) {
			if (filepath[i] == '"')
				filepath.erase(i, 1);
		}

		int bytes = MultiByteToWideChar(CP_UTF8, 0, filepath.data(), -1, nullptr, 0);

		std::wstring wfilepath(bytes, L'\0');

		MultiByteToWideChar(CP_UTF8, 0, filepath.data(), -1, wfilepath.data(), bytes);

		std::ifstream openedfile(wfilepath, std::ios::binary);

		while (openedfile.read(reinterpret_cast<char*>(buffer), 16) || openedfile.gcount() > 0) {
			size_t bytesread = openedfile.gcount();

			std::cout << std::setw(8) << std::setfill('0') << std::hex << offset << " ";

			for (size_t i = 0; i < 16;++i) {
				if (i < bytesread) {
					std::cout << std::setw(2) << static_cast<int>(buffer[i]) << " ";
				}
				else {
					std::cout << "   ";
				}
			}

			std::cout << " |";

			for (size_t i = 0; i < bytesread;++i) {
				if ((buffer[i] >= 32) && (buffer[i] <= 126)) {
					std::cout << static_cast<char>(buffer[i]);
				}
				else {
					std::cout << ".";
				}
			}

			std::cout << "|" << std::endl;

			offset += 16;
		}

		offset = 0;
	}
}