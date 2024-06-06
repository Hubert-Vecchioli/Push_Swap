/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:36:44 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/06 10:44:11 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_cheapest_move
{
	int	index;
	int	nb_moves_needed;
}	t_cheapest_move;

typedef struct s_stack_elem
{
	int					value;
	struct t_stack_elem	*next;
	struct t_stack_elem	*prev;
}	t_stack_elem;

typedef struct s_stack
{
	t_stack_elem	*stack_elem;
	int				size;
}	t_stack;

#endif