#include "GamePlay.h"
#include <fstream>

std::vector<std::string> levelup_commands{"intelligence", "spellpower", "strength", "agility"};
std::string levelup_greetings = "Your level has increased, you can upgrade your stats\n"
                                "Write stat name to increase it. You can do it 2 times\n";
std::vector<std::string> levelup_answers{"", "", "", ""};

class levelup: public low_level_gameplay{
public:
    levelup(): low_level_gameplay("levelup", levelup_greetings, levelup_commands, levelup_answers, 0){}
    void execute(int number, Hero *hero) override{
        hero->stats[number]++;
        output_text("You have increased " + hero->name_stats[number] + "\n");
        outflag = false;
    }
};

static levelup Levelup;

std::vector<std::string> choose_hero_commands{"mage", "warrior", "berserk", "warlock", "rogue", "archer"};
std::string choose_hero_greetings = "Choose your class, each class have unique ability and own base stats, that will scale upon game\n";
std::vector<std::string> choose_hero_answers{"", "", "", ""};

class choose_hero: public low_level_gameplay{
public:
    choose_hero(): low_level_gameplay("choose_hero", choose_hero_greetings, choose_hero_commands, choose_hero_answers, 2){}
    void execute(int number, Hero *hero) override{
        output_text(classes[number].base_stats());
        output_text(hero->passivki[number]->passive_info());
        output_text("Write YES to choose " + classes[number].name + " and anything else to return\n");
        std::string command = input_command();
        if(command == "yes"){
            hero->health = classes[number].health;
            hero->mana = classes[number].mana;
            hero->phys_damage = classes[number].phys_damage;
            hero->spell_damage = classes[number].spell_damage;
            hero->passivka = hero->passivki[number];
            outflag = false;
        }
    };
};

static choose_hero Chosen;

std::vector<std::string> choose_save_commands{"1", "2", "3", "autosave", "new"};
std::string choose_save_greetings = "Choose your save(from 1 to 3) or start a new game\n";
std::vector<std::string> choose_save_answers{"", "", "", ""};

class choose_save: public low_level_gameplay{
public:
    choose_save(): low_level_gameplay("choose_save", choose_save_greetings, choose_save_commands, choose_save_answers, 1){}
    void execute(int number, Hero *hero) override{
        if(number == commands.size() - 1){
            outflag = false;
        }
        else{
            std::ifstream in;
            in.open("Cave_Adventure_saves.txt");
            std::string line;
            std::getline(in, line);
            if(line != "normal"){
                output_text("There are not any saves\n");
            }
            else{
                for (int i = 0; i < number * 33; ++i) {
                    std::getline(in, line);
                }
                std::getline(in, line);
                if(line != "normal"){
                    output_text("There is not save\n");
                }
                else{
                    outflag = false;
                    std::getline(in, line);
                    hero->name = line;
                    for (int i = 0; i < 4; ++i) {
                        std::getline(in, line);
                        hero->stats[i] = std::stoi(line);
                    }
                    std::getline(in, line);
                    hero->health = std::stoi(line);
                    std::getline(in, line);
                    hero->mana = std::stoi(line);
                    std::getline(in, line);
                    hero->phys_damage = std::stoi(line);
                    std::getline(in, line);
                    hero->spell_damage = std::stoi(line);
                    std::getline(in, line);
                    hero->money = std::stoi(line);
                    std::getline(in, line);
                    hero->exp = std::stoi(line);
                    std::getline(in, line);
                    hero->level = std::stoi(line);
                    std::getline(in, line);
                    hero->level_cap = std::stoi(line);
                    std::getline(in, line);
                    hero->cave = std::stoi(line);
                    std::getline(in, line);
                    hero->revive = std::stoi(line);
                    std::getline(in, line);
                    hero->time = std::stoi(line);
                    for (int i = 0; i < 5; ++i) {
                        std::getline(in, line);
                        hero->Loot[i].type = std::stoi(line);
                        std::getline(in, line);
                        hero->Loot[i].tier = std::stoi(line);
                        std::getline(in, line);
                        hero->Loot[i].rarity = std::stoi(line);
                    }
                    std::getline(in, line);
                    hero->passivka = hero->passivki[std::stoi(line)];
                }
            }
            in.close();
        }
    };
};

