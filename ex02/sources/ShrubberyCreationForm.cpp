#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream> 

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

ShrubberyCreationForm::cannotOpenFileException::cannotOpenFileException(std::string filename) throw()
{
  _errorMsg = "Cant open file " + filename;
}

ShrubberyCreationForm::cannotOpenFileException::~cannotOpenFileException () throw()
{
  std::cout << "cannotOpenFileException destructor called" << std::endl;
}

const char* ShrubberyCreationForm::cannotOpenFileException::what() const throw()
{
  return _errorMsg.c_str();
}

void  ShrubberyCreationForm::formAction() const
{
  std::string filename = _target + "_shrubbery";
  
  std::ofstream file(filename.c_str());
  if (!file.is_open())
    throw ShrubberyCreationForm::cannotOpenFileException(filename);

  file <<
  "          🌿🌿🌿            \n"
  "         /       \\         \n"
  "        /  🐒     \\        \n"
  "       /   |       \\       \n"
  "      🍃  /|\\      🍃      \n"
  "      |  / | \\      |      \n"
  "      | /  |  \\     |      \n"
  "    __|/   |   \\|___|      \n"
  "   /   \\   |   /    \\     \n"
  "  🌿    \\  |  /    🌿      \n"
  "         \\ | /             \n"
  "          \\|/              \n"
  "           |                \n"
  "           |                \n"
  "           |                \n"
  "        ___| ___            \n"
  "       /        \\          \n"
  "      /          \\         \n";
  file.close();
}
