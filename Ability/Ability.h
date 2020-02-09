#ifndef ABILITY_H
#define ABILITY_H

class Unit;

class Ability {
protected:
	Unit* m_owner;

public:
	Ability(Unit* owner);
	virtual~Ability();

	virtual void useAbility() = 0;
	virtual void useAbility(Unit* enemy = nullptr) = 0;
};

#endif // ABILITY_H