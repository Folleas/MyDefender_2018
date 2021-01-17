/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions that manage the main loop
*/

#include "my_defender.h"

void select_scene(sfRenderWindow *window, menu_t menu, \
game_t *game, pause_t pause)
{
    static int state = MENU;

    switch (state) {
        case MENU:
            state = f_menu(window, menu, (*game).event);
            break;
        case GAME:
            state = f_game(window, &(*game));
            break;
        case PAUSE:
            state = f_pause(window, pause, (*game).event);
            break;
        case END_GAME:
            f_end_game(window, (*game));
    }
    return;
}

void loop(menu_t menu, game_t game, pause_t pause, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            sfRenderWindow_clear(window, sfBlack);
        }
        game.event = event;
        select_scene(window, menu, &game, pause);
        sfRenderWindow_display(window);
    }
}