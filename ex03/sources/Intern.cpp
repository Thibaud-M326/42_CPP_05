#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"

#include <iostream>

Intern::Intern()
:
  _formCreated(NULL)
{
  std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
:
  _formCreated(copy._formCreated)
{
  std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
  if (this == &other)
    return *this;
  _formCreated = other._formCreated;
  return *this;
}

Intern::~Intern()
{
  std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makePresidential(std::string target)
{
  _formCreated = new PresidentialPardonForm(target);
  return _formCreated;
}

AForm* Intern::makeRobotomy(std::string target)
{
  _formCreated = new RobotomyRequestForm(target);
  return _formCreated;
}

AForm* Intern::makeShrubbery(std::string target)
{
  _formCreated = new ShrubberyCreationForm(target);
  return _formCreated;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* (Intern::*formFactory[])( std::string ) = {
		&Intern::makePresidential,
		&Intern::makeRobotomy,
		&Intern::makeShrubbery
	};

	for (size_t i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			return (this->*formFactory[i])(target);
		}
	}
  throw std::runtime_error("form does not exist");
}

