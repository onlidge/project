#include "Interface.h"
#include "Data.h"

void change_equip(Hero *hero, Equipment new_equip){
    std::string command;
    int type = new_equip.type - 1;
    for (int i = type; i > 3; i = i - 2) {
        type--;
    }
    output_text("Now you have " + hero->Loot[type].info() + " and " + new_equip.info() + ".\n");
    output_text("Write 'Sell' if you want to sell first equipment and own another, or write anything else to do the opposite.\n");
    command = input_command();
    if (command == "sell") {
        hero->money += hero->Loot[type].cost();
        output_text("You earned " + toString(hero->Loot[type].cost()) + " gold\n");
        if (hero->Loot[type].rarity == 3) {
            hero->change(-hero->Loot[type].tier);
        }
        if (new_equip.rarity == 3) {
            hero->change(new_equip.tier);
        }
        hero->Loot[type] = new_equip;
    } else {
        hero->money += new_equip.cost();
        output_text("You earned " + toString(new_equip.cost()) + " gold\n");
    }
}

class low_level_gameplay{
protected:
    std::vector<std::string> commands;
    std::vector<std::string> answers;
    std::string greetings = "";
    std::string name = "";
    bool outflag;
    int clearscr;
public:
    std::vector<std::string> post_greetings;
    virtual ~low_level_gameplay() {}
    virtual void execute(int number, Hero *hero) = 0;
    low_level_gameplay() = default;
    low_level_gameplay(std::string inname, std::string inout, std::vector<std::string> incommands, std::vector<std::string> inanswers, int clr){
        greetings = inout;
        name = inname;
        commands = incommands;
        answers = inanswers;
        clearscr = clr;
    }
    std::string available(){
        std::string out = "Available: ";
        for (int i = 0; i < commands.size(); ++i) {
            out += commands[i] + " ";
        }
        out += "\n";
        return out;
    }
    int gameplay(Hero *hero){
        outflag = true;
        if(clearscr == 1){
            clearscreen();
        }
        int number = commands.size();
        while(outflag){
            number = commands.size();
            if(clearscr == 2){
                clearscreen();
            }
            output_text(greetings);
            for (int i = 0; i < post_greetings.size(); ++i) {
                output_text(post_greetings[i]);
            }
            output_text(available());
            std::string command = input_command();
            for (int i = 0; i < number; ++i) {
                if(command == commands[i]){
                    number = i;
                    break;
                }
            }
            if(number == commands.size()){
                output_text("Wrong command\n");
                continue;
            }
            execute(number, hero);
        }
        return number;
    }
};

std::vector<std::string> library_commands{"battle", "equipment", "stats", "game", "exit"};
std::string library_greetings = "Welcome to the Library\n"
                                "You can find information about this game here\n";
std::vector<std::string> library_answers{
    "There is 5 Chapters. Chapter has cave levels with 3 monsters in each.\n"
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
    "Each level you have to defeat monsters\n",
    "There are 5 types of equipment. Helmet, Armor, Boots, Weapon and Talisman\n"
    "Also, the Weapon is divided into the Staff and the Sword, and the Talisman into the Spell Talisman and the Physical Talisman.\n"
    "Each type specializes in a certain type of damage.\n"
    "Each item can be of a certain rarity: None, Rare, Epic, or Legendary.\n"
    "Rarity increases the number of bonuses.\n"
    "Equipment also has forging, each level of forging increases equipment bonuses.\n"
    "So far, there are 3 levels of forging: +0, +1 and +2.\n",
    "You have 4 stats: Intelligence, Agility, Strength and Spell Power.\n"
    "Each level you will be offered 2 times to increase one of the stats.\n"
    "Stat gives bonuses depending on the basic characteristics.\n"
    "What each stat affects:\n"
    "Strength - each stat gives +20% of base health and +20% of base physical damage.\n"
    "Spell Power - each stat grants +20% base mana and +20% base spell damage.\n"
    "Agility - each stat gives +15% evasion and +5% attack rate, as well as +4 health regeneration per turn.\n"
    "Intelligence - each stat gives +5% evasion and +15% attack rate, as well as +4 mana regeneration per turn.\n",
    "The goal of the game is to score as many points as possible.\n"
    "You get points for each new chapter completed, equipment by the end of the game, hero level, as well as for some other achievements.\n"
    "You are deducted points for the number of revivals, as well as for the time that the in-game character spent.\n"
    "Time increases every turn of battle or during training.\n"
    "In addition to the goal to score points, there is also a goal to complete all the chapters and defeat the Eternal Dragon.\n",
};


class library: public low_level_gameplay{
public:
    library(): low_level_gameplay("library", library_greetings, library_commands, library_answers, 1){}
    void execute(int number, Hero *hero) override{
        output_text(answers[number]);
        if(number == commands.size() - 1){
            outflag = false;
        }
    }
};

