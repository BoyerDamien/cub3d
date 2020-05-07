/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:56:56 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 12:04:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite *ft_sprite(t_game *game, t_vector point, double x, double angle){
    t_sprite *new;
    (void)angle;
    
    if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
        return (NULL);
    new->dist = point.dist(&point, game->character.coordinate);
    //new->dist = new->dist * cos(game->character.orientation - angle);
    new->x = (int)point.x;
    new->y = (int)point.y;
    new->height = new->dist > 0 ? game->window.height / new->dist : game->window.height;
    new->height = new->height > game->window.height ? game->window.height : new->height;
    new->onset = ft_vector(x,  game->win_center - new->height / 2, 0);
    new->ratio = 255 / new->dist * LIGHT_RATIO;
    return (new);  
}