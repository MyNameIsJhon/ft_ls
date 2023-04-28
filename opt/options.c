#include <libft.h>
#include "options.h"
#include "list.h"

ls_flags *ls_flags_init()
{
    ls_flags *flags;

    if(!(flags = (ls_flags*) malloc(sizeof(ls_flags))))
        return NULL;
    
    flags->a = 0;
    flags->R = 0;
    flags->l = 0;
    flags->r = 0;
    flags->t = 0;

    flags->path = NULL;

    return flags;
}

ls_flags *exit_flags(ls_flags *flags)
{
    if(flags != NULL)
        free(flags);
    return NULL;
}

void ret_ls_flags(char c, ls_flags *flags)
{
    if(c == 'l')
        flags->l = 1;
    else if(c == 'R')
        flags->R = 1;
    else if(c == 'a')
        flags->a = 1;
    else if(c == 'r')
        flags->r = 1;
    else if(c == 't')
        flags->t = 1;
}

ls_flags *ls_flags_set(char *str)
{
    ls_flags *flags = NULL; //ne pas oublier de free()

    flags = ls_flags_init();
    
    int i = 1;

    if(str[0] == '-')
    {
        while(str[i])
        {
            ret_ls_flags(str[i], flags);
            i++;
        }
    }
    else if(flags->path == NULL)
        flags->path = ft_strdup(str);
}

ls_flags *ls_rec_fall(int argc, char **argv)
{

}

