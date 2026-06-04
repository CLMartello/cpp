
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main()
{
	Bureaucrat nino("Nino", 1);
	Bureaucrat morfeu("Morfeu", 150);

	ShrubberyCreationForm scf("Shrub");
	RobotomyRequestForm rrf("Robot");
	PresidentialPardonForm ppf("Presid");

	//Try signing forms - ShrubberyCreationForm
	nino.signForm(scf);
	morfeu.signForm(scf);
	std::cout << std::endl;

	//Try execute form - ShrubberyCreationForm
	nino.executeForm(scf);
	morfeu.executeForm(scf);
	std::cout << std::endl;

	//Try signing forms - RobotomyRequestForm
	nino.signForm(rrf);
	std::cout << std::endl;

	//Try execute form - RobotomyRequestForm
	nino.executeForm(rrf);
	morfeu.executeForm(rrf);
	std::cout << std::endl;

	//Try signing forms - PresidentialPardonForm
	nino.signForm(ppf);
	morfeu.signForm(ppf);
	std::cout << std::endl;

	//Try execute form - PresidentialPardonForm
	nino.executeForm(ppf);
	morfeu.executeForm(ppf);

	return (0);
}
