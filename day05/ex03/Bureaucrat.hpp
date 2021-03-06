#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:

	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & bureaucrat);
	Bureaucrat();
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incGrade();
	void		decGrade();
	bool		signForm(Form const & form) const;
	void		executeForm(Form const & form) const;
	Bureaucrat	&operator=(Bureaucrat const & bureaucrat);

	class GradeTooHighException : public std::exception
	{

	public:

		GradeTooHighException(GradeTooHighException & exc) throw();
		GradeTooHighException() throw();
		virtual ~GradeTooHighException() throw();

		GradeTooHighException	&operator=(GradeTooHighException const & exc);

		virtual const char* what() const throw();

	} hightException;

	class GradeTooLowException : public std::exception
	{

	public:

		GradeTooLowException(GradeTooLowException & exc) throw();
		GradeTooLowException() throw();
		virtual ~GradeTooLowException() throw();

		GradeTooLowException	&operator=(GradeTooLowException const & exc);

		virtual const char* what() const throw();
	
	} lowException;

private:
	const std::string	_name;
	int					_grade;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat);

#endif
