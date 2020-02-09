#include "Warlock.h"
#include "SpellCaster.h"
#include "../Units/Properties.h"
#include "../States/State.h"
#include "../States/MagicState.h"
#include "../Ability/WarlockAbility.h"
#include "../Attacks/Attack.h"
#include "../Units/Exceptions.h"


Warlock::Warlock(const std::string& name, UnitType unitType)
	: SpellCaster(name, new State(unitType, HP_WARLOCK, DMG_WARLOCK, false), new MagicState(MANA_WARLOCK, true), 
		new Attack(this), new WarlockAbility(this))
{
}

Warlock::~Warlock() {}

Demon* Warlock::getDemon() const {
	WarlockAbility* warlockAbility = dynamic_cast<WarlockAbility*>(m_ability);

	if ( warlockAbility ) {
        return warlockAbility->getDemon();
    } else {
	    throw NotAllowedException();
	}
}
//
void Warlock::cast(SpellName spell, Unit *target) {
    try {
        Demon *demon = getDemon();

        if (target == demon) {
            throw InvalidTargetException();
        } else {
            SpellCaster::cast(spell, target);
        }
    } catch (NoDemonException &ex) {
        SpellCaster::cast(spell, target);
    }
    catch (NotAllowedException &ex) {
        return;
    }
}