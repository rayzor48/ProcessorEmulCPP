
#include "Mem.h"
#include <string>

		Mem::Mem() {
			size_mem = 100;
			memory = new unsigned short int[size_mem];
		}

		Mem::Mem(int size) {
			size_mem = size;
			memory = new unsigned short int[size];
		}

		unsigned short int  Mem::read(int address) {
			if (address < size_mem) {
				return memory[address];
			}

			return 1111;
		}
		
		//добавить проверку на размеры
		void Mem::loadProgramm(unsigned short int* mass, int size) {
			for (int i = 0; i < size; i++) {
				memory[i] = mass[i];
			}
		}
		 
		bool Mem::write(int address, unsigned short word)
		{
			if (address < size_mem) {
				memory[address] = word;
				return true;
			}

			return false;
		}

		void Mem::print_mem()
		{
			std::string mem_items = "memory = [";

			for (int i = 0; i < size_mem && memory[i] != 52685; i++) {
				mem_items += std::to_string(memory[i]);
				mem_items += ", ";
			}

			mem_items += "]";
			std::cout << mem_items << std::endl;
		}

		Mem::~Mem()
		{
			delete[] memory;
		}