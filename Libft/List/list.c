#include "libft.h"
#include "list.h"

t_list *ft_lstnew(void *content)
{
    t_list *lst;

    lst = (t_list*) malloc(sizeof(t_list));

    if(!content || !lst)
        return NULL;

    lst->content = content;
    lst->next = NULL;

    return (lst);
}

void ft_lstadd_front(t_list **alst, t_list *new)
{
    if(!alst || !new)
        return;
    new->next = *alst;
    alst = &new;
}

size_t ft_lstsize(t_list *lst)
{
    t_list *curs;
    size_t i = 0;

    curs = lst;

    while(curs->next != NULL)
    {
        curs = curs->next;
        i++;
    }
    return (i);
}

t_list *ft_lstlast(t_list *lst)
{
    t_list *curs;

    curs = lst;

    while(curs->next != NULL)
        curs = curs->next;
    return (curs);
}

void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *curs = ft_lstlast(*alst);

    if(!alst || !new)
        return;
    
    curs->next = new;
    new->next = NULL;
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if(!lst || !del)
        return;
    
    (del)(lst->content);
    free(lst);
}

void ft_lstclear(t_list **alst)
{
    t_list *curr;
    t_list *tmp;

    if(!alst)
        return;
    
    curr = *alst;

    while(curr)
    {
        tmp = curr;
        curr = curr->next;
        if(tmp != NULL)
            free(tmp);
        tmp = curr;
    }
}
void ft_lstclearall(t_list **alst, void (*f)(void*))
{
    t_list *curr;
    t_list *tmp;

    if(!alst)
        return;
    
    curr = *alst;

    while(curr)
    {
        tmp = curr;
        f(curr->content);
        curr = curr->next;
        if(tmp != NULL)
            free(tmp);
        tmp = curr;
    }
}

void ft_lstiter(t_list *lst, void (*f)(void*))
{
    t_list *curr;

    if(!lst || !f)
        return;
    while(curr)
    {
        (f)(curr->content);
        curr = curr->next;
    }
}
