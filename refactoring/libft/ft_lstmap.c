#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
	t_list *new_head;
	t_list *tmp;
	t_list *curr;

	if (lst == NULL || (new_head = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	curr = new_head;
	tmp = lst->next;
	while (tmp)
	{
		if ((curr->next = ft_lstnew(f(tmp->content))) == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		curr = curr->next;
		tmp = tmp->next;
	}
	return (new_head);
}