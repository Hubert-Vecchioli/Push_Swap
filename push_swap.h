/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:36:44 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/05 11:18:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack_elem
{
	int				value;
	int				index;
	struct s_clist	*next;
	struct s_clist	*prev;
}	t_stack_elem;

typedef struct s_stack
{
	t_stack_elem	*stack_elem;
	int				size;
}	t_stack;

#endif