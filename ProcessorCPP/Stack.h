#pragma once
#include <iostream>
#include <string>

class Stack
{
private:
	int SP;//указатель стека
	int size_stack;
	unsigned short int* stack;
public:
	Stack();
	Stack(int size);
	bool push(unsigned short int word);
	unsigned short int pop();
	void print_stack();
	~Stack();
};

