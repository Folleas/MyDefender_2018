/*
** EPITECH PROJECT, 2018
** My_runnre
** File description:
** My_runner's bootstrap
*/

#include "my_defender.h"

game_object create_object(char const *pts, sfVector2f scale, \
sfVector2f position)
{
    game_object object;
    (void)scale;

    object.texture = sfTexture_createFromFile(pts, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setPosition(object.sprite, position);
    return (object);
}

void destroy_object(game_object obj)
{
    sfTexture_destroy(obj.texture);
    sfSprite_destroy(obj.sprite);
}