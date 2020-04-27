#include "../../../includes/cub3d.h"

static t_vector ft_cast_one_ray(t_game *game, double angle)
{
    t_vector direction;
    t_vector point;

    point = game->character.coordinate;
    direction = ft_vector(sin(angle), cos(angle), 0);
    while (!ft_is_wall(game, point.x, point.y)){
      point = point.add(&point, direction.mul_scalar(&direction, 0.01));
    }
    return (point);
}

static void render(t_game *game, double dist, int x)
{
    double height;
    t_vector onset;
    t_vector offset;
    int win_center;
    int win_height;

    win_center = game->window.width / 2 ;
    win_height = game->window.height;
    if (dist >= 0)
    {
        height = win_height * 0.5 / (dist + 0.00001);
        height = height > win_height ? win_height : height;
        if (height < win_height)
        {
            onset = ft_vector(x,  win_center - height / 2, 0);
            offset = ft_vector(x, win_center + height / 2, 0);
            ft_trace_column(ft_vector(x, 0, 0), onset, &game->window, game->ceil_color);
            ft_draw_wall(onset, offset, game, 255 / dist * LIGHT_RATIO);
            ft_draw_ground(offset, ft_vector(x, win_height, 0), game, game->floor_color);
        }
    }
}

void ft_cast_ray(t_game *game)
{
    t_vector point;
    double angle_min;
    double dist;
    double step;
    int x;

    x = game->window.width;
    angle_min = game->character.orientation - (game->character.fov / 2);
    step = ((game->character.orientation + (game->character.fov / 2)) - angle_min) / x;
    while (x)
    {
        point = ft_cast_one_ray(game, angle_min);
        dist = point.dist(&point, game->character.coordinate);
        dist = dist * cos(game->character.orientation - (angle_min));
        ft_choose_texture(point, game, point);
        render(game, dist, x);
        angle_min += step;
        x--;
    }
}
