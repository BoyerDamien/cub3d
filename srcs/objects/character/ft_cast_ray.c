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
    t_vector direction;
    t_vector point;

    point = game->character.coordinate;
    direction = ft_vector(sin(angle), cos(angle), 0);
    while (check_map(game, point)){
      point = point.add(&point, direction.mul_scalar(&direction, 0.01));
    }
    return (point);
}

static void render(t_game *game, double dist, int x)
{
    double height;
    t_vector onset;
    t_vector offset;

    if (dist >= 0)
    {
        height = BLOCK_SIZE / (dist + 0.00001) * game->cam_dist;
        height = height > WIN_HEIGHT ? WIN_HEIGHT : height;
        if (height <= WIN_HEIGHT)
        {
            onset = ft_vector(x, WIN_CENTER - height / 2, 0);
            offset = ft_vector(x, WIN_CENTER + height / 2, 0);
            ft_trace_line(ft_vector(x, 0, 0), onset, game->window, CEILING_COLOR);
            ft_draw_wall(onset, offset, game, 255 / dist * LIGHT_RATIO);
            ft_draw_ground(offset, ft_vector(x, WIN_HEIGHT-2, 0), game, GROUND_COLOR);
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

    angle_min = game->character.orientation - (game->character.fov / 2);
    step = ((game->character.orientation + (game->character.fov / 2)) - angle_min) / WIN_WIDTH;
    x = WIN_WIDTH;
    while (x)
    {
        point = ft_cast_one_ray(game, angle_min);
        dist = point.dist(&point, game->character.coordinate);
        dist = dist * cos(game->character.orientation - (angle_min));
        ft_choose_texture(point, game);
        render(game, dist, x);
        angle_min += step;
        x--;
    }
}
