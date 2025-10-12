/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 05:11:56 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/06 13:46:32 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void	*f_upper(void *arr)
{
	size_t	i;
	char	*arr1;

	i = 0;
	arr1 = (char *) arr;
	while (arr1[i])
	{
		arr1[i] = ft_toupper(arr1[i]);
		i++;
	}
	return ((void *) arr1);
}

static void	ft_print(t_list *borrar)
{
	t_list	*i;

	i = borrar;
	while (i)
	{
		printf("%s \n", (char *)i->content);
		i = i->next;
	}
}

static void	delete(void *arr)
{
	free(arr);
} 
 */
static int	ft_lstnew_safe(t_list **new, t_list **tail, void *new_content,
							void (*del)(void *))
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
	{
		if (del && new_content)
			del(new_content);
		ft_lstclear(new, del);
		return (0);
	}
	tmp->content = new_content;
	tmp->next = NULL;
	if (!(*new))
		*new = tmp;
	else
		(*tail)->next = tmp;
	*tail = tmp;
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*new;
	t_list	*tail;
	void	*new_content;

	if (!f)
		return (NULL);
	new = NULL;
	tail = NULL;
	list = lst;
	while (list)
	{
		new_content = f(list->content);
		if (!ft_lstnew_safe(&new, &tail, new_content, del))
			return (NULL);
		list = list->next;
	}
	return (new);
}
/* int	main(void)
{
	t_list	*lista;
	t_list	*new;

	lista = ft_lstnew((char *)ft_strdup("uno"));
	lista->next = ft_lstnew((char *)ft_strdup("dos"));
	lista->next->next = ft_lstnew((char *)ft_strdup("tres"));
	ft_print(lista);
	new = ft_lstmap(lista, f_upper, delete);
	ft_print(new);
	ft_lstclear(&lista, delete);
	ft_lstclear(&new, delete);
	return (0);
} */
