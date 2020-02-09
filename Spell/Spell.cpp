#include "Spell.h"
#include <iostream>

Spell::Spell(int cost, int points) 
	: m_cost(cost), m_points(points)
{
}

Spell::~Spell() {}

int Spell::getCost() const { return m_cost; }
int Spell::getPoints() const { return m_points; }

std::ostream& operator<<(std::ostream& out, const Spell* spell) {
	return spell->print(out);
}