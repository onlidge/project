#include "Monsters.h"
#include <vector>

class Location{
public:
    std::string name;
    int amount = 0;
    std::vector<std::vector<Monster>> levels;
    std::vector<int> treasure;
    Location(){};
    Location(std::string inname, int inamount, const Monster (*Chapter)[3], std::vector<int> treasure_input){
        name = inname;
        amount = inamount;
        for (int i = 0; i < amount; ++i) {
            levels.push_back(std::vector<Monster>());
            for (int j = 0; j < 3; ++j) {
                levels[i].push_back(Chapter[i][j]);
            }
        }
        treasure = treasure_input;
    }
    void generate_location(){
        for (int i = 0; i < amount; ++i) {
            for (int j = 0; j < 3; ++j) {
                levels[i][j].rebuild();
            }
        }
    }
};
