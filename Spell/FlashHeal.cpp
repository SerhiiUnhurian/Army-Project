#include "FlashHeal.h"
#include "Spell.h"
#include "../Units/Unit.h"
#include "../Units/Properties.h"


FlashHeal::FlashHeal() : Spell(MANA_FLASH_HEAL, POINTS_FLASH_HEAL) {}
FlashHeal::~FlashHeal() {}

void FlashHeal::apply(Unit* target, float dmgCoeff, float healCoeff) {
	target->addHitPoints(m_points*healCoeff);
}

std::ostream& FlashHeal::print(std::ostream& out) const {
	out << "[Flash Heal] Points/ManaCost: " << m_points << "/" << m_cost;

	return out;  
}