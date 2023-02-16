/*
** EPITECH PROJECT, 2022
** bs_my_hunter
** File description:
** draw_sprites
*/

#include "../includes/my_radar.h"

void draw_towers(game *gm, sfRenderWindow *window, towers **tower)
{
    for (int i = 0; i < gm->countT; i++) {
        if (gm->disable_sprites == sfFalse) {
            sfRenderWindow_drawSprite(gm->window, gm->tower[i]->tower, NULL);
        }
        if (gm->disable_hitboxes == sfFalse) {
            sfRenderWindow_drawCircleShape(gm->window,
            gm->tower[i]->area, NULL);
        }
    }
}

void condition_to_draw_planes(game *gm)
{
    for (int i = 0; i < gm->countA; i++) {
        if (gm->seconds >= gm->plane[i]->delay &&
        gm->plane[i]->flying == PARKED) {
            gm->plane[i]->flying = FLYING;
        }
    }
}

void draw_planes(game *gm)
{
    for (int i = 0; i < gm->countA; i++) {
        if (gm->seconds >= gm->plane[i]->delay &&
        gm->plane[i]->flying == FLYING) {
            (gm->disable_sprites == sfFalse) ?
            (sfRenderWindow_drawSprite(gm->window, gm->plane[i]->plane, NULL))
            : 0;
            (gm->disable_hitboxes == sfFalse) ?
            (sfRenderWindow_drawRectangleShape(gm->window, gm->plane[i]->hitbox,
            NULL)) : 0;
        }
    }
}

void draw_corners(sfRenderWindow *window, zones **corner)
{
    int index = 0;
    for (int i = 0; i < DIV * DIV; i++) {
        sfRenderWindow_drawRectangleShape(window, corner[i]->box, NULL);
    }
}

int draw_sprites(game *gm)
{
    sfRenderWindow_clear(gm->window, sfWhite);
    sfRenderWindow_drawSprite(gm->window, gm->map_s, NULL);
    draw_corners(gm->window, gm->corner);
    draw_towers(gm, gm->window, gm->tower);
    condition_to_draw_planes(gm);
    draw_planes(gm);
    if (sfClock_getElapsedTime(gm->clock).microseconds > 1000000.0) {
        gm->seconds += 1;
        sfClock_restart(gm->clock);
    }
    if (sfClock_getElapsedTime(gm->clock_plane).microseconds / 1000000.0 >
    1 / FRAMERATE) {
        move_planes(gm);
        sfClock_restart(gm->clock_plane);
    }
    sfRenderWindow_display(gm->window);
}
