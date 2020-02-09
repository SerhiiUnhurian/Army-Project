#include "Unit.h"
#include "Soldier.h"
#include "Rogue.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Berserker.h"
#include "Demon.h"
#include "Properties.h"

#include "../Spellcasters/Wizard.h"
#include "../Spellcasters/Priest.h"
#include "../Spellcasters/Healer.h"
#include "../Spellcasters/Warlock.h"
#include "../Spellcasters/Necromancer.h"
#include <iostream>
#include <cassert>

Unit::Unit(const std::string& name, State* state, Attack* attack, Ability* ability) 
	: m_name(name), m_state(state), m_attack(attack), m_ability(ability)
{
}

Unit::~Unit() {
	delete m_state;
	delete m_attack;
	delete m_ability;

    auto it = m_observers.begin();

    while ( it != m_observers.end() ) {
        (*it)->detach(this);
        it++;
    }
}

// const std::string Unit::getType() const {
// 	switch (m_type) {
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

const State* Unit::getState() const { 
	return m_state; 
}

const std::string& Unit::getName() const {
	return m_name;
}

int Unit::getHitPoints() const {
	return m_state->getHitPoints();
}

int Unit::getMaxHitPoints() const {
	return m_state->getMaxHitPoints();
}

int Unit::getDamage() const {
	return m_state->getDamage();
}

void Unit::ensureIsAlive() const {
	m_state->ensureIsAlive();
}

bool Unit::isAlive() const {
    return m_state->isAlive();
};

UnitType Unit::getUnitType() const {
	return m_state->getUnitType();
}

void Unit::setState(State* state) {
	int newHP = m_state->getHitPoints() * state->getMaxHitPoints() / m_state->getMaxHitPoints();

	delete m_state;

	m_state = state;
	m_state->setHitPoints(newHP);
}

void Unit::setAttack(Attack* attack) {
	delete m_attack;
	m_attack = attack;
}

void Unit::setAbility(Ability* ability) {
	delete m_ability;
	m_ability = ability;
}


void Unit::takeDamage(int dmg) { 
	m_state->reduceHitPoints(dmg);

	if ( !isAlive() ) {
		notifySubscribers();

		if ( getUnitType() == NECROMANCER ) {
			Necromancer* nec = dynamic_cast<Necromancer*>(this);

			auto it = nec->getObservables().begin();

			while ( it != nec->getObservables().end() ) {
				(*it)->unsubscribe(nec);
				it++;
			}
			nec->getObservables().clear();
		}
	}
}

void Unit::takeMagicDamage(int dmg) {
	m_state->takeMagicDamage(dmg);

	if ( !isAlive() ) {
		notifySubscribers();

		if ( getUnitType() == NECROMANCER ) {
			Necromancer* nec = dynamic_cast<Necromancer*>(this);

			auto it = nec->getObservables().begin();

			while ( it != nec->getObservables().end() ) {
				(*it)->unsubscribe(nec);
				it++;
			}
			nec->getObservables().clear();
		}
	}
}

void Unit::addHitPoints(int hp) {
	m_state->addHitPoints(hp);
}

void Unit::attack(Unit* enemy) {
	m_attack->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
	m_attack->counterAttack(enemy);
}

void Unit::useAbility() {
	if ( m_ability != nullptr )
		m_ability->useAbility();

	// реализовать try-catch
}

void Unit::useAbility(Unit* enemy) {
	if ( m_ability != nullptr )
		m_ability->useAbility(enemy);

	// реализовать try-catch
}

std::ostream& Unit::print(std::ostream& out) const {
	out << "Name: " << m_name << ", ";
	out << m_state;

	return out;
}

Unit* Unit::createUnit(const std::string& name, UnitType unitType) {
	Unit* concreteUnit = nullptr;

	switch ( unitType ) {
		case SOLDIER :
			concreteUnit = new Soldier(name, unitType);
			break;
		case ROGUE :
			concreteUnit = new Rogue(name, unitType);
			break;
		case VAMPIRE :
			concreteUnit = new Vampire(name, unitType);
			break;
		case WEREWOLF :
			concreteUnit = new Werewolf(name, unitType);
			break;
		case BERSERKER :
			concreteUnit = new Berserker(name, unitType);
			break;
		case WIZARD :
			concreteUnit = new Wizard(name, unitType);
			break;
		case HEALER :
			concreteUnit = new Healer(name, unitType);
			break;
		case PRIEST :
			concreteUnit = new Priest(name, unitType);
			break;
		case WARLOCK :
			concreteUnit = new Warlock(name, unitType);
			break;
		case NECROMANCER :
			concreteUnit = new Necromancer(name, unitType);
			break;
		// case DEMON :
		// 	concreteUnit = new Demon(name, unitType);
		// 	break;
		default:
			std::cout << "You can't create such type of unit\n";
			assert(false);
	}

	return concreteUnit;
}

std::ostream& operator<<(std::ostream& out, const Unit* unit) {
	return unit->print(out);
}


void Unit::subscribe(Necromancer* observer) {
	m_observers.insert(observer);
}
void Unit::unsubscribe(Necromancer* observer) {
	m_observers.erase(observer);
}
void Unit::notifySubscribers() {
	if (!m_observers.empty()) {
		int hp = getMaxHitPoints() * 0.2;

		auto it = m_observers.begin();

		while (it != m_observers.end()) {
			(*it)->update(hp);
			it++;
		}
		m_observers.clear();
	}
}


void Unit::printObservers() const {
	if ( !m_observers.empty() ) {
		std::cout << "Observers:\n";

		auto it = m_observers.begin();

		while ( it != m_observers.end() ) {
			std::cout << (*it)->getName() << std::endl;
			it++;
		}
	} else {
		std::cout << "Observers: empty\n";
	}
}