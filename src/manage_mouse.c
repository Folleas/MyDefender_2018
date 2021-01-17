/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** manage_mouse.c
*/

#include "my_defender.h"

vector2ti_t fill_grid_stats(sfVector2u window_size)
{
    vector2ti_t grid;
    int size_x = window_size.x / 8;
    int size_y = window_size.y / 6;

    grid.grid_x = malloc(sizeof(int) * 9);
    grid.grid_y = malloc(sizeof(int) * 7);

    for (int i = 0; i != 7; i++) {
        grid.grid_x[i] = i * size_x;
        grid.grid_y[i] = i * size_y;
    }
    grid.grid_x[7] = 7 * size_x;
    grid.grid_x[8] = 8 * size_x;
    return (grid);
}

sfVector2i find_mousepos_map(sfVector2i mouse_inscreen, vector2ti_t grid)
{
    sfVector2i mouse_inmap = {0, 0};

    for (int i = 0; i != 8; i++) {
        if (mouse_inscreen.x >= 0 && mouse_inscreen.x <= 1920) {
            if (mouse_inscreen.x >= grid.grid_x[i] && \
            mouse_inscreen.x < grid.grid_x[i + 1] && i < 8) {
                mouse_inmap.x = i;
                break;
            }
        }
    }
    for (int i = 0; i != 6; i++) {
        if (mouse_inscreen.y >= 0 && mouse_inscreen.y <= 1080) {
            if (mouse_inscreen.y >= grid.grid_y[i] && \
            mouse_inscreen.y < grid.grid_y[i + 1] && i < 6) {
                mouse_inmap.y = i;
                break;
            }
        }
    }
    return (mouse_inmap);
}

game_t manage_cursor(game_t game, sfRenderWindow *window, sfEvent event)
{
    static int status;

    sfVector2i mouse_pos = sfMouse_getPosition((const sfWindow *)window);
    sfRenderWindow_drawSprite(window, \
    game.cursor.cursor_image[T0].sprite, NULL);

    for (int i = 0; i != 5; i++) {
        sfSprite_setPosition(game.cursor.cursor_image[i].sprite, \
        (sfVector2f){mouse_pos.x, mouse_pos.y});
    }
    status = collision_hud(sfMouse_getPosition((const sfWindow*)window), \
    &game, game.cursor.hud_button.buttons[0], status, T1);
    status = collision_hud(sfMouse_getPosition((const sfWindow*)window), \
    &game, game.cursor.hud_button.buttons[1], status, T2);
    status = collision_hud(sfMouse_getPosition((const sfWindow*)window), \
    &game, game.cursor.hud_button.buttons[2], status, T3);
    status = collision_hud(sfMouse_getPosition((const sfWindow*)window), \
    &game, game.cursor.hud_button.buttons[3], status, T4);
    game.cursor.status = status;
    draw_cursor(game.cursor, window);
    game = put_tower(game, event, &status);
    return (game);
}