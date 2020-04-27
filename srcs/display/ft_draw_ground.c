#include "../../includes/cub3d.h"

void ft_draw_ground(t_vector onset, t_vector offset, t_game *game, t_color color)
{
	double ratio;
	t_color n_color;
	double win_center;
	t_color white;

	win_center = game->window.height / 2;
	white = ft_color(255, 255, 255);
	while ( onset.y <= offset.y )
	{
		ratio = (onset.y - win_center) / (game->window.height - win_center);
		n_color = color.add_light(&color, white, ratio);
		game->window.draw(&game->window, onset, n_color);
		onset.y++;
	}
}