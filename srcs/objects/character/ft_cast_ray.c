#include "../../../includes/cub3d.h"

static int check_map(t_game *game, t_vector point)
{
    t_vector result;

    result = ft_check_map(game, point);
    if (game->map.content[(int)round(result.y)][(int)round(result.x)] != '1')
        return (1);
    return (0);
}

static t_vector ft_cast_one_ray(t_game *game, double angle)
{
    float dist;
    t_vector direction;
    t_vector point;

    dist = 0;
    point = game->character.coordinate;
    while (check_map(game, point))
    {
        direction = ft_vector(dist * sin(angle), dist * cos(angle), 0);
        point = direction.add(&direction, game->character.coordinate);
        dist += 0.1;
    }
    //printf("BEFORE = [%f -- %f]\n", point.x, point.y);
   
    while (!check_map(game, point))
    {
        direction = ft_vector(dist * sin(angle), dist * cos(angle), 0);
        point = direction.add(&direction, game->character.coordinate);
        dist -= 0.001;
    }
    //printf("After = [%f -- %f]\n", point.x, point.y);
    return (point);
}

static void render(t_game *game, double dist, double ratio)
{
    double height;
    t_vector onset;
    t_vector offset;
    double x;
    t_color color;
 
    if (dist >= 0)
    {
        height = BLOCK_SIZE / (dist + 0.00001) * game->cam_dist;
        height = height > WIN_HEIGHT ? WIN_HEIGHT : height;
        if (height <= WIN_HEIGHT)
        {
            x = WIN_WIDTH * ratio;
            onset = ft_vector(x, WIN_CENTER - height / 2, 0);
            offset = ft_vector(x, WIN_CENTER + height / 2, 0);
            color = ft_color(0, 0, 0);
            ft_trace_line(ft_vector(x, 0, 0), onset, game->window, CEILING_COLOR);
            ft_draw_wall(onset, offset, *game, 255/dist * LIGHT_RATIO);
            ft_draw_ground(offset, ft_vector(x, WIN_HEIGHT-2, 0), *game, GROUND_COLOR);
        }
    }
}

void ft_cast_ray(t_game *game)
{
    double angle_min;
    double angle_max;
    t_vector point;
    double dist;
    double i;
    double ratiox;
    double ratioy;
    double ratiox_rounded;
    double ratioy_rounded;
    double calcx;
    double calcy;

    i = 0;
    angle_min = game->character.orientation - (game->character.fov / 2);
    angle_max = game->character.orientation + (game->character.fov / 2);
    while (angle_min + i < angle_max)
    {
        point = ft_cast_one_ray(game, angle_min + i);
        ratiox = ((int)point.x + 1 - point.x) ;
        ratioy = ((int)point.y + 1 - point.y) ;
        ratiox_rounded = round(ratiox);
        ratioy_rounded = round(ratioy);
        calcx = ft_abs(ratiox - 0.5);
        calcy = ft_abs(ratioy - 0.5);

        if (calcx > calcy && ratiox_rounded == 0)
            game->actual_text= game->wall_texture_O;
        else if (calcx > calcy && ratiox_rounded == 1)
            game->actual_text= game->wall_texture_E;
        else if (calcy > calcx && ratioy_rounded == 0)
            game->actual_text= game->wall_texture_N;
        else if (calcy > calcx && ratioy_rounded == 1)
            game->actual_text= game->wall_texture_S;
        dist = point.dist(&point, game->character.coordinate);
        if (angle_min + i != game->character.orientation)
            dist = dist * cos(game->character.orientation - (angle_min + i));
        render(game, dist, ((angle_max - (angle_min + i)) / (angle_max - angle_min)));
        i += 0.001;
    }
}