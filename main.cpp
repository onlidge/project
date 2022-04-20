#include "Game.h"

Game Cave_Adventure;

int main() {
    clearscreen();
    Hero hero("", 1, 1, 1, 1);
    output_text("Welcome, write your name\n");
    hero.name = input_text();
    Chosen.gameplay(&hero);
    hero.reload();
    Cave_Adventure.post_greetings.push_back(hero.hero_info());
    Cave_Adventure.post_greetings.push_back(hero.stat_info());
    Cave_Adventure.gameplay(&hero);
    score(&hero);
    continue_mechanic();
}