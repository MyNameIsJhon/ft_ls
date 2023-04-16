#include <stdarg.h>
#include <stddef.h>
#include "list.h"
#include "libft.h"

size_t ft_list_strstrlen(t_list **alst)
{
    t_list *lst;

    size_t count = 0;

    lst = *alst;

    while(lst != NULL)
    {
        lst = lst->next;
        count += ft_strlen((char*)(lst->content));
    }

    return count;
}

char *ft_listtostr(t_list **alst, char *str)
{
    t_list *lst;
    lst = *alst;

    while(lst != NULL)
    {
        ft_strcat(str, (char*) lst->content);
        lst = lst->next;
    }

    return str;
}


char *ft_strsjoin(int count, ...)
{
    va_list ap;
    t_list *lst;
    t_list **alst;
    int i = 0;

    size_t size = 0;

    char *str;

    va_start(ap, count);

    lst = ft_lstnew(ft_strdup(va_arg(ap, char*)));
    alst = &lst;

    while(i++ < count)
    {
        ft_lstadd_back(alst, ft_lstnew(ft_strdup(va_arg(ap, char*))));
    }

    size = ft_list_strstrlen(alst);

    if(!(str = (char*) malloc(sizeof(char) * size)))
        return NULL;
    str = ft_listtostr(alst, str);

    ft_lstclearall(alst, &free);

    return str;
}