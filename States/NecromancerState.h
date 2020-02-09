#ifndef NECROMANCER_STATE_H
#define NECROMANCER_STATE_H

#include "State.h"

class NecromancerState : public State {
private:
	std::unordered_set<Unit*> m_observables;

public:
	NecromancerState(UnitType unitType, int hp, int dmg, bool isUndead);
	virtual ~NecromancerState();

	// virtual void reduceHitPoints(int hp) override;
	// virtual void takeMagicDamage(int dmg) override;
};

#endif // NECROMANCER_STATE_H