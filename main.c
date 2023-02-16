/*
** EPITECH PROJECT, 2022
** bs_my_radar
** File description:
** main.c
*/

#include "./includes/my_radar.h"
#include "./includes/mini_printf.h"

void print_help(void)
{
    mini_printf("Air traffic simulation panel\n\n");
    mini_printf("USAGE\n");
    mini_printf(" ./my_radar [OPTIONS] path_to_script\n");
    mini_printf(" path_to_script\tThe path of the script file (in script directory).\n\n");
    mini_printf("OPTIONS\n");
    mini_printf(" -h\tprint the usage and quit.\n\n");
    mini_printf("USER INTERACTIONS\n");
    mini_printf(" 'Q' key or press CROSS\tclose the window.\n");
    mini_printf(" 'L' key\tenable/disable hitboxes and areas.\n");
    mini_printf(" 'S' key\tenable/disable sprites.\n");
}

void init_sprites_textures(game *gm)
{
    gm->map_t = sfTexture_createFromFile("./img/world_map.png", NULL);
    gm->map_s = sfSprite_create();
    gm->text_t = sfTexture_createFromFile("./img/text.png", NULL);
    sfSprite_setTexture(gm->map_s, gm->map_t, sfTrue);
    return;
}

game *init_struct(char *argv[])
{
    game *gm = malloc(sizeof(game));
    gm->mode = (sfVideoMode){1920, 1080, 32};
    gm->window = sfRenderWindow_create(gm->mode, "SFML window",
    sfResize | sfClose, NULL);
    gm->plane_t = sfTexture_createFromFile("./img/plane.png", NULL);
    gm->tower_t = sfTexture_createFromFile("./img/tower.png", NULL);
    gm->clock = sfClock_create();
    gm->clock_plane = sfClock_create();
    gm->arrived_planes = 0;
    gm->seconds = 0;
    gm->height = 0;
    gm->width = 0;
    gm->countA = 0;
    gm->countT = 0;
    gm->disable_sprites = sfFalse;
    gm->disable_hitboxes = sfFalse;
    init_sprites_textures(gm);
    return gm;
}

int gameplay(char *argv[], game *gm)
{
    set_positions(gm);
    init_boolean_in_zone(gm->plane, gm->countA);
    gm->corner = init_zones(gm->corner, gm->countA);
    while (sfRenderWindow_isOpen(gm->window)) {
        manage_events(gm);
        check_key_s(gm);
        check_key_l(gm);
        check_area(gm);
        check_arrival(gm);
        draw_sprites(gm);
        check_collisions(gm);
        check_all_planes_arrived(gm);
    }
    destroy(gm);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        print_help();
        return 0;
    }
    if (argc == 2) {
        game *gm = init_struct(argv);
        if (parser(argv[1], gm))
            return 84;
        return gameplay(argv, gm);
    }
    mini_printf("bad arguments : retry with -h\n");
    return 84;
}
