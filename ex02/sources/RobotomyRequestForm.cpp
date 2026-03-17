#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
:
  AForm("RobotomyRequestForm", 72, 45),
  _target(target)
{
  std::cout << "RobotomyRequestForm constructor called on :" << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
:
  AForm("RobotomyRequestForm", 72, 45),
  _target(copy._target)
{
  std::cout << "RobotomyRequestForm copy constructor called on :" << _target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
  if (this == &other)
    return *this;
  _target = other._target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << "RobotomyRequestForm destructor called on :" << _target << std::endl;
}

void  RobotomyRequestForm::formAction() const
{
  srand(time(0));

  int randomNum = rand() % 2;
  

  std::cout << "**drilling noise**" << std::endl;
  if (randomNum == 1)
    std::cout << _target << " has been robotomized" << std::endl;
  else 
    std::cout << _target << " robotomization failed" << std::endl;
}
