/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** check_area
*/

#include "../includes/my_radar.h"

sfBool check_point_in_area(sfVector2f hitbox_corner, sfVector2f area_center,
int radius)
{
    float dist_x = hitbox_corner.x - area_center.x;
    float dist_y = hitbox_corner.y - area_center.y;
    return (pow(dist_x, 2) + pow(dist_y, 2) < pow(radius, 2));
}

sfBool check_area_shortten(game *gm, int i, int j)
{
    sfBool boolean = sfFalse;
    rectangle *rect = get_rectangle_rotated_vector(gm->plane[i]->hitbox,
    gm->plane[i]->angle);
    sfVector2f *corner = malloc(sizeof(sfVector2f) * 4);
    corner[0] = rect->top_left;
    corner[1] = rect->top_right;
    corner[2] = rect->bot_left;
    corner[3] = rect->bot_right;
    sfVector2f area_pos = sfCircleShape_getPosition(gm->tower[j]->area);
    sfVector2f area_center = {area_pos.x + gm->tower[j]->radius,
    area_pos.y + gm->tower[j]->radius};
    for (int i = 0; i < 4; i++) {
        if (check_point_in_area(corner[i], area_center,
        gm->tower[j]->radius)) {
            boolean = sfTrue;
        }
    }
    free(corner);
    return boolean;
}

void intern_loop_area(game *gm, int i)
{
    for (int j = 0; j < gm->countT; j++) {
        if (check_area_shortten(gm, i, j) == sfTrue) {
            sfRectangleShape_setOutlineColor(gm->plane[i]->hitbox, sfGreen);
            gm->plane[i]->in_zone = sfTrue;
            return;
        } else {
            sfRectangleShape_setOutlineColor(gm->plane[i]->hitbox, sfRed);
            gm->plane[i]->in_zone = sfFalse;
        }
    }
}

void check_area(game *gm)
{
    for (int i = 0; i < gm->countA; i++) {
        if (gm->plane[i]->flying != PARKED && gm->plane[i]->flying != CRASHED)
            intern_loop_area(gm, i);
    }
}
