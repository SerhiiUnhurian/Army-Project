#ifndef WEREWOLF_ABILITY_H
#define WEREWOLF_ABILITY_H

#include "Ability.h"

class WerewolfAbility final : public Ability {
private:
	void bite(Unit* enemy);
public:
	WerewolfAbility(Unit* owner);
	virtual~WerewolfAbility();

	virtual void useAbility() override;
	virtual void useAbility(Unit* enemy) override;

	void transform();
};

#endif // WEREWOLF_ABILITY_H