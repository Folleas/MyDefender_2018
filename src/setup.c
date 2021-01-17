/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions used to setup the game
*/

#include "my_defender.h"

game_object *setup_cursor_image(cursor_t cursor)
{
    cursor.cursor_image = malloc(sizeof(game_object) * 5);
    cursor.cursor_image[T0] = create_object("res/cursor.png", \
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    cursor.cursor_image[T1] = create_object("res/cursorT1.png", \
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    cursor.cursor_image[T2] = create_object("res/cursorT2.png", \
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    cursor.cursor_image[T3] = create_object("res/cursorT3.png", \
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    cursor.cursor_image[T4] = create_object("res/cursorT4.png", \
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    return (cursor.cursor_image);
}

game_object *setup_background()
{
    game_object *background = malloc(sizeof(game_object) * 8);

    background[0] = create_object("res/X.png", (sfVector2f){1, 1}, \
    (sfVector2f){0, 0});
    background[1] = create_object("res/o.png", (sfVector2f){1, 1}, \
    (sfVector2f){240, 0});
    background[2] = create_object("res/P.png", (sfVector2f){1, 1}, \
    (sfVector2f){480, 0});
    background[3] = create_object("res/ends.png", (sfVector2f){1, 1}, \
    (sfVector2f){720, 0});
    background[4] = create_object("res/T1.png", (sfVector2f){1, 1}, \
    (sfVector2f){0, 0});
    background[5] = create_object("res/T2.png", (sfVector2f){1, 1}, \
    (sfVector2f){240, 0});
    background[6] = create_object("res/T3.png", (sfVector2f){1, 1}, \
    (sfVector2f){480, 0});
    background[7] = create_object("res/T4.png", (sfVector2f){1, 1}, \
    (sfVector2f){720, 0});
    return (background);
}

game_t setup_clocks(game_t game)
{
    game.clock = sfClock_create();
    game.clock2 = sfClock_create();
    game.towers.clockt1 = sfClock_create();
    game.towers.clockt2 = sfClock_create();
    game.towers.clockt3 = sfClock_create();
    game.towers.clockt32 = sfClock_create();
    game.towers.clockt4 = sfClock_create();
    return (game);
}

towers_t setup_tower()
{
    towers_t towers;

    towers.nb_t1 = 0;
    towers.nb_t2 = 0;
    towers.nb_t3 = 0;
    towers.nb_t4 = 0;
    towers.t1 = malloc(sizeof(sfVector2f) * 10);
    towers.t2 = malloc(sizeof(sfVector2f) * 10);
    towers.t3 = malloc(sizeof(sfVector2f) * 10);
    towers.t4 = malloc(sizeof(sfVector2f) * 10);
    return (towers);
}