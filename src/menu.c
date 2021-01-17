/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Game's menu associated functions
*/

#include "my_defender.h"

menu_t init_menu()
{
    menu_t menu;

    menu.button = create_buttons(3, (sfVector2i){900, 500});
    menu.background = create_object("res/menu.png", (sfVector2f){1, 1}, \
    (sfVector2f){0, 0});
    return (menu);
}

int switch_menu(sfRenderWindow *window, menu_t menu, sfEvent event, int i)
{
    int state = MENU;
    switch (i) {
        case 0 :
            state = collision_box(sfMouse_getPosition((const sfWindow *)window), \
            menu.button.buttons[i], event, MENU, GAME);
            break;
        case 1 :
            state = collision_box(sfMouse_getPosition((const sfWindow *)window), \
            menu.button.buttons[i], event, MENU, GAME);
            break;
        case 2 :
            state = collision_box(sfMouse_getPosition((const sfWindow *)window), \
            menu.button.buttons[i], event, MENU, QUIT);
            break;
    }
    return (state);
}

int f_menu(sfRenderWindow *window, menu_t menu, sfEvent event)
{
    int state = MENU;

    sfRenderWindow_drawSprite(window, menu.background.sprite, NULL);
    for (int i = 0; i != 3; i++) {
        state = switch_menu(window, menu, event, i);
        draw_sprites(window, menu.button.buttons_obj);
        if (state == QUIT)
            sfRenderWindow_close(window);
        if (state != MENU)
            break;
    }
    return (state);
}