#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include "libft.h"
#include "list.h"
#include "ls_list.h"



/*****************************************************************************************\
                            PETITE FICHE TRICHE FLAGS 

    -l = use a long listing format
    -R = récursive
    -a = all
    -r = reverse order
    -t = sort by timeq


    Programme devant êtres refait, à première vue les affecter les structures 
    Entry ainsi que stat directement à ma structure personnalisé causerait des 
    erreurs de mémoire. d'un autre point de vue cela affectera aussi les permorances
    car trop d'informations prise en compte pour les besoins du programme.


\****************************************************************************************/



void *ft_ls(char *path, int opt)
{
   

}

int main(int argc, char **argv)
{
    
}
