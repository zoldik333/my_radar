/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-theo.vermorel
** File description:
** check_file
*/

#include "../includes/my_radar.h"

int check_file_planes(game *gm, char **tmp, int count)
{
    for (int i = 0; i < count; i++) {
        switch (i) {
            case 1: if (my_str_isnum(tmp[i])) return 1;
            if (my_getnbr(tmp[i]) < 0 || my_getnbr(tmp[i]) > 1920) return 1;
            break;
            case 2: if (my_str_isnum(tmp[i])) return 1;
            if (my_getnbr(tmp[i]) < 0 || my_getnbr(tmp[i]) > 1080) return 1;
            break;
            case 3: if (my_str_isnum(tmp[i])) return 1;
            if (my_getnbr(tmp[i]) < 0 || my_getnbr(tmp[i]) > 1920) return 1;
            break;
            case 4: if (my_str_isnum(tmp[i])) return 1;
            if (my_getnbr(tmp[i]) < 0 || my_getnbr(tmp[i]) > 1080) return 1;
            break;
            case 5: if (my_str_isnum(tmp[i])) return 1; CHECK_IF_ZERO(); break;
            case 6: if (my_str_isnum(tmp[i])) return 1; CHECK_IF_ZERO(); break;
            default: break;
        }
    } return 0;
}

int check_file_towers(game *gm, char **tmp, int count)
{
    for (int i = 0; i < count; i++) {
        switch (i) {
            case 1: if (my_str_isnum(tmp[i])) return 1;
            if (my_getnbr(tmp[i]) < 0 || my_getnbr(tmp[i]) > 1920) return 1;
            break;
            case 2: if (my_str_isnum(tmp[i])) return 1;
            if (my_getnbr(tmp[i]) < 0 || my_getnbr(tmp[i]) > 1080) return 1;
            break;
            case 3: if (my_str_isnum(tmp[i])) return 1; CHECK_IF_ZERO(); break;
            default: break;
        }
    }
    return 0;
}

int check_file(game *gm)
{
    char **tmp; int count; int err = 0;
    for (int i = 0; i < gm->height; i++) {
        switch (gm->parser[i][0]) {
            case 'A' : tmp = my_str_to_word_array(gm->parser[i]);
                count = my_str_to_word_count(gm->parser[i]);
                err += (check_file_planes(gm, tmp, count));
                free(tmp); break;
            case 'T' : tmp = my_str_to_word_array(gm->parser[i]);
                count = my_str_to_word_count(gm->parser[i]);
                err += check_file_towers(gm, tmp, count);
                free(tmp); break;
            default: break;
        }
    }
    if (err > 0)
        return 1;
    return 0;
}
