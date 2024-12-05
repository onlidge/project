#include "Equipment.h"
#include <sstream>

static int maxlevel = 15;
static int level_borders[15]{100, 300, 600, 1000, 1500, 2100, 2800, 3600, 4500, 5500, 6600, 7800, 9100, 10500, 12000};

std::string toString(int val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

static std::string mage_name = "Mana drain";
static std::string mage_description = "Restores 20 mana after killing a monster";
static std::string warrior_name = "Endless potential";
static std::string warrior_description = "Increases physical damage by 20% of the initial value before each successful attack";
static std::string berserk_name = "Unstoppable";
static std::string berserk_description = "If the result of the attack is \"Missed\", deals half damage";
static std::string warlock_name = "Lifesteal";
static std::string warlock_description = "Restores 20% health after killing a monster";
static std::string rogue_name = "Mastery";
static std::string rogue_description = "Gain 5% evasion and attack rate after killing a monster";
static std::string archer_name = "Education";
static std::string archer_description = "Good basic stats";

class Hero{
    int mn(){
        int s = mana;
        s += s * stats[1] / 5;
        if(Loot[0].tier > 0){
            s += Loot[0].tier * mana / 10;
        }
        return s;
    }
    int spldmg(){
        int s = spell_damage;
        s += s * stats[1] / 5;
        if(Loot[3].type == 5){
            s += Loot[3].tier * spell_damage / 5;
        }
        if(Loot[4].type == 7){
            s += Loot[4].tier * spell_damage / 10;
        }
        return s;
    }
    int evd(){
        int s = 0;
        s += stats[3] * 15 + stats[0] * 5;
        if(Loot[1].rarity > 1){
            s += Loot[1].tier * 20;
        }
        if(Loot[4].rarity > 0){
            s += Loot[4].tier * 10;
        }
        if(Loot[2].rarity > 0){
            s += Loot[2].tier * 10;
        }
        return s;
    }
    int atk(){
        int s = 0;
        s += stats[3] * 5 + stats[0] * 15;
        if(Loot[3].rarity > 1){
            s += Loot[3].tier * 20;
        }
        if(Loot[4].rarity > 0){
            s += Loot[4].tier * 10;
        }
        if(Loot[2].rarity > 0){
            s += Loot[2].tier * 10;
        }
        return s;
    }
    int hlthrgn(){
        int s = 5;
        s += stats[3] * 4;
        if(Loot[0].rarity > 0){
            s += Loot[0].tier * 4;
        }
        if(Loot[1].rarity > 0){
            s += Loot[1].tier * 8;
        }
        if(Loot[4].type == 6 and Loot[4].rarity > 1){
            s += Loot[4].tier * 4;
        }
        return s;
    }
    int mnrgn(){
        int s = 5;
        s += stats[0] * 2;
        if(Loot[0].rarity > 0){
            s += Loot[0].tier * 3;
        }
        if(Loot[3].rarity > 0){
            s += Loot[3].tier * 5;
        }
        if(Loot[4].type == 7 and Loot[4].rarity > 1){
            s += Loot[4].tier * 3;
        }
        return s;
    }
    int hlth(){
        int s = health;
        s += s * stats[2] / 5;
        if(Loot[1].tier > 0){
            s += Loot[1].tier * health / 5;
        }
        if(Loot[0].rarity > 0){
            s += Loot[0].tier * health / 10;
        }
        if(Loot[0].rarity > 1){
            s += Loot[0].tier * health / 10;
        }
        if(Loot[2].rarity > 1){
            s += Loot[2].tier * health / 10;
        }
        if(Loot[2].rarity > -1){
            s += Loot[2].tier * health / 10;
        }
        return s;
    }
    int physdmg(){
        int s = phys_damage;
        s += s * stats[2] / 5;
        if(Loot[3].type == 4){
            s += Loot[3].tier * 2 * phys_damage / 5;
        }
        if(Loot[4].type == 6){
            s += Loot[4].tier * phys_damage / 10;
        }
        return s;
    }
    std::string name_stat[11]{"Health", "Health cap", "Mana", "Mana cap", "Physical damage", "Spell Amplification", "Evasion", "Bonus Attack rate", "Health regeneration", "Mana regeneration", "Damage"};
public:
    int stat[11]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int dmg(){
        return stat[4] + stat[5];
    }
    std::string name = "";
    std::string name_stats[4]{"Intelligence", "Spellpower", "Strength", "Agility"};
    class passive{
    public:
        std::string name = "";
        std::string description = "";
        int number = 0;
        virtual ~passive() {}
        passive(std::string inname, std::string indescription){
            name = inname;
            description = indescription;
        }
        virtual int attack_event(bool result, bool dead, Hero *hero) = 0;
        std::string passive_info(){
            return name + "\n" + description + "\n";
        }
    };
    class mage: public passive{
    public:
        mage(): passive(mage_name, mage_description){
            number = 0;
        }
        int attack_event(bool result, bool dead, Hero *hero) override{
            if(result and dead){
                hero->stat[2] += 20;
            }
            if(result){
                return hero->stat[10];
            }
            return 0;
        }
    };
    class warrior: public passive{
    public:
        warrior(): passive(warrior_name, warrior_description){
            number = 1;
        }
        int attack_event(bool result, bool dead, Hero *hero) override{
            if(result){
                hero->stat[4] += hero->physdmg() / 5;
            }
            hero->stat[10] = hero->dmg();
            if(result){
                return hero->stat[10];
            }
            return 0;
        }
    };
    class rogue: public passive{
    public:
        rogue(): passive(rogue_name, rogue_description){
            number = 4;
        }
        int attack_event(bool result, bool dead, Hero *hero) override{
            if(result and dead){
                hero->stat[6] += 5;
                hero->stat[7] += 5;
            }
            if(result){
                return hero->stat[10];
            }
            return 0;
        }
    };
    class berserk: public passive{
    public:
        berserk(): passive(berserk_name, berserk_description){
            number = 2;
        }
        int attack_event(bool result, bool dead, Hero *hero) override{
            if(result){
                return hero->stat[10];
            }
            return hero->stat[10] / 2;
        }
    };
    class warlock: public passive{
    public:
        warlock(): passive(warlock_name, warlock_description){
            number = 3;
        }
        int attack_event(bool result, bool dead, Hero *hero) override{
            if(result and dead){
                hero->stat[0] += hero->hlth() / 5;
            }
            if(result){
                return hero->stat[10];
            }
            return 0;
        }
    };
    class archer: public passive{
    public:
        archer(): passive(archer_name, archer_description){
            number = 5;
        }
        int attack_event(bool result, bool dead, Hero *hero) override{
            if(result){
                return hero->stat[10];
            }
            return 0;
        }
    };
    mage Mage;
    warrior Warrior;
    rogue Rogue;
    berserk Berserk;
    warlock Warlock;
    archer Archer;
    passive* passivki[6]{&Mage, &Warrior, &Berserk, &Warlock, &Rogue, &Archer};
    passive* passivka;
    int health = 0;
    int mana = 0;
    int phys_damage = 0;
    int spell_damage = 0;
    int stats[4]{0, 0, 0, 0};
    int money = 0;
    int exp = 0;
    int level = 0;
    bool level_cap = false;
    int cave = 1;
    int revive = 0;
    long long time = 0;
    Equipment Loot[5];
    Hero();
    Hero(const std::string in_name, const int stat_1, const int stat_2, const int stat_3, const int stat_4){
        name = in_name;
        health = stat_1;
        mana = stat_2;
        phys_damage = stat_3;
        spell_damage = stat_4;
    }
    void reload(){
        stat[0] = hlth();
        stat[1] = stat[0];
        stat[2] = mn();
        stat[3] = stat[2];
        stat[4] = physdmg();
        stat[5] = spldmg();
        stat[6] = evd();
        stat[7] = atk();
        stat[8] = hlthrgn();
        stat[9] = mnrgn();
        stat[10] = dmg();
    }
    std::string stat_info(){
        std::string out = "";
        for (int i = 0; i < 10; ++i) {
            if(i != 1 and i != 3){
                out += name_stat[i] + ": " + toString(stat[i]) + "\n";
            }
        }
        return out;
    }
    std::string hero_info(){
        std::string out = "";
        out += name + "\n";
        out += "Stats: Intelligence " + toString(stats[0]) + " Spellpower " + toString(stats[1]) + " Strength " + toString(stats[2]) + " Agility " + toString(stats[3])  + "\n";
        out += "Level: " + toString(level) + "/" + "15" + "\n" + "Experience: " + toString(exp) + "/" + toString(level_borders[level])+ "\n";
        out += "Helm: " + Loot[0].info() + "\n";
        out += "Armor: " + Loot[1].info() + "\n";
        out += "Boots: " + Loot[2].info() + "\n";
        out += "Weapon: " + Loot[3].info() + "\n";
        out += "Talisman: " + Loot[4].info() + "\n";
        out += "Money: " + toString(money) + "\n";
        return out;
    }
    void change(int x){
        stats[3] += x;
        stats[2] += x;
        stats[1] += x;
        stats[0] += x;
    }
    std::string base_stats(){
        std::string out = "";
        out += "Health: " + toString(health) + "\n";
        out += "Physical Damage: " + toString(phys_damage) + "\n";
        out += "Spell Amplification: " + toString(spell_damage) + "\n";
        out += "Mana: " + toString(mana) + "\n";
        return out;
    }
};
