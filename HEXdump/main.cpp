#include <iostream>
#include <fstream>
#include <iomanip>

int main(){
	
	std::string   filepath;
	unsigned char buffer[16];
	size_t        offset = 0;
	
	while (true) {
		std::cout << "file path:";
		std::cin >> filepath;
		std::cout << std::endl;

		std::ifstream openedfile(filepath, std::ios::binary);

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
	}
}