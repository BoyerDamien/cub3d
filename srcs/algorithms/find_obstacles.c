#include "../../includes/cub3d.h"

static t_obstacle search_vertical(t_map *map, int x, int y)
{
    t_obstacle new;

    new.onset = ft_vector(x, y, 0);
    while (map->content[y][x] == '1' && y < map->ny - 1)
        y++;
    new.offset = ft_vector(x, y, 0);
    new.length = new.offset.dist(&new.offset, new.onset);
    return (new);
}

static t_obstacle search_horizontal(t_map *map, int x, int y)
{
    t_obstacle new;

    new.onset = ft_vector(x, y, 0);
    while (map->content[y][x] == '1' && x < map->nx - 1)
        x++;
    new.offset = ft_vector(x, y, 0);
    new.length = new.offset.dist(&new.offset, new.onset);
    return (new);
}

static t_obstacle search_diagonal(t_map *map, int x, int y)
{
    t_obstacle new;

    new.onset = ft_vector(x, y, 0);
    while (map->content[y][x] == '1' && x < map->nx - 1 && y < map->ny - 1)
    {
        x++;
        y++;
    }
    new.offset = ft_vector(x, y, 0);
    new.length = new.offset.dist(&new.offset, new.onset);
    return (new);
}

static t_obstacle find_largest(t_map *map, int x, int y)
{
    t_obstacle result;
    t_obstacle tmp;
    int i;
    static t_obstacle (*t[3])(t_map*, int, int) = {search_horizontal, search_vertical, search_diagonal};
    
    i = 0;
    result.length = 0;
    while (i < 3)
    {
        tmp = (t[i])(map, x, y);
        if (tmp.length > result.length)
            result = tmp;
        i++;
    }
    return (result);
}

void find_obstacles(t_map *map, int x, int y)
{
    t_obstacle new;
    if (x < map->nx && y < map->ny)
    {
        new = find_largest(map, x, y);
        printf("ONSET = [%f -- %f] -- OFFSET = [%f -- %f]\n", new.onset.x,new.onset.y,new.offset.x, new.offset.y);
    }
}