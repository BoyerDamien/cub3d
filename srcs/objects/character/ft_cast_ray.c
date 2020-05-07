/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:46:22 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void display_sprites(t_game *game)
{
    t_sprite *sprite;
    t_element *last;

    while (game->sprites.size > 0)
    {
        last = game->sprites.last;
        sprite = (t_sprite *)last->content;
        ft_draw_sprite(sprite, game);
        game->map.content[sprite->y][sprite->x] = '2';
        free(sprite);
        game->sprites.remove(&game->sprites, last);
    }
}

static inline t_vector ft_cast_one_ray(t_game *game, double angle, int x)
{
    t_vector direction;
    t_vector point;
    t_sprite *sprite;

    point = game->character.coordinate;
    direction = ft_vector(sin(angle), cos(angle), 0);
    while (!ft_is_wall(game, point.x, point.y))
    {
        if (ft_is_sprite(game, point.x, point.y) && (point.x - point.x) < 0.03 && (point.y - (int)point.y) < 0.03)
        {
            printf("point = %f -- %f -- x = %d\n", point.x, point.y, x);
            sprite = ft_sprite(game, point, x, angle);
            game->map.content[sprite->y][sprite->x] = 'a';
            game->sprites.append(&game->sprites, sprite);
        }
        point = point.add(&point, direction.mul_scalar(&direction, 0.03));
    }
    return (point);
}

static inline void render(t_game *game, double dist, int x)
{
    double height;
    t_vector onset;
    t_vector offset;
    int win_height;

    win_height = game->window.height;
    if (dist >= 0)
    {
        height = dist > 0 ? win_height / dist : win_height;
        height = height > win_height ? win_height : height;
        if (height <= win_height)
        {
            onset = ft_vector(x, game->win_center - height / 2, 0);
            offset = ft_vector(x, game->win_center + height / 2, 0);
            ft_draw_ceil(ft_vector(x, 0, 0), onset, game, game->ceil_color);
            ft_draw_wall(onset, offset, game, 255 / dist * LIGHT_RATIO);
            onset = ft_vector(x, win_height, 0);
            ft_draw_ground(offset, onset, game, game->floor_color);
        }
    }
}

void ft_cast_ray(t_game *game)
{
    t_vector point;
    double angle_max;
    double dist;
    double step;
    int x;

    x = game->window.width;
    angle_max = game->character.orientation + (game->character.fov / 2);
    step = game->character.fov / x;
    printf("\n--------------------------------\n");
    while (x)
    {
        point = ft_cast_one_ray(game, angle_max, x);
        dist = point.dist(&point, game->character.coordinate);
        dist = dist * cos(game->character.orientation - angle_max);
        ft_choose_texture(point, game);
        render(game, dist, x);
        angle_max -= step;
        x--;
    }
    if (game->sprites.size > 0)
        display_sprites(game);
}
