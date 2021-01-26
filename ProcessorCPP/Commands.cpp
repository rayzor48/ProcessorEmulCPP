#include "Commands.h"
void Commands::flags_mod(unsigned short int* flags)
{

}

//арифметические операции
unsigned short int Commands::add(unsigned short int a, unsigned short int b, unsigned short int* flags)
{
	result = a + b;
	std::cout << " Operations : '+' ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "result = a + b = " << result << std::endl;

	flags_update(flags);
	return result;
}

unsigned short int Commands::sub(unsigned short int a, unsigned short int b, unsigned short int* flags)
{
	result = a - b;

	std::cout << " Operations : '-' ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "result = a - b = " << result << std::endl;

	flags_update(flags); 
	return result;
}

unsigned short int Commands::inc(unsigned short int a, unsigned short int* flags)
{	
	result = a + 1;

	std::cout << " Operations : '+1' ";
	std::cout << "result = a + 1 = " << result << std::endl;
	flags_update(flags);
	return result;
}

unsigned short int Commands::dec(unsigned short int a, unsigned short int* flags)
{
	result = a - 1;

	std::cout << " Operations : '-1' ";
	std::cout << "result = a - 1 = " << result << std::endl;

	flags_update(flags);
	return result;
}

void Commands::flags_update(unsigned short int* flags)
{
	flags_up();
	
	*flags = 0;
	*flags += s ? 1 : 0;
	*flags += z ? 2 : 0;
	*flags += c ? 4 : 0;

	std::cout << "Register of flags = " << *flags << std::endl;
}

void Commands::flags_up()
{
	/*if (result > 65535)
	{
		c = result > 65535;
		result = 0;
	}*/

	c = result > 65535;
	result = c ? 0 : result;

	z = result == 0;
	
	s = result < 0;
	result = s ? 0 : result;
	/*
	if (result < 0)
	{
		s = result <0;
		result = 0;
	}*/

	std::cout << "result = " << result << std::endl;
	std::cout << "c = " << c << ", z = " << z << ", s = " << s << std::endl;
}

//литерал
void Commands::literal(Stack *s, Mem *m, int *PC)
{
	*PC +=1;//увеличиваем счетчик чтобы прочитать операнд
	std::cout << "Stack <= " <<  m->read(*PC)<<std::endl;
	unsigned short int word = m->read(*PC);

	s->push(word);
}

//чтение/запись слова в память
unsigned short int  Commands::read(Mem *m, int address)
{	std::cout << "Memory[" << address << "] => " << m->read(address) << std::endl;
	return m->read(address);
}

void Commands::write(Mem *m, unsigned short int word, int address)
{
	std::cout << "Memory[" << address << "] <= " << word << std::endl;
	m->write(address, word);
}

//Чтение/запись регистров
void Commands::writeToReg(Stack* s, unsigned short int* reg, char regName)
{
	std::cout << "Write from stack to Register:  " << std::endl;
	std::cout << "stack => Register[" << regName << "] = " << *reg;
	//unsigned short  d = s->pop();
	//std::cout << "pop() = " << d << "\n";
	*reg = s->pop();
	std::cout << *reg << std::endl;
}

void Commands::writeToStack(Stack* s, unsigned short int *reg, char regName)
{

	std::cout << "Write drom Registers to stack:  " << std::endl;
	std::cout << "stack <= Register[" << regName << "] = " << *reg << std::endl;
	s->push(*reg);
}

//прыжки
int Commands::jump_to(Mem *m, int PC)
{
	//std::cout << "jump_to = " << m->read(PC + 1) << "\n";
	std::cout << "Memory[ " << m->read(m->read(PC + 1)) << " ] = " << m->read(PC + 1) << "\n";
	return m->read(PC+1);
}

int Commands::if_flag(Mem* m, int PC, bool flag)
{	
	PC = PC + 1;

	//std::cout << "if_flag_1: " << "PC = " << PC << ", flag = " << flag << std::endl;

	if (flag) {
		//std::cout << "mem(PC) = " << m->read(PC) << std::endl;
		std::cout << "PC = "<< PC << " or ";
		PC = m->read(PC) - 1;
		std::cout << PC << " ? " << std::endl;
	}

	//std::cout << "if_flag_2: " << "PC = " << PC << ", flag = " << flag << std::endl;
	return PC;
}

void Commands::push()
{
	//добавить метод который будет обновлять флаги
}

unsigned short int Commands::drop(Stack* s)
{
	s->pop();
	return 0;
}
//операции со стеком
unsigned short int Commands::dup(Stack* s)
{
	unsigned short int top_word = s->pop();
	s->push(top_word);
	s->push(top_word);
	return 0;
}

unsigned short int Commands::over(Stack* s)
{
	unsigned short int top_word = s->pop();
	unsigned short int sub_top_word = s->pop();

	s->push(sub_top_word);
	s->push(top_word);
	s->push(sub_top_word);

	return 0;
}

unsigned short int Commands::swipe(Stack* s)
{
	unsigned short int top_word = s->pop();
	unsigned short int sub_top_word = s->pop();

	s->push(top_word);
	s->push(sub_top_word);
	return 0;
}
