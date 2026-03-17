#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "../includes/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
    std::string _target;

    virtual void  formAction() const;

	public:
		ShrubberyCreationForm(const std::string target);	
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);	
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};

#endif
