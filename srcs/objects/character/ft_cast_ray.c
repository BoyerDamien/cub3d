#include "../../../includes/cub3d.h"

static int check_map(t_vector point, t_character *character, char **map_content)
{
    int rx;
    int ry;
    t_vector coordinate;

    coordinate = point;
    rx = (coordinate.x - character->map_coordinate.x) / character->cube_width;
	ry = (coordinate.y - character->map_coordinate.y) / character->cube_height;
	if (map_content[ry][rx] != '1')
		return (1);
    return (0);
}

t_vector ft_cast_one_ray(t_character *character, char **map_content, t_window window, double angle)
{
    int dist;
    t_vector point;
    t_vector direction;

    dist = 0;
    point = character->coordinate;
    while (check_map(point, character, map_content))
    {
        direction = ft_vector(dist * sin(angle), dist * cos(angle), 0);
        point = direction.add(&direction, character->coordinate);
        window.draw(&window, point, ft_color(255, 255, 255));
        dist++;
    }
    return (point);
}

void ft_cast_ray(t_character *character, char **map_content, t_window window)
{
    double ratio;
    double angle_min;
    double angle_max;
    double rad_orientation;
    t_vector point;
    double dist;
    double i;

    i = 0;
    rad_orientation = ft_degree_to_rad(character->orientation);
    angle_min = rad_orientation - ft_degree_to_rad(character->fov / 2);
    angle_max = rad_orientation + ft_degree_to_rad(character->fov / 2);
    point = ft_cast_one_ray(character, map_content, window, rad_orientation);
    while (angle_min + i < angle_max)
    {
        point = ft_cast_one_ray(character, map_content, window, angle_min + i);
        point = point.sub(&point, character->coordinate);
        dist = point.length(&point);
        ratio = ((angle_min + i - angle_min) / (angle_max - angle_min));
        //printf("DIST = %f\n", dist);
        //printf("MIN = %f -- MAX = %f -- RATIO = %f -- x = %f\n",angle_min + i, angle_max, ratio, 800 * ratio);
        ft_trace_line(ft_vector(800 * ratio, 400 - 200 / dist, 0),ft_vector(800 * ratio, 400 + 600 / dist , 0), window, ft_color(255,255,255));
        i += 0.003;
    }
}