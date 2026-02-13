#include "FragTrap.hpp"
#include <iostream>

int main()
{
std::cout << "----- create a FragTrap -----" << std::endl;
	{
		FragTrap a("FT");
		a.attack("target");
		a.highFivesGuys();
		a.takeDamage(10);
		a.beRepaired(5);
	}
std::cout << "----- scope ended -----" << std::endl;

std::cout << "\n----- copy tests -----" << std::endl;
	{
		FragTrap b("B");
		FragTrap c(b);
		FragTrap d;
		d = b;
		b.highFivesGuys();
		c.highFivesGuys();
		d.highFivesGuys();
	}
std::cout << "----- end -----" << std::endl;

return 0;
}
