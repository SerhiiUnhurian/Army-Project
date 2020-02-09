#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include <iostream>


class Healer final: public SpellCaster {
public:
	Healer(const std::string name, UnitType unitType);
	virtual ~Healer();
};

#endif // HEALER_H