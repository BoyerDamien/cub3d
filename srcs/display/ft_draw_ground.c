#include "../../includes/cub3d.h"

void ft_draw_ground(t_vector onset, t_vector offset, t_game *game, t_color color)
{

	t_vector direction;
	t_vector point;
	double dist;
    double ratio;

	direction = offset.direction(&offset, onset);
	dist = offset.dist(&offset, onset);
	while (dist >= 0)
	{
		point = onset.add(&onset, direction.mul_scalar(&direction, dist));
        ratio = (point.y - WIN_CENTER) / (WIN_HEIGHT - WIN_CENTER);
		game->window.draw(&game->window, point, color.add_light(&color, ft_color(255, 255, 255), ratio));
		dist--;
	}
}