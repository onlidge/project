#include "Locations.h"
#include "Heroes.h"

static Hero Mage("Mage", 200, 150, 50, 100);
static Hero Warrior("Warrior", 600, 30, 100, 50);
static Hero Berserk("Berserk", 150, 60, 200, 50);
static Hero Witcher("Witcher", 300, 60, 50, 100);
static Hero Rogue("Rogue", 50, 200, 200, 200);
static Hero Archer("Archer", 200, 90, 150, 50);

static Hero classes[6]{Mage, Warrior, Berserk, Witcher, Rogue, Archer};

static std::string monsters_chapter1[3]{"Goblin", "Elite Goblin", "Goblin King"};
static std::string monsters_chapter2[3]{"Boar", "Grizzly", "Hydra"};
static std::string monsters_chapter3[3]{"Undead", "Ghoul", "Abomination"};
static std::string monsters_chapter4[3]{"Orc", "Red Orc", "Orc Shaman"};
static std::string monsters_chapter5[4]{"Baby Dragon", "Dragon", "Dragon Prince", "Eternal Dragon"};

static Monster Chapter_1[3][3] = {{Monster(1, monsters_chapter1[0], 1), Monster(2, monsters_chapter1[0], 1), Monster(1, monsters_chapter1[0], 1)},
                                  {Monster(2, monsters_chapter1[0], 1), Monster(3, monsters_chapter1[1], 1), Monster(2, monsters_chapter1[0], 1)},
                                  {Monster(3, monsters_chapter1[1], 1), Monster(4, monsters_chapter1[2], 1), Monster(3, monsters_chapter1[1], 1)}
};
static Monster Chapter_2[3][3] = {{Monster(3, monsters_chapter2[0], 1), Monster(4, monsters_chapter2[0], 1), Monster(3, monsters_chapter2[0], 1)},
                                  {Monster(5, monsters_chapter2[1], 1), Monster(4, monsters_chapter2[0], 1), Monster(5, monsters_chapter2[1], 1)},
                                  {Monster(5, monsters_chapter2[1], 1), Monster(7, monsters_chapter2[2], 1), Monster(5, monsters_chapter2[1], 1)}
};
static Monster Chapter_3[3][3] = {{Monster(5, monsters_chapter3[0], 1), Monster(6, monsters_chapter3[0], 1),  Monster(5, monsters_chapter3[0], 1)},
                                  {Monster(7, monsters_chapter3[1], 1), Monster(6, monsters_chapter3[0], 1),  Monster(7, monsters_chapter3[1], 1)},
                                  {Monster(7, monsters_chapter3[1], 1), Monster(10, monsters_chapter3[2], 1), Monster(7, monsters_chapter3[1], 1)}
};
static Monster Chapter_4[3][3] = {{Monster(7, monsters_chapter4[0], 1), Monster(8, monsters_chapter4[0], 1),  Monster(7, monsters_chapter4[0], 1)},
                                  {Monster(9, monsters_chapter4[1], 1), Monster(8, monsters_chapter4[0], 1),  Monster(9, monsters_chapter4[1], 1)},
                                  {Monster(9, monsters_chapter4[1], 1), Monster(13, monsters_chapter4[2], 1), Monster(9, monsters_chapter4[1], 1)}
};
static Monster Chapter_5[4][3] = {{Monster(9, monsters_chapter5[0], 1),  Monster(10, monsters_chapter5[0], 1), Monster(9, monsters_chapter5[0], 1)},
                                  {Monster(11, monsters_chapter5[1], 1), Monster(10, monsters_chapter5[0], 1), Monster(11, monsters_chapter5[1], 1)},
                                  {Monster(11, monsters_chapter5[1], 1), Monster(16, monsters_chapter5[2], 1), Monster(11, monsters_chapter5[1], 1)},
                                  {Monster(16, monsters_chapter5[2], 1), Monster(23, monsters_chapter5[3], 1), Monster(16, monsters_chapter5[2], 1)}
};

static Location Chapters[5]{
    Location("First Chapter", 3, Chapter_1, std::vector<int>({0, 0, 0})),
    Location("Second Chapter", 3, Chapter_2, std::vector<int>({0, 1, 1})),
    Location("Third Chapter", 3, Chapter_3, std::vector<int>({1, 1, 2})),
    Location("Fourth Chapter", 3, Chapter_4, std::vector<int>({1, 2, 3})),
    Location("Fifth Chapter", 4, Chapter_5, std::vector<int>({2, 2, 3, 3})),
};