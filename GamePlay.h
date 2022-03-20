#include <iostream>
#include "Data.h"

void levelup(Hero *hero){
    if(not hero->level_cap and hero->exp >= level_borders[hero->level]){
        std::cout << "Your level has increased, you can upgrade your stats\n"
                     "--------------------------------------------\n";
        while(not hero->level_cap and hero->exp >= level_borders[hero->level]){
            hero->level++;
            hero->exp -= level_borders[hero->level - 1];
            if(hero->level == 15){
                hero->level_cap = true;
            }
            std::cout << "Write stat name to increase it (Agility, Strength, Spellpower, Intelligence) \nYou can do it 2 more times\n"
                         "--------------------------------------------\n";
            std::string command;
            int cnt = 2;
            while(cnt > 0){
                std::cin >> command;
                if(command == "Agility"){
                    cnt--;
                    hero->Agility++;
                }
                else if(command == "Strength"){
                    cnt--;
                    hero->Strength++;
                }
                else if(command == "Spellpower"){
                    cnt--;
                    hero->Spellpower++;
                }
                else if(command == "Intelligence"){
                    cnt--;
                    hero->Intelligence++;
                }
                else{
                    std::cout << "Wrong stat, try another\n";
                }
                std::cout << "--------------------------------------------\n";
            }
        }
    }
}

void generate_location(Location *location){
    for (int i = 0; i < location->amount; ++i) {
        for (int j = 0; j < 3; ++j) {
            location->levels[i][j].rebuild();
        }
    }
}

bool Attack(int atk_rate, int evade_rate){
    int rate = evade_rate - atk_rate;
    std::cout << "attack chance: " << atk_rate + 100 << " - " << evade_rate << " = " << atk_rate + 100 - evade_rate << "\n";
    int ran = RAND() % 100;
    if(rate > ran){
        std::cout << "Result: missed\n"
                     "--------------------------------------------\n";
        return false;
    }
    std::cout << "Result: damage dealed\n"
                 "--------------------------------------------\n";
    return true;
}

