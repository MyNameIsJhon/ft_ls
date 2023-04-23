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

char  *ls_make_rights(ls_files *file) // crée une chaine alloué servanmt à afficher les droit comme dans ls
{
    int nb = file->st_perm;
    char right[10] = "----------";

    char *right_return;

    int right_nb[3];

    int i = 0;
    int y = 1;

    if(!file)
        return NULL;

    if(nb == 0)
        return ft_strdup("----------");

    right_nb[0] = nb / 100; //root
    right_nb[1] = (nb - right_nb[0]) / 10;//admin
    right_nb[2] = nb - right_nb[0] - right_nb[1]; //user

    while(right[i] != '\0')
    {
        if(file->d_type == (char) 4)
            right[0] = 'd';
        while(i < 3)
        {
            if(right_nb[i] - 4 >= 0)
            {
                right[y] = 'r';
                right_nb[i] -= 4;
            }
            y++;
            if(right_nb[i] - 2 >= 0)
            {
                right[y] = 'w';
                right_nb[i] -= 2;
            }
            y++;
            if(right_nb[i] - 1 >= 0)
            {
                right[y] = 'x';
                right_nb[i] -= 1;
            }
            y++;

            i++;
        }
    }

    right_return = ft_strdup(right);

    return right_return;
}


void ls_display(ls_files **pt_file)
{
    ls_files *curr_file = *pt_file;

    while(curr_file != NULL)
    {
        if(curr_file->a_name[0] != '.')
            printf("%s   ", curr_file->str_time);
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