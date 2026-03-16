#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:
    const std::string _name;
    bool              _isSigned;
    const int         _requiredGradeToSign;
    const int         _requiredGradeToExecute;

		class GradeTooHighException : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};

	public:
		Form(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute);	
		Form(const Form & copy);	
    Form& operator=(const Form& other);
		~Form();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getRequiredGradeToSign() const;
    int         getRequiredGradeToExecute() const;

    bool        beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& s);

#endif
