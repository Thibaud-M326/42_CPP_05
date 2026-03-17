#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"

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

}


// std::cout <<
// "          🌿🌿🌿            \n"
// "         /       \\         \n"
// "        /  🐒     \\        \n"
// "       /   |       \\       \n"
// "      🍃  /|\\      🍃      \n"
// "      |  / | \\      |      \n"
// "      | /  |  \\     |      \n"
// "    __|/   |   \\|___|      \n"
// "   /   \\   |   /    \\     \n"
// "  🌿    \\  |  /    🌿      \n"
// "         \\ | /             \n"
// "          \\|/              \n"
// "           |                \n"
// "           |                \n"
// "           |                \n"
// "        ___| ___            \n"
// "       /        \\          \n"
// "      /          \\         \n" << std::endl;
