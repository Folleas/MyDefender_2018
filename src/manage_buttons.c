/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions used to manage buttons
*/

#include "my_defender.h"

all_button_t create_buttons(int nb, sfVector2i pos)
{
    all_button_t buttons;

    buttons.buttons = malloc(sizeof(buttons_t) * nb);
    buttons.buttons_obj = malloc(sizeof(game_object) * (nb + 1));
    buttons.buttons_obj[nb].sprite = NULL;
    for (int i = 0; i != nb; i++) {
        buttons.buttons[i] = init_button((sfVector2f){pos.x, pos.y + i * 100},\
        (sfVector2f){100, 60});
        buttons.buttons_obj[i] = create_object("res/button.png", \
        (sfVector2f){1, 1}, (sfVector2f){pos.x, pos.y + i * 100});
    }
    return (buttons);
}

all_button_t create_hud_buttons()
{
    all_button_t buttons;

    buttons.buttons = malloc(sizeof(buttons_t) * 4);
    buttons.buttons_obj = malloc(sizeof(game_object) * (4 + 1));
    buttons.buttons_obj[4].sprite = NULL;
    buttons.buttons[0] = init_button((sfVector2f){47, 91}, \
    (sfVector2f){80, 80});
    buttons.buttons_obj[0] = create_object("res/cursorT1.png", \
    (sfVector2f){1, 1}, (sfVector2f){47, 91});
    buttons.buttons[1] = init_button((sfVector2f){203, 91}, \
    (sfVector2f){80, 80});
    buttons.buttons_obj[1] = create_object("res/cursorT2.png", \
    (sfVector2f){1, 1}, (sfVector2f){203, 91});
    buttons.buttons[2] = init_button((sfVector2f){435, 91}, \
    (sfVector2f){80, 80});
    buttons.buttons_obj[2] = create_object("res/cursorT3.png", \
    (sfVector2f){1, 1}, (sfVector2f){435, 91});
    buttons.buttons[3] = init_button((sfVector2f){592, 91}, \
    (sfVector2f){80, 80});
    buttons.buttons_obj[3] = create_object("res/cursorT4.png", \
    (sfVector2f){1, 1}, (sfVector2f){592, 91});
    return (buttons);
}

buttons_t init_button(sfVector2f position, sfVector2f size)
{
    buttons_t button;

    button.rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button.rect, position);
    button.pos = position;
    sfRectangleShape_setScale(button.rect, size);
    button.size = size;
    return (button);
}

int collision_box(sfVector2i crsor_pos, buttons_t button, sfEvent event, \
int actual_state, int to_state)
{
    int state = actual_state;
    sfVector2f cursor_pos;
    cursor_pos.x = crsor_pos.x;
    cursor_pos.y = crsor_pos.y;

    if (cursor_pos.x >= button.pos.x && \
    cursor_pos.x <= button.pos.x + button.size.x) {
        if (cursor_pos.y >= button.pos.y && \
        cursor_pos.y <= button.pos.y + button.size.y) {
            if (event.type == sfEvtMouseButtonPressed)
                state = to_state;
        }
    }
    return (state);
}

int collision_hud(sfVector2i crsor_pos, game_t *game, buttons_t button, \
int from_status, int to_status)
{
    sfVector2f cursor_pos;
    int status = from_status;

    cursor_pos.x = crsor_pos.x;
    cursor_pos.y = crsor_pos.y;
    if (cursor_pos.x >= button.pos.x && \
    cursor_pos.x <= button.pos.x + button.size.x) {
        if (cursor_pos.y >= button.pos.y && \
        cursor_pos.y <= button.pos.y + button.size.y) {
            if ((*game).event.type == sfEvtMouseButtonPressed && \
            (*game).money >= 100) {
                status = to_status;
                (*game).money -= 100;
            }
        }
    }
    return (status);
}