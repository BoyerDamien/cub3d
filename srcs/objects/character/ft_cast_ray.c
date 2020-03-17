#include "../../../includes/cub3d.h"

static int check_map(t_game *game, t_vector point)
{
    t_vector result;

    result = ft_check_map(game, point);
    if (game->map.content[(int)result.y][(int)result.x] != '1')
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
        //game->window.draw(&game->window, point, ft_color(255, 255, 255));
        dist += 0.5;
    }
    while (!check_map(game, point))
    {
        direction = ft_vector(dist * sin(angle), dist * cos(angle), 0);
        point = direction.add(&direction, game->character.coordinate);
        //game->window.draw(&game->window, point, ft_color(255, 255, 255));
        dist -= 0.02;
    }
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
        height = BLOCK_SIZE / (dist + 0.00001) * CAM_DIST;
        height = height > WIN_HEIGHT ? WIN_HEIGHT : height;
        if (height <= WIN_HEIGHT)
        {
            x = WIN_WIDTH * ratio;
            onset = ft_vector(x, WIN_CENTER - height / 2, 0);
            offset = ft_vector(x, WIN_CENTER + height / 2, 0);
            color = ft_color(100, 100, 100);
            ft_trace_line(ft_vector(x, 0, 0), onset, game->window, ft_color(0, 0, 255));
            ft_trace_line(onset, offset, game->window, color.add_light(&color, ft_color(255, 255, 255), 255/dist));
            ft_trace_line(offset, ft_vector(x, WIN_HEIGHT-2, 0), game->window, color.add_light(&color, ft_color(0, 255, 0), 255/dist));
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

    i = 0;
    angle_min = game->character.orientation - (game->character.fov / 2);
    angle_max = game->character.orientation + (game->character.fov / 2);
    while (angle_min + i < angle_max)
    {
        point = ft_cast_one_ray(game, angle_min + i);
        dist = point.dist(&point, game->character.coordinate);
        if (angle_min + i != game->character.orientation)
            dist = dist * cos(game->character.orientation - (angle_min + i));
        render(game, dist, ((angle_max - (angle_min + i)) / (angle_max - angle_min)));
        i += 0.001;
    }
}