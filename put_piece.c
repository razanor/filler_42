/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analizator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:05:23 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/22 13:05:40 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	player(t_filler *f, t_flag *n)
{
	if ((n->i + n->a) < f->y_map && (n->j + n->b) < f->x_map && 
		(f->map[n->i + n->a][n->j + n->b] == f->player || 
			f->map[n->i + n->a][n->j + n->b] == ft_tolower(f->player)))
		return (1);
	else
		return (0);		
}

static int	bot(t_filler *f, t_flag *n)
{
	if ((n->i + n->a) < f->y_map && (n->j + n->b) < f->x_map && 
		(f->map[n->i + n->a][n->j + n->b] == f->bot || 
			f->map[n->i + n->a][n->j + n->b] == ft_tolower(f->bot)))
		return (1);
	else
		return (0);
}	

static void	check_piece(t_filler *f, t_flag *n)
{
	while (f->piece[n->a])
	{
		n->b = 0;
		while (f->piece[n->a][n->b])
		{
			if (f->piece[n->a][n->b] == '*')
			{
				if (player(f,n))
					(n->flag)++;
				if (bot(f,n))
					(n->flag1)++;
				if (((n->i + n->a) >= f->y_map || (n->j + n->b) >= f->x_map))
					(n->flag2)++;
			}
				(n->b)++;
		}
		(n->a)++;
	} 
}

void 		put_piece(t_filler *f)
{
	t_flag n;

	n = (t_flag){0, 0, 0, 0, 0, 0, 0};
	while (f->map[n.i])
	{
		n.j = 0;
		while (f->map[n.i][n.j])
		{
			n.a = 0;
			check_piece(f, &n);
			if (n.flag == 1 && n.flag1 == 0 && n.flag2 == 0)
			{	
				ft_printf("%d %d\n", n.i, n.j);
			}
			n.flag = 0;
			n.flag1 = 0;
			n.flag2 = 0;
			n.j++;
		}
		n.i++;
	}
	ft_printf("%d %d\n", 0, 0);
}