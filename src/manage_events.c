/*
** EPITECH PROJECT, 2022
** bs_my_hunter
** File description:
** manage_events
*/

#include "../includes/my_radar.h"

void check_key_l(game *gm)
{
    if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue &&
    gm->disable_hitboxes == sfFalse) {
        gm->disable_hitboxes = sfTrue;
    } else if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue &&
    gm->disable_hitboxes == sfTrue) {
        gm->disable_hitboxes = sfFalse;
    }
}

void check_key_s(game *gm)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
    gm->disable_sprites == sfFalse) {
        gm->disable_sprites = sfTrue;
    } else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
    gm->disable_sprites == sfTrue) {
        gm->disable_sprites = sfFalse;
    }
}

void manage_events(game *gm)
{
    while (sfRenderWindow_pollEvent(gm->window, &gm->event)) {
        if (gm->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ) ==
        sfTrue) {
            sfRenderWindow_close(gm->window);
        }
    }
}
