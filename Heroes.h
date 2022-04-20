#include "Equipment.h"
#include <sstream>

static int maxlevel = 15;
static int level_borders[15]{200, 500, 700, 1100, 1700, 2500, 3700, 5100, 6900, 9000, 11200, 14000, 17000, 21000, 25000};

std::string toString(int val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

class Hero{
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
        if(Loot[2].rarity > 0){
            s += Loot[2].tier * health / 10;
        }
        return s;
    }
    int mn(){
        int s = mana;
        s += s * stats[1] / 5;
        if(Loot[0].tier > 0){
            s += Loot[0].tier * mana / 10;
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
        if(Loot[2].tier > 0){
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
        if(Loot[2].tier > 0){
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
        s += stats[0] * 4;
        if(Loot[0].rarity > 0){
            s += Loot[0].tier * 4;
        }
        if(Loot[3].rarity > 0){
            s += Loot[3].tier * 8;
        }
        if(Loot[4].type == 7 and Loot[4].rarity > 1){
            s += Loot[4].tier * 4;
        }
        return s;
    }
    std::string name_stat[10]{"Health", "Health cap", "Mana", "Mana cap", "Physical damage", "Spell damage", "Evasion", "Bonus Attack rate", "Health regeneration", "Mana regeneration"};
public:
    std::string name = "";
    std::string name_stats[4]{"Intelligence", "Spellpower", "Strength", "Agility"};
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
    int stat[10]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
        out += "Spell Damage: " + toString(spell_damage) + "\n";
        out += "Mana: " + toString(mana) + "\n";
        return out;
    }
};
