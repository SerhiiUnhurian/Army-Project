#include "Fireball.h"
#include "Spell.h"
#include "../Units/Unit.h"
#include "../Units/Properties.h"

Fireball::Fireball() : Spell(MANA_FIREBALL, POINTS_FIREBALL) 
{
}
Fireball::~Fireball() {}

void Fireball::apply(Unit* target, float dmgCoeff, float healCoeff) {
    target->takeMagicDamage(m_points*dmgCoeff);
}

std::ostream& Fireball::print(std::ostream& out) const {
	out << "[Fireball] Points/ManaCost: " << m_points << "/" << m_cost;

	return out;  
}