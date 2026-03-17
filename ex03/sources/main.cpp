#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("jhon", 2);
    Intern someRandomIntern;
    AForm* rrf;
    AForm* ppf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");  //sign 72, exec 45
    ppf = someRandomIntern.makeForm("presidential pardon", "Carnage");  //sign 72, exec 45

    //cannot sign
    jhon.signForm(*rrf);
    //cannot execute
    jhon.executeForm(*rrf);
    jhon.executeForm(*rrf);
    jhon.executeForm(*ppf);

    delete rrf;
    delete ppf;
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }
}

