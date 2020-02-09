#ifndef UNIT_H
#define UNIT_H

#include "../Attacks/Attack.h"
#include "../States/State.h"
#include "../Ability/Ability.h"
#include "../Interface/Observable.h"
#include "../Interface/Observer.h"
#include "Properties.h"
#include <iostream>
#include <set>

class Necromancer;

class Unit : public Observable {
protected:
	std::string m_name;
	State* m_state;
	Attack* m_attack;
	Ability* m_ability;
	std::set<Necromancer*> m_observers;
	
	Unit(const std::string& name, State* state, Attack* attack, Ability* ability=nullptr);
	virtual ~Unit();

public:
	const State* getState() const;
    const std::string& getName() const;
	int getHitPoints() const;
	int getMaxHitPoints() const;
	int getDamage() const;
	void ensureIsAlive() const;
	bool isAlive() const;
	UnitType getUnitType() const;

	virtual void setState(State* state);
	void setAttack(Attack* attack);
	void setAbility(Ability* ability);

	virtual void takeDamage(int dmg);
	virtual void takeMagicDamage(int dmg); // virtual?
	void addHitPoints(int hp);

	virtual void attack(Unit* enemy);
	virtual void counterAttack(Unit* enemy);

	void useAbility();
	void useAbility(Unit* enemy);

	static Unit* createUnit(const std::string& name, UnitType unitType);

	virtual std::ostream& print(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const Unit* unit);

	virtual void subscribe(Necromancer* observer) override;
	virtual void unsubscribe(Necromancer* observer) override;
	virtual void notifySubscribers() override;

	void printObservers() const;
};

#endif // UNIT_H