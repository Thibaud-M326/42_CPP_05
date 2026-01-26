#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("jhon", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
