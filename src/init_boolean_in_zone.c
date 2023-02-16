/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** init_boolean_in_zone
*/

#include "../includes/my_radar.h"

void init_boolean_in_zone(planes **plane, int countA)
{
    for (int i = 0; i < countA; i++) {
        plane[i]->in_zone = sfTrue;
        plane[i]->in_corner = sfFalse;
    }
}