choose_save Choose_save;

std::vector<std::string> make_save_commands{"1", "2", "3"};
std::string make_save_greetings = "Choose save slot(from 1 to 3)\n";
std::vector<std::string> make_save_answers{"", "", "", ""};

class make_save: public low_level_gameplay{
public:
    make_save(): low_level_gameplay("make_save", make_save_greetings, make_save_commands, make_save_answers, 1){}
    void execute(int number, Hero *hero) override{
        outflag = false;
        std::string new_save = "normal\n";
        std::ifstream in;
        in.open("Cave_Adventure_saves.txt");
        std::string line;
        std::getline(in, line);
        if(line != "normal"){
            in.close();
            std::ofstream out;
            out.open("Cave_Adventure_saves.txt");
            out << "normal\n";
            for (int i = 0; i < 4; ++i) {
                out << "notnormal\n";
                for (int j = 0; j < 32; ++j) {
                    out << "0\n";
                }
            }
            out.close();
            std::ifstream in;
        }
        in.close();
        in.open("Cave_Adventure_saves.txt");
        std::getline(in, line);
        for (int i = 0; i < number * 33; ++i) {
            std::getline(in, line);
            new_save += line + "\n";
        }
        new_save += "normal\n";
        new_save += hero->name + "\n";
        for (int i = 0; i < 4; ++i) {
            new_save += toString(hero->stats[i]) + "\n";
        }
        new_save += toString(hero->health) + "\n";
        new_save += toString(hero->mana) + "\n";
        new_save += toString(hero->phys_damage) + "\n";
        new_save += toString(hero->spell_damage) + "\n";
        new_save += toString(hero->money) + "\n";
        new_save += toString(hero->exp) + "\n";
        new_save += toString(hero->level) + "\n";
        new_save += toString(int(hero->level_cap)) + "\n";
        new_save += toString(hero->cave) + "\n";
        new_save += toString(hero->revive) + "\n";
        new_save += toString(hero->time) + "\n";
        for (int i = 0; i < 5; ++i) {
            new_save += toString(hero->Loot[i].type) + "\n";
            new_save += toString(hero->Loot[i].tier) + "\n";
            new_save += toString(hero->Loot[i].rarity) + "\n";
        }
        new_save += toString(hero->passivka->number) + "\n";
        for (int i = 0; i < 33; ++i) {
            std::getline(in, line);
        }
        for (int i = 0; i < (3 - number) * 33; ++i) {
            std::getline(in, line);
            new_save += line + "\n";
        }
        in.close();
        std::ofstream out;
        out.open("Cave_Adventure_saves.txt");
        out << new_save;
        out.close();
    }
};

make_save Make_save;

std::vector<low_level_gameplay*> Game_lowcommands{&Cave, &Forge, &Shop, &Library, &Equipment_command, &Make_save, &Levelup};
std::vector<std::string> Game_commands{"cave", "forge", "shop", "library", "equipment", "save", "end_game"};
std::string Game_greetings = "You are in the Castle now\nWrite command or location where to go\n";
std::vector<std::string> Game_answers{"", "", "", ""};
class Game: public high_level_gameplay{
public:
    Game(): high_level_gameplay(Game_lowcommands, "Game", Game_greetings, Game_commands, Game_answers, 2){};
    void execute(int number, Hero *hero) override{
        if(number == commands.size() - 1){
            outflag = false;
        }
        else{
            hero->reload();
            lowcommands[5]->execute(3, hero);
            if(not hero->level_cap and hero->exp >= level_borders[hero->level]){
                output_text("Your level has increased, you can upgrade your stats\n");
                for (int i = 0; i < 2; ++i) {
                    lowcommands[6]->gameplay(hero);
                }
                hero->level++;
                hero->exp -= level_borders[hero->level - 1];
                if(hero->level == maxlevel){
                    hero->level_cap = true;
                }
            }
            lowcommands[number]->gameplay(hero);
            hero->reload();
            post_greetings[0] = hero->hero_info();
            post_greetings[1] = hero->stat_info();
        }
    }
};
