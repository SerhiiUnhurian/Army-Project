#ifndef SPELL_BOOK_H
#define SPELL_BOOK_H

#include <map>
#include "../States/MagicState.h"
#include "../States/MagicState.h"
#include "../Units/Properties.h"

class Spell;

class SpellBook {
private:
	static SpellBook* s_spellBook;
	std::map<int, Spell*> m_book;

	SpellBook();

public:
	~SpellBook();

	static SpellBook* getSpellBook();

	Spell* getSpell(SpellName spell) const;

	friend std::ostream& operator<<(std::ostream& out, const SpellBook* spellBook); 
};

#endif // SPELL_BOOK_H