void change_equip(Hero *hero, Equipment new_equip){
    std::string command;
    if(new_equip.type == 1){
        std::cout << "Now you have " << hero->Helm.info() << " and " << new_equip.info() << ".\n"
                                                                                            "--------------------------------------------\n";
        if(hero->Helm.rarity == 3){
            std::cout << "You can't have a Helm, you already have Legendary one\n"
                         "--------------------------------------------\n";
            hero->money += new_equip.cost();
            std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                                   "--------------------------------------------\n";
        }
        else {
            std::cout << "Write 'Sell' if you want to sell first equipment and own another, or write anything else to do the opposite.\n"
                       "--------------------------------------------\n";
            std::cin >> command;
            if (command == "Sell") {
                hero->money += hero->Helm.cost();
                std::cout << "You earned " << hero->Helm.cost() << " gold\n"
                                                                   "--------------------------------------------\n";
                if (new_equip.rarity == 3) {
                    hero->change(new_equip.tier);
                }
                hero->Helm = new_equip;
            } else {
                hero->money += new_equip.cost();
                std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                  "--------------------------------------------\n";
            }
        }
    }
    if(new_equip.type == 2){
        std::cout << "Now you have " << hero->Armor.info() << " and " << new_equip.info() << ".\n"
                                                                                             "--------------------------------------------\n";
        if(hero->Armor.rarity == 3){
            std::cout << "You can't have a Armor, you already have Legendary one\n"
                         "--------------------------------------------\n";
            hero->money += new_equip.cost();
            std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                                   "--------------------------------------------\n";
        }
        else {
            std::cout << "Write 'Sell' if you want to sell first equipment and own another, or write anything else to do the opposite.\n"
                       "--------------------------------------------\n";
            std::cin >> command;
            if (command == "Sell") {
                hero->money += hero->Armor.cost();
                std::cout << "You earned " << hero->Armor.cost() << " gold\n"
                                                                    "--------------------------------------------\n";
                if (new_equip.rarity == 3) {
                    hero->change(new_equip.tier);
                }
                hero->Armor = new_equip;
            } else {
                hero->money += new_equip.cost();
                std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                  "--------------------------------------------\n";
            }
        }
    }
    if(new_equip.type == 3){
        std::cout << "Now you have " << hero->Boots.info() << " and " << new_equip.info() << ".\n"
                                                                                             "--------------------------------------------\n";
        if(hero->Boots.rarity == 3){
            std::cout << "You can't have Boots, you already have Legendary one\n"
                         "--------------------------------------------\n";
            hero->money += new_equip.cost();
            std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                                   "--------------------------------------------\n";
        }
        else {
            std::cout << "Write 'Sell' if you want to sell first equipment and own another, or write anything else to do the opposite.\n"
                       "--------------------------------------------\n";
            std::cin >> command;
            if (command == "Sell") {
                hero->money += hero->Boots.cost();
                std::cout << "You earned " << hero->Boots.cost() << " gold\n"
                                                                    "--------------------------------------------\n";
                if (new_equip.rarity == 3) {
                    hero->change(new_equip.tier);
                }
                hero->Boots = new_equip;
            } else {
                hero->money += new_equip.cost();
                std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                  "--------------------------------------------\n";
            }
        }
    }
    if(new_equip.type == 4 or new_equip.type == 5){
        std::cout << "Now you have " << hero->Weapon.info() << " and " << new_equip.info() << ".\n"
                                                                                             "--------------------------------------------\n";
        if(hero->Weapon.rarity == 3){
            std::cout << "You can't have a Weapon, you already have Legendary one\n"
                         "--------------------------------------------\n";
            hero->money += new_equip.cost();
            std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                                   "--------------------------------------------\n";
        }
        else {
            std::cout << "Write 'Sell' if you want to sell first equipment and own another, or write anything else to do the opposite.\n"
                       "--------------------------------------------\n";
            std::cin >> command;
            if (command == "Sell") {
                hero->money += hero->Weapon.cost();
                std::cout << "You earned " << hero->Weapon.cost() << " gold\n"
                                                                     "--------------------------------------------\n";
                if (new_equip.rarity == 3) {
                    hero->change(new_equip.tier);
                }
                hero->Weapon = new_equip;
            } else {
                hero->money += new_equip.cost();
                std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                  "--------------------------------------------\n";
            }
        }
    }
    if(new_equip.type == 6 or new_equip.type == 7){
        std::cout << "Now you have " << hero->Talisman.info() << " and " << new_equip.info() << ".\n"
                                                                                             "--------------------------------------------\n";
        if(hero->Talisman.rarity == 3){
            std::cout << "You can't have a Talisman, you already have Legendary one\n"
                         "--------------------------------------------\n";
            hero->money += new_equip.cost();
            std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                                   "--------------------------------------------\n";
        }
        else {
            std::cout << "Write 'Sell' if you want to sell first equipment and own another, or write anything else to do the opposite.\n"
                       "--------------------------------------------\n";
            std::cin >> command;
            if (command == "Sell") {
                hero->money += hero->Talisman.cost();
                std::cout << "You earned " << hero->Talisman.cost() << " gold\n"
                                                                       "--------------------------------------------\n";
                if (new_equip.rarity == 3) {
                    hero->change(new_equip.tier);
                }
                hero->Talisman = new_equip;
            } else {
                hero->money += new_equip.cost();
                std::cout << "You earned " << new_equip.cost() << " gold\n"
                                                                  "--------------------------------------------\n";
            }
        }
    }
}

