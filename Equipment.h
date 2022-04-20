#include <string>

static std::string Rarity[4]{"", "Rare ", "Epic ", "Legendary "};
static std::string Tier[4]{"", "+0", "+1", "+2"};
static std::string Type[8]{"None", "Helm ", "Armor ", "Boots ", "Sword ", "Staff ", "Physical Talisman ", "Spell Talisman "};
static std::string stat[9]{" % Health\n", " % Mana\n", " % Physical Damage\n", " % Spell Damage\n", " Mana regen\n", " Health regen\n", " % Evasion\n", " % Attack rate\n", " to all stats\n"};
static std::string type_stats[7][9]{
    {}
};

class Equipment{
    std::string toString(int val)
    {
        std::ostringstream oss;
        oss<< val;
        return oss.str();
    }
public:
    int type = 0;
    int tier = 0;
    int rarity = 0;
    Equipment(){};
    Equipment(int typein, int rarityin, int tierin){
        type = typein;
        rarity = rarityin;
        tier = tierin;
    }
    std::string info(){
        std::string out = "";
        out += Rarity[rarity];
        out += Type[type];
        out += Tier[tier];
        return out;
    }
    std::string Stats(){
        std::string out = "";
        if(type == 1){
            if(rarity > -1){
                out += "+ " + toString(10 * tier) + stat[1] + "\n";
            }
            if(rarity > 0){
                out += "+ " + toString(4 * tier) + stat[4] + "\n";
                out += "+ " + toString(4 * tier) + stat[5] + "\n";
            }
            if(rarity > 1){
                out += "+ " + toString(10 * tier) + stat[0] + "\n";
            }
            if(rarity > 2){
                out += "+ " + toString(1 * tier) + stat[8] + "\n";
            }
        }
        if(type == 3){
            if(rarity > -1){
                out += "+ " + toString(10 * tier) + stat[0] + "\n";
            }
            if(rarity > 0){
                out += "+ " + toString(5 * tier) + stat[6] + "\n";
                out += "+ " + toString(5 * tier) + stat[7] + "\n";
            }
            if(rarity > 1){
                out += "+ " + toString(10 * tier) + stat[0] + "\n";
            }
            if(rarity > 2){
                out += "+ " + toString(1 * tier) + stat[8] + "\n";
            }
        }
        if(type == 2){
            if(rarity > -1){
                out += "+ " + toString(10 * tier) + stat[0] + "\n";
            }
            if(rarity > 0){
                out += "+ " + toString(8 * tier) + stat[5] + "\n";
            }
            if(rarity > 1){
                out += "+ " + toString(20 * tier) + stat[6] + "\n";
            }
            if(rarity > 2){
                out += "+ " + toString(1 * tier) + stat[8] + "\n";
            }
        }
        if(type == 4){
            if(rarity > -1){
                out += "+ " + toString(20 * tier) + stat[2] + "\n";
            }
            if(rarity > 0){
                out += "+ " + toString(8 * tier) + stat[4] + "\n";
            }
            if(rarity > 1){
                out += "+ " + toString(20 * tier) + stat[7] + "\n";
            }
            if(rarity > 2){
                out += "+ " + toString(1 * tier) + stat[8] + "\n";
            }
        }
        if(type == 5){
            if(rarity > -1){
                out += "+ " + toString(20 * tier) + stat[3] + "\n";
            }
            if(rarity > 0){
                out += "+ " + toString(8 * tier) + stat[4] + "\n";
            }
            if(rarity > 1){
                out += "+ " + toString(20 * tier) + stat[7] + "\n";
            }
            if(rarity > 2){
                out += "+ " + toString(1 * tier) + stat[8] + "\n";
            }
        }
        if(type == 6){
            if(rarity > -1){
                out += "+ " + toString(10 * tier) + stat[2] + "\n";
            }
            if(rarity > 0){
                out += "+ " + toString(5 * tier) + stat[6] + "\n";
                out += "+ " + toString(5 * tier) + stat[7] + "\n";
            }
            if(rarity > 1){
                out += "+ " + toString(4 * tier) + stat[5] + "\n";
            }
            if(rarity > 2){
                out += "+ " + toString(1 * tier) + stat[8] + "\n";
            }
        }
        if(type == 7){
            if(rarity > -1){
                out += "+ " + toString(10 * tier) + stat[3] + "\n";
            }
            if(rarity > 0){
                out += "+ " + toString(5 * tier) + stat[6] + "\n";
                out += "+ " + toString(5 * tier) + stat[7] + "\n";
            }
            if(rarity > 1){
                out += "+ " + toString(4 * tier) + stat[4] + "\n";
            }
            if(rarity > 2){
                out += "+ " + toString(1 * tier) + stat[8] + "\n";
            }
        }
        return out;
    }
    int cost(){
        return (1 << (2 * rarity)) * (tier) * 5;
    }
};

Equipment generate_treasure(int rarity, int tier){
    int equip_type = RAND() % 7 + 1;
    return Equipment(equip_type, rarity, tier);
}