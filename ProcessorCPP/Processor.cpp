#include "Processor.h"

Processor::Processor()
{
	memory = new Mem();
	stack = new Stack();
	commands_sys = new Commands();

	flag_end = true;
	unsigned short int mass[] = { 0, 19, 0, 20, 0, 30, 27, 26, 0, 1, 25, 1, 100 };
	unsigned short int mass2[] = { 0, 5, 9, 22, 7, 21, 3, 100};

	unsigned short int mass1[] = { 0, 30, 25, 2, 7, 5, 25, 2, 14, 6, 9, 7, 22, 29, 5, 25, 2, 14, 26, 26, 4, 28, 22, 25, 27, 7, 28, 21, 12, 100,  6, 24, 67, 2, 4, 123 ,100, 756};//массив идет в конце программы. первое число после конца программы - кол-во элементов массива, далее идет сам массив чисел
	memory->loadProgramm(mass1, 38);//при изменении числа эллементов массива не забыть поменять длинну массива отправляющуюся в функцию
	PC = 0;
}

Processor::~Processor()
{
	delete memory;
	delete stack;
	delete commands_sys;

}
 
// спроектировать нормальную структуру команды
void Processor::run()
{
	unsigned short int result_ALU;

	int op_code;
	bool flag;

	//memory->print_mem();

	while (flag_end) {
		op_code = memory->read(PC);

		switch (op_code)
		{
		case 0:
			std::cout << "Literal : " << std::endl;
			commands_sys->literal(stack, memory, &PC);
			break;
		case 1:
			std::cout << "Write to memory : " << std::endl;

			commands_sys->write(memory, stack->pop(), stack->pop());
			break;
		case 2:
			std::cout << "Read memory :" << std::endl;
			std::cout << "Stack <= ";
			stack->push(commands_sys->read(memory, stack->pop()));
			break;
		case 3:
			std::cout << "ALU opertions : " << std::endl;
			result_ALU = commands_sys->add(stack->pop(), stack->pop(), &f);

			std::cout << "Stack <= " << result_ALU << std::endl;
			stack->push(result_ALU);
			//std::cout << "result = " << result_ALU << std::endl;
			break;
		case 4:
			std::cout << "ALU opertions : " << std::endl;
			result_ALU = commands_sys->sub(stack->pop(), stack->pop(), &f);
			
			std::cout << "Stack <= " << result_ALU << std::endl;
			stack->push(result_ALU);
			//std::cout << "result = " << result_ALU << std::endl;
			break;
		case 5:
			std::cout << "ALU opertions : " << std::endl;
			result_ALU = commands_sys->inc(stack->pop(), &f);

			std::cout << "Stack <= " << result_ALU << std::endl;
			stack->push(result_ALU);
			break;
		case 6:
			std::cout << "ALU opertions : " << std::endl;
			result_ALU = commands_sys->dec(stack->pop(), &f);

			std::cout << "Stack <= " << result_ALU << std::endl;
			stack->push(result_ALU);
			break;

			//Запись из стека в один из 7 регистров
		case 7:
			commands_sys->writeToReg(stack, &a, 'a');
			break;
		case 8:
			commands_sys->writeToReg(stack, &b, 'b');
			break;
		case 9:
			commands_sys->writeToReg(stack, &c, 'c');
			break;
		case 10:
			commands_sys->writeToReg(stack, &d, 'd');
			break;
		case 11:
			commands_sys->writeToReg(stack, &e, 'e');
			break;
		case 12:
			commands_sys->writeToReg(stack, &h, 'h');
			break;
		case 13:
			commands_sys->writeToReg(stack, &l, 'l');
			break;
			//Запись из регистра в стек
		case 14:
			commands_sys->writeToStack(stack, &a, 'a');
			break;
		case 15:
			commands_sys->writeToStack(stack, &b, 'b');
			break;
		case 16:
			commands_sys->writeToStack(stack, &c, 'c');
			break;
		case 17:
			commands_sys->writeToStack(stack, &d, 'd');
			break;
		case 18:
			commands_sys->writeToStack(stack, &e, 'e');
			break;
		case 19:
			commands_sys->writeToStack(stack, &h, 'h');
			break;
		case 20:
			commands_sys->writeToStack(stack, &l, 'l');
			break;
			//jumps
		case 21:

			std::cout << "JUMP operation : " << std::endl;
			PC = commands_sys->jump_to(memory, PC) - 1; 
			c = commands_sys->dec(c, &f);

			std::cout << "PC <= " << PC << std::endl;
			break;
		case 22:	//flag s
			std::cout << "IF operation : " << std::endl << " flag 'S' = ";
			flag = (1 & f) == 1;
			std::cout << flag << std::endl;
			PC = commands_sys->if_flag(memory, PC, flag) ;

			std::cout << "PC <= " << PC << std::endl;
			break;
		case 23:	//flag z
			std::cout << "IF operation : " << std::endl << " flag 'Z' =";
			flag = (2 & f) == 2;
			std::cout << flag << std::endl;
			PC = commands_sys->if_flag(memory, PC, flag) ;

			std::cout << "PC <= " << PC << std::endl;
			//c = commands_sys->dec(c, &f);
			break;
		case 24:    //flag c
			std::cout << "IF operation : " << std::endl << " flag 'C' = ";
			flag = (4 & f) == 4;
			std::cout << flag<< std::endl;
			PC = commands_sys->if_flag(memory, PC, flag) ;

			std::cout << "PC <= " << (PC + 1) << std::endl;
			break;
		case 25:
			std::cout << "Stack operations : \n DUP" << std::endl;
			commands_sys->dup(stack);
			break;
		case 26:
			std::cout << "Stack operations : \n OVER" << std::endl;
			commands_sys->over(stack);
			break;
		case 27:
			std::cout << "Stack operations : \n SWIPE" << std::endl;
			commands_sys->swipe(stack);
			break;
		case 28:
			std::cout << "Stack operations : \n DROP" << std::endl;
			commands_sys->drop(stack);
			break;
		case 100:
			std::cout << "end programm"<< std::endl;
			flag_end = false;
			return;
		default:
			break;
		}

		std::cout << "\nPC = " << PC++ << ", ";
		std::cout << "OP_CODE = " << op_code << ", ";
		stack->print_stack();
		std::cout << "reg : a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << ", e = " << e << ", h = " << h << ", l = " << l << ", f = " << f <<std::endl;
		memory->print_mem();

		if (PC >100) {
			return;
		}
		std::cout << std::endl;
	}

}
