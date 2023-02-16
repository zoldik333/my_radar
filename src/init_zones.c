/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** init_zones
*/

#include "../includes/my_radar.h"

sfRectangleShape *fill_boxes(zones *corner, sfVector2f rect_pos, int count)
{
    corner->box = sfRectangleShape_create();
    sfRectangleShape_setSize(corner->box, (sfVector2f){BOX_X, BOX_Y});
    sfRectangleShape_setFillColor(corner->box, sfTransparent);
    sfRectangleShape_setOutlineThickness(corner->box, 1.00);
    sfRectangleShape_setOutlineColor(corner->box, (sfColor){200, 200, 0, 100});
    sfRectangleShape_setPosition(corner->box, rect_pos);
    return corner->box;
}

zones **init_zones(zones **corner, int count)
{
    int index = 0;
    sfVector2f rect_position;
    corner = malloc(sizeof(zones *) * (DIV * DIV));
    for (int i = 0; i < DIV; i++) {
        for (int j = 0; j < DIV; j++) {
            corner[index] = malloc(sizeof(zones));
            corner[index]->zone.width = BOX_X;
            corner[index]->zone.height = BOX_Y;
            corner[index]->pos_left = corner[index]->zone.width * j;
            corner[index]->pos_top = corner[index]->zone.height * i;
            corner[index]->zone.left = corner[index]->pos_left;
            corner[index]->zone.top = corner[index]->pos_top;
            rect_position = (sfVector2f){BOX_X * j, BOX_Y * i};
            corner[index]->box = fill_boxes(corner[index], rect_position,
            count);
            index += 1;
        }
    }
    return corner;
}
