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



void *ft_ls(char *path, ls_files **pt_files)
{
    DIR *dir = NULL;

    ls_files *file;

    ls_files *dr_file = NULL;
    ls_files **ptdr_files = &dr_file;

    struct dirent *entry = NULL;
    struct stat file_stat;

    char  path_st;

    char sep = '/';

    int i = 0;

    dir = opendir(path); // non identifié

    if(dir == NULL)
    {
        ft_putstr("Erreur lors de l'allocation de dir\n");
        return NULL;
    }


    
    while(((entry = readdir(dir)) != NULL) && (lstat(ft_strsjoin(3, path, &sep, entry->d_name), &file_stat) == 0))
    {
        if(i == 0)
        {
            file = ls_new(&file_stat, entry);
            pt_files = &file;
        }
        else
            ls_add_back(pt_files, ls_new(&file_stat, entry));
        ft_putnbr(i++);//comment

        if(entry->d_type == 4) //récupération des répertoire
            ls_add_back(ptdr_files, ls_new(&file_stat, entry));

        closedir(dir);
        path = ft_strsjoin(3, path, &sep, entry->d_name);
        dir = opendir(path);
    }

    
    while(file != NULL)
    {
        ft_printf("%s  ", file->entry->d_name);
        file = file->next;;
    }

    while(dr_file->next != NULL)
    {
        ft_ls(ft_strjoin(path, dr_file->entry->d_name), &dr_file);
        dr_file = dr_file->next;
    }

    free(path);
    ls_free(pt_files);
    ls_free(ptdr_files);

    closedir(dir);
}


int main(int argc, char **argv)
{
    char *papa;
    papa = ft_strsjoin(4, "papaoutai", "papanesaispas", "jaque");

    ft_putstr(papa);


    return 0;
}
