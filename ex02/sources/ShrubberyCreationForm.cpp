#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
:
  AForm("ShrubberyCreationForm", 145, 137),
  _target(target)
{
  std::cout << "ShrubberyCreationForm constructor called on :" << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
:
  AForm("ShrubberyCreationForm", 145, 137),
  _target(copy._target)
{
  std::cout << "ShrubberyCreationForm copy constructor called on :" << _target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
  if (this == &other)
    return *this;
  _target = other._target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "ShrubberyCreationForm destructor called on :" << _target << std::endl;
}

void  ShrubberyCreationForm::formAction() const
{
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
