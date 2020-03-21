#include "../../../includes/cub3d.h"

t_texture ft_texture(void *mlx_ptr, char *path)
{
    t_texture new;

    new.img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &new.width, &new.height);
    new.img_data = mlx_get_data_addr(new.img_ptr, &new.bpp, &new.size_line, &new.endian);
    return (new);
}