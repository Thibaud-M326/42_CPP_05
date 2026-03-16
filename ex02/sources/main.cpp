#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("jhon", 20);

    PresidentialPardonForm ppf("police");

    jhon.signForm(ppf);
    jhon.executeForm(ppf);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }
}
