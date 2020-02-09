#include <iostream>
// #include "Attack.h"
// #include "State.h"
#include "Units/Soldier.h"
#include "Units/Rogue.h"
#include "Units/Unit.h"
#include "Units/Vampire.h"
#include "Units/Werewolf.h"
#include "Spellcasters/Warlock.h"
#include "Spellcasters/Necromancer.h"
#include "Units/Demon.h" // без этой строки не выводит Демона

#include "Units/Properties.h"
#include "Units/Exceptions.h"
#include "Units/Berserker.h"
#include "Spellcasters/Wizard.h"
#include "Spellcasters/Healer.h"
#include "Spellcasters/Priest.h"


#include "States/MagicState.h"
#include "Spellcasters/SpellCaster.h"

int main() {
    Soldier* s1 = new Soldier("Soldier", SOLDIER);
//    Rogue* r1 = new Rogue("Rogue", ROGUE);
    Berserker* b1 = new Berserker("Berserker", BERSERKER);
    Vampire* v1 = new Vampire("Vampire", VAMPIRE);
//    Werewolf* w1 = new Werewolf("Werewolf", WEREWOLF);

    Wizard* wiz1 = new Wizard("Wizard", WIZARD);
//    Healer* h1 = new Healer("Healer", HEALER);
//    Priest* p1 = new Priest("Priest", PRIEST);
    Warlock* war1 = new Warlock("Warlock", WARLOCK);
    Necromancer* n1 = new Necromancer("Necromancer", NECROMANCER);

    // Testing Werewolf and Rogue
//    w1->attack(r1);
//    w1->useAbility(r1);
//    r1->useAbility(s1);
//    r1->attack(w1);
//    std::cout << w1 << std::endl;
//    std::cout << r1 << std::endl;

    // Testing Werewolf and Necromancer
//    w1->attack(n1);
//    w1->useAbility(n1);
//    n1->useAbility(s1);
//    std::cout << n1 << std::endl;

    // Testing Necromancer and Vampire
//    n1->attack(s1);
//    v1->useAbility(s1);

    // Testing Berserker
//    n1->cast(FIREBALL, b1);
//    b1->attack(n1);
//    n1->cast(FIREBALL, n1);
//    w1->useAbility(n1);
//    n1->cast(FIREBALL, b1);

    // Testing Priest
//    p1->attack(n1);
//    p1->attack(v1);
//    p1->cast(FIREBALL, n1);
//    p1->cast(FIREBALL, v1);
//    p1->cast(FLASH_HEAL, v1);

    // Testing Vampire and Werewolf
//    w1->useAbility(v1);
//    v1->useAbility(w1);

    // Testing Warlock
   // war1->useAbility();
   // war1->useAbility(wiz1);
   // wiz1->attack(war1->getDemon());
   // war1->cast(FIREBALL, war1->getDemon());
   // v1->useAbility(war1);
   // v1->useAbility(war1->getDemon());

    // Testing Priest
//    p1->cast(FIREBALL, n1);
//    p1->cast(FIREBALL, s1);
//    p1->attack(n1);
//    p1->attack(s1);
//
//    p1->cast(FLASH_HEAL, n1);
//    p1->cast(FLASH_HEAL, s1);

   //  Testing Wizaard
   // try {
   //     wiz1->cast(FIREBALL, s1);
   //     wiz1->cast(FIREBALL, s1);
   //     n1->cast(FIREBALL, s1);
   //     wiz1->cast(FIREBALL, v1);
   //     wiz1->cast(FIREBALL, s1);
   // }
   // catch (OutOfHpException* ex) {
   // }

	return 0;
}
