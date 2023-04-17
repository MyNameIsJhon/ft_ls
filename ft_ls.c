#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"
#include "list.h"
#include "ls_list.h"

/*******************************************************************\
                            PETITE FICHE TRICHE FLAGS 

    -l = use a long listing format
    -R = récursive
    -a = all
    -r = reverse order
    -t = sort by timeq


\********************************************************************/



int main(int argc, char **argv)
{
    t_list *lst = NULL;
    t_list **alst = &lst;

    // papa = ft_strsjoin(2, "papaoutai", "papanesaispas", "jaque");

    char* str = ft_strsjoin(3, "sasa", "mama", "lolo");

    ft_printf("%s \n", str);

    free(str);

    return 0;
}
