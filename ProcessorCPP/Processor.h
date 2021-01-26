#pragma once
#include "Mem.h"
#include "Stack.h"
#include "Commands.h"

class Processor
{
public: 
	//Регистры :
	//Регистр флагов - f 
	//Присутствуют флаги : 
	//z - флаг нуля
	//s - флаг знака
	//с - флаг переполнения
	unsigned short int a, b, c, d, e, h, l, f;
	int PC; // счетчик команд
	bool flag_end;

	Mem * memory;
	Stack * stack;
	Commands * commands_sys;

private :

public :
	Processor();
	~Processor();
	void run();
};

