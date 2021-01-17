/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Functions used to manage enemies
*/

#include "my_defender.h"

ennemie_t *check_enemy_tab(game_t game, int difficulty_factor)
{
    int count = 0;

    for (int i = 0; i != 15; i++) {
        if (game.enemy[i].hp <= 0) {
            count++;
        }
    }
    if (count == 15) {
        game.enemy = fill_enemy_tab(game, difficulty_factor);
    }
    return (game.enemy);
}

void draw_enemies(game_t game, sfRenderWindow *window)
{
    for (int i = 0; i != 15; i++) {
        sfSprite_setPosition(game.enemy[i].enemy_obj.sprite, \
        (sfVector2f){game.enemy[i].position.x * 240 + 95, \
        game.enemy[i].position.y * 180 + 65});
        sfRenderWindow_drawSprite(window, \
        game.enemy[i].enemy_obj.sprite, NULL);
    }
}

game_t action_enemy(game_t game, int permission, sfTime time2, int i)
{
    if (game.enemy[i].hp > 0 && game.enemy[i].speed != 0 && \
    game.enemy[i].position.x != -50) {
        game.enemy[i] = path_finding(game, i);
    }
    else if (game.enemy[i].hp == 0) {
        game.money += 50;
        game.enemy[i].hp -= 10;
        game.enemy[i].position = (sfVector2i){-50, -50};
    }
    game.enemy = manage_tower_1(game, i);
    game.enemy = manage_tower_2(game, i);
    if (sfTime_asSeconds(time2) > 5) {
        permission = YES;
        time2 = sfClock_restart(game.towers.clockt3);
    }
    game.enemy = manage_tower_3(game, i, &permission);
    game.enemy = check_enemy_tab(game, 1);
    game.enemy = pop_enemy(game);
    return (game);
}

game_t manage_enemy(sfClock *clock, game_t game, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(clock);
    sfTime time2 = sfClock_getElapsedTime(game.towers.clockt3);
    static int permission = NO;

    if (sfTime_asSeconds(time) > 0.5) {
        for (int i = 0; i != 15; i++) {
            manage_animation(&game.enemy[i].enemy_obj.rect.left, \
            &game.enemy[i].enemy_obj);
            game = action_enemy(game, permission, time2, i);
        }
        time = sfClock_restart(clock);
    }
    draw_enemies(game, window);
    return (game);
}

ennemie_t *pop_enemy(game_t game)
{
    static int count = 0;
    sfTime time;

    time = sfClock_getElapsedTime(game.clock2);
    if (sfTime_asSeconds(time) > 1.5) {
            game.enemy[count++].speed = 1;
            if (count == 15)
                count = 0;
            time = sfClock_restart(game.clock2);
    }
    return (game.enemy);


}