#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "../includes/AForm.hpp"

class PresidentialPardonForm : public AForm;
{
	private:
    std::string _target;

    void  action();

	public:
		PresidentialPardonForm(const std::string target);	
		PresidentialPardonForm(const PresidentialPardonForm& copy);	
    PresidentialPardonForm& operator=(const PresdentialPardonForm& other);
		~PresidentialPardonForm();
};

#endif
