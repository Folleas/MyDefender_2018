/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Game's functionment associated functions
*/

#include "my_defender.h"

game_t put_tower(game_t game, sfEvent event, int *status)
{
    if (game.cursor.status != T0 && \
    game.map[game.cursor.pos.y][game.cursor.pos.x] == 'w') {
        if (event.type == sfEvtMouseButtonPressed) {
            game.map[game.cursor.pos.y][game.cursor.pos.x] = \
            game.cursor.status + 32;
            *status = T0;
            game = switch_stat_tower(game);
        }
    }
    return (game);
}

void draw_cursor(cursor_t cursor, sfRenderWindow *window)
{
    if (cursor.status == T0)
        sfRenderWindow_drawSprite(window, \
        cursor.cursor_image[T0].sprite, NULL);
    if (cursor.status == T1)
        sfRenderWindow_drawSprite(window, \
        cursor.cursor_image[T1].sprite, NULL);
    if (cursor.status == T2)
        sfRenderWindow_drawSprite(window, \
        cursor.cursor_image[T2].sprite, NULL);
    if (cursor.status == T3)
        sfRenderWindow_drawSprite(window, \
        cursor.cursor_image[T3].sprite, NULL);
    if (cursor.status == T4)
        sfRenderWindow_drawSprite(window, \
        cursor.cursor_image[T4].sprite, NULL);
}

void draw_game(char **map, game_object *b, sfRenderWindow *window)
{
    for (int i = 0; i != 6; i++) {
        for (int j = 0; j != 8; j++) {
            switch_draw_game(map, b, window, i, j);
        }
    }
}

void draw_game_next(game_object *b, sfRenderWindow *window, \
char **map, sfVector2i pos)
{
    switch (map[pos.y][pos.x]) {
        case T1 + 32 :
            sfSprite_setPosition(b[4].sprite, (sfVector2f){pos.x * 240, pos.y * 180});
            sfRenderWindow_drawSprite(window, b[4].sprite, NULL);
            break;
        case T2 + 32 :
            sfSprite_setPosition(b[5].sprite, (sfVector2f){pos.x * 240, pos.y * 180});
            sfRenderWindow_drawSprite(window, b[5].sprite, NULL);
            break;
        case T3 + 32 :
            sfSprite_setPosition(b[6].sprite, (sfVector2f){pos.x * 240, pos.y * 180});
            sfRenderWindow_drawSprite(window, b[6].sprite, NULL);
            break;
        case T4 + 32 :
            sfSprite_setPosition(b[7].sprite, (sfVector2f){pos.x * 240, pos.y * 180});
            sfRenderWindow_drawSprite(window, b[7].sprite, NULL);
            break;
        default :
            sfSprite_setPosition(b[2].sprite, (sfVector2f){pos.x * 240, pos.y * 180});
            sfRenderWindow_drawSprite(window, b[2].sprite, NULL);
            break;
    }
}

int f_game(sfRenderWindow *window, game_t *game)
{
    int state = GAME;

    sfText_setString((*game).text, int_to_str((*game).money));
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    state = collision_box(sfMouse_getPosition((const sfWindow *)window), \
    (*game).button.buttons[0], (*game).event, state, PAUSE);
    draw_game((*game).map, (*game).background, window);
    *game = manage_cursor(*game, window, (*game).event);
    sfRenderWindow_drawSprite(window, (*game).button.buttons_obj[0].sprite,\
    NULL);
    sfRenderWindow_drawSprite(window, (*game).hud.sprite, NULL);
    (*game) = manage_enemy((*game).clock, *game, window);
    (*game).cursor.pos = find_mousepos_map(sfMouse_getPosition(\
    (const sfWindow *)window), (*game).grid);
    (*game).castel_hp -= manage_damage(game);
    if ((*game).castel_hp <= 0) {
        return (END_GAME);
    }
    sfRenderWindow_drawText(window, (*game).text, NULL);
    return (state);
}