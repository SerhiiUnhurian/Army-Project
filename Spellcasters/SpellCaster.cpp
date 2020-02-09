#include "SpellCaster.h"
#include "../Spell/SpellBook.h"
#include "../Spell/Spell.h"
#include "../States/State.h"
#include "../States/MagicState.h"
#include "../Units/Unit.h"
#include "../Units/Exceptions.h"


SpellCaster::SpellCaster(const std::string& name, State* state, MagicState* magicState, Attack* attack, Ability* ability)
	: Unit(name, state, attack, ability), m_magicState(magicState), m_spellBook(SpellBook::getSpellBook())
{
}

SpellCaster::~SpellCaster() {
	delete m_magicState;
	// delete m_spellBook; share pointer
}

const SpellBook* SpellCaster::getSpellBook() const {
	if ( !m_spellBook )	{ throw NotAllowedException(); } // Where to catch?
	return m_spellBook;
}

void SpellCaster::setState(State* state) {
	Unit::setState(state);

	delete m_magicState;
	delete m_spellBook; 

	m_magicState = nullptr;
	m_spellBook = nullptr;
}

void SpellCaster::cast(SpellName spell, Unit* target) {
    if ( !m_magicState ) { throw NotAllowedException(); }
    if ( target == this ) { return; }

    ensureIsAlive();

	try {
		Spell *concreteSpell = m_spellBook->getSpell(spell);

        if ( m_magicState->ensureHasMana(concreteSpell->getCost()) ) {
            concreteSpell->apply(target, m_magicState->getDmgCoeff(), m_magicState->getHealCoeff());
            m_magicState->reduceMana(concreteSpell->getCost());
        } else {
            std::cout << "Not enough mana!" << std::endl;
        }
    } catch(std::out_of_range error) {
        std::cout << "No such spell in spell book!" << std::endl;
        return;
    }
}

std::ostream& SpellCaster::print(std::ostream& out) const {
	Unit::print(out);
	if ( m_magicState ) {
		out << ", " << m_magicState;
	}
	return out;
}

void SpellCaster::addMana(int mana) {
    ensureIsAlive();

    m_magicState->increaseMana(mana);
}
