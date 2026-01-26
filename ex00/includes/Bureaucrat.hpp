#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

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
		~Bureaucrat();
};

#endif
