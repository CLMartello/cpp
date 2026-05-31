
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;

	//Try ShrubberyCreationForm creation
	try
	{
		AForm* scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Lavender");
		delete scf;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//Try RobotomyRequestForm creation
	try
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	//Try PresidentialPardonForm creation
	try
	{
		AForm* ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Cassender");
		delete ppf;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//Try unkwown creation
	try
	{
		AForm* ukw;
		ukw = someRandomIntern.makeForm("anything not valid", "Bartender");
		delete ukw;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
