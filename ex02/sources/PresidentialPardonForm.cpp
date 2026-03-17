#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
:
  Form("PresidentialPardonForm", 25, 5),
  _target(target)
{
  std::cout << "PresidentialPardonForm constructor called on :" << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
:
  _target(copy._target)
{
  std::cout << "PresidentialPardonForm copy constructor called on :" << _target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const Form& other)
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

void  PresidentialPardonForm::formAction() const;
{
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" std::endl;
}
