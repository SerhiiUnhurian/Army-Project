#ifndef WOLF_STATE_H
#define WOLF_STATE_H

#include "State.h"

class WolfState : public State {
public:
	WolfState(UnitType unitType, int hp, int dmg, bool isUndead);
	virtual ~WolfState();

	virtual void takeMagicDamage(int dmg) override;
};

#endif // WOLF_STATE_H