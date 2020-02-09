#include "MagicState.h"
#include "../Units/Exceptions.h"
#include "../Units/Properties.h"
#include <iostream>


MagicState::MagicState(int mana, bool isCombatant)
	: m_mana(mana), m_maxMana(mana)
{
	m_dmgCoeff = ( isCombatant ) ? 1.0 : 0.5;
	m_healCoeff = ( isCombatant ) ? 0.5 : 1.0;
}

MagicState::~MagicState() {}

int MagicState::getMana() const { return m_mana; }
int MagicState::getMaxMana() const { return m_maxMana; }
float MagicState::getDmgCoeff() const { return m_dmgCoeff; }
float MagicState::getHealCoeff() const { return m_healCoeff; }

void MagicState::increaseMana(int mana) {
    int newMana = m_mana + mana;

    m_mana = ( newMana < m_maxMana ) ? newMana : m_maxMana;
}

void MagicState::reduceMana(int mana) {
	if ( m_mana == 0 || m_mana < mana ) { 
		throw OutOfManaException(); 
	}
	m_mana -= mana;
}

 bool MagicState::ensureHasMana(int mana) const {
 	return m_mana >= mana;
 }

std::ostream& operator<<(std::ostream& out, const MagicState* magicState) {
	out << "Mana: "<< magicState->m_mana << "/" << magicState->m_maxMana << ", ";
	out << "DmgCoeff/HealCoeff: " << magicState->m_dmgCoeff << "/" << magicState->m_healCoeff;

	return out;
}


