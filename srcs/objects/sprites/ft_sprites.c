/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:56:56 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 15:56:24 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite *ft_sprite(t_game *game, t_ray *ray, double dist){
    t_sprite *new;

    if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
        return (NULL);
    new->point = ray->point;
    new->sprite = ray->point.sub(&ray->point, game->character.coordinate);
    new->inv_det = 1.0 / (game->character.plane.x * game->character.orientation.y - game->character.orientation.x * game->character.plane.y);
    new->transform = ft_vector(0,0,0);
    new->transform.x = new->inv_det * (game->character.orientation.y * new->sprite.x - game->character.orientation.x * new->sprite.y);
    new->transform.y = new->inv_det * (-game->character.plane.y * new->sprite.x + game->character.plane.x * new->sprite.y);
    new->screen_x = (int)((game->window.width / 2) * (1 + new->transform.x / new->transform.y));
    new->height = abs((int)(game->window.height / (new->transform.y))); 
    new->onset = ft_vector(0,0,0);
    new->offset = ft_vector(0,0,0);
    new->onset.y = -new->height / 2 + game->window.height / 2;
    new->onset.y = new->onset.y < 0 ? 0 : new->onset.y;
    new->offset.y = new->height / 2 + game->window.height / 2;
    new->offset.y = new->offset.y >= game->window.height ? game->window.height - 1: new->offset.y;
    new->width = abs((int)(game->window.height / new->transform.y));
    new->onset.x = -new->width / 2 + new->screen_x;
    new->onset.x = new->onset.x < 0 ? 0 : new->onset.x;
    new->offset.x =  new->width / 2 + new->screen_x;
    new->offset.x = new->offset.x >= game->window.width ? game->window.width - 1: new->offset.x;
    new->ratio = 255 / dist * LIGHT_RATIO;
    return (new);  
}