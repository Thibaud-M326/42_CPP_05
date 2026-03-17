#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat jhon("jhon", 2);

	   PresidentialPardonForm ppf("police");

	   jhon.signForm(ppf);
	   jhon.signForm(ppf);
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
