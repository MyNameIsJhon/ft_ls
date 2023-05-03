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
#include "options.h"
#include <stdio.h>


size_t strlen_ls_name(ls_files **pt_file)
{
    ls_files *file;

    file = *pt_file;

    size_t len = 0;
    size_t len_curr;

    while(file != NULL)
    {
        len_curr = ft_strlen(file->d_name);
        if(len < len_curr)
            len = len_curr;
        file = file->next;
    }

    return len;
}

// Générer une chaîne d'espaces pour aligner les colonnes
char *generate_spaces(int count) {
    char *spaces = malloc(count + 1);
    for (int i = 0; i < count; i++) {
        spaces[i] = ' ';
    }
    spaces[count] = '\0';
    return spaces;
}

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
    int i = 1;
    char *str_space = NULL;

    int len_max = strlen_ls_name(pt_file);

    
    while(curr_file != NULL)
    {
        
        if(curr_file->a_name[0] != '.')
        {
            ft_putstr(curr_file->d_name);
            if(curr_file->int_links < 6)
            {
                str_space = generate_spaces(len_max - ft_strlen(curr_file->d_name) + 4);
                ft_putstr(str_space);
                free(str_space);
                if((i % 6) == 0)
                    ft_putchar('\n');
                i++;
            }
            else
            {
                ft_putstr("    ");
            }            
            
        }
        curr_file = curr_file->next;

    }
}

void ls_display_all(ls_files **pt_file)
{
    ls_files *curr_file = *pt_file;

    int i = 1;
    char *str_space = NULL;

    int len_max = strlen_ls_name(pt_file);

    while(curr_file != NULL) // all 
    {
        ft_putstr(curr_file->d_name);
        if(curr_file->int_links < 6)
        {
            str_space = generate_spaces(len_max - ft_strlen(curr_file->d_name) + 4);
            ft_putstr(str_space);
            free(str_space);
            if((i % 6) == 0)
                ft_putchar('\n');
            i++;
        }
        else
        {
            ft_putstr("    ");
        }   
        curr_file = curr_file->next;
    }
}

// Calculer le nombre maximal de caractères nécessaires pour afficher la taille des fichiers
int max_file_size(ls_files *files) {
    int max_size = 0;
    while (files) {
        int size = 0;
        long long st_size = files->st_size;
        while (st_size > 0) {
            size++;
            st_size /= 10;
        }
        if (size > max_size) {
            max_size = size;
        }
        files = files->next;
    }
    return max_size;
}


int file_size_digits(ls_files *file) {
    int size = 0;
    long long st_size = file->st_size;
    while (st_size > 0) {
        size++;
        st_size /= 10;
    }
    return size;
}



void ls_display_list(ls_files **pt_file, ls_flags *flags) // pas encore configuré pour ls -al
{
    ls_files *file = *pt_file;
    int max_space = max_file_size(*pt_file);

    char *len_spaces;

    if(flags->a == 0)
    {
        while(file != NULL)
        {
            if(ft_strcmp(file->d_name, "..") != 0 && ft_strcmp(file->d_name, ".") != 0 && file->d_name[0] != '.' )
            {
                len_spaces = generate_spaces(max_space - file_size_digits(file));
                printf("%s  %d  %s  %s  %s%d  %s  %s\n", ls_make_rights(file), file->int_links, file->pw_name, file->pw_name, len_spaces, file->st_size, file->str_time, file->d_name);
                free(len_spaces);

            }
            file = file->next;
            
        }
    }
    else if(flags->a != 0)
    {
        while(file != NULL)
        {
            len_spaces = generate_spaces(max_space - file_size_digits(file));
            printf("%s  %d  %s  %s  %s%d  %s  %s\n", ls_make_rights(file), file->int_links, file->pw_name, file->pw_name, len_spaces, file->st_size, file->str_time, file->d_name);
            free(len_spaces);
            file = file->next;
        }
    }

}

void ls_display_for_all(ls_files **pt_file, ls_flags *flags)
{
    if(flags->R == 1)
    {
        if(flags->l)
            ls_display_list(pt_file, flags);
        else if(flags->a)
            ls_display_all(pt_file);
        else
            ls_display(pt_file);
    }
    else if(flags->l)
        ls_display_list(pt_file, flags);
    else if(flags->a)
        ls_display_all(pt_file);
    else
        ls_display(pt_file);
}

