
#ifndef PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	std::string getTarget() const;
    void execute(const Bureaucrat &executor) const;

};

#endif