static library Library;

std::vector<std::string> shop_commands{"rare", "epic", "legendary", "exit"};
std::string shop_greetings = "Welcome to the shop\n"
                             "You can buy chests and obtain new equipment here\n"
                             "Rare Chest: 500 gold\n"
                             "Epic Chest: 1250 gold\n"
                             "Legendary Chest: 2750 gold\n";
std::vector<std::string> shop_answers{"", "", "", ""};

class shop: public low_level_gameplay{
public:
    shop(): low_level_gameplay("shop", shop_greetings, shop_commands, shop_answers, 1){}
    void execute(int number, Hero *hero) override{
        if(number == commands.size() - 1){
            outflag = false;
        }
        else if(hero->money >= 250 * ((1 << (number + 2)) - (1 << number) - 1)){
            hero->money -= 250 * ((1 << (number + 2)) - (1 << number) - 1);
            int first = RAND() % 100;
            int second = RAND() % 100;
            int rarity = number;
            int tier = 1;
            if(first > 89){
                rarity += 2;
            }
            else if(first > 54 + 10 * (number > 1)){
                rarity += 1;
            }
            if(second > 89){
                tier += 2;
            }
            else if(second > 54){
                tier += 1;
            }
            Equipment new_equip = generate_treasure(std::min(rarity, 3), tier);
            change_equip(hero, new_equip);
        }
        else{
            output_text("You do not have enough money\n");
        }
    }
};

shop Shop;

std::vector<std::string> forge_commands{"helm", "armor", "boots", "weapon", "talisman", "exit"};
std::string forge_greetings = "Welcome to the Forge\n"
                              "You can forge your equipment here\n"
                              "100 gold to forge Common\n"
                              "250 gold to forge Rare\n"
                              "550 gold to forge Epic\n"
                              "1150 gold to forge Legendary\n";
std::vector<std::string> forge_answers{"", "", "", ""};

class forge: public low_level_gameplay{
public:
    forge(): low_level_gameplay("forge", forge_greetings, forge_commands, forge_answers, 1){}
    void execute(int number, Hero *hero) override{
        if(number == commands.size() - 1){
            outflag = false;
        }
        else{
            if(hero->Loot[number].tier == 0){
                output_text("You do not have it\n");
            }
            else if(hero->money < ((3 * (1 << (hero->Loot[number].rarity)) - 1) * 50)){
                output_text("You do not have enough money\n");
            }
            else if(hero->Loot[number].tier == 3){
                output_text("You already have it on max forge(max is +2)\n");
            }
            else {
                hero->Loot[number].tier++;
                if(hero->Loot[number].rarity == 3){
                    hero->change(1);
                }
                hero->money -= (3 * (1 << (hero->Loot[number].rarity)) - 1) * 50;
            }
        }
    }
};

forge Forge;

std::vector<std::string> equipment_commands{"helm", "armor", "boots", "weapon", "talisman", "exit"};
std::string equipment_greetings = "Choose equipment type\n";
std::vector<std::string> equipment_answers{"", "", "", ""};

class equipment: public low_level_gameplay{
public:
    equipment(): low_level_gameplay("equipment", equipment_greetings, equipment_commands, equipment_answers, 1){}
    void execute(int number, Hero *hero) override{
        if(number == commands.size() - 1){
            outflag = false;
        }
        else{
            output_text(hero->Loot[number].info() + "\n");
            output_text(hero->Loot[number].Stats());
        }
    };
};

static equipment Equipment_command;

class high_level_gameplay: public low_level_gameplay{
protected:
    std::vector<low_level_gameplay*> lowcommands;
public:
    high_level_gameplay(std::vector<low_level_gameplay*> inlowcommands, std::string inname, std::string inout, std::vector<std::string> incommands, std::vector<std::string> inanswers, int clr){
        lowcommands = inlowcommands;
        greetings = inout;
        name = inname;
        commands = incommands;
        answers = inanswers;
        clearscr = clr;
    }
};

std::vector<std::string> attack_type_commands{"spell", "phys"};
std::string attack_type_greetings = "Choose damage type, write spell or phys\n";
std::vector<std::string> attack_type_answers{"", "", "", ""};

class attack_type: public low_level_gameplay{
public:
    attack_type(): low_level_gameplay("attack_type", attack_type_greetings, attack_type_commands, attack_type_answers, 0){}
    void execute(int number, Hero *hero) override{
        outflag = false;
    };
};

attack_type Attack_type;

std::vector<std::string> attack_spell_commands{"zero", "one", "two", "three", "ult"};
std::string attack_spell_greetings = "Choose attack type: one (costs 10 mana), two (costs 30 mana), three (costs 70 mana), ult (costs 150 mana) or zero (costs 0 mana)\n";
std::vector<std::string> attack_spell_answers{"", "", "", ""};

