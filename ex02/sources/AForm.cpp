#include "../includes/AForm.hpp"

#include <iostream>

AForm::AForm(const std::string name,  const int requiredGradeToSign, const int requiredGradeToExecute)
:
  _name(name),
  _isSigned(false),
  _requiredGradeToSign(requiredGradeToSign),
  _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "AForm constructor called on : " << _name << std::endl;

	if (_requiredGradeToSign > 150 || _requiredGradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (_requiredGradeToSign < 1 || _requiredGradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& copy)
:
	_name(copy._name),
	_isSigned(copy._isSigned),
  _requiredGradeToSign(copy._requiredGradeToSign),
  _requiredGradeToExecute(copy._requiredGradeToExecute)
{
	std::cout << "AForm copy constructor called on : " << _name << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
  if (this == &other)
    return *this;
	_isSigned = other._isSigned;
  return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called on : " << _name << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm gradeTooHigh";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm gradeTooLow";
}

const char* AForm::notSignedAFormException::what() const throw()
{
	return "AForm is not signed";
}

const char* AForm::alreadySignedAFormException::what() const throw()
{
	return "AForm is already signed";
}

std::string AForm::getName() const
{
  return _name;
}

bool AForm::getIsSigned() const
{
  return _isSigned;
}

int AForm::getRequiredGradeToSign() const
{
  return _requiredGradeToSign;
}

int AForm::getRequiredGradeToExecute() const
{
  return _requiredGradeToExecute;
}

void  AForm::beSigned(const Bureaucrat& bureaucrat)
{
  int bureaucratGrade = bureaucrat.getGrade();

  if (_isSigned)
		throw AForm::alreadySignedAFormException();

  if (bureaucratGrade <= _requiredGradeToSign)
    _isSigned = true;
  else
		throw AForm::GradeTooLowException();
}

void        AForm::execute(Bureaucrat const & executor) const
{
  int bureaucratGrade = executor.getGrade();

  if (!_isSigned)
		throw AForm::notSignedAFormException();

  if (bureaucratGrade <= _requiredGradeToExecute)
    formAction();
  else
		throw AForm::GradeTooLowException();

}

std::ostream& operator<<(std::ostream& stream, const AForm& form)
{
	stream  << "form :" << form.getName() << "\n"
          << "isSigned :" << form.getIsSigned() << "\n"
          << "requiredGradeToSign :" << form.getRequiredGradeToSign() << "\n"
          << "requiredGradeToExecute :" << form.getRequiredGradeToExecute() << std::endl;
	return (stream);	
}
