#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("jhon", 20);

    //form grade too low, no destructor for form;
    Form signIn("signIn", 200, 20);

    jhon.signForm(signIn);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

	try
	{
		Bureaucrat jhon("jhon", 20);

    //form grade too high, no destructor for form;
    Form signIn("signIn", 0, 20);

    jhon.signForm(signIn);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

	try
	{
		Bureaucrat jhon("jhon", 20);

    Form signIn("signIn", 10, 20);

    //bureaucrat can't sign, grade too low, all destructor will be called
    jhon.signForm(signIn);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  std::cout << std::endl;

  try
  {
    Bureaucrat jhon("jhon", 20);

    Form signIn("signIn", 20, 20);

    //signIn work, all destructor will be called
    jhon.signForm(signIn);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }
}
