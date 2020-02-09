#ifndef SPELL_CASTER_h
#define SPELL_CASTER_h

#include "../States/MagicState.h"
#include "../Spell/SpellBook.h"
#include "../Units/Unit.h"
#include "../States/State.h"
#include "../Attacks/Attack.h"


class SpellCaster : public Unit {
protected:
	MagicState* m_magicState;
	SpellBook* m_spellBook;

	SpellCaster(const std::string& name, State* state, MagicState* magicState, Attack* attack, Ability* ability=nullptr);
	virtual ~SpellCaster();

public:
    SpellCaster(const std::string &name, State *state, Attack *attack, Ability *ability, MagicState *mMagicState);

    const SpellBook* getSpellBook() const;

	virtual void setState(State* state) override;

	virtual void cast(SpellName spell, Unit* target);

	void addMana(int mana);

	virtual std::ostream& print(std::ostream& out) const override;
};

#endif // SPELL_CASTER_h