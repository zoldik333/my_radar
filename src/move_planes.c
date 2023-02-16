/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** move_sprites
*/

#include "../includes/my_radar.h"

void move_planes(game *gm)
{
    double tmp; int sign_x; int sign_y;
    for (int i = 0; i < gm->countA; i++) {
        if (gm->plane[i]->flying == FLYING) {
            sign_x = (gm->plane[i]->arv.x - gm->plane[i]->dep.x > 0) ? 1 : -1;
            sign_y = (gm->plane[i]->arv.y - gm->plane[i]->dep.y > 0) ? 1 : -1;
            sfSprite_move(gm->plane[i]->plane, gm->plane[i]->move);
            sfRectangleShape_move(gm->plane[i]->hitbox, gm->plane[i]->move);
        }
    }
}
