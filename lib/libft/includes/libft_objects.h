/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_objects.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:53:50 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/03 14:48:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_OBJECTS_H
#	define LIBFT_OBJECTS_H

typedef struct		s_format
{
	char			converter;
	int				min;
	int				max;
	int				point;
	int				padding;
	int				inversed;
	int				min_zero;
	int				max_zero;
	int				space_padding;
	int				zero_padding;
	char			*flag;
}					t_format;

typedef struct		s_element
{
	void				*content;
	struct s_element	*previous;
	struct s_element	*next;
}					t_element;

typedef struct		s_list
{
	int					size;
	struct s_element	*first;

	void (*append)(struct s_list*, void*);
	void (*clear)(struct s_list*);
	void (*remove)(struct s_list*, t_element*);
	void (*iter)(t_element*, void (*f)(t_element*));
	t_element *(*last)(struct s_list*);
	t_element *(*get)(struct s_list*, int);
	struct s_list (*concat)(struct s_list*, struct s_list);
	struct s_list (*copy)(struct s_list*);
	struct s_list (*map)(struct s_list*, void *(*f)(t_element*));
}					t_list;
#	endif