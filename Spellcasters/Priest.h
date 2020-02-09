#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include <iostream>


class Priest final: public SpellCaster {
public:
	Priest(const std::string& name, UnitType unitType);
	virtual ~Priest();

    virtual void cast(SpellName spell, Unit* target);
};

#endif // PRIEST_H