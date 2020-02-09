#include "SpellBook.h"
#include "Fireball.h"
#include "FlashHeal.h"
#include "../States/MagicState.h"
#include "../Units/Properties.h"
#include "SpellBook.h"
#include <map>

class Spell;

SpellBook::SpellBook() {

	m_book.insert(std::pair<SpellName, Spell*>(FIREBALL, new Fireball()));
	m_book.insert(std::pair<SpellName, Spell*>(FLASH_HEAL, new FlashHeal()));
}

SpellBook::~SpellBook() {
	m_book.clear();
}

SpellBook* SpellBook::getSpellBook() {
	if ( s_spellBook == nullptr ) {
		s_spellBook = new SpellBook();
	}
	return s_spellBook;
}

Spell* SpellBook::getSpell(SpellName spell) const {
	return m_book.at(spell);
}

std::ostream& operator<<(std::ostream& out, const SpellBook* spellBook) {
	auto it { spellBook->m_book.begin() };

	out << "--Spell Book--" << std::endl;

	while (it != spellBook->m_book.end())
	{
		out << it->second << std::endl;
		it++;
	}
	out << "--End of Spell Book--" << std::endl;

    return out;
}

SpellBook* SpellBook::s_spellBook = nullptr;
