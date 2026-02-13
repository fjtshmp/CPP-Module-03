#include "ClapTrap.hpp"
#include <iostream>

static void print_status(const ClapTrap &c)
{
	std::cout << "[STATUS] " << c.getName()
	          << " HP=" << c.getHitPoints()
	          << " EP=" << c.getEnergyPoints()
	          << " AD=" << c.getAttackDamage()
	          << "\n";
}

int main(void)
{
	ClapTrap a("A",10,10,0);
	ClapTrap b("B",10,10,0);

	a.setAttackDamage(3);

	print_status(a);
	print_status(b);

	std::cout << "\n-- basic actions --\n";
	a.attack("target_dummy");
	a.beRepaired(5);
	a.takeDamage(4);
	print_status(a);

	std::cout << "\n-- drain energy --\n";
	for (int i = 0; i < 12; ++i)
		a.attack("wall");
	print_status(a);

	std::cout << "\n-- hp to zero then try actions --\n";
	a.takeDamage(100);
	a.attack("someone");
	a.beRepaired(10);
	print_status(a);

	std::cout << "\n-- copy tests --\n";
	ClapTrap c = b;
	ClapTrap d("D",10,10,0);
	d = a;
	print_status(c);
	print_status(d);

	return 0;
}