class attack_spell: public low_level_gameplay{
public:
    attack_spell(): low_level_gameplay("attack_spell", attack_spell_greetings, attack_spell_commands, attack_spell_answers, 0){}
    void execute(int number, Hero *hero) override{
        if(hero->stat[2] < ((1 << number) - 1) * 10){
            output_text("Not enough mana, try again\n");
        }
        else {
            outflag = false;
            hero->stat[2] -= ((1 << number) - 1) * 10;
        }
    }
};

attack_spell Attack_spell;

std::vector<std::string> attack_target_commands{"1", "2", "3"};
std::string attack_target_greetings = "Choose first target, if your attack type is two or three next target will be to the right (write 1, 2 or 3)\n";
std::vector<std::string> attack_target_answers{"", "", "", ""};

class attack_target: public low_level_gameplay{
public:
    attack_target(): low_level_gameplay("attack_target", attack_target_greetings, attack_target_commands, attack_target_answers, 0){}
    void execute(int number, Hero *hero) override{
        outflag = false;
    };
};

attack_target Attack_target;

std::vector<low_level_gameplay*> battle_lowcommands{&Attack_type, &Attack_spell, &Attack_target};
std::vector<std::string> battle_commands{"1", "2", "3", "4", "5"};
std::string battle_greetings = "Choose your chapter(from 1 to 5)\n";
std::vector<std::string> battle_answers{"", "", "", ""};

class battle: public high_level_gameplay{
    bool Attack(int atk_rate, int evade_rate){
        int rate = evade_rate - atk_rate;
        int ran = RAND() % 100;
        if(rate > ran){
            output_text("attack chance: " + toString(atk_rate + 100) + " - " + toString(evade_rate) + " = " + toString(atk_rate + 100 - evade_rate) + "\n" + "Result: missed\n");
            return false;
        }
        output_text("attack chance: " + toString(atk_rate + 100) + " - " + toString(evade_rate) + " = " + toString(atk_rate + 100 - evade_rate) + "\n" + "Result: damage dealt\n");
        return true;
    }
    Location location_data;
    Location* location;
public:
    battle(): high_level_gameplay(battle_lowcommands, "cave", battle_greetings, battle_commands, battle_answers, 1){}
    void execute(int number, Hero *hero) override{
        if(hero->cave < number + 1){
            output_text("Wrong chapter, your current chapter is " + toString(hero->cave + 1) + "\n");
            output_text("Write something to quit\n");
            std::string command = input_text();
            outflag = false;
        }
        else{
            location_data = Chapters[number];
            location_data.generate_location();
            location = &location_data;
            hero->reload();
            long long time = 0;
            int oldness = 0;
            bool here = true;
            for (int i = 0; i < location->amount; ++i) {
                if(not here){
                    break;
                }
                bool win = true;
                std::string command;
                while(win){
                    clearscreen();
                    output_text("Cave Level: " + toString(i + 1) + "\n");
                    time += 1;
                    hero->stat[2] = std::min(hero->stat[3], hero->stat[2] = hero->stat[9] + hero->stat[2]);
                    hero->stat[0] = std::min(hero->stat[1], hero->stat[0] + hero->stat[8]);
                    bool lost = false;
                    for (int j = 0; j < 3; ++j) {
                        std::cout << j + 1 << ")";
                        if(not location->levels[i][j].dead) {
                            output_text(location->levels[i][j].info());
                            lost = true;
                        }
                        else{
                            output_text(location->levels[i][j].name + " is dead\n");
                        }
                    }
                    if(not lost){
                        break;
                    }
                    output_text(hero->name + ":\n" + hero->stat_info());
                    int type = battle_lowcommands[0]->gameplay(hero);
                    int dmg = hero->stat[5] * (type == 0) + hero->stat[4] * (type == 1);
                    int count = battle_lowcommands[1]->gameplay(hero);
                    if(count == 4){
                        count = 6;
                    }
                    int start = 1;
                    if(count < 3 and count > 0){
                        start += battle_lowcommands[2]->gameplay(hero);
                    }
                    clearscreen();
                    for (int j = start - 1; j < start + count - 1; ++j) {
                        if (not location->levels[i][j % 3].dead) {
                            bool old = true;
                            output_text(hero->name + " is attacking " + location->levels[i][j % 3].name + "\n");
                            if(location->levels[i][j % 3].evade > hero->stat[7] + 85 and oldness % 10 == 0){
                                output_text("Your attack rate is lower than 15%\n"
                                            "Write 'DIE' to die from old age and lose 10 time, or anything else to continue suffering\n");
                                command = input_command();
                                if(command == "die"){
                                    hero->stat[0] = 0;
                                    time += 10;
                                    old = false;
                                }
                                else{
                                    oldness += 1;
                                }
                            }
                            if (old and Attack(hero->stat[7], location->levels[i][j % 3].evade)) {
                                output_text("Monster HP: " + toString(location->levels[i][j % 3].health) + " - " +
                                toString(dmg) + " = " + toString(std::max(location->levels[i][j % 3].health - dmg, 0)) + "\n");
                                location->levels[i][j % 3].health -= dmg;
                                if (location->levels[i][j % 3].health <= 0) {
                                    location->levels[i][j % 3].dead = true;
                                    hero->money += location->levels[i][j % 3].money;
                                    hero->exp += location->levels[i][j % 3].exp;
                                }
                            }
                        }
                    }
                    if(hero->stat[0] <= 0){
                        win = false;
                    }
                    for (int j = 0; j < 3; ++j) {
                        if(not location->levels[i][j].dead) {
                            output_text(location->levels[i][j % 3].name + " is attacking " + hero->name + "\n");
                            if(Attack(location->levels[i][j].attack, hero->stat[6])){
                                output_text("Hero HP: " + toString(hero->stat[0]) + " - " + toString(location->levels[i][j].damage) + " = " +
                                toString(std::max(hero->stat[0] - location->levels[i][j].damage, 0)) + "\n");
                                hero->stat[0] -= location->levels[i][j].damage;
                                if(hero->stat[0] <= 0){
                                    win = false;
                                }
                            }
                        }
                    }
                    continue_mechanic();
                }
                if(not win){
                    output_text("You were killed\n");
                    here = false;
                    hero->revive += 1;
                }
                else{
                    hero->cave = std::max(hero->cave, number + 2);
                    output_text("You won \n");
                    Equipment new_equip = generate_treasure(location->treasure[i], 1 + 2 * (i == 3));
                    output_text("You found " + new_equip.info() + "\n");
                    change_equip(hero, new_equip);
                    if(number == 4){
                        output_text("You have cleared the cave, good job\n");
                    }
                }
            }
            continue_mechanic();
            hero->time += time;
            outflag = false;
        }
    }
};

