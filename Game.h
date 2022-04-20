#include "GamePlay.h"

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

std::vector<std::string> choose_hero_commands{"mage", "warrior", "berserk", "witcher", "rogue", "archer"};
std::string choose_hero_greetings = "Choose your class, each class have own base stats, that will scale upon game\n";
std::vector<std::string> choose_hero_answers{"", "", "", ""};

class choose_hero: public low_level_gameplay{
public:
    choose_hero(): low_level_gameplay("choose_hero", choose_hero_greetings, choose_hero_commands, choose_hero_answers, 0){}
    void execute(int number, Hero *hero) override{
        output_text(classes[number].base_stats());
        output_text("Write YES to choose " + classes[number].name + " and anything else to return\n");
        std::string command = input_command();
        if(command == "yes"){
            hero->health = classes[number].health;
            hero->mana = classes[number].mana;
            hero->phys_damage = classes[number].phys_damage;
            hero->spell_damage = classes[number].spell_damage;
            outflag = false;
        }
    };
};

static choose_hero Chosen;

std::vector<low_level_gameplay*> Game_lowcommands{&Cave, &Forge, &Shop, &Library, &Equipment_command, &Levelup};
std::vector<std::string> Game_commands{"cave", "forge", "shop", "library", "equipment", "end_game"};
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
            if(not hero->level_cap and hero->exp >= level_borders[hero->level]){
                output_text("Your level has increased, you can upgrade your stats\n");
                for (int i = 0; i < 2; ++i) {
                    lowcommands[5]->gameplay(hero);
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
