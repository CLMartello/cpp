
#ifndef SHRUBBERYCREATIONFORM_HPP

#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

    void execute(const Bureaucrat &executor) const;

};

#endif