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



void *ft_ls(char *path, int opt)
{
    DIR *dir;
    struct dirent *entry;

    ls_files *files = NULL;
    ls_files **pt_files = &files;

    struct stat file_stat;
    char *path_stat;

    char c = '/';

    int i = 0;

    if(!(dir = opendir(path)))
        return NULL;
    if((entry = readdir(dir)) != NULL)
    {
        path_stat = ft_strsjoin(3, path, &c, entry->d_name);
        if(stat(path_stat, &file_stat))
            files = ls_new(&file_stat, entry, path_stat);//possibilitée d'ajout dans la structure
        else
            return NULL;
        free(path_stat);
    }
    else
        return NULL;
    while((entry = readdir(dir)) != NULL)
    {
        path_stat = ft_strsjoin(3, path, &c, entry->d_name);
        if(stat(path_stat, &file_stat))
            ls_add_back(pt_files, ls_new(&file_stat, entry, path_stat)); //possibilitée d'ajout dans la structure
        else
            return NULL;
        free(path_stat);
    }


    //affichage

    while(files != NULL) // en cas d'instruction récursive
    {
        if(files->entry->d_type == DT_DIR)
            ft_ls(files->path, 1);
        files = files->next;
    }

    free(path);
    ls_free(pt_files);

}

int main(int argc, char **argv)
{
    t_list *lst = NULL;
    t_list **alst = &lst;
    char *path;

    path = ft_strdup("./");

    ft_ls(path, 1);


    return 0;
}
