/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions used to move stuff
*/

#include "my_defender.h"

int move_rect(int rect_left)
{
    rect_left += 32;
    if (rect_left >= 252) {
        rect_left = 0;
    }
    return (rect_left);
}

void init_rect(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 28;
    rect->height = 28;
}

ennemie_t *fill_enemy_tab(game_t game, int difficulty_factor)
{
    game.enemy = malloc(sizeof(ennemie_t) * 15);
    for (int i = 0; i != 15; i++) {
        game.enemy[i].position = search_for_s(game.map);
        game.enemy[i].hp = 6 * difficulty_factor;
        game.enemy[i].speed = 1 * ((difficulty_factor * 2) / 10);
        game.enemy[i].enemy_obj = create_object("res/enemy.png", \
        (sfVector2f){1, 1}, (sfVector2f){1, 1});
    }
    return (game.enemy);
}