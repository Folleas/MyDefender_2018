/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions used to manage towers
*/

#include "my_defender.h"

ennemie_t *manage_tower_1(game_t game, int j)
{
    for (int i = 0; i != game.towers.nb_t1; i++) {
        if (game.towers.t1[i].x == game.enemy[j].position.x && \
        game.towers.t1[i].y + 1 == game.enemy[j].position.y) {
            game.enemy[j].hp -= 2;
        }
        if (game.towers.t1[i].x == game.enemy[j].position.x && \
        game.towers.t1[i].y - 1 == game.enemy[j].position.y) {
            game.enemy[j].hp -= 2;
        }
        if (game.towers.t1[i].x + 1 == game.enemy[j].position.x && \
        game.towers.t1[i].y == game.enemy[j].position.y) {
            game.enemy[j].hp -= 2;
        }
        if (game.towers.t1[i].x - 1 == game.enemy[j].position.x && \
        game.towers.t1[i].y == game.enemy[j].position.y) {
            game.enemy[j].hp -= 2;
        }
    }
    return (game.enemy);
}

ennemie_t *manage_tower_2(game_t game, int j)
{
    for (int i = 0; i != game.towers.nb_t2; i++) {
        if (game.towers.t2[i].x + 1 == game.enemy[j].position.x && \
        game.towers.t2[i].y == game.enemy[j].position.y) {
            game.enemy[j].hp = 0;
        }
        if (game.towers.t2[i].x - 1 == game.enemy[j].position.x && \
        game.towers.t2[i].y == game.enemy[j].position.y) {
            game.enemy[j].hp = 0;
        }
    }
    return (game.enemy);
}

ennemie_t *check_positions_t3(game_t game, int j)
{
    for (int i = 0; i != game.towers.nb_t3; i++) {
        if (game.towers.t3[i].x == game.enemy[j].position.x && \
        game.towers.t3[i].y + 1 == game.enemy[j].position.y)
            game.enemy[j].speed = 0;
        if (game.towers.t3[i].x == game.enemy[j].position.x && \
        game.towers.t3[i].y - 1 == game.enemy[j].position.y)
            game.enemy[j].speed = 0;
        if (game.towers.t3[i].x + 1 == game.enemy[j].position.x && \
        game.towers.t3[i].y == game.enemy[j].position.y)
            game.enemy[j].speed = 0;
        if (game.towers.t3[i].x - 1 == game.enemy[j].position.x && \
        game.towers.t3[i].y == game.enemy[j].position.y)
            game.enemy[j].speed = 0;
        return (game.enemy);
    }
    return(game.enemy);
}

ennemie_t *manage_tower_3(game_t game, int j, int *permission)
{
    sfTime time2;
    time2 = sfClock_getElapsedTime(game.towers.clockt32);

    if (*permission == NO)
        return(game.enemy);
    game.enemy = check_positions_t3(game, j);
    if (sfTime_asSeconds(time2) > 1.5 && game.enemy[j].speed == 0) {
        game.enemy[j].speed = 1;
        time2 = sfClock_restart(game.towers.clockt32);
    }
    *permission = NO;
    return (game.enemy);
}

