/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:30:20 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/04 05:42:03 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		(*ft_lstlast(*lst)).next = new;
		// add prev and the index?
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL); // TODO On doit free stack et ft_error()
	(*lst).value = value;
	(*lst).next = NULL;
	// TODO ajouter les prevs
	return (lst);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*buffer;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		buffer = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buffer;
	}
}
