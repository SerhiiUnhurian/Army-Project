#include "State.h"
#include "../Units/Exceptions.h"
#include "../Units/Properties.h"
#include <iostream>

State::State(UnitType unitType, int hp, int dmg, bool isUndead) 
	: m_unitType(unitType), m_hitPoints(hp), m_maxHitPoints(hp),m_damage(dmg), m_isUndead(isUndead)
{
}

State::~State() {}

UnitType State::getUnitType() const {
	return m_unitType;
}

// const std::string State::getType() const {
// 	switch (m_unitType) {
// 		case SOLDIER : { return "Soldier"; }
// 		case ROGUE : { return "Rogue"; }
// 		case WIZARD : { return "Wizard"; }
// 		case HEALER : { return "Healer"; }
// 		case PRIEST : { return "Priest"; }
// 		case VAMPIRE : { return "Vampire"; }
// 		case BERSERKER : { return "Berserker"; }
// 		case WEREWOLF : { return "Werewolf"; }
// 	}
// }

int State::getHitPoints() const { return m_hitPoints; }
int State::getMaxHitPoints() const { return m_maxHitPoints; }
int State::getDamage() const { return m_damage; }
bool State::isUndead() const { return m_isUndead; }
void State::ensureIsAlive() const { 
	if( m_hitPoints == 0 ) { throw new OutOfHpException(); }
}

bool State::isAlive() const {
	return m_hitPoints > 0;
}

void State::setHitPoints(int newHP) { m_hitPoints = newHP; }

void State::addHitPoints(int hp) {
	ensureIsAlive();

	int newHp = m_hitPoints + hp;

	m_hitPoints = ( newHp < m_maxHitPoints ) ? newHp : m_maxHitPoints;
};

void State::reduceHitPoints(int dmg) {
	ensureIsAlive();

	int newHp = m_hitPoints - dmg;
	m_hitPoints = ( newHp > 0 ) ? newHp : 0;

	// if ( newHp > 0 ) {
	// 	m_hitPoints = newHp;
	// } else {
	// 	m_hitPoints = 0;
	// 	notifySubscribers();
	// }
};

void State::takeMagicDamage(int dmg) {
	reduceHitPoints(dmg);
}

std::ostream& operator<<(std::ostream& out, const State* state) {
	std::string unitType;

	switch ( state->getUnitType() ) {
		case SOLDIER : { unitType = "Soldier"; break; }
		case ROGUE : { unitType = "Rogue"; break; }
		case WIZARD : { unitType = "Wizard"; break; }
		case HEALER : { unitType = "Healer"; break; }
		case PRIEST : { unitType = "Priest"; break; }
		case VAMPIRE : { unitType = "Vampire"; break; }
		case BERSERKER : { unitType = "Berserker"; break; }
		case WEREWOLF : { unitType = "Werewolf"; break; }
		case WARLOCK : { unitType = "Warlock"; break; }
		case DEMON : { unitType = "Demon"; break; }
		case NECROMANCER : { unitType = "Necromancer"; break; }
	}
	out << "Type: " << unitType << ", ";
	out << "Hp: " << state->m_hitPoints << "/" << state->m_maxHitPoints << ", ";
	out << "Dmg: " << state->m_damage;

	return out;
}