static battle Cave;

void score(Hero *hero){
    long long time = hero->time;
    int chapter = hero->cave;
    int revive = hero->revive;
    clearscreen();
    long long s = 0;
    output_text("Your ingame time: " + toString(time) + " it is -" + toString(time * 25) + " points\n");
    s -= time * 25;
    output_text("Your Hero level: " + toString(hero->level) + " it is +" + toString((1 << hero->level) * 20) + " points\n");
    s += (1 << hero->level) * 20;
    output_text("Your Helm: " + hero->Loot[0].info() + " it is +" + toString((1 << hero->Loot[0].tier) * (1 << hero->Loot[0].rarity) * 10) + " points\n");
    s += (1 << hero->Loot[0].tier) * (1 << hero->Loot[0].rarity) * 10;
    output_text("Your Armor: " + hero->Loot[1].info() + " it is +" + toString((1 << hero->Loot[1].tier) * (1 << hero->Loot[1].rarity) * 10) + " points\n");
    s += (1 << hero->Loot[1].tier) * (1 << hero->Loot[1].rarity) * 10;
    output_text("Your Boots: " + hero->Loot[2].info() + " it is +" + toString((1 << hero->Loot[2].tier) * (1 << hero->Loot[2].rarity) * 10) + " points\n");
    s += (1 << hero->Loot[2].tier) * (1 << hero->Loot[2].rarity) * 10;
    output_text("Your Weapon: " + hero->Loot[3].info() + " it is +" + toString((1 << hero->Loot[3].tier) * (1 << hero->Loot[3].rarity) * 10) + " points\n");
    s += (1 << hero->Loot[3].tier) * (1 << hero->Loot[3].rarity) * 10;
    output_text("Your Talisman: " + hero->Loot[4].info() + " it is +" + toString((1 << hero->Loot[4].tier) * (1 << hero->Loot[4].rarity) * 10) + " points\n");
    s += (1 << hero->Loot[4].tier) * (1 << hero->Loot[4].rarity) * 10;
    output_text("Your best Chapter is: " + toString(chapter - 1) + " it is +" + toString((1 << chapter) * 200) + " points\n");
    s += (1 << chapter) * 200;
//    std::cout << "Your Stats are: Agility " << hero->Agility << " Strength " << hero->Strength << " Spellpower " << hero->Spellpower << " Intelligence " << hero->stats[0] << " it is +" << (hero->Agility + hero->Strength + hero->Spellpower + hero->stats[0]) * 100 << " points\n";
//    s += (hero->Agility + hero->Strength + hero->Spellpower + hero->stats[0]) * 100;
    output_text("You were revived: " + toString(revive) + " times. It is -" + toString(revive * 100) + " points\n");
    s -= revive * 100;
    output_text("Your Final score is: " + toString(s) + "\n" + "Well done!\n");
}
