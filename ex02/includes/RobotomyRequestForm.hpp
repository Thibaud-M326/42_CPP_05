#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "../includes/AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
    std::string _target;

    virtual void  formAction() const;

	public:
		RobotomyRequestForm(const std::string target);	
		RobotomyRequestForm(const RobotomyRequestForm& copy);	
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
};

#endif
