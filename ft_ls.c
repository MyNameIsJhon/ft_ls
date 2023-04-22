#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include "libft.h"
#include "list.h"
#include "ls_list.h"
#include "sort_alg.h"
#include "ls_aff.h"
#include <string.h>



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
    ls_files *file;
    ls_files **pt_file = &file;

    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    ls_files *curr_file;

    char *path_stat;

    int i = 0;

    int y = 0;


    if(!path || !opt)
        return NULL;
    if(!(dir = opendir(path)))
        return NULL;
    while(entry = readdir(dir))
    {
        path_stat = ft_strsjoin(3, path, "/", entry->d_name);

        if(i == 0)
        {
            if(lstat(path_stat, &file_stat) == 0)
            {
                file = ls_new(&file_stat, entry, path_stat);
            }
            else
            {
                ls_free(pt_file);
                return NULL;
            }
        }
        else
        {
            if(lstat(path_stat, &file_stat) == 0)
            {
                ls_add_back(pt_file, ls_new(&file_stat, entry, path_stat));
            }
            else
            {
                ls_free(pt_file);
                return NULL;
            }
        }
        free(path_stat);
        i++;
    }

    mergeSort(pt_file);//fonction servant à l'organisation

    curr_file = file;

    ls_display(pt_file);
    
    while(curr_file != NULL && opt == 0)
    {
        if(curr_file->d_type == (char) 4 && strcmp(curr_file->d_name, "..") != 0 && strcmp(curr_file->d_name, ".") != 0)
            ft_ls(curr_file->path, 1);
        curr_file = curr_file->next;
    }
    
   
    closedir(dir);
    ls_free(pt_file);
}

int main(int argc, char **argv)
{

    
    t_list *lst = NULL;
    t_list **alst = &lst;
    char *path;

    path = ft_strdup(".");//important bug ne pas assigner de "/" pour le moment en dernier caractère

    ft_ls(path, 1);


    return 1;

    
}
