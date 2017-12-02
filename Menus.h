#ifndef MENUS_H
#define MENUS_H
#include <string>

class Menus
{
public:
	int intQuery(std::string prompt, int lowerBound, int upperBound);
	Menus();
	~Menus();
};

#endif