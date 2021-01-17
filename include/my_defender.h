/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** My_defender's header file
*/

#ifndef MY_DEFENDER
#define MY_DEFENDER

#define MENU 0
#define GAME 1
#define PAUSE 2
#define QUIT 3
#define END_GAME 4

#define TRUE 1
#define FALSE 0

#define YES 1
#define NO 0

#define T0 0
#define T1 1
#define T2 2
#define T3 3
#define T4 4

#include <../CSFML-2.5/include/SFML/Graphics.h>
#include <../CSFML-2.5/include/SFML/Window.h>
#include <../CSFML-2.5/include/SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_defender.h"

typedef enum type_s {
    Player = 0,
    Layer,
    Enemy
} type_t;

typedef struct vector2ti_s {
    int *grid_x;
    int *grid_y;
} vector2ti_t;

typedef struct button_s {
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *rect;
} buttons_t;

typedef struct game_object_t {
    type_t obj_type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    float speed;
} game_object;

typedef struct ennemie_s {
    sfVector2i position;
    int hp;
    int speed;
    int color;
    game_object enemy_obj;
} ennemie_t;

typedef struct all_button_s {
    buttons_t *buttons;
    game_object *buttons_obj;
} all_button_t;

typedef struct cursor_s {
    sfVector2i pos;
    int status;
    game_object *cursor_image;
    all_button_t hud_button;
} cursor_t;

typedef struct towers_s {
    sfVector2i *t1;
    int nb_t1;
    sfClock *clockt1;
    sfVector2i *t2;
    int nb_t2;
    sfClock *clockt2;
    sfVector2i *t3;
    int nb_t3;
    sfClock *clockt3;
    sfClock *clockt32;
    sfVector2i *t4;
    int nb_t4;
    sfClock *clockt4;
} towers_t;

typedef struct game_s {
    char **map;
    all_button_t button;
    vector2ti_t grid;
    game_object *background;
    ennemie_t *enemy;
    sfClock *clock;
    sfClock *clock2;
    game_object hud;
    cursor_t cursor;
    towers_t towers;
    int castel_hp;;
    int money;
    sfFont *font;
    sfText *text;
    sfEvent event;
} game_t;

typedef struct pause_s {
    all_button_t button;
    game_object background;
} pause_t;

typedef struct menu_s {
    all_button_t button;
    game_object background;
} menu_t;

//manage_object.c
void init_rect(sfIntRect *rect);
game_object create_object(char const *pts, sfVector2f scale, \
sfVector2f position);
void destroy_object(game_object obj);

//manage_buttons.c
buttons_t init_button(sfVector2f position , sfVector2f size);
int collision_box(sfVector2i cursor_pos, buttons_t button, sfEvent event,\
int actual_state, int to_state);
all_button_t create_buttons(int nb, sfVector2i pos);
all_button_t create_hud_buttons(void);
int collision_hud(sfVector2i crsor_pos, game_t *game, buttons_t button,\
int from_status, int to_status);

//manage_mouse.c
sfVector2i find_mousepos_map(sfVector2i mouse_inscreen, vector2ti_t grid);
vector2ti_t fill_grid_stats(sfVector2u window_size);

//move_functions.c
int move_rect(int rect_left);

//manage_enemy.c
ennemie_t *check_enemy_tab(game_t game, int difficulty_factor);
ennemie_t path_finding(game_t game, int i);
ennemie_t *pop_enemy(game_t game);
game_t manage_enemy(sfClock *clock, game_t game, sfRenderWindow *window);
void draw_enemies(game_t game, sfRenderWindow *window);
game_t action_enemy(game_t game, int permission, sfTime time2, int i);

//init.c
void init_window(sfRenderWindow **window, char const *title, \
int width, int height);
ennemie_t *fill_enemy_tab(game_t game, int difficulty_factor);
game_object *setup_background(void);
game_t setup_clocks(game_t game);

//game.c
int f_game(sfRenderWindow *window, game_t *game);
game_t init_game(sfRenderWindow *window);
void draw_game(char **map, game_object *background, sfRenderWindow *window);
game_t manage_cursor(game_t game, sfRenderWindow *window, sfEvent event);
void draw_cursor(cursor_t cursor, sfRenderWindow *window);
game_t put_tower(game_t game, sfEvent event, int *status);
void draw_game_next(game_object *background, sfRenderWindow *window, \
char **map, sfVector2i pos);
int manage_damage(game_t *enemy);

//menu.c
int f_menu(sfRenderWindow *window, menu_t menu, sfEvent event);
menu_t init_menu(void);
int switch_menu(sfRenderWindow *window, menu_t menu, sfEvent event, int i);

//pause.c
pause_t init_pause(void);
int f_pause(sfRenderWindow *window, pause_t pause, sfEvent event);

//main_loop.c
void loop(menu_t menu, game_t game, pause_t pause, sfRenderWindow *window);
void select_scene(sfRenderWindow *window, menu_t menu, \
game_t *game, pause_t pause);

//tower.c
ennemie_t *manage_tower_1(game_t game, int i);
ennemie_t *manage_tower_2(game_t game, int j);
ennemie_t *manage_tower_3(game_t game, int j, int *permission);
ennemie_t *check_positions_t3(game_t game, int j);

//end_game.c
void f_end_game(sfRenderWindow *window, game_t game);

//general.c
void draw_sprites(sfRenderWindow *window, game_object *objects);
sfVector2i search_for_s(char **map);
char *read_map(void);
char **create_map(void);
game_t switch_stat_tower(game_t game);
char *int_to_str(int nbr);
void create_string(sfFont **font, sfText **text);
void manage_animation(int *rect_left, game_object *animated);
void switch_draw_game(char **map, game_object *background, \
sfRenderWindow *window, int i, int j);

//setup.c
towers_t setup_tower(void);
game_object *setup_cursor_image(cursor_t cursor);
game_object *setup_background(void);
game_t setup_clocks(game_t game);

#endif
