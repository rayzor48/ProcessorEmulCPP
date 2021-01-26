#pragma once
#include "Mem.h"
#include "Stack.h"
#include "Commands.h"

class Processor
{
public: 
	//�������� :
	//������� ������ - f 
	//������������ ����� : 
	//z - ���� ����
	//s - ���� �����
	//� - ���� ������������
	unsigned short int a, b, c, d, e, h, l, f;
	int PC; // ������� ������
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

