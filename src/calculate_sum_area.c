/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** calculate_sum_area
*/

#include "../includes/my_radar.h"

float *calculate_hypothenusis(sfVector2f rect, sfVector2f corner_rect)
{
    float *sides = malloc(sizeof(float) * 3);
    sides[0] = fabs(rect.x - corner_rect.x);
    sides[1] = fabs(rect.y - corner_rect.y);
    sides[2] = sqrtf(pow(sides[0], 2) + pow(sides[1], 2));
    return sides;
}

float calculate_area(float *hyp)
{
    float perimeter = (hyp[0] + hyp[1] + hyp[2]) / 2;
    float area = sqrtf(perimeter * (perimeter - hyp[0]) * (perimeter - hyp[1]) *
    (perimeter - hyp[2]));
    return area;
}

float calculate_sum_area(rectangle *rect_i, sfVector2f corner_rect)
{
    float sum_area = 0;
    float **hyp = malloc(sizeof(float *) * 4);
    sfVector2f *tab_vector = malloc(sizeof(sfVector2f) * 4);
    tab_vector[0] = rect_i->top_left;
    tab_vector[1] = rect_i->top_right;
    tab_vector[2] = rect_i->bot_left;
    tab_vector[3] = rect_i->bot_right;
    for (int i = 0; i < 4; i++) {
        hyp[i] = calculate_hypothenusis(tab_vector[i], corner_rect);
        sum_area += calculate_area(hyp[i]);
        free(hyp[i]);
    }
    free(hyp);
    free(tab_vector);
    return sum_area;
}
