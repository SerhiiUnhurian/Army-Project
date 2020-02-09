#ifndef WARLOCK_H
#define WARLOCK_H

// #include "../Units/Properties.h"
#include "SpellCaster.h"
#include <iostream>

class Demon;

class Warlock final: public SpellCaster {
public:
	Warlock(const std::string& name, UnitType unitType);
	virtual ~Warlock();

	Demon* getDemon() const;

    virtual void cast(SpellName spell, Unit* target) override;
};

#endif // WARLOCK_H