long long battle(Hero *hero, Location *location){
    int health = hlth(hero);
    int health_cap = health;
    int mana = mn(hero);
    int mana_cap = mana;
    int physical_damage = physdmg(hero);
    int spell_damage = spldmg(hero);
    int evade = evd(hero);
    int attack = atk(hero);
    int health_regen = hlthrgn(hero);
    int mana_regen = mnrgn(hero);
    long long time = 0;
    bool here = true;
    for (int i = 0; i < location->amount; ++i) {
        if(not here){
            break;
        }
        std::cout << "Cave Level: " << i + 1 << "\n";
        std::cout << "--------------------------------------------\n";
        bool win = true;
        std::string command;
        while(win){
            time += 1;
            mana = std::min(mana_cap, mana = mana_regen + mana);
            health = std::min(health_cap, health + health_regen);
            bool lost = false;
            for (int j = 0; j < 3; ++j) {
                std::cout << j + 1 << ")";
                if(not location->levels[i][j].dead) {
                    std::cout << location->levels[i][j].info();
                    lost = true;
                }
                else{
                    std::cout << location->levels[i][j].name << " is dead\n";
                }
                std::cout << "--------------------------------------------\n";
            }
            if(not lost){
                break;
            }
            std::cout << hero->name << ":\n";
            std::cout << "Health: " << health << "\n";
            std::cout << "Mana: " << mana << "\n";
            std::cout << "--------------------------------------------\n";
            int dmg;
            bool flag = true;
            std::cout << "Choose damage type, write spell or phys\n";
            std::cout << "--------------------------------------------\n";
            while(flag) {
                std::cin >> command;
                if (command == "spell") {
                    dmg = spell_damage;
                    flag = false;
                } else if (command == "phys") {
                    dmg = physical_damage;
                    flag = false;
                } else {
                    std::cout << "Wrong type, try again\n";
                }
                std::cout << "--------------------------------------------\n";
            }
            int count;
            flag = true;
            std::cout << "Choose attack type: one (costs 10 mana), two (costs 30 mana), three (costs 75 mana), ult (costs 200 mana) or zero (costs 0 mana)\n";
            std::cout << "--------------------------------------------\n";
            std::cout << "Your current mana is: " << mana << "/" << mana_cap << "\n";
            std::cout << "--------------------------------------------\n";
            bool double_attack = false;
            while(flag) {
                std::cin >> command;
                if (command == "one") {
                    if(mana < 10){
                        std::cout << "Not enough mana, try again";
                    }
                    else {
                        count = 1;
                        flag = false;
                        mana -= 10;
                    }
                }
                else if (command == "two") {
                    if(mana < 30){
                        std::cout << "Not enough mana, try again";
                    }
                    else {
                        count = 2;
                        flag = false;
                        mana -= 30;
                    }
                }
                else if (command == "three") {
                    if(mana < 75){
                        std::cout << "Not enough mana, try again\n";
                    }
                    else {
                        count = 3;
                        flag = false;
                        mana -= 75;
                    }
                }
                else if (command == "ult") {
                    if(mana < 200){
                        std::cout << "Not enough mana, try again\n";
                    }
                    else {
                        count = 3;
                        double_attack = true;
                        flag = false;
                        mana -= 200;
                    }
                }
                else if (command == "zero") {
                    count = 0;
                    flag = false;
                }
                else {
                    std::cout << "Wrong attack type, try again\n";
                }
                std::cout << "--------------------------------------------\n";
            }
            int start = 1;
            if(count > 0 and count < 3) {
                flag = true;
                std::cout << "Choose first target, if your attack type is two or three next target will be to the right (write 1, 2 or 3)\n";
                std::cout << "--------------------------------------------\n";
                while (flag) {
                    std::cin >> command;
                    if (command == "1"){
                        start = 1;
                        flag = false;
                    }
                    else if (command == "2"){
                        start = 2;
                        flag = false;
                    }
                    else if (command == "3"){
                        start = 3;
                        flag = false;
                    }
                    else{
                        std::cout << "Wrong target, try again\n";
                    }
                    std::cout << "--------------------------------------------\n";
                }
            }
            int oldness = 0;
            for (int k = 0; k < 1 + double_attack; ++k) {
                for (int j = start - 1; j < start + count - 1; ++j) {
                    if (not location->levels[i][j % 3].dead) {
                        bool old = true;
                        std::cout << hero->name << " is attacking " << location->levels[i][j % 3].name << "\n";
                        if(location->levels[i][j % 3].evade > attack + 85 and oldness % 10 == 0){
                            std::cout << "Your attack rate is lower than 15%\n";
                            std::cout << "Write 'DIE' to die from old age and lose 10 time, or anything else to continue suffering\n";
                            std::cin >> command;
                            if(command == "DIE"){
                                health = 0;
                                time += 10;
                                old = false;
                            }
                            else{
                                oldness += 1;
                            }
                        }
                        if (old and Attack(attack, location->levels[i][j % 3].evade)) {
                            location->levels[i][j % 3].health -= dmg;
                            if (location->levels[i][j % 3].health <= 0) {
                                location->levels[i][j % 3].dead = true;
                                hero->money += location->levels[i][j % 3].money;
                                hero->exp += location->levels[i][j % 3].exp;
                            }
                        }
                    }
                }
            }
            if(health <= 0){
                win = false;
            }
            for (int j = 0; j < 3; ++j) {
                if(not location->levels[i][j].dead) {
                    std::cout << location->levels[i][j % 3].name << " is attacking " << hero->name << "\n";
                    if(Attack(location->levels[i][j].attack, evade)){
                        health -= location->levels[i][j].damage;
                        if(health <= 0){
                            win = false;
                        }
                    }
                }
            }
        }
        if(not win){
            std::cout << "You were killed\n";
            std::cout << "--------------------------------------------\n";
            here = false;
            hero->alive = false;
        }
        else{
            std::cout << "You won \n";
            std::cout << "--------------------------------------------\n";
            Equipment new_equip = generate_treasure(location->treasure[i], 1 + 2 * (i == 3));
            std::cout << "You found " << new_equip.info() << "\n";
            std::cout << "--------------------------------------------\n";
            change_equip(hero, new_equip);
        }
    }
    std::cout << "You left the Cave\n";
    std::cout << "--------------------------------------------\n";
    return time;
}

