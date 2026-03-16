#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"

int main()
{
	try
	{
    //grade too low, no destructor calling
		Bureaucrat jhon("jhon", 151);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  try
	{
    //grade too high, no destructor calling
		Bureaucrat bernard("bernard", 0);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  try
	{
		Bureaucrat louca("louca", 2);

    louca.incrementGrade(); 
    //grade too high, a destructor will be called
    louca.incrementGrade(); 
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  try
	{
		Bureaucrat jhonny("jhonny", 150);

    //grade too low, a destructor will be called
    jhonny.decrementGrade(); 
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }
}
