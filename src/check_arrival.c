/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** destroy_planes
*/

#include "../includes/my_radar.h"

void check_arrival(game *gm)
{
    gm->arrived_planes = 0;
    for (int i = 0; i < gm->countA; i++) {
        sfVector2f pos = sfRectangleShape_getPosition(gm->plane[i]->hitbox);
        if (fabs(gm->plane[i]->arv.x - pos.x) <= 10 &&
        fabs(gm->plane[i]->arv.y - pos.y) <= 10) {
            gm->plane[i]->flying = CRASHED;
        }
        if (gm->plane[i]->flying == CRASHED) {
            gm->arrived_planes += 1;
        }
    }
}

void check_all_planes_arrived(game *gm)
{
    if (gm->arrived_planes == gm->countA)
        sfRenderWindow_close(gm->window);
}