long long train(Hero *hero){
    long long time = 0;
    std::cout << "Welcome to the Training_Field\n";
    std::cout << "You can add exp here, if you need only a bit\n";
    std::cout << "Choose your training type:\n";
    std::cout << "--------------------------------------------\n";
    if(not hero->level_cap){
        std::cout << "+ 100 exp per 20 time(write 1)\n+ 100 exp per 5 time and 100 gold(write 2)\n";
    }
    else{
        std::cout << "You have max level\n";
    }
    std::cout << "Write exit to quit\n";
//    std::cout << "+ 1 stat per 100 time(write 3)\n+ 1 stat per 20 time and 500 gold(write 3)\nWrite exit to quit\n";
    std::cout << "--------------------------------------------\n";
    bool flag = true;
    std::string command;
    while(flag){
        std::cin >> command;
        if(command == "1" and not hero->level_cap){
            time += 20;
            hero->exp += 100;
            flag = false;
        }
        else if(command == "2" and not hero->level_cap){
            if(hero->money < 100){
                std::cout << "Not enough money\n";
            }
            else {
                time += 5;
                hero->exp += 100;
                hero->money -= 100;
                flag = false;
            }
        }
//        else if(command == "3"){
//            std::cout << "Choose stat(Agility, Strenght, Spellpower, Intelligence)\n";
//            int cnt = 1;
//            while(cnt > 0){
//                std::cin >> command;
//                if(command == "Agility"){
//                    cnt--;
//                    hero->Agility++;
//                }
//                else if(command == "Strength"){
//                    cnt--;
//                    hero->Strength++;
//                }
//                else if(command == "Spellpower"){
//                    cnt--;
//                    hero->Spellpower++;
//                }
//                else if(command == "Intelligence"){
//                    cnt--;
//                    hero->Intelligence++;
//                }
//                else{
//                    std::cout << "Wrong stat, try another\n";
//                }
//            }
//            time += 100;
//            flag = false;
//        }
//        else if(command == "4"){
//            if(hero->money < 500){
//                std::cout << "Not enough money\n";
//            }
//            else {
//                std::cout << "Choose stat(Agility, Strenght, Spellpower, Intelligence)\n";
//                int cnt = 1;
//                while(cnt > 0){
//                    std::cin >> command;
//                    if(command == "Agility"){
//                        cnt--;
//                        hero->Agility++;
//                    }
//                    else if(command == "Strength"){
//                        cnt--;
//                        hero->Strength++;
//                    }
//                    else if(command == "Spellpower"){
//                        cnt--;
//                        hero->Spellpower++;
//                    }
//                    else if(command == "Intelligence"){
//                        cnt--;
//                        hero->Intelligence++;
//                    }
//                    else{
//                        std::cout << "Wrong stat, try another\n";
//                    }
//                }
//                time += 100;
//                hero->money -= 500;
//                flag = false;
//            }
//        }
        else if(command == "exit"){
            flag = false;
        }
        else{
            std::cout << "It is not a command, try another\n";
        }
        std::cout << "--------------------------------------------\n";
    }
    return time;
}

