/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** check_collisions
*/

#include "../includes/my_radar.h"

rectangle *get_rectangle_rotated_vector(sfRectangleShape *hitbox, float angle)
{
    sfVector2f pos = sfRectangleShape_getPosition(hitbox);
    sfVector2f size = sfRectangleShape_getSize(hitbox);
    sfVector2f rect_center = {pos.x + size.x / 2, pos.y + size.y / 2};
    rectangle *rect = get_rectangle_rotated(hitbox, rect_center, angle);
    rect->top_left = get_corner_points(rect->top_left, rect_center, angle);
    rect->top_right = get_corner_points(rect->top_right, rect_center, angle);
    rect->bot_left = get_corner_points(rect->bot_left, rect_center, angle);
    rect->bot_right = get_corner_points(rect->bot_right, rect_center, angle);
    return rect;
}

sfBool checking_collisions_inside_loops(game *gm, int i, int j,
rectangle *rect_i)
{
    float area;
    rectangle *rect_j = get_rectangle_rotated_vector(gm->plane[j]->hitbox,
    gm->plane[j]->angle);
    sfVector2f *corner = malloc(sizeof(sfVector2f) * 4);
    corner[0] = rect_j->top_left;
    corner[1] = rect_j->top_right;
    corner[2] = rect_j->bot_left;
    corner[3] = rect_j->bot_right;
    for (int k = 0; k < 4; k++) {
        area = calculate_sum_area(rect_i, corner[k]);
        if (rectangles_are_colliding(area) == sfTrue) {
            gm->plane[i]->flying = CRASHED;
            gm->plane[j]->flying = CRASHED;
            return sfTrue;
        }
        area = 0;
    }
    free(corner);
    return sfFalse;
}

void intern_loop_collisions(game *gm, int i , rectangle *rect_i)
{
    for (int j = 0; j < gm->countA; j++) {
        if (i == j)
            break;
        if (gm->plane[j]->flying == FLYING &&
        gm->plane[j]->in_zone == sfFalse) {
            checking_collisions_inside_loops(gm, i, j, rect_i);
        }
    }
}

void check_collisions(game *gm)
{
    for (int i = 0; i < gm->countA; i++) {
        if (gm->plane[i]->flying == FLYING &&
        gm->plane[i]->in_zone == sfFalse) {
            rectangle *rect_i =
            get_rectangle_rotated_vector(gm->plane[i]->hitbox,
            gm->plane[i]->angle);
            intern_loop_collisions(gm, i, rect_i);
            free(rect_i);
        }
    }
    return;
}
