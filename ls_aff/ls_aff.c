/*****************************************************************************************\
                            PETITE FICHE TRICHE FLAGS 

    -l = use a long listing format
    -R = récursive
    -a = all
    -r = reverse order
    -t = sort by times


    Programme devant êtres refait, à première vue les affecter les structures 
    Entry ainsi que stat directement à ma structure personnalisé causerait des 
    erreurs de mémoire. d'un autre point de vue cela affectera aussi les permorances
    car trop d'informations prise en compte pour les besoins du programme.


\****************************************************************************************/

#include "ls_list.h"
#include "libft.h"

void ls_display(ls_files **pt_file)
{
    ls_files *curr_file = *pt_file;

    while(curr_file != NULL)
    {
        if(curr_file->a_name[0] != '.')
            printf("%o   ", curr_file->st_perm);
        curr_file = curr_file->next;
    }
}

void ls_display_all(ls_files **pt_file)
{
    ls_files *curr_file = *pt_file;

     while(curr_file != NULL) // all 
    {
        printf("%s    ", curr_file->a_name);
        curr_file = curr_file->next;
    }
}