#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	std::cout << "----- create ScavTrap a -----\n";
	ScavTrap a("Serena");
	print_status(a);

	std::cout << "\n----- actions -----\n";
	a.attack("target");
	a.takeDamage(30);
	a.beRepaired(10);
	a.guardGate();
	print_status(a);

	std::cout << "\n----- copy / assign -----\n";
	ScavTrap b(a);
	ScavTrap c;
	c = a;
	print_status(b);
	print_status(c);

	std::cout << "\n----- scope end (destruction order) -----\n";
	return 0;
}
