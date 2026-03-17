#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class AForm 
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

		class notSignedAFormException : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};

		class alreadySignedAFormException : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};

	public:
		AForm(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute);	
		AForm(const AForm & copy);	
    AForm& operator=(const AForm& other);
		virtual ~AForm();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getRequiredGradeToSign() const;
    int         getRequiredGradeToExecute() const;

    void        beSigned(const Bureaucrat& bureaucrat);
    void        execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& s);

#endif
