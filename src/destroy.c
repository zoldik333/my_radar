/*
** EPITECH PROJECT, 2022
** bs_my_radar
** File description:
** destroy
*/
#include "../includes/my_radar.h"

void destroy_planes(game *gm)
{
    for (int i = 0; i < gm->countA; i++) {
        sfSprite_destroy(gm->plane[i]->plane);
        sfRectangleShape_destroy(gm->plane[i]->hitbox);
    }
    free(gm->plane);
    sfTexture_destroy(gm->plane_t);
}

void destroy_towers(game *gm)
{
    for (int i = 0; i < gm->countT; i++) {
        sfSprite_destroy(gm->tower[i]->tower);
        sfCircleShape_destroy(gm->tower[i]->area);
    }
    free(gm->tower);
    sfTexture_destroy(gm->tower_t);
}

void destroy_corner(game *gm)
{
    for (int i = 0; i < DIV * DIV; i++) {
        sfRectangleShape_destroy(gm->corner[i]->box);
    }
    free(gm->corner);
}

void destroy(game *gm)
{
    destroy_planes(gm);
    destroy_towers(gm);
    destroy_corner(gm);
    sfClock_destroy(gm->clock);
    sfClock_destroy(gm->clock_plane);
    sfSprite_destroy(gm->map_s);
    sfTexture_destroy(gm->map_t);
    sfRenderWindow_destroy(gm->window);
    free(gm->parser);
    free(gm);
}
