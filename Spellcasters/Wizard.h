#ifndef WIZARD_H
#define WIZARD_H

// #include "../Units/Properties.h"
#include "SpellCaster.h"
#include <iostream>


class Wizard final: public SpellCaster {
public:
	Wizard(const std::string name, UnitType unitType);
	virtual ~Wizard();
};

#endif // WIZARD_H