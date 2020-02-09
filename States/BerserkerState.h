#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include "State.h"

class BerserkerState : public State {
public:
	BerserkerState(UnitType unitType, int hp, int dmg, bool isUndead);
	virtual ~BerserkerState();

	virtual void takeMagicDamage(int dmg) override;
};

#endif // BERSERKER_STATE_H