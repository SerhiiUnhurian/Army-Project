#ifndef Vimpire_ABILITY_H
#define Vimpire_ABILITY_H

#include "Ability.h"

class VampireAbility final : public Ability {
private:
	void bite(Unit* enemy);
public:
	VampireAbility(Unit* owner);
	virtual~VampireAbility();

    virtual void useAbility();
	virtual void useAbility(Unit* enemy) override;
};

#endif // Vimpire_ABILITY_H