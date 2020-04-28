#include "../../includes/cub3d.h"

void ft_draw_ground(t_vector onset, t_vector offset, t_game *game, t_color color)
{
	double ratio;
	t_color n_color;
	t_color white;
	double denom;

	white = ft_color(255, 255, 255);
	denom = (game->window.height - game->win_center);
	while ( onset.y <= offset.y )
	{
		ratio = (onset.y - game->win_center) / denom;
		n_color = color.add_light(&color, white, ratio);
		game->window.draw(&game->window, onset, n_color);
		onset.y++;
	}
}