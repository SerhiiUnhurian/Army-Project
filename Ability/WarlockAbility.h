#ifndef WARLOCK_ABILITY_H
#define WARLOCK_ABILITY_H

#include "Ability.h"
#include "../Units/Demon.h"
#include "../Units/Soldier.h"

class WarlockAbility final : public Ability {
private:
	Demon* m_demon = nullptr;
public:
	WarlockAbility(Unit* owner);
	virtual~WarlockAbility();

	virtual void useAbility() override;
	virtual void useAbility(Unit* enemy) override;

	Demon* getDemon() const;
};

#endif // WARLOCK_ABILITY_H