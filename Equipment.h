#include <string>

static std::string Rarity[4]{"", "Rare ", "Epic ", "Legendary "};
static std::string Tier[4]{"", "+0", "+1", "+2"};
static std::string Type[8]{"None", "Helm ", "Armor ", "Boots ", "Sword ", "Staff ", "Physical Talisman ", "Spell Talisman "};
static std::string stat[9]{" % Health\n", " % Mana\n", " % Physical Damage\n", " % Spell Damage\n", " Mana regen\n", " Health regen\n", " % Evasion\n", " % Attack rate\n", " to all stats\n"};

class Equipment{
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
    void Stats(){
        if(type == 1){
            if(rarity > -1){
                std::cout << "+ " << 10 * tier << stat[1];
            }
            if(rarity > 0){
                std::cout << "+ " << 4 * tier << stat[4];
                std::cout << "+ " << 4 * tier << stat[5];
            }
            if(rarity > 1){
                std::cout << "+ " << 10 * tier << stat[0];
            }
            if(rarity > 2){
                std::cout << "+ " << 1 * tier << stat[8];
            }
        }
        if(type == 3){
            if(rarity > -1){
                std::cout << "+ " << 10 * tier << stat[0];
            }
            if(rarity > 0){
                std::cout << "+ " << 5 * tier << stat[6];
                std::cout << "+ " << 5 * tier << stat[7];
            }
            if(rarity > 1){
                std::cout << "+ " << 10 * tier << stat[0];
            }
            if(rarity > 2){
                std::cout << "+ " << 1 * tier << stat[8];
            }
        }
        if(type == 2){
            if(rarity > -1){
                std::cout << "+ " << 10 * tier << stat[0];
            }
            if(rarity > 0){
                std::cout << "+ " << 8 * tier << stat[5];
            }
            if(rarity > 1){
                std::cout << "+ " << 20 * tier << stat[6];
            }
            if(rarity > 2){
                std::cout << "+ " << 1 * tier << stat[8];
            }
        }
        if(type == 4){
            if(rarity > -1){
                std::cout << "+ " << 20 * tier << stat[2];
            }
            if(rarity > 0){
                std::cout << "+ " << 8 * tier << stat[4];
            }
            if(rarity > 1){
                std::cout << "+ " << 20 * tier << stat[7];
            }
            if(rarity > 2){
                std::cout << "+ " << 1 * tier << stat[8];
            }
        }
        if(type == 5){
            if(rarity > -1){
                std::cout << "+ " << 20 * tier << stat[3];
            }
            if(rarity > 0){
                std::cout << "+ " << 8 * tier << stat[4];
            }
            if(rarity > 1){
                std::cout << "+ " << 20 * tier << stat[7];
            }
            if(rarity > 2){
                std::cout << "+ " << 1 * tier << stat[8];
            }
        }
        if(type == 6){
            if(rarity > -1){
                std::cout << "+ " << 10 * tier << stat[2];
            }
            if(rarity > 0){
                std::cout << "+ " << 5 * tier << stat[6];
                std::cout << "+ " << 5 * tier << stat[6];
            }
            if(rarity > 1){
                std::cout << "+ " << 4 * tier << stat[5];
            }
            if(rarity > 2){
                std::cout << "+ " << 1 * tier << stat[8];
            }
        }
        if(type == 7){
            if(rarity > -1){
                std::cout << "+ " << 10 * tier << stat[3];
            }
            if(rarity > 0){
                std::cout << "+ " << 5 * tier << stat[7];
                std::cout << "+ " << 5 * tier << stat[6];
            }
            if(rarity > 1){
                std::cout << "+ " << 4 * tier << stat[4];
            }
            if(rarity > 2){
                std::cout << "+ " << 1 * tier << stat[8];
            }
        }
    }
    int cost(){
        return (1 << (2 * rarity)) * (tier) * 5;
    }
};

Equipment generate_treasure(int rarity, int tier){
    int equip_type = RAND() % 7 + 1;
    return Equipment(equip_type, rarity, tier);
}