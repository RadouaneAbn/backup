#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define BIG_FELLO "Zaphod Beeblebrox"

class PresidentialPardonForm : public AForm
{
private:
  std::string _target;

public:
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm(void);
  PresidentialPardonForm(PresidentialPardonForm &old_obj);
  PresidentialPardonForm &operator=(PresidentialPardonForm &old_obj);

  std::string getTarget(void) const;
  void executingForm(Bureaucrat const &executor) const;
};

#endif