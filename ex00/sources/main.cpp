#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("jhon", 120);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
}
