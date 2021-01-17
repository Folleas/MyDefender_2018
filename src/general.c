/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** General functions used by the game
*/

#include "my_defender.h"

void draw_sprites(sfRenderWindow *window, game_object *objects)
{
    for (int i = 0 ; objects[i].sprite != NULL; i++) {
        sfRenderWindow_drawSprite(window, objects[i].sprite, NULL);
    }
}

sfVector2i search_for_s(char **map)
{
    for (int i = 0; i != 6; i++) {
        for (int j = 0; j != 8; j++) {
            if (map[i][j] == '[')
                return ((sfVector2i){j, i});
        }
    }
    return ((sfVector2i){0, 0});
}

game_t switch_stat_tower(game_t game)
{
    switch (game.cursor.status) {
        case T1 :
            game.towers.t1[game.towers.nb_t1].x = game.cursor.pos.x;
            game.towers.t1[game.towers.nb_t1++].y = game.cursor.pos.y;
            break;
        case T2 :
            game.towers.t2[game.towers.nb_t2].x = game.cursor.pos.x;
            game.towers.t2[game.towers.nb_t2++].y = game.cursor.pos.y;
            break;
        case T3 :
            game.towers.t3[game.towers.nb_t3].x = game.cursor.pos.x;
            game.towers.t3[game.towers.nb_t3++].y = game.cursor.pos.y;
            break;
        case T4 :
            game.towers.t4[game.towers.nb_t4].x = game.cursor.pos.x;
            game.towers.t4[game.towers.nb_t4++].y = game.cursor.pos.y;
            break;
    }
    return (game);
}

char *read_map()
{
    char *filepath = "include/map.txt";
    int fd;
    char *buffer = malloc(sizeof(char) * 55);
    int nbyte;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return ("error");
    nbyte = read(fd, buffer, 55);
    if (nbyte == -1)
        return ("error");
    return (buffer);
}

char **create_map()
{
    char *map_line = read_map();
    char **map;
    int j = 0;

    map = malloc(sizeof(char *) * 7);
    map[6] = NULL;
    for (int i = 0; i != 6; i++) {
        map[i] = malloc(sizeof(char) * 9);
        map[i][8] = '\0';
        for (int k = 0; k != 8; k++)
            map[i][k] = map_line[j++];
        j++;
    }
    return (map);
}
