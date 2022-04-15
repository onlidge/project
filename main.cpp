#include <iostream>
#include "GamePlay.h"

int main() {
    std::string command;
//    std::cout << "Would you like to start a new game a load existed?\n";
//    std::cout << "Write 'LOAD' to load game or anything else to start new one\n";
//    std::cin >> command;
    Hero hero("no one", 1, 1, 1, 1);
    bool lost = true;
    bool win = false;
    long long time = 0;
    int revive = 0;
    int current_cave_level = 1;
    int count = 0;
//    if(command == "LOAD"){
//        std::cout << "Available slots: 3\n";
//        for (int i = 0; i < 3; ++i) {
//            if(save_numbers[i][0] == 0){
//                std::cout << "Slot " << i + 1 << " is empty\n";
//            }
//            else{
//                std::cout << "Slot " << i + 1 << ":\n" << backup[i].hero_info();
//                count++;
//            }
//        }
//        if(count == 0){
//            std::cout << "There are not any existed games\n";
//        }
//        else{
//            std::cout << "Choose Slot or you will start new game (Write 1, 2 or 3)";
//
//            std::cin >> command;
//            if(command =)
//        }
//    }
    if (count == 0){
        std::cout << "Welcome, write your name\n";
        std::cout << "--------------------------------------------\n";
        std::string name;
        std::cin >> name;
        std::cout << "Hello " << name
                  << " Choose your class, each class have own base stats, that will scale upon game\n";
        std::cout << "--------------------------------------------\n";
        bool chosen = true;
        while (chosen) {
            std::cout << "Available classes: Mage, Warrior, Rogue, Witcher, Berserk, Archer\n";
            std::cout << "Write class name to choose or see base stats\n";
            std::cout << "--------------------------------------------\n";
            std::cin >> command;
            if (command == "Mage") {
                std::cout << Mage.base_stats();
                std::cout << "--------------------------------------------\n";
                std::cout << "Write YES to choose Mage and anything else to return\n";
                std::cout << "--------------------------------------------\n";
                std::cin >> command;
                if (command == "YES") {
                    hero = Mage;
                    hero.name = name;
                    chosen = false;
                }
            } else if (command == "Warrior") {
                std::cout << Warrior.base_stats();
                std::cout << "--------------------------------------------\n";
                std::cout << "Write YES to choose Warrior and anything else to return\n";
                std::cout << "--------------------------------------------\n";
                std::cin >> command;
                if (command == "YES") {
                    hero = Warrior;
                    hero.name = name;
                    chosen = false;
                }
            } else if (command == "Rogue") {
                std::cout << Rogue.base_stats();
                std::cout << "--------------------------------------------\n";
                std::cout << "Write YES to choose Rogue and anything else to return\n";
                std::cout << "--------------------------------------------\n";
                std::cin >> command;
                if (command == "YES") {
                    hero = Rogue;
                    hero.name = name;
                    chosen = false;
                }
            } else if (command == "Witcher") {
                std::cout << Witcher.base_stats();
                std::cout << "--------------------------------------------\n";
                std::cout << "Write YES to choose Witcher and anything else to return\n";
                std::cout << "--------------------------------------------\n";
                std::cin >> command;
                if (command == "YES") {
                    hero = Witcher;
                    hero.name = name;
                    chosen = false;
                }
            } else if (command == "Berserk") {
                std::cout << Berserk.base_stats();
                std::cout << "--------------------------------------------\n";
                std::cout << "Write YES to choose Berserk and anything else to return\n";
                std::cout << "--------------------------------------------\n";
                std::cin >> command;
                if (command == "YES") {
                    hero = Berserk;
                    hero.name = name;
                    chosen = false;
                }
            } else if (command == "Archer") {
                std::cout << Archer.base_stats();
                std::cout << "--------------------------------------------\n";
                std::cout << "Write YES to choose Archer and anything else to return\n";
                std::cout << "--------------------------------------------\n";
                std::cin >> command;
                if (command == "YES") {
                    hero = Archer;
                    hero.name = name;
                    chosen = false;
                }
            }
        }
    }
    std::cout << "If you are a new player, you need to go to the Library to understand(hope you will) what is going on\n";
    while (hero.alive){
        std::cout << "--------------------------------------------\n";
        levelup(&hero);
        std::cout << "You are in the Castle now\n";
        std::cout << "Write command or location where to go\n" << "Available locations: Cave Training Forge Shop Library\nAvailable commands: Info Stats Equipment_Info End_Game\n";
        std::cout << "--------------------------------------------\n";
        std::cin >> command;
        std::cout << "--------------------------------------------\n";
        if(command == "Cave"){
            std::cout << "Choose your chapter, your current max possible chapter is " << current_cave_level << "\n";
            std::cout << "--------------------------------------------\n";
            int chap = 1;
            bool flag = true;
            while (flag){
                std::cin >> command;
                if(command == "1"){
                    flag = false;
                    chap = 1;
                }
                else if(command == "2" and current_cave_level > 1){
                    flag = false;
                    chap = 2;
                }
                else if(command == "3" and current_cave_level > 2){
                    flag = false;
                    chap = 3;
                }
                else if(command == "4" and current_cave_level > 3){
                    flag = false;
                    chap = 4;
                }
                else if(command == "5" and current_cave_level > 4){
                    flag = false;
                    chap = 5;
                }
                else {
                    std::cout << "Wrong Chapter, try again \n";
                }
                std::cout << "--------------------------------------------\n";
            }
            Location loc = Chapters[chap - 1];
            generate_location(&loc);
            time += battle(&hero, &loc);
            if(not hero.alive){
                std::cout << "Do you want to revive? (Yes or No) \n";
                std::cout << "--------------------------------------------\n";
                bool flag = true;
                while(flag){
                    std::cin >> command;
                    if(command == "Yes"){
                        hero.alive = true;
                        flag = false;
                        revive += 1;
                    }
                    else if(command == "No"){
                        flag = false;
                    }
                    else{
                        std::cout << "Wrong answer, try again\n";
                        std::cout << "--------------------------------------------\n";
                    }
                }
            }
            else{
                if(current_cave_level < 5 and not win){
                    current_cave_level = std::max(chap + 1, current_cave_level);
                }
                else if(chap == 5){
                    std::cout << "You defeat Eternal Dragon\nDo you want to continue? (type YES or anything else for NO)\n";
                    std::cout << "--------------------------------------------\n";
                    std::cin >> command;
                    win = true;
                    if(command != "YES"){
                        break;
                        lost = false;
                    }
                }
            }
        }
        else if(command == "Info"){
            std::cout << hero.hero_info();
        }
        else if(command == "Stats"){
            std::cout << "Health: " << hlth(&hero) << "\n";
            std::cout << "Mana: " << mn(&hero) << "\n";
            std::cout << "Physical damage: " << physdmg(&hero) << "\n";
            std::cout << "Spell damage: " << spldmg(&hero) << "\n";
            std::cout << "Evasion: "  << evd(&hero) << "\n";
            std::cout << "Attack rate: " << atk(&hero) + 100 << "\n";
            std::cout << "Health regeneration: " << hlthrgn(&hero) << "\n";
            std::cout << "Mana regeneration: " << mnrgn(&hero) << "\n";
            std::cout << "--------------------------------------------\n";
        }
        else if(command == "Equipment_Info"){
            std::cout << "Choose equipment type: Helm, Armor, Boots, Weapon, Talisman\n";
            std::cout << "--------------------------------------------\n";
            bool flag = true;
            while(flag){
                std::cin >> command;
                if(command == "Helm"){
                    flag = false;
                    std::cout << hero.Helm.info() << "\n";
                    hero.Helm.Stats();
                }
                else if(command == "Armor"){
                    flag = false;
                    std::cout << hero.Armor.info() << "\n";
                    hero.Armor.Stats();
                }
                else if(command == "Boots"){
                    flag = false;
                    std::cout << hero.Boots.info() << "\n";
                    hero.Boots.Stats();
                }
                else if(command == "Weapon"){
                    flag = false;
                    std::cout << hero.Weapon.info() << "\n";
                    hero.Weapon.Stats();
                }
                else if(command == "Talisman"){
                    flag = false;
                    std::cout << hero.Talisman.info() << "\n";
                    hero.Talisman.Stats();
                }
                else{
                    std::cout << "Wrong type, try again\n";
                }
                std::cout << "--------------------------------------------\n";
            }
        }
        else if(command == "Training"){
            time += train(&hero);
        }
        else if(command == "End_Game"){
            lost = false;
            break;
        }
        else if(command == "Forge"){
            time += forge(&hero);
        }
        else if(command == "Library"){
            time += library();
        }
        else if(command == "Shop"){
            time += shop(&hero);
        }
        else{
            std::cout << "This is not a command \nTry again \n";
        }
    }
    std::cout << time << "\n";
    if(lost) {
        std::cout << "Life is unfair. You are dead." << "\n";
        std::cout << "--------------------------------------------\n";
    }
    else{
        std::cout << "You are alive\n";
        std::cout << "--------------------------------------------\n";
    }
    score(time, &hero, current_cave_level + int(win), revive);
    std::cout << "Write something to end\n";
    std::cin >> command;
}
