/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-theo.vermorel
** File description:
** load_2d_arr_from_file
*/

#include "../includes/my_radar.h"

int get_coord(char const *filepath, game *gm)
{
    char buffer; int width = 0;
    int fd = open(filepath, O_RDONLY);
    if (fd == - 1)
        return 1;
    while (read(fd, &buffer, 1)) {
        if (buffer == '\n') {
            gm->width = (gm->width < width) ? width : gm->width;
            width = 0;
            gm->height += 1;
        }
        width += 1;
    }
    close(fd);
    return 0;
}

int load_2d_arr_from_file(char const *filepath, game *gm)
{
    FILE * fp;
    size_t len = 0;
    int i = 0;
    fp = fopen(filepath, "r");
    if (fp == NULL)
        return 1;
    gm->parser = malloc(sizeof(char *) * (gm->height + 1));
    for (int i = 0; i < gm->height; i++)
        gm->parser[i] = malloc(sizeof(char) * (gm->width + 1));
    for (int i = 0; i < gm->height; i++) {
        getline(&(gm->parser[i]), &len, fp);
        switch (gm->parser[i][0]) {
        case 'A': gm->countA += 1; break;
        case 'T': gm->countT += 1; break;
        default: return 1;
        }
    }
    fclose(fp);
    return 0;
}
