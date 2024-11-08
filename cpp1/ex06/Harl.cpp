#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::error(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::warning(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void	Harl::complain( std::string level ) {
	void(Harl::*functions[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
	};

	std::string levels[4] = {
		"DEBUG","INFO","WARNING","ERROR"};
	
	int i;
	for ( i = 0; i < 4; i++)
		if (level == levels[i])
			break;

	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*functions[0])();
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*functions[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*functions[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*functions[3])();
			std::cout << std::endl;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}

//se puede usar std::unordered_map