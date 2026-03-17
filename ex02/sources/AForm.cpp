#include "../includes/AForm.hpp"

#include <iostream>

Form::Form(const std::string name,  const int requiredGradeToSign, const int requiredGradeToExecute)
:
  _name(name),
  _isSigned(false),
  _requiredGradeToSign(requiredGradeToSign),
  _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "Form constructor called on : " << _name << std::endl;

	if (_requiredGradeToSign > 150 || _requiredGradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (_requiredGradeToSign < 1 || _requiredGradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& copy)
:
	_name(copy._name),
	_isSigned(copy._isSigned),
  _requiredGradeToSign(copy._requiredGradeToSign),
  _requiredGradeToExecute(copy._requiredGradeToExecute)
{
	std::cout << "Form copy constructor called on : " << _name << std::endl;
}

Form& Form::operator=(const Form& other)
{
  if (this == &other)
    return *this;
	_isSigned = other._isSigned;
  return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called on : " << _name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form gradeTooHigh";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form gradeTooLow";
}

const char* Form::notSignedFormException::what() const throw()
{
	return "Form is not signed";
}

const char* Form::alreadySignedFormException::what() const throw()
{
	return "Form is already signed";
}

std::string Form::getName() const
{
  return _name;
}

bool Form::getIsSigned() const
{
  return _isSigned;
}

int Form::getRequiredGradeToSign() const
{
  return _requiredGradeToSign;
}

int Form::getRequiredGradeToExecute() const
{
  return _requiredGradeToExecute;
}

void  Form::beSigned(const Bureaucrat& bureaucrat)
{
  int bureaucratGrade = bureaucrat.getGrade();

  if (_isSigned)
		throw Form::alreadySignedFormException();

  if (bureaucratGrade <= _requiredGradeToSign)
    _isSigned = true;
  else
		throw Form::GradeTooLowException();
}

void        Form::execute(Bureaucrat const & executor) const
{
  int bureaucratGrade = bureaucrat.getGrade();

  if (!_isSigned)
		throw Form::notSignedFormException();

  if (bureaucratGrade <= _requiredGradeToExecute)
    formAction();
  else
		throw Form::GradeTooLowException();

}

std::ostream& operator<<(std::ostream& stream, const Form& form)
{
	stream  << "form :" << form.getName() << "\n"
          << "isSigned :" << form.getIsSigned() << "\n"
          << "requiredGradeToSign :" << form.getRequiredGradeToSign() << "\n"
          << "requiredGradeToExecute :" << form.getRequiredGradeToExecute() << std::endl;
	return (stream);	
}
