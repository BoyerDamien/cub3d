/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:12:34 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 10:54:00 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

typedef	struct	s_vector
{
	double x;
	double y;
	double z;
	void			(*update)(struct s_vector*, double x, double y, double z);
	struct s_vector (*add)(struct s_vector*, struct s_vector);
	struct s_vector (*sub)(struct s_vector*, struct s_vector);
	struct s_vector (*mul)(struct s_vector*, struct s_vector);
	struct s_vector (*div)(struct s_vector*, struct s_vector);
	struct s_vector (*add_scalar)(struct s_vector*, double);
	struct s_vector (*sub_scalar)(struct s_vector*, double);
	struct s_vector (*div_scalar)(struct s_vector*, double);
	struct s_vector (*mul_scalar)(struct s_vector*, double);
	struct s_vector (*direction)(struct s_vector *, struct s_vector);
	struct s_vector (*normalise)(struct s_vector *);
	double			(*length)(struct s_vector*);
	double			(*dot)(struct s_vector*, struct s_vector);
	struct s_vector (*cross)(struct s_vector*, struct s_vector);
}			t_vector;

t_vector	ft_vector(double x, double y, double z);
t_vector	ft_vec_add(t_vector *vec1, t_vector vec2);
t_vector	ft_vec_sub(t_vector *vec1, t_vector vec2);
t_vector	ft_vec_div(t_vector *vec1, t_vector vec2);
t_vector	ft_vec_mul(t_vector *vec1, t_vector vec2);
t_vector	ft_vec_add_scalar(t_vector *vec, double scalar);
t_vector	ft_vec_sub_scalar(t_vector *vec, double scalar);
t_vector	ft_vec_mul_scalar(t_vector *vec, double scalar);
t_vector	ft_vec_div_scalar(t_vector *vec, double scalar);
t_vector	ft_vec_direction(t_vector *point, t_vector origin);
double		ft_vec_length(t_vector *vec);
double		ft_vec_dot(t_vector *vec1, t_vector vec2);
void		ft_vec_update(t_vector *vec, double x, double y, double z);
t_vector	ft_vec_normalise(t_vector *vec);
t_vector	ft_vec_cross_product(t_vector *vec1, t_vector vec2);

#endif
