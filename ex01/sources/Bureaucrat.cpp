#include "../includes/Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, const int grade)
:
	_name(name)
{
	std::cout << "Bureaucrat constructor called on : " << _name << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & copy)
:
	_name(copy._name),
	_grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called on : " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
  if (this == &other)
    return *this;
  _grade = other._grade;
  return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called on : " << _name << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat gradeTooHigh";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat gradeTooLow";
}

std::string Bureaucrat::getName() const
{
  return _name;
}

int         Bureaucrat::getGrade() const
{
  return _grade;
}

void  Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
  _grade -= 1;
}

void  Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
  _grade += 1;
}

void  Bureaucrat::signForm(Form& form)
{
  try 
  {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  }
  catch (std::exception & e)
  {
    std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
  }
}

