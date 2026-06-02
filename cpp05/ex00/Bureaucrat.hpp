
#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class	Bureaucrat {
private:
	const std::string	_name;
	int					_grade; //from 1 to 150

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const; //const after is for not modifying the object
	void incrementGrade();
	void decrementGrade();

	class   GradeTooHighException: public std::exception
	//this class inherit from std::exception
	//so it becomes a type of exception
	{
	public:
		//this is a function:
		//outputs a const char* (string)
		//function what() -> standard function used by all exceptions, it will return error message
		//const after because this function what() does not modify the object
		//this function never throws, because this class have the error message
		virtual const char* what() const throw();
		//what needs to be public, to be called by the functions
		//virtual because this function can be overriden and supports polymorphism
	};

	class   GradeTooLowException: public std::exception
	{	
	public:
	    virtual const char* what() const throw();
	};

};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &object);

#endif
