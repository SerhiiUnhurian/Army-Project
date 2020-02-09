#include "Necromancer.h"
#include "SpellCaster.h"
#include "../Units/Properties.h"
#include "../States/State.h"
#include "../States/MagicState.h"
#include "../Attacks/NecromancerAttack.h"
// #include "../States/NecromancerState.h"
#include "../Units/Exceptions.h"
#include "../Spell/Spell.h"

Necromancer::Necromancer(const std::string& name, UnitType unitType)
	: SpellCaster(name, new State(unitType, HP_NECROMANCER, DMG_NECROMANCER, true), new MagicState(MANA_NECROMANCER, true), 
		new NecromancerAttack(this))
{
}

Necromancer::~Necromancer() {
	auto it = m_observables.begin();

	while ( it != m_observables.end() ) {
		(*it)->unsubscribe(this);
		it++;
	}
}

void Necromancer::cast(SpellName spell, Unit* target) {
//    if ( target == this ) { return; }
//
//    SpellCaster::cast(spell, target);
//
//    if ( target->getUnitType() != BERSERKER )  {
//        attach(target);
//    }
    if ( !m_magicState ) { throw NotAllowedException(); }
    if ( target == this ) { return; }

    ensureIsAlive();

    Spell *concreteSpell = m_spellBook->getSpell(spell);

    if ( m_magicState->ensureHasMana(concreteSpell->getCost()) ) {
        concreteSpell->apply(target, m_magicState->getDmgCoeff(), m_magicState->getHealCoeff());
        m_magicState->reduceMana(concreteSpell->getCost());
        if ( target->getUnitType() != BERSERKER )  {
            attach(target);
        }
    } else {
        std::cout << "Not enough mana!" << std::endl;
    }
}

std::set<Unit*>& Necromancer::getObservables() {
	return m_observables;
}

void Necromancer::setState(State* state) {
	SpellCaster::setState(state);

	if ( !m_observables.empty() ) {
		auto it = m_observables.begin();

		while ( it != m_observables.end() ) {
			(*it)->unsubscribe(this);
			it++;
		}
		m_observables.clear();
	}
}

// void Necromancer::takeDamage(int dmg) {
// 	Unit::takeDamage(dmg);

// 	if ( !isAlive() && !m_observables.empty() ) {
// 		auto it = m_observables.begin();

// 		while ( it != m_observables.end() ) {
// 			(*it)->unsubscribe(this);
// 			it++;
// 		}
// 	}
// }

// void Necromancer::takeMagicDamage(int dmg) {
// 	Unit::takeMagicDamage(dmg);

// 	if ( !isAlive() && !m_observables.empty() ) {
// 		auto it = m_observables.begin();

// 		while ( it != m_observables.end() ) {
// 			(*it)->unsubscribe(this);
// 			it++;
// 		}
// 	}
// }


void Necromancer::attach(Unit* observable) {
	if ( getUnitType() != NECROMANCER ) { return; }

	m_observables.insert(observable);
	observable->subscribe(this);
}
void Necromancer::detach(Unit* observable) {
	if ( getUnitType() != NECROMANCER ) { return; }

    m_observables.erase(observable);
}
void Necromancer::update(int hp) {
	if ( getUnitType() != NECROMANCER ) { return; }

	addHitPoints(hp);
	detach(observable);
}


void Necromancer::printObservables() const {
	if ( !m_observables.empty() ) {
		std::cout << "Observables:\n";
		
		auto it = m_observables.begin();

		while ( it != m_observables.end() ) {
			std::cout << (*it)->getName() << std::endl;
			it++;
		}
	} else {
		std::cout << "Observables: empty\n";
	}
}