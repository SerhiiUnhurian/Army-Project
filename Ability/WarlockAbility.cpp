#include "WarlockAbility.h"
#include "../Units/Exceptions.h"
#include "../Units/Properties.h"

WarlockAbility::WarlockAbility(Unit* owner) 
	: Ability(owner)
{
}

WarlockAbility::~WarlockAbility() {
	if ( m_demon ) { 
		delete m_demon; 
	}
}

void WarlockAbility::useAbility() {
	// summon()  Private func of WarlockAbility ???
	if ( !m_owner->isAlive() ) { return; }

 	if ( !m_demon ) {
 		std::string name = m_owner->getName() + "'s demon";
	 	m_demon = new Demon(name, DEMON, m_owner);
	}
}

void WarlockAbility::useAbility(Unit* enemy) {
	if ( !m_owner->isAlive() ) { return; }

 	if ( enemy == m_owner || enemy == m_demon ) { throw InvalidTargetException(); }
 	
 	if ( m_demon ) {
		m_demon->attack(enemy);
 	} else {
 	    std::cout << "You have no demon under control!" << std::endl;
 	}
}

Demon* WarlockAbility::getDemon() const {
	if (m_demon) {
		return m_demon;
	} else {
		throw NoDemonException();
	}
}