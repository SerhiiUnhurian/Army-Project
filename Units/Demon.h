#ifndef DEMON_H
#define DEMON_H

#include "Unit.h"
#include <iostream>

class Demon : public Unit {
public:
	Unit* m_master;

	Demon(const std::string name, UnitType unitType, Unit* master);
	virtual ~Demon();	
};

#endif // DEMON_H