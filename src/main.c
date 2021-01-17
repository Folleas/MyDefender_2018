/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** Main file
*/

#include "my_defender.h"

int main(void)
{
    menu_t menu;
    game_t game;
    pause_t pause;
    sfRenderWindow *window;

    init_window(&window, "My_defender", 1920, 1080);
    menu = init_menu();
    game = init_game(window);
    pause = init_pause();
    loop(menu, game, pause, window);
    return (0);
}