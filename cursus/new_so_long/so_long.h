#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_xpm
{
    void *data;
    int images_count;
    int current_image;
} t_xpm;


typedef struct s_player
{
    int x;
    int y;
    int live_x;
    int live_y;
    t_xpm img;
} t_player;

typedef struct s_collectible
{
    int x;
    int y;
    int live_x;
    int live_y;
    t_xpm img;
} t_collectible;

#endif