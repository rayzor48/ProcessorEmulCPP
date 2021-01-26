#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	//std::cout << "Stack constructor 1" << std::endl;
	SP = 0;
	size_stack = 100;
	stack = new unsigned short int[100];
	std::cout << "size_stack = " << size_stack << std::endl;
	//std::cout << "SP =  " << SP << std::endl;
}

Stack::Stack(int size)
{
	//std::cout << "Stack constructor 2" << std::endl;
	SP = 0;
	size_stack = size;
	stack = new unsigned short int[size];
	std::cout << "size_stack = " << size_stack << std::endl;
	//std::cout << "SP =  " << SP << std::endl;
}

bool Stack::push(unsigned short int word)
{

	stack[SP] = word;
	SP += 1;
	//std::cout << "SP =  " << SP << std::endl;
	return true;
}

unsigned short int Stack::pop()
{	
	SP = (SP > 0) ? (SP - 1) : 0;
	unsigned short int word = stack[SP];
	stack[SP] = 0;
	//std::cout << "SP =  " << SP << std::endl;
	
	return word;
}

void Stack::print_stack()
{
	std::cout << "SP =  " << SP << std::endl;
	std::string stack_items = "stack = [";

	for (int i = 0; i < SP && i < size_stack; i++) {
		stack_items += std::to_string(stack[i]);
		stack_items += ", ";
	}

	stack_items += "]";
	std::cout << stack_items << std::endl;
}



Stack::~Stack()
{
	std::cout << "=====================================================" << std::endl;
	std::cout << "Stack destructor " << std::endl;
	std::cout << "=====================================================" << std::endl;
	///std::cout << "SP =  " << SP << std::endl;

	delete [] stack;
}

