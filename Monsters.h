#include <string>
#include <sstream>
#include "random"
#include "sstream"
#include <ctime>

std::mt19937 RAND(time(nullptr));
class Monster{
private:
    template <typename T>
    std::string toString(T val)
    {
        std::ostringstream oss;
        oss << val;
        return oss.str();
    }
public:
    std::string name = "Murloc";
    int health = 0;
    int evade = 0;
    int attack = 0;
    int damage = 0;
    int money = 0;
    int exp = 0;
    int level = 0;
    int diff = 0;
    bool dead = false;
    Monster(){};
    Monster& operator =(const Monster& other) = default;
    Monster(const int levelin, std::string inname, int diffin){
        name = inname;
        level = levelin;
        diff = diffin;
    }
    void rebuild(){
        dead = false;
        int sum = 4 * level;
        int ran = RAND() % (2 * level);
        health += 50 * (level + ran) * diff;
        sum -= ran;
        ran = RAND() % (std::min(sum, 2 * level));
        evade += 8 * (level + ran) * diff;
        sum -= ran;
        ran = RAND() % (std::min(sum, 2 * level));
        attack += 8 * (level + ran) * diff;
        sum -= ran;
        damage += 5 * (level + sum) * diff;
        money = (level * 15 + RAND() % 15) * diff;
        exp = (level * 15 + RAND() % 10) * diff;
    }
    std::string info(){
        std::string out = "";
        out += name + "\n";
        out += "Health: " + toString(health) + "\n";
        out += "Damage: " + toString(damage) + "\n";
        out += "Evasion: " + toString(evade) + "\n";
        out += "Attack rate: " + toString(attack + 100) + "\n";
        return out;
    }
};