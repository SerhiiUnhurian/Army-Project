#include "../Units/Exceptions.h"
#include "Priest.h"
#include "SpellCaster.h"
#include "../Units/Properties.h"
#include "../States/State.h"
#include "../States/MagicState.h"
#include "../Attacks/PriestAttack.h"
#include "../Spell/SpellBook.h"
#include "../Spell/Spell.h"


Priest::Priest(const std::string& name, UnitType unitType)
	: SpellCaster(name, new State(unitType, HP_PRIEST, DMG_PRIEST, false), new MagicState(MANA_PRIEST, false), new PriestAttack(this))
{
}

Priest::~Priest() {}

void Priest::cast(SpellName spell, Unit* target) {
    if (!m_magicState) { throw NotAllowedException(); }
    if (target == this) { return; }

    ensureIsAlive();

    try {
        Spell *concreteSpell = getSpellBook()->getSpell(spell);

        if ( m_magicState->ensureHasMana(concreteSpell->getCost()) ) {
            if ( spell == FIREBALL && target->getState()->isUndead() ) {
                concreteSpell->apply(target, m_magicState->getDmgCoeff()*2, m_magicState->getHealCoeff());
            } else {
                concreteSpell->apply(target, m_magicState->getDmgCoeff(), m_magicState->getHealCoeff());
            }
            m_magicState->reduceMana(concreteSpell->getCost());
        } else {
            std::cout << "Not enough mana!" << std::endl;
        }
    } catch (std::out_of_range error) {
        std::cout << "No such spell in spell book!" << std::endl;
    }
}