long long forge(Hero *hero){
    long long time = 0;
    std::cout << "Welcome to the Forge\n";
    std::cout << "You can forge your equipment here\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "100 gold to forge Common\n"
                 "250 gold to forge Rare\n"
                 "550 gold to forge Epic\n"
                 "1150 gold to forge Legendary\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Write Helm, Armor, Boots, Weapon or Talisman to upgrade it\nWrite exit to quit\n";
    std::cout << "--------------------------------------------\n";
    bool flag = true;
    std::string command;
    while(flag){
        std::cin >> command;
        if(command == "Helm"){
            if(hero->Helm.tier == 0){
                std::cout << "You do not have Helm\n";
            }
            else if(hero->money < ((3 * (1 << (hero->Helm.rarity)) - 1) * 50)){
                std::cout << "You do not have enough money\n";
            }
            else if(hero->Helm.tier == 3){
                std::cout << "You already have Helm on max forge\n";
            }
            else {
                hero->Helm.tier++;
                if(hero->Helm.rarity == 3){
                    hero->change(1);
                }
                hero->money -= (3 * (1 << (hero->Helm.rarity)) - 1) * 50;
                flag = false;
            }
        }
        else if(command == "Armor"){
            if(hero->Armor.tier == 0){
                std::cout << "You do not have Armor\n";
            }
            else if(hero->money < ((3 * (1 << (hero->Armor.rarity)) - 1) * 50)){
                std::cout << "You do not have enough money\n";
            }
            else if(hero->Armor.tier == 3){
                std::cout << "You already have Armor on max forge\n";
            }
            else {
                hero->Armor.tier++;
                if(hero->Armor.rarity == 3){
                    hero->change(1);
                }
                hero->money -= (3 * (1 << (hero->Armor.rarity)) - 1) * 50;
                flag = false;
            }
        }
        else if(command == "Boots"){
            if(hero->Boots.tier == 0){
                std::cout << "You do not have Boots\n";
            }
            else if(hero->money < ((3 * (1 << (hero->Boots.rarity)) - 1) * 50)){
                std::cout << "You do not have enough money\n";
            }
            else if(hero->Boots.tier == 3){
                std::cout << "You already have Boots on max forge\n";
            }
            else {
                hero->Boots.tier++;
                if(hero->Boots.rarity == 3){
                    hero->change(1);
                }
                hero->money -= (3 * (1 << (hero->Boots.rarity)) - 1) * 50;
                flag = false;
            }
        }
        else if(command == "Weapon"){
            if(hero->Weapon.tier == 0){
                std::cout << "You do not have Weapon\n";
            }
            else if(hero->money < ((3 * (1 << (hero->Weapon.rarity)) - 1) * 50)){
                std::cout << "You do not have enough money\n";
            }
            else if(hero->Weapon.tier == 3){
                std::cout << "You already have Weapon on max forge\n";
            }
            else {
                hero->Weapon.tier++;
                if(hero->Weapon.rarity == 3){
                    hero->change(1);
                }
                hero->money -= (3 * (1 << (hero->Weapon.rarity)) - 1) * 50;
                flag = false;
            }
        }
        else if(command == "Talisman"){
            if(hero->Talisman.tier == 0){
                std::cout << "You do not have Talisman\n";
            }
            else if(hero->money < ((3 * (1 << (hero->Talisman.rarity)) - 1) * 50)){
                std::cout << "You do not have enough money\n";
            }
            else if(hero->Talisman.tier == 3){
                std::cout << "You already have Talisman on max forge\n";
            }
            else {
                hero->Talisman.tier++;
                if(hero->Talisman.rarity == 3){
                    hero->change(1);
                }
                hero->money -= (3 * (1 << (hero->Talisman.rarity)) - 1) * 50;
                flag = false;
            }
        }
        else if(command == "exit"){
            flag = false;
        }
        else{
            std::cout << "It is not a command, try another\n";
        }
        std::cout << "--------------------------------------------\n";
    }
    return time;
}

