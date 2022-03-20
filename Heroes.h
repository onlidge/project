#include "Equipment.h"
#include <sstream>

static int level_borders[15]{200, 500, 700, 1100, 1700, 2500, 3700, 5100, 6900, 9000, 11200, 14000, 17000, 21000, 25000};

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

class Hero{
public:
    std::string name = "";
    int Intelligence = 0;
    int Spellpower = 0;
    int Strength = 0;
    int Agility = 0;
    int health = 0;
    int mana = 0;
    int phys_damage = 0;
    int spell_damage = 0;
    int money = 0;
    int exp = 0;
    int level = 0;
    bool level_cap = false;
    bool alive = true;
    Equipment Helm;
    Equipment Armor;
    Equipment Boots;
    Equipment Weapon;
    Equipment Talisman;
    Hero();
    Hero(const std::string in_name, const int stat_1, const int stat_2, const int stat_3, const int stat_4){
        name = in_name;
        health = stat_1;
        mana = stat_2;
        phys_damage = stat_3;
        spell_damage = stat_4;
    }
    std::string hero_info(){
        std::string out = "";
        out += name + "\n";
        out += "Stats: Intelligence " + toString(Intelligence) + " Spellpower " + toString(Spellpower) + " Strenght " + toString(Strength) + " Agility " + toString(Agility)  + "\n";
        out += "Level: " + toString(level) + "/" + "15" + "\n" + "Experience: " + toString(exp) + "/" + toString(level_borders[level])+ "\n";
        out += "Helm: " + Helm.info() + "\n";
        out += "Armor: " + Armor.info() + "\n";
        out += "Boots: " + Boots.info() + "\n";
        out += "Weapon: " + Weapon.info() + "\n";
        out += "Talisman: " + Talisman.info() + "\n";
        out += "Money: " + toString(money) + "\n";
        return out;
    }
    void change(int x){
        Agility += x;
        Strength += x;
        Spellpower += x;
        Intelligence += x;
    }
    std::string base_stats(){
        std::string out = "";
        out += "Health: " + toString(health) + "\n";
        out += "Physical Damage: " + toString(phys_damage) + "\n";
        out += "Spell Damage: " + toString(spell_damage) + "\n";
        out += "Mana: " + toString(mana) + "\n";
        return out;
    }
};

int hlth(Hero *hero){
    int s = hero->health;
    s += s * hero->Strength / 5;
    if(hero->Armor.tier > 0){
        s += hero->Armor.tier * hero->health / 5;
    }
    if(hero->Helm.rarity > 0){
        s += hero->Helm.tier * hero->health / 10;
    }
    if(hero->Helm.rarity > 1){
        s += hero->Helm.tier * hero->health / 10;
    }
    if(hero->Boots.rarity > 1){
        s += hero->Boots.tier * hero->health / 10;
    }
    if(hero->Boots.rarity > 0){
        s += hero->Boots.tier * hero->health / 10;
    }
    return s;
}

int mn(Hero *hero){
    int s = hero->mana;
    s += s * hero->Spellpower / 5;
    if(hero->Helm.tier > 0){
        s += hero->Helm.tier * hero->mana / 10;
    }
    return s;
}

int physdmg(Hero *hero){
    int s = hero->phys_damage;
    s += s * hero->Strength / 5;
    if(hero->Weapon.type == 4){
        s += hero->Weapon.tier * 2 * hero->phys_damage / 5;
    }
    if(hero->Talisman.type == 6){
        s += hero->Talisman.tier * hero->phys_damage / 10;
    }
    return s;
}

int spldmg(Hero *hero){
    int s = hero->spell_damage;
    s += s * hero->Spellpower / 5;
    if(hero->Weapon.type == 5){
        s += hero->Weapon.tier * hero->spell_damage / 5;
    }
    if(hero->Talisman.type == 7){
        s += hero->Talisman.tier * hero->spell_damage / 10;
    }
    return s;
}

int evd(Hero *hero){
    int s = 0;
    s += hero->Agility * 15 + hero->Intelligence * 5;
    if(hero->Armor.rarity > 1){
        s += hero->Armor.tier * 20;
    }
    if(hero->Talisman.rarity > 0){
        s += hero->Talisman.tier * 10;
    }
    if(hero->Boots.tier > 0){
        s += hero->Boots.tier * 10;
    }
    return s;
}

int atk(Hero *hero){
    int s = 0;
    s += hero->Agility * 5 + hero->Intelligence * 15;
    if(hero->Weapon.rarity > 1){
        s += hero->Weapon.tier * 20;
    }
    if(hero->Talisman.rarity > 0){
        s += hero->Talisman.tier * 10;
    }
    if(hero->Boots.tier > 0){
        s += hero->Boots.tier * 10;
    }
    return s;
}

int hlthrgn(Hero *hero){
    int s = 5;
    s += hero->Agility * 4;
    if(hero->Helm.rarity > 0){
        s += hero->Helm.tier * 4;
    }
    if(hero->Armor.rarity > 0){
        s += hero->Armor.tier * 8;
    }
    if(hero->Talisman.type == 6 and hero->Talisman.rarity > 1){
        s += hero->Talisman.tier * 4;
    }
    return s;
}

int mnrgn(Hero *hero){
    int s = 5;
    s += hero->Intelligence * 4;
    if(hero->Helm.rarity > 0){
        s += hero->Helm.tier * 4;
    }
    if(hero->Weapon.rarity > 0){
        s += hero->Weapon.tier * 8;
    }
    if(hero->Talisman.type == 7 and hero->Talisman.rarity > 1){
        s += hero->Talisman.tier * 4;
    }
    return s;
}