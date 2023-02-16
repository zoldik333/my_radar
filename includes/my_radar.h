/*
** EPITECH PROJECT, 2022
** bs_my_radar
** File description:
** my_radar
*/

#pragma once
        //GRAPHIC LIBRARIES
        #include <SFML/Graphics.h>
        #include <SFML/System/Export.h>
        #include <SFML/System/Time.h>
        #include <SFML/System/Types.h>
        #include <SFML/System/Vector2.h>
        #include <time.h>
        #include <math.h>
        //OTHER LIBRARIES
        #include <fcntl.h>
        #include <stdlib.h>
        #include <stdio.h>
        #include <unistd.h>
        #include <sys/types.h>
        #include <sys/stat.h>

        //MACROS
        #define PARKED 0
        #define FLYING 1
        #define CRASHED 2
        #define DIV 4
        #define BOX_X 1920 / DIV
        #define BOX_Y 1080 / DIV
        #define SIZE 20
        #define AREA_RECTANGLE 400
        #define AREA_CORNER BOX_X * BOX_Y
        #define FRAMERATE 60

        #define CHECK_IF_ZERO() \
            if (my_getnbr(tmp[i]) < 0) \
                return 1;

        #define ERR_MSG() \
            mini_printf("Script contains at least one error.");

        //PLANES
        typedef struct {
            sfVector2f dep;
            sfVector2f arv;
            sfVector2f move;
            int speed;
            int delay;
            int flying;
            sfSprite *plane;
            sfRectangleShape *hitbox;
            float angle;
            sfBool in_zone;
            sfBool in_corner;
        } planes;

        //RECT
        typedef struct {
            sfVector2f top_left;
            sfVector2f top_right;
            sfVector2f bot_left;
            sfVector2f bot_right;
        } rectangle;

        //TOWERS
        typedef struct {
            sfVector2f pos;
            int radius;
            sfSprite *tower;
            sfCircleShape *area;
        } towers;

        //ZONES
        typedef struct {
            sfFloatRect zone;
            sfRectangleShape *box;
            float pos_left;
            float pos_top;
            int *index;
            int nb_index;
        } zones;

        //MAIN STRUCT
        typedef struct {
            //GAME
            sfVideoMode mode;
            sfRenderWindow *window;
            sfEvent event;

            //TEXTURES & SPRITES
            sfTexture *map_t;
            sfSprite *map_s;
            sfTexture *plane_t;
            sfTexture *tower_t;
            sfTexture *text_t;
            int arrived_planes;

            //CLOCK
            sfClock *clock;
            sfClock *clock_plane;
            int seconds;

            //PARSER
            char **parser;
            int height;
            int width;
            int countA;
            int countT;

            //PLANES
            planes **plane;

            //TOWERS
            towers **tower;

            //ZONES
            zones **corner;

            //DISABLE
            sfBool disable_sprites;
            sfBool disable_hitboxes;
        } game;

        //PARSER
        char *my_strncpy(char *dest, char const *src, int n);
        int my_str_to_word_count(char const *str);
        char **my_str_to_word_array(char const *str);
        int get_coord(char const *filepath, game *gm);
        int load_2d_arr_from_file(char const *filepath, game *gm);

        //PARSER -> CHECK FILE
        int my_str_isnum(char const *str);
        int check_file_planes(game *gm, char **tmp, int count);
        int check_file_towers(game *gm, char **tmp, int count);
        int check_file(game *gm);

        // PARSER -> FILL STRUCT
        void fill_towers(game *gm, char **tmp, int count, int t);
        void fill_planes(game *gm, char **tmp, int count, int a);
        int separate_planes_towers(game *gm);
        int parser(char *filepath, game *gm);
        void init_boolean_in_zone(planes **plane, int countA);

        //MAIN - STRUCT
        void init_sprites_textures(game *gm);
        game *init_struct(char *argv[]);
        void destroy(game *gm);

        //SET_POSITIONS
        void set_positions(game *gm);

        //DRAW_SPRITES
        void draw_towers(game *gm, sfRenderWindow *window, towers **tower);
        void draw_planes(game *gm);
        void move_planes(game *gm);
        int draw_sprites(game *gm);

        //INIT_ZONES
        zones **init_zones(zones **corner, int count);

        //MOVE_SPRITES
        void move_planes(game *gm);

        //MANAGE_EVENTS
        void check_all_planes_arrived(game *gm);
        void manage_events(game *gm);

        //CHECK_KEYS -> MANAGE_EVENTS
        void check_key_l(game *gm);
        void check_key_s(game *gm);

        //CHECK_COLLISIONS
        float *calculate_hypothenusis(sfVector2f rect, sfVector2f corner_rect);
        float calculate_area(float *hyp);
        float calculate_sum_area(rectangle *rect_i, sfVector2f corner_rect);
        rectangle *get_rectangle_rotated_vector(sfRectangleShape *hitbox,
        float angle);
        void check_collisions(game *gm);

        //CHECK_COLLISIONS -> GET_RECTANGLE_ROTATED
        rectangle *get_rectangle_rotated(sfRectangleShape *hitbox,
        sfVector2f center, float angle);
        sfVector2f get_corner_points(sfVector2f corner, sfVector2f center,
        float angle);
        sfBool rectangles_are_colliding(float area);


        //CHECK_AREA
        sfBool check_point_in_area(sfVector2f hitbox_corner,
        sfVector2f area_center, int radius);
        sfBool check_area_shortten(game *gm, int i, int j);
        void check_area(game *gm);

        //CHECK_ARRIVAL
        void check_arrival(game *gm);

        //OTHER
        int my_getnbr(char const *str);
        float my_compute_power_rec(float nb, float p);
