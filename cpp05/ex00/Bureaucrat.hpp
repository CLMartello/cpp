
#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class	Bureaucrat {
private:
	const std::string	_name;
	int			_grade; //from 1 to 150

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	const std::string getName() const;
	int getGrade() const; //const after is for not modifying the object
	void incrementGrade();
	void decrementGrade();

	class   GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what() const;
	};

	class   GradeTooLowException: public std::exception
	{	
	public:
	        virtual const char* what() const;
	};

};

#endif
