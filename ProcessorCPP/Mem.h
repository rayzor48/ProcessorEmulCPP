#pragma once
#include<iostream>

class Mem
{
	
private:
	unsigned short int* memory;
	int size_mem;
public:
	Mem();
	Mem(int size);
	void loadProgramm(unsigned short int *mass, int size);
	unsigned short int read(int address);
	bool write(int address, unsigned short word);
	void print_mem();
	~Mem();
};
