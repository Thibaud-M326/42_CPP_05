#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include "../includes/AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int               _grade;

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
		Bureaucrat(const std::string name, const int grade);	
		Bureaucrat(const Bureaucrat & copy);	
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;

    void  incrementGrade();
    void  decrementGrade();

    void  signForm(Form& form);
    void  executeForm(Form const& form);
};

#endif