long long shop(Hero *hero){
    long long time = 0;
    std::cout << "Welcome to the shop\n";
    std::cout << "You can buy chests and obtain new equipment here\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Rare Chest: 500 gold\n"
                 "Epic Chest: 1250 gold\n"
                 "Legendary Chest: 2750 gold\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Write Rare, Epic or Legendary to buy Chest or exit to quit\n";
    std::cout << "--------------------------------------------\n";
    bool flag = true;
    std::string command;
    while(flag){
        std::cin >> command;
        if(command == "Rare"){
            if(hero->money >= 500){
                hero->money -= 500;
                int first = RAND() % 100;
                int second = RAND() % 100;
                int rarity = 0;
                int tier = 1;
                if(first > 89){
                    rarity += 2;
                }
                else if(first > 54){
                    rarity += 1;
                }
                if(second > 89){
                    tier += 2;
                }
                else if(second > 54){
                    tier += 1;
                }
                Equipment new_equip = generate_treasure(rarity, tier);
                change_equip(hero, new_equip);
            }
            else{
                std::cout << "You do not have enough money\n";
            }
        }
        else if(command == "Epic"){
            if(hero->money >= 1250){
                hero->money -= 1250;
                int first = RAND() % 100;
                int second = RAND() % 100;
                int rarity = 1;
                int tier = 1;
                if(first > 89){
                    rarity += 2;
                }
                else if(first > 54){
                    rarity += 1;
                }
                if(second > 89){
                    tier += 2;
                }
                else if(second > 54){
                    tier += 1;
                }
                Equipment new_equip = generate_treasure(rarity, tier);
                change_equip(hero, new_equip);
            }
            else{
                std::cout << "You do not have enough money\n";
            }
        }
        else if(command == "Legendary"){
            if(hero->money >= 2750){
                hero->money -= 2750;
                int first = RAND() % 100;
                int second = RAND() % 100;
                int rarity = 2;
                int tier = 1;
                if(first > 64){
                    rarity += 1;
                }
                if(second > 89){
                    tier += 2;
                }
                else if(second > 54){
                    tier += 1;
                }
                Equipment new_equip = generate_treasure(rarity, tier);
                change_equip(hero, new_equip);
            }
            else{
                std::cout << "You do not have enough money\n";
            }
        }
        else if(command == "exit"){
            flag = false;
        }
        else{
            std::cout << "It is not a command, try another\n";
        }
        std::cout << "--------------------------------------------\n";
    }
    return time;
}

long long library(){
    long long time = 0;
    std::string command;
    bool flag = true;
    std::cout << "Welcome to the Library\n";
    std::cout << "You can find information about this game here\n";
    while(flag){
        std::cout << "Write Game, Battle, Stats or Equipment\n";
        std::cout << "Write exit to quit\n";
        std::cin >> command;
        if(command == "Battle"){
            std::cout << "There is 5 Chapters. Chapter has cave levels with 3 monsters in each.\n"
                         "On each level you must defeat all the monsters or die.\n"
                         "The battle with monsters takes place step by step.\n"
                         "First you attack, then every monster left alive attacks you.\n"
                         "Each turn, you must choose a physical or magical type of attack, the attack itself, and the first target to attack.\n"
                         "There are 4 + 1 attack types.\n"
                         "'one' - You attack the selected target\n"
                         "'two' - You attack the selected target, as well as the next\n"
                         "'three' - You attack all monsters\n"
                         "'ult' - You attack all monsters twice\n"
                         "'zero' - You skip a turn\n"
                         "If you defeated all the monsters, you go to the next level of the cave, and also get random equipment as a reward.\n"
                         "If you died you will be offered a choice: Revive or not.\n"
                         "If you respawn, you will return to the Castle, but you will be deducted points. Otherwise the game will end..\n"
                         "Each level you have to defeat monsters\n";
        }
        else if(command == "Equipment"){
            std::cout << "There are 5 types of equipment. Helmet, Armor, Boots, Weapon and Talisman\n"
                         "Also, the Weapon is divided into the Staff and the Sword, and the Talisman into the Spell Talisman and the Physical Talisman.\n"
                         "Each type specializes in a certain type of damage.\n"
                         "Each item can be of a certain rarity: None, Rare, Epic, or Legendary.\n"
                         "Rarity increases the number of bonuses.\n"
                         "Equipment also has forging, each level of forging increases equipment bonuses.\n"
                         "So far, there are 3 levels of forging: +0, +1 and +2.\n";
        }
        else if(command == "Stats"){
            std::cout << "You have 4 stats: Intelligence, Agility, Strength and Spell Power.\n"
                         "Each level you will be offered 2 times to increase one of the stats.\n"
                         "Stat gives bonuses depending on the basic characteristics.\n"
                         "What each stat affects:\n"
                         "Strength - each stat gives +20% of base health and +20% of base physical damage.\n"
                         "Spell Power - Each stat grants +20% base mana and +20% base spell damage.\n"
                         "Agility - each stat gives +15% evasion and +5% attack rate, as well as +4 health regeneration per turn.\n"
                         "Intelligence - each stat gives +5% evasion and +15% attack rate, as well as +4 mana regeneration per turn.\n";
        }
        else if(command == "Game"){
            std::cout << "The goal of the game is to score as many points as possible.\n"
                         "You get points for each new chapter completed, equipment by the end of the game, hero level, as well as for some other achievements.\n"
                         "You are deducted points for the number of revivals, as well as for the time that the in-game character spent.\n"
                         "Time increases every turn of battle or during training.\n"
                         "In addition to the goal to score points, there is also a goal to complete all the chapters and defeat the Eternal Dragon.\n";
        }
        else if(command == "exit"){
            flag = false;
        }
        else{
            std::cout << "It is not a command, try another\n";
        }
        std::cout << "--------------------------------------------\n";
    }
    return time;
}

