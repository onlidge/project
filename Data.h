#include "Locations.h"
#include "Heroes.h"

static Hero Mage("Mage", 200, 150, 50, 100);
static Hero Warrior("Warrior", 600, 30, 100, 50);
static Hero Berserk("Berserk", 150, 60, 200, 50);
static Hero Witcher("Witcher", 300, 60, 50, 100);
static Hero Rogue("Rogue", 50, 200, 200, 200);
static Hero Archer("Archer", 200, 90, 150, 50);

static Monster Chap_1_Stage_1[3]{Monster(1, "Goblin", 1), Monster(1, "Goblin", 1), Monster(1, "Goblin", 1)};
static Monster Chap_1_Stage_2[3]{Monster(2, "Elite Goblin", 1), Monster(1, "Goblin", 1), Monster(2, "Elite Goblin", 1)};
static Monster Chap_1_Stage_3[3]{Monster(2, "Elite Goblin", 1), Monster(3, "Goblin King", 1), Monster(1, "Elite Goblin", 1)};
static Monster Chap_2_Stage_1[3]{Monster(2, "Beast", 1), Monster(2, "Beast", 1), Monster(2, "Beast", 1)};
static Monster Chap_2_Stage_2[3]{Monster(3, "Elite Beast", 1), Monster(2, "Beast", 1), Monster(3, "Beast", 1)};
static Monster Chap_2_Stage_3[3]{Monster(3, "Elite Beast", 1), Monster(4, "Beast King", 1), Monster(3, "Elite Beast", 1)};
static Monster Chap_3_Stage_1[3]{Monster(3, "Zombie", 1), Monster(3, "Zombie", 1), Monster(3, "Zombie", 1)};
static Monster Chap_3_Stage_2[3]{Monster(4, "Elite Zombie", 1), Monster(3, "Zombie", 1), Monster(4, "Elite Zombie", 1)};
static Monster Chap_3_Stage_3[3]{Monster(4, "Elite Zombie", 1), Monster(5, "Zombie King", 1), Monster(4, "Elite Zombie", 1)};
static Monster Chap_4_Stage_1[3]{Monster(4, "Orc", 1), Monster(4, "Orc", 1), Monster(4, "Orc", 1)};
static Monster Chap_4_Stage_2[3]{Monster(5, "Elite Orc", 1), Monster(4, "Orc", 1), Monster(5, "Elite Orc", 1)};
static Monster Chap_4_Stage_3[3]{Monster(5, "Elite Orc", 1), Monster(6, "Orc King", 1), Monster(5, "Elite Orc", 1)};
static Monster Chap_5_Stage_1[3]{Monster(5, "Dragon", 1), Monster(5, "Dragon", 1), Monster(5, "Dragon", 1)};
static Monster Chap_5_Stage_2[3]{Monster(6, "Elite Dragon", 1), Monster(5, "Dragon", 1), Monster(6, "Elite Dragon", 1)};
static Monster Chap_5_Stage_3[3]{Monster(6, "Elite Dragon", 1), Monster(7, "Dragon Prince", 1), Monster(6, "Elite Dragon", 1)};
static Monster Chap_5_Stage_4[3]{Monster(7, "Dragon Prince", 1), Monster(8, "Eternal Dragon", 1), Monster(7, "Dragon Prince", 1)};

static Monster Chapter_1[3][3] = {{Monster(1, "Goblin", 1), Monster(2, "Goblin", 1), Monster(1, "Goblin", 1)},
                                  {Monster(2, "Goblin", 1), Monster(3, "Elite Goblin", 1), Monster(2, "Goblin", 1)},
                                  {Monster(3, "Elite Goblin", 1), Monster(4, "Goblin King", 1), Monster(3, "Elite Goblin", 1)}
};
static Monster Chapter_2[3][3] = {{Monster(3, "Beast", 1), Monster(4, "Beast", 1), Monster(3, "Beast", 1)},
                                  {Monster(5, "Elite Beast", 1), Monster(4, "Beast", 1), Monster(5, "Beast", 1)},
                                  {Monster(5, "Elite Beast", 1), Monster(7, "Beast King", 1), Monster(5, "Elite Beast", 1)}
};
static Monster Chapter_3[3][3] = {{Monster(5, "Zombie", 1), Monster(6, "Zombie", 1), Monster(5, "Zombie", 1)},
                                  {Monster(7, "Elite Zombie", 1), Monster(6, "Zombie", 1), Monster(7, "Elite Zombie", 1)},
                                  {Monster(7, "Elite Zombie", 1), Monster(10, "Zombie King", 1), Monster(7, "Elite Zombie", 1)}
};
static Monster Chapter_4[3][3] = {{Monster(7, "Orc", 1), Monster(8, "Orc", 1), Monster(7, "Orc", 1)},
                                  {Monster(9, "Elite Orc", 1), Monster(8, "Orc", 1), Monster(9, "Elite Orc", 1)},
                                  {Monster(9, "Elite Orc", 1), Monster(13, "Orc King", 1), Monster(9, "Elite Orc", 1)}
};
static Monster Chapter_5[4][3] = {{Monster(9, "Dragon", 1), Monster(10, "Dragon", 1), Monster(9, "Dragon", 1)},
                                  {Monster(11, "Elite Dragon", 1), Monster(10, "Dragon", 1), Monster(11, "Elite Dragon", 1)},
                                  {Monster(11, "Elite Dragon", 1), Monster(16, "Dragon Prince", 1), Monster(11, "Elite Dragon", 1)},
                                  {Monster(16, "Dragon Prince", 1), Monster(23, "Eternal Dragon", 1), Monster(16, "Dragon Prince", 1)}
};

static Location Chapters[5]{
    Location("First Chapter", 3, Chapter_1, std::vector<int>({0, 0, 0})),
    Location("Second Chapter", 3, Chapter_2, std::vector<int>({0, 1, 1})),
    Location("Third Chapter", 3, Chapter_3, std::vector<int>({1, 1, 2})),
    Location("Fourth Chapter", 3, Chapter_4, std::vector<int>({1, 2, 3})),
    Location("Fifth Chapter", 4, Chapter_5, std::vector<int>({2, 2, 3, 3})),
};