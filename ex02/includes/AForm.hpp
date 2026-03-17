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

    virtual void  formAction() const = 0;

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

		class notSignedFormException : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};

		class alreadySignedFormException : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};

	public:
		Form(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute);	
		Form(const Form & copy);	
    Form& operator=(const Form& other);
		virtual ~Form();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getRequiredGradeToSign() const;
    int         getRequiredGradeToExecute() const;

    void        beSigned(const Bureaucrat& bureaucrat);
    void        execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const Form& s);

#endif
