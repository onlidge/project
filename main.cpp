#include "Game.h"

Game Cave_Adventure;

int main() {
    clearscreen();
    Hero hero("", 1, 1, 1, 1);
    if(Choose_save.gameplay(&hero) == 4){;
        clearscreen();
        output_text("Welcome, write your name\n");
        hero.name = input_text();
        Chosen.gameplay(&hero);
        output_text("If you are a new player, you should go to the library.\n"
                    "There is some useful information.\n");
        continue_mechanic();
    }
    hero.reload();
    Cave_Adventure.post_greetings.push_back(hero.hero_info());
    Cave_Adventure.post_greetings.push_back(hero.stat_info());
    Cave_Adventure.post_greetings.push_back(hero.passivka->passive_info());
    Cave_Adventure.gameplay(&hero);
    score(&hero);
    continue_mechanic();
}