/*
** EPITECH PROJECT, 2022
** bs_my_hunter
** File description:
** set_positions
*/

#include "../includes/my_radar.h"

void set_positions(game *gm)
{
    sfRenderWindow_setFramerateLimit(gm->window, FRAMERATE);
    sfSprite_setPosition(gm->map_s, (sfVector2f){0, 0});
}
