#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
:
  AForm("PresidentialPardonForm", 25, 5),
  _target(target)
{
  std::cout << "PresidentialPardonForm constructor called on :" << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
:
  AForm("PresidentialPardonForm", 25, 5),
  _target(copy._target)
{
  std::cout << "PresidentialPardonForm copy constructor called on :" << _target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
  if (this == &other)
    return *this;
  _target = other._target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "PresidentialPardonForm destructor called on :" << _target << std::endl;
}

void  PresidentialPardonForm::formAction() const
{
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
