#ifndef ATTACK_H
#define ATTACK_H

class Unit;

class Attack {
protected:
	Unit* m_owner;

public:
	Attack(Unit* owner);
	virtual ~Attack();

	virtual void attack(Unit* enemy);
	virtual void counterAttack(Unit* enemy);
};

#endif // ATTACK_H