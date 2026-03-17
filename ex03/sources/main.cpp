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

    //sign
    jhon.signForm(*rrf);
    //execute
    jhon.executeForm(*rrf);
    //execute
    jhon.executeForm(*rrf);
    //not yet signed
    jhon.executeForm(*ppf);

    delete rrf;
    delete ppf;
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }
}

