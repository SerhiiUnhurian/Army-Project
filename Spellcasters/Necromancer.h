#ifndef NECROMANCER_H
#define NECROMANCER_H

// #include "../Units/Properties.h"
#include "../Interface/Observer.h"
#include "SpellCaster.h"
#include <iostream>
#include <set>

class Necromancer final: public SpellCaster, public Observer {
private:
	std::set<Unit*> m_observables;

public:
	Necromancer(const std::string& name, UnitType unitType);
	virtual ~Necromancer();

	virtual void cast(SpellName spell, Unit* target) override;

	virtual void setState(State* state) override;

	std::set<Unit*>& getObservables();

	// virtual void takeDamage(int dmg) override;
	// virtual void takeMagicDamage(int dmg) override;

	virtual void attach(Unit* observable) override;
	virtual void detach(Unit* observable) override;
	virtual void update(int hp) override;

	void printObservables() const;
};

#endif // NECROMANCER_H