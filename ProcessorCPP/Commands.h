#pragma once
#include "Stack.h";
#include "Mem.h";
#include <iostream>

class Commands
{
private :
	bool z, s, c;

	int result;
	void flags_mod(unsigned short int *flags);

public : 
		//Арифметика
	unsigned short int add(unsigned short int a, unsigned short int b, unsigned short int *flags);
	unsigned short int sub(unsigned short int a, unsigned short int b, unsigned short int* flags);
	unsigned short int inc(unsigned short int a, unsigned short int* flags);
	unsigned short int dec(unsigned short int a, unsigned short int* flags);
		//работа с флагами
	void flags_update(unsigned short int* flags);
	void flags_up();

		//Непосредственный операнд
	void literal(Stack* s, Mem* m, int *PC);
	
	
		//Операции с памятью 
	unsigned short int  read(Mem *m, int address);
	void write(Mem *m, unsigned short int word, int address);
		
		//Операции с регистрами
	
	// stack -> register[number]
	void writeToReg(Stack* s, unsigned short int *reg, char regName);
	
	// stack <- register[number]
	void writeToStack(Stack *s, unsigned short int *reg, char regName);


		//jumps
	int jump_to(Mem *m, int PC);
	int if_flag(Mem* m, int PC, bool flag);
	
	bool getFlag();

		//операции со стеком
	void push();
	unsigned short int drop(Stack* s);
	unsigned short int dup(Stack *s);
	unsigned short int over(Stack* s);
	unsigned short int swipe(Stack* s);


};

