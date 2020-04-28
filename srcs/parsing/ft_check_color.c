/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 10:51:52 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/28 20:31:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_correct(int color)
{
    return (color >= 0 && color <= 255);
}

int is_number(char *color)
{
    while(ft_isspace(*color))
        color++;
    while (*color)
    {
        if (!ft_isdigit(*color))
            return (0);
        color++;
    }
    return (1);
}

int test_color_line(char *line)
{
    char **line_splitted;
    int i;

    i = 0;
    line_splitted = NULL;
    line = ft_move_until(line, "not", ft_isalpha);
    if (line && (line_splitted = ft_split(line, ',')))
    {
        while (line_splitted[i])
        {
            if (!is_number(line_splitted[i]) || !is_correct(ft_atoi(line_splitted[i])))
            {
                printf("color = %s\n", line_splitted[i]);
                ft_split_clean(line_splitted);
                return (0);
            }
            i++;
        }
        ft_split_clean(line_splitted);
        return (1);
    }
    ft_split_clean(line_splitted);
    return (0);
}

int ft_check_one_color(char *path, char *charcode)
{
    char *line;
    char *message;

    message = ft_strjoin("Check color\t\t", charcode);
    if ((line = ft_tag_line(path, charcode, 2)) && test_color_line(line))
    {
        ft_display_process_status(message, "ok");
        free(message);
        free(line);
        return (1);
    }
    ft_display_process_status(message, "error");
    ft_display_error("No valid color was found", __func__);
    free(message);
    free(line);
    return (0);
}

void ft_check_color(char *path)
{
    static char *charcode[2] = {"F", "C"};
    int i;

    i = 0;
    while (i < 2)
    {
        if (!ft_check_one_color(path, charcode[i]))
            exit(0);
        i++;
    }
}