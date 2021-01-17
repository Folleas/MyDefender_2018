/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** General functions used by my_defender
*/

#include "my_defender.h"

void switch_draw_game(char **map, game_object *background, \
sfRenderWindow *window, int i, int j)
{
    switch (map[i][j]) {
        case 'X':
            sfSprite_setPosition(background[0].sprite, \
            (sfVector2f){j * 240, i * 180});
            sfRenderWindow_drawSprite(window, background[0].sprite, NULL);
            break;
        case 'w':
            sfSprite_setPosition(background[1].sprite, \
            (sfVector2f){j * 240, i * 180});
            sfRenderWindow_drawSprite(window, background[1].sprite, NULL);
            break;
        case '[' || ']':
            sfSprite_setPosition(background[3].sprite, \
            (sfVector2f){j * 240, i * 180});
            sfRenderWindow_drawSprite(window, background[3].sprite, NULL);
            break;
        default :
            draw_game_next(background, window, map, (sfVector2i){i, j});
    }
}

int manage_damage(game_t *game)
{
    for (int i = 0; i != 15; i++) {
        if ((*game).enemy[i].position.x != -50) {
            if ((*game).map[(*game).enemy[i].position.y] \
            [(*game).enemy[i].position.x + 1] == ']') {
                (*game).enemy[i].position = (sfVector2i){-50, -50};
                return (1);
            }
        }
    }
    return (0);
}

ennemie_t path_finding(game_t game, int i)
{
    if (game.map[game.enemy[i].position.y][game.enemy[i].position.x + 1] == \
    game.map[game.enemy[i].position.y][game.enemy[i].position.x] + 1 || \
    game.map[game.enemy[i].position.y][game.enemy[i].position.x + 1] ==  \
    'a') {
        game.enemy[i].position.x += 1;
    }
    else if (game.map[game.enemy[i].position.y - 1][game.enemy[i].position.x] == \
    game.map[game.enemy[i].position.y][game.enemy[i].position.x] + 1 || \
    game.map[game.enemy[i].position.y - 1][game.enemy[i].position.x] ==  \
    'a') {
        game.enemy[i].position.y -= 1;
    }
    else if (game.map[game.enemy[i].position.y + 1][game.enemy[i].position.x] == \
    game.map[game.enemy[i].position.y][game.enemy[i].position.x] + 1 || \
    game.map[game.enemy[i].position.y + 1][game.enemy[i].position.x] ==  \
    'a') {
        game.enemy[i].position.y += 1;
    }
    return (game.enemy[i]);
}

char *int_to_str(int nbr)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    int count = 0;

    str[5] = '\0';
    for (int i = 10000; i != 0; i /= 10) {
        str[count] = nbr / i + '0';
        nbr %= i;
        count += 1;
    }
    return (str);
}

void manage_animation(int *rect_left, game_object *animated)
{
    *rect_left = move_rect(*rect_left);
    sfSprite_setTextureRect(animated->sprite, animated->rect);
}

