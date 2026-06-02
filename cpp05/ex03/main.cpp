
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern intern;

	//Try ShrubberyCreationForm creation
	try
	{
		AForm* scf;
		scf = intern.makeForm("shrubbery creation", "Lavender");
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
		rrf = intern.makeForm("robotomy request", "Bender");
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
		ppf = intern.makeForm("presidential pardon", "Cassender");
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
		ukw = intern.makeForm("anything not valid", "Bartender");
		delete ukw;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
