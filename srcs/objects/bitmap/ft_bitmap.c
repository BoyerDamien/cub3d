/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:47:39 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/14 11:08:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	write_pixel(t_bmp_header *bmp, t_game *game, int fd)
{
	int x;
	int y;
	int index;

	y = bmp->image_height;
	while (y)
	{
		x = 0;
		while (x < bmp->image_width)
		{
			index = (y * game->window.img.size_line + x * 4);
			write(fd, &game->window.img.img_data[index], 4);
			x++;
		}
		y--;
	}
}

t_bmp_header		ft_bitmap(t_game *game)
{
	t_bmp_header new;

	new.file_size = 54 + game->window.img.height * game->window.img.size_line;
	new.pixel_offset = 54;
	new.header_size = 40;
	new.image_width = game->window.img.width;
	new.image_height = game->window.img.height;
	new.planes = 1;
	new.bpp = game->window.img.bpp;
	return (new);
}

static inline void	write_header(t_bmp_header *bmp, int fd)
{
	write(fd, "BM", 2);
	write(fd, &bmp->file_size, sizeof(int));
	write(fd, &bmp->unused, sizeof(int));
	write(fd, &bmp->pixel_offset, sizeof(int));
	write(fd, &bmp->header_size, sizeof(int));
	write(fd, &bmp->image_width, sizeof(int));
	write(fd, &bmp->image_height, sizeof(int));
	write(fd, &bmp->planes, sizeof(short int));
	write(fd, &bmp->bpp, sizeof(short int));
	write(fd, &bmp->unused, sizeof(int));
	write(fd, &bmp->unused, sizeof(int));
	write(fd, &bmp->unused, sizeof(int));
	write(fd, &bmp->unused, sizeof(int));
	write(fd, &bmp->unused, sizeof(int));
	write(fd, &bmp->unused, sizeof(int));
}

void				ft_write_bmp_file(t_game *game)
{
	t_bmp_header	bmp;
	int				fd;

	bmp = ft_bitmap(game);
	if ((fd = open("cub3d.bmp", O_WRONLY | O_CREAT, S_IRWXU | O_TRUNC)) < 0)
	{
		game->finish(game);
		ft_display_error("Cannot open cub3d.bmp", __func__);
		exit(EXIT_FAILURE);
	}
	write_header(&bmp, fd);
	write_pixel(&bmp, game, fd);
	close(fd);
}
