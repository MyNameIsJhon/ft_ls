#include <libft.h>
#include "options.h"
#include "list.h"

int valid_flags(char c, ls_flags *flags) //retourne 1 si valide et 0 si non, permet de set les drapeaux
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
    else
        return 0;
    return 1;

}

ls_flags *ls_flags_init()
{
    ls_flags *flags;

    if(!(flags = (ls_flags*) malloc(sizeof(ls_flags))))
        return NULL;

    flags->l = 0;
    flags->R = 0;
    flags->a = 0;
    flags->r = 0;
    flags->t = 0;

    flags->path = NULL;
}

ls_flags *ls_flags_set(int argc, char **argv)
{
    int i = 1;
    int y = 1;                              //commence à 1 car 1 = ./ft_ls
    ls_flags *flags = ls_flags_init();

    if(argc == 1 || flags == NULL)
        return NULL;
    while(i < argc)
    {
        if(argv[i][0] == '-')
        {
            while(valid_flags(argv[i][y], flags))
                y++;
            y = 0;
        }
        else if(flags->path == NULL)
            flags->path = ft_strdup(argv[i]); // chaine à libéré et erreur possible en cas de mauvaise introduction du path
        i++;
    }

    return flags;
}