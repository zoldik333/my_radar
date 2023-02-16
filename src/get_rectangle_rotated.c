/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** get_rectangle_rotated
*/

#include "../includes/my_radar.h"

sfBool rectangles_are_colliding(float area)
{
    if (area > AREA_RECTANGLE) {
        return sfFalse;
    }
    return sfTrue;
}

sfVector2f get_corner_points(sfVector2f corner, sfVector2f center, float angle)
{
    sfVector2f rotated_points;
    rotated_points.x = cos(angle) * (corner.x - center.x)
    - sin(angle) * (corner.y - center.y) + center.x;
    rotated_points.y = sin(angle) * (corner.x - center.x)
    + cos(angle) * (corner.y - center.y) + center.y;
    return rotated_points;
}

rectangle *get_rectangle_rotated(sfRectangleShape *hitbox, sfVector2f center,
float angle)
{
    sfVector2f pos = sfRectangleShape_getPosition(hitbox);
    sfVector2f size = sfRectangleShape_getSize(hitbox);
    rectangle *rect = malloc(sizeof(rectangle));
    rect->top_left = (sfVector2f) {pos.x, pos.y};
    rect->top_right = (sfVector2f) {pos.x + size.x, pos.y};
    rect->bot_left = (sfVector2f) {pos.x, pos.y + size.y};
    rect->bot_right = (sfVector2f) {pos.x + size.x, pos.y + size.y};
    return rect;
}
