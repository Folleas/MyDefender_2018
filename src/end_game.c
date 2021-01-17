/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions that manage the end game
*/

#include "my_defender.h"

void f_end_game(sfRenderWindow *window, game_t game)
{
    game_object end_screen = create_object("res/lost.png", \
    (sfVector2f){1, 1}, (sfVector2f){0, 0});

    sfRenderWindow_drawSprite(window, end_screen.sprite, NULL);
}