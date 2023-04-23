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

char *ls_make_rights(ls_files *file) {
    char *rights = malloc(sizeof(char) * 11);
    if (!rights)
        return NULL;

    int nb = file->st_perm;
    rights[0] = S_ISDIR(file->st_perm) ? 'd' : '-';
    rights[1] = (nb & S_IRUSR) ? 'r' : '-';
    rights[2] = (nb & S_IWUSR) ? 'w' : '-';
    rights[3] = (nb & S_IXUSR) ? 'x' : '-';
    rights[4] = (nb & S_IRGRP) ? 'r' : '-';
    rights[5] = (nb & S_IWGRP) ? 'w' : '-';
    rights[6] = (nb & S_IXGRP) ? 'x' : '-';
    rights[7] = (nb & S_IROTH) ? 'r' : '-';
    rights[8] = (nb & S_IWOTH) ? 'w' : '-';
    rights[9] = (nb & S_IXOTH) ? 'x' : '-';
    rights[10] = '\0';

    return rights;
}


void ls_display(ls_files **pt_file)
{
    ls_files *curr_file = *pt_file;

    while(curr_file != NULL)
    {
        if(curr_file->a_name[0] != '.')
            printf("%d   ", curr_file->int_links);
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

void ls_display_list(ls_files **pt_file)
{
    ls_files *file = *pt_file;

    while(file != NULL)
    {
        if(ft_strcmp(file->d_name, "..") != 0 && ft_strcmp(file->d_name, ".") != 0 && file->d_name[0] != '.')
            ft_printf("%s  %d  %s  %s  %d  %s  %s\n", ls_make_rights(file), file->int_links, file->pw_name, file->pw_name, file->st_size, file->str_time, file->d_name);
        file = file->next;
    }
}