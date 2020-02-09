#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <unordered_set>

class Necromancer;

class Observable {
public:
	virtual void subscribe(Necromancer* observer) = 0;
	virtual void unsubscribe(Necromancer* observer) = 0;
	virtual void notifySubscribers() = 0;
};

#endif // OBSERVABLE_H