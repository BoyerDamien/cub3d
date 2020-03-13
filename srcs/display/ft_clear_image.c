#include "../../includes/cub3d.h"

void ft_clear_image(t_window *window)
{
    int i;
    int j;

    j = 0;
    while (j < window->height)
    {
        i = 0;
        while (i < window->width)
        {
            window->draw(window, ft_vector(i,j,0), ft_color(0, 0, 0));
            i++;
        }
        j++;
    }
}  