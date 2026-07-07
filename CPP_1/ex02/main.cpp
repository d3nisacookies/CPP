#include <iomanip>
#include <iostream>
#include <string>

int	main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string *ptr = &var;
	std::string &ref = var;

	std::cout << "memory address of a string variable: " << &var << std::endl;
	std::cout << "memory address of the pointer: " << ptr << std::endl;
	std::cout << "memory address of the reference: " << &ref << std::endl;

	std::cout << "value of string variable: " << var << std::endl;
	std::cout << "value pointed by ptr: " << *ptr << std::endl;
	std::cout << "value pointed by ref: " << ref << std::endl;

	return (0);
}