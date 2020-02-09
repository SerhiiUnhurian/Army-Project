#ifndef OBSERVER_H
#define OBSERVER_H

#include <unordered_set>

class Unit;

class Observer {
public:
	virtual void attach(Unit* observable) = 0;
	virtual void detach(Unit* observable) = 0;
	virtual void update(int hp) = 0;
};

#endif // OBSERVER_H