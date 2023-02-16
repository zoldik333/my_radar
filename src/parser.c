/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** parser
*/

#include "../includes/my_radar.h"
#include "../includes/mini_printf.h"

void fill_towers(game *gm, char **tmp, int count, int t)
{
    for (int i = 0; i < count; i++) {
        switch (i) {
            case 1: gm->tower[t]->pos.x = my_getnbr(tmp[i]); break;
            case 2: gm->tower[t]->pos.y = my_getnbr(tmp[i]); break;
            case 3: gm->tower[t]->radius = my_getnbr(tmp[i]); break;
        }
    }
    gm->tower[t]->tower = sfSprite_create();
    sfSprite_setTexture(gm->tower[t]->tower, gm->tower_t, sfTrue);
    sfSprite_setPosition(gm->tower[t]->tower, (sfVector2f){gm->tower[t]->pos.x,
    gm->tower[t]->pos.y});
    gm->tower[t]->area = sfCircleShape_create();
    sfCircleShape_setRadius(gm->tower[t]->area, (float)gm->tower[t]->radius);
    sfCircleShape_setFillColor(gm->tower[t]->area, sfTransparent);
    sfCircleShape_setOutlineThickness(gm->tower[t]->area, 2.00);
    sfCircleShape_setPosition(gm->tower[t]->area, (sfVector2f)
    {gm->tower[t]->pos.x + 15 - (gm->tower[t]->radius),
    gm->tower[t]->pos.y + 15 - (gm->tower[t]->radius)});
    sfCircleShape_setOutlineColor(gm->tower[t]->area, sfYellow);
}

void set_angle(game *gm, int a)
{
    float tan; int supp;
    sfSprite_setOrigin(gm->plane[a]->plane, (sfVector2f){10, 10});
    sfRectangleShape_setOrigin(gm->plane[a]->hitbox, (sfVector2f){10, 10});
    tan = (gm->plane[a]->arv.y - gm->plane[a]->dep.y) /
    (gm->plane[a]->arv.x - gm->plane[a]->dep.x);
    gm->plane[a]->angle = atanf(tan);
    supp = (gm->plane[a]->arv.x < gm->plane[a]->dep.x) ? 180 : 0;
    sfSprite_setRotation(gm->plane[a]->plane, (gm->plane[a]->angle
    * 180 / M_PI + supp));
    sfRectangleShape_setRotation(gm->plane[a]->hitbox,
    gm->plane[a]->angle * 180 / M_PI + supp);
    float move_x = gm->plane[a]->arv.x - gm->plane[a]->dep.x;
    float move_y = gm->plane[a]->arv.y - gm->plane[a]->dep.y;
    float move_sec = (fabs(move_x) > fabs(move_y))
    ? fabs(move_x) : fabs(move_y);
    gm->plane[a]->move = (sfVector2f){move_x / move_sec * gm->plane[a]->speed,
    move_y / move_sec * gm->plane[a]->speed};
}

void fill_planes(game *gm, char **tmp, int count, int a)
{
    for (int i = 0; i < count; i++) {
        switch (i) {
            case 1: gm->plane[a]->dep.x = my_getnbr(tmp[i]); break;
            case 2: gm->plane[a]->dep.y = my_getnbr(tmp[i]); break;
            case 3: gm->plane[a]->arv.x = my_getnbr(tmp[i]); break;
            case 4: gm->plane[a]->arv.y = my_getnbr(tmp[i]); break;
            case 5: gm->plane[a]->speed = my_getnbr(tmp[i]); break;
            case 6: gm->plane[a]->delay = my_getnbr(tmp[i]); break;
            default: break;
        }
    }
    gm->plane[a]->plane = sfSprite_create(); gm->plane[a]->flying = PARKED;
    sfSprite_setTexture(gm->plane[a]->plane, gm->plane_t, sfTrue);
    sfSprite_setPosition(gm->plane[a]->plane, gm->plane[a]->dep);
    gm->plane[a]->hitbox = sfRectangleShape_create(); set_angle(gm, a);
    sfRectangleShape_setSize(gm->plane[a]->hitbox, (sfVector2f){SIZE, SIZE});
    sfRectangleShape_setFillColor(gm->plane[a]->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(gm->plane[a]->hitbox, 1.00);
    sfRectangleShape_setOutlineColor(gm->plane[a]->hitbox, sfGreen);
    sfRectangleShape_setPosition(gm->plane[a]->hitbox, gm->plane[a]->dep);
}

int separate_planes_towers(game *gm)
{
    int count_a = 0; int count_t = 0; char **tmp; int count;
    gm->plane = malloc(sizeof(planes *) * gm->countA);
    gm->tower = malloc(sizeof(towers *) * gm->countT);
    for (int i = 0; i < gm->countA; i++)
        gm->plane[i] = malloc(sizeof(planes));
    for (int i = 0; i < gm->countT; i++)
        gm->tower[i] = malloc(sizeof(towers));
    for (int i = 0; i < gm->height; i++) {
        if (gm->parser[i][0] == 'A') {
            tmp = my_str_to_word_array(gm->parser[i]);
            count = my_str_to_word_count(gm->parser[i]);
            fill_planes(gm, tmp, count, count_a); count_a ++;
        }
        if (gm->parser[i][0] == 'T') {
            tmp = my_str_to_word_array(gm->parser[i]);
            count = my_str_to_word_count(gm->parser[i]);
            fill_towers(gm, tmp, count, count_t); count_t ++;
        }
    } free(tmp);
}

int parser(char *filepath, game *gm)
{
    if (get_coord(filepath, gm)) {
        ERR_MSG();
        return 1;
    }
    if (load_2d_arr_from_file(filepath, gm)) {
        ERR_MSG();
        return 1;
    }
    if (check_file(gm)) {
        ERR_MSG();
        return 1;
    }
    separate_planes_towers(gm);
}
