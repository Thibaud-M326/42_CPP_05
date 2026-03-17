#ifndef INTERN_HPP
#define INTERN_HPP

#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

class Intern
{
  private:

    AForm* _formCreated;

    AForm* makePresidential(std::string target);
    AForm* makeRobotomy(std::string target);
    AForm* makeShrubbery(std::string target);

  public:
    Intern();
    Intern(const Intern& copy);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string formName, std::string target);
};

#endif
