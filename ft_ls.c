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
    DIR *dir = NULL;
    struct dirent *entry = NULL;

    ls_files *files = NULL;
    ls_files **pt_files = &files;

    struct stat file_stat;
    char *path_stat;

    char *c = "/\0";
    

    int i = 0;

    if((dir = opendir(path)) == NULL)
        return NULL;
    back_no_recur:
    if((entry = readdir(dir)) != NULL)
    {
        if (ft_strequ(entry->d_name, ".") || ft_strequ(entry->d_name, ".."))
            goto back_no_recur;

        path_stat = ft_strsjoin(3, path, c, entry->d_name);
        if(stat(path_stat, &file_stat))
            files = ls_new(&file_stat, entry, path_stat);//possibilitée d'ajout dans la structure
        else
            files = ls_new(NULL, entry, path_stat);
        free(path_stat);
    }
    else
        return NULL;
    while ((entry = readdir(dir)) != NULL)
    {
        if (ft_strequ(entry->d_name, ".") || ft_strequ(entry->d_name, ".."))
            continue;

        path_stat = ft_strsjoin(3, path, c, entry->d_name);
        if (stat(path_stat, &file_stat))
            ls_add_back(pt_files, ls_new(&file_stat, entry, path_stat));
        else
            return NULL;
        free(path_stat);
        
    }




    ls_read(pt_files, "opts");

    while(files != NULL) 
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

    path = ft_strdup("../ft_ls");

    ft_ls(path, 1);


    return 1;

    
}