void score(long long time, Hero *hero, int chapter, int revive){
    long long s = 0;
    std::cout << "Your ingame time: " << time << " it is -" << time * 25 << " points\n";
    s -= time * 25;
    std::cout << "Your Hero level: " << hero->level << " it is +" << (1 << hero->level) * 20 << " points\n";
    s += (1 << hero->level * 20);
    std::cout << "Your Helm: " << hero->Helm.info() << " it is +" << (1 << hero->Helm.tier) * (1 << hero->Helm.rarity) * 10 << " points\n";
    s += (1 << hero->Helm.tier) * (1 << hero->Helm.rarity) * 10;
    std::cout << "Your Armor: " << hero->Armor.info() << " it is +" << (1 << hero->Armor.tier) * (1 << hero->Armor.rarity) * 10 << " points\n";
    s += (1 << hero->Armor.tier) * (1 << hero->Armor.rarity) * 10;
    std::cout << "Your Boots: " << hero->Boots.info() << " it is +" << (1 << hero->Boots.tier) * (1 << hero->Boots.rarity) * 10 << " points\n";
    s += (1 << hero->Boots.tier) * (1 << hero->Boots.rarity) * 10;
    std::cout << "Your Weapon: " << hero->Weapon.info() << " it is +" << (1 << hero->Weapon.tier) * (1 << hero->Weapon.rarity) * 20 << " points\n";
    s += (1 << hero->Weapon.tier) * (1 << hero->Weapon.rarity) * 10;
    std::cout << "Your Talisman: " << hero->Talisman.info() << " it is +" << (1 << hero->Talisman.tier) * (1 << hero->Talisman.rarity) * 20 << " points\n";
    s += (1 << hero->Talisman.tier) * (1 << hero->Talisman.rarity) * 10;
    std::cout << "Your best Chapter is: " << chapter - 1 << " it is +" << (1 << chapter) * 200 << " points\n";
    s += (1 << chapter) * 200;
    std::cout << "Your Stats are: Agility " << hero->Agility << " Strength " << hero->Strength << " Spellpower " << hero->Spellpower << " Intelligence " << hero->Intelligence << " it is +" << (hero->Agility + hero->Strength + hero->Spellpower + hero->Intelligence) * 100 << " points\n";
    s += (hero->Agility + hero->Strength + hero->Spellpower + hero->Intelligence) * 100;
    std::cout << "You were revived: " << revive << " times. It is -" << revive * 100 << " points\n";
    s -= revive * 100;
    std::cout << "Your Final score is: " << s << "\n" << "Well done!\n";
    std::cout << "--------------------------------------------\n";
}

