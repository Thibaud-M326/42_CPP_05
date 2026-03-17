#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("jhon", 30);

    PresidentialPardonForm ppf("police"); //sign 25, exec 5

    //cannot sign
    jhon.signForm(ppf);
    //cannot execute
    jhon.executeForm(ppf);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  std::cout << std::endl;

	try
	{
		Bureaucrat jhon("jhon", 20);

    PresidentialPardonForm ppf("police"); //sign 25, exec 5

    //can sign
    jhon.signForm(ppf);
    //cannot execute
    jhon.executeForm(ppf);
	}
  catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  std::cout << std::endl;

	try
  {
    Bureaucrat jhon("jhon", 2);

    PresidentialPardonForm ppf("police"); //sign 25, exec 5

    //can sign
    jhon.signForm(ppf);
    //already signed
    jhon.signForm(ppf);
    //can execute
    jhon.executeForm(ppf);
  }
	catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  std::cout << std::endl;

	try
  {
    Bureaucrat jhon("jhon", 2);

    PresidentialPardonForm ppf("police"); //sign 25, exec 5

    //can sign
    jhon.signForm(ppf);
    //can execute
    jhon.executeForm(ppf);
  }
	catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  std::cout << std::endl;

	try
  {
    Bureaucrat jhon("jhon", 45);

    RobotomyRequestForm rrf("Jhon Weak"); //sign 72, exec 45

    //can sign
    jhon.signForm(rrf);
    //can execute
    jhon.executeForm(rrf);
  }
	catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  std::cout << std::endl;

	try
  {
    Bureaucrat jhon("jhon", 137);

    ShrubberyCreationForm scf("platane"); //sign 145, exec 137

    //can sign
    jhon.signForm(scf);
    //can execute
    jhon.executeForm(scf);
  }
	catch (std::exception & e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

}

