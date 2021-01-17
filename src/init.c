/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions used to initialize the game
*/

#include "my_defender.h"

void init_window(sfRenderWindow **window, char const *title, \
int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    *window = sfRenderWindow_create(mode, title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

game_t init_game(sfRenderWindow *window)
{
    game_t game;

    game.towers = setup_tower();
    game.cursor.status = T0;
    game.cursor.cursor_image = setup_cursor_image(game.cursor);
    game = setup_clocks(game);
    game.button = create_buttons(1, (sfVector2i){1800, 100});
    game.cursor.hud_button = create_hud_buttons();
    game.background = setup_background();
    game.map = create_map();
    game.hud = create_object("res/HUD.png", (sfVector2f){1, 1},\
    (sfVector2f){0, 0});
    game.enemy = fill_enemy_tab(game, 1);
    game.grid = fill_grid_stats(sfWindow_getSize((const sfWindow *)window));
    game.money = 500;
    game.castel_hp = 10;
    create_string(&game.font, &game.text);
    for (int i = 0; i != 15; i++)
        init_rect(&game.enemy[i].enemy_obj.rect);
    return (game);
}

void create_string(sfFont **font, sfText **text)
{
    *font = sfFont_createFromFile("res/police.ttf");
    *text = sfText_create();
    sfText_setOrigin(*text, (sfVector2f){0, 0});
    sfText_setString(*text, "00000");
    sfText_setFont(*text, *font);
    sfText_setCharacterSize(*text, 30);
}
