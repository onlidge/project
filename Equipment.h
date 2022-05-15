#include <string>

static std::string Rarity[4]{"", "Rare ", "Epic ", "Legendary "};
static std::string Tier[4]{"", "+0", "+1", "+2"};
static std::string Type[8]{"None", "Helm ", "Armor ", "Boots ", "Sword ", "Staff ", "Physical Talisman ", "Spell Talisman "};
static std::string stat[9]{" % Health\n", " % Mana\n", " % Physical Damage\n", " % Spell Damage\n", " Mana regen\n", " Health regen\n", " % Evasion\n", " % Attack rate\n", " to all stats\n"};
static int type_stats[7][8]{
    {1, 10, 9, 3, 0, 10, 8, 1},
    {0, 10, 5, 8, 6, 20, 8, 1},
    {0, 10, 10, 5, 0, 10, 8, 1},
    {2, 20, 4, 5, 7, 20, 8, 1},
    {3, 20, 4, 5, 7, 20, 8, 1},
    {3, 10, 10, 5, 5, 4, 8, 1},
    {2, 10, 10, 5, 4, 3, 8, 1},
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
        if(type > 0){
            for (int i = 0; i < 4; ++i) {
                if(rarity > i - 1){
                    out += "+ " + toString(type_stats[type - 1][2 * i + 1] * tier);
                    if(type_stats[type - 1][2 * i] == 9){
                        out += stat[4] + "\n";
                        out += "+ " + toString(type_stats[type - 1][2 * i + 1] * tier);
                        out += stat[5] + "\n";
                    }
                    else if(type_stats[type - 1][2 * i] == 10){
                        out += stat[6] + "\n";
                        out += "+ " + toString(type_stats[type - 1][2 * i + 1] * tier);
                        out += stat[7] + "\n";
                    }
                    else{
                        out += stat[type_stats[type - 1][2 * i]] + "\n";
                    }
                }
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