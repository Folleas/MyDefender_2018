/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** game's pause associated functions
*/

#include "my_defender.h"

pause_t init_pause()
{
    pause_t pause;

    pause.button = create_buttons(2, (sfVector2i){900, 500});
    pause.background = create_object("res/pause.png", \
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    return (pause);
}

int f_pause(sfRenderWindow *window, pause_t pause, sfEvent event)
{
    int state = PAUSE;

    for (int i = 0; i != 2; i++) {
        if (i == 0)
            state = collision_box(sfMouse_getPosition(\
            (const sfWindow *)window), pause.button.buttons[i],\
            event, PAUSE, GAME);
        if (i == 1)
            state = collision_box(sfMouse_getPosition(\
            (const sfWindow *)window), \
            pause.button.buttons[i], event, PAUSE, MENU);
        sfRenderWindow_drawSprite(window, pause.background.sprite, NULL);
        draw_sprites(window, pause.button.buttons_obj);
        if (state != PAUSE)
            break;
    }
    return (state);
}
