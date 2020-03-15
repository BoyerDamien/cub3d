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
    float dist;
    t_vector point;
    t_vector direction;

    dist = 0;
    point = character->coordinate;
    angle = ft_degree_to_rad(angle);
    while (check_map(point, character, map_content))
    {
        direction = ft_vector(dist * sin(angle), dist * cos(angle), 0);
        point = direction.add(&direction, character->coordinate);
        window.draw(&window, point, ft_color(255, 255, 255));
        //printf("DIST = %f\n", dist);
        dist+=0.09;
    }
    return (point);
}

double ft_plane_intersect(t_vector point, t_character character, t_vector n)
{
	double t;
	t_vector diff;
	double denom;

	denom = n.dot(&n, point.direction(&point, character.coordinate));
	if (denom > 0.00001 || denom < -0.00001)
    {
        diff = point.sub(&point, character.coordinate);
        t = diff.dot(&diff, n) / denom;
        if (t >= 0)
            return (t);
    }
    return(0);
}

double compute_dist(t_vector point, t_vector origin, double angle)
{
   double hyp;
   t_vector tmp;

   tmp = point.sub(&point, origin);
   hyp = point.length(&tmp);
   return (hyp * sin(ft_degree_to_rad(angle)));
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
    double width;
    t_vector onset;
    t_vector offset;
    double x;

    i = 0;
    rad_orientation = (character->orientation);
    angle_min = rad_orientation - (character->fov / 2);
    angle_max = rad_orientation + (character->fov / 2);
    while (angle_min + i < angle_max)
    {
        point = ft_cast_one_ray(character, map_content, window, angle_min + i);
        point = point.sub(&point, character->coordinate);
        dist = point.length(&point);
        if (angle_min + i != rad_orientation)
            dist = dist * cos(ft_degree_to_rad(ft_abs(rad_orientation - (angle_min + i))));
        ratio = ((angle_max - (angle_min + i)) / (angle_max - angle_min));
        if (dist >= 0)
        {
            width = WALL_HEIGHT / (dist + 0.00001) * 35;
            width = width > 800 ? 800 : width;
            if (width <= 800)
            {
                x = 800 * ratio;
                onset = ft_vector(x , round(400 - width / 2), 0);
                offset = ft_vector(x, round(400 + width / 2) , 0);
                ft_trace_line(onset, offset, window, ft_color(255,255,255));
            }
        }
        i += 0.07;
    }
}