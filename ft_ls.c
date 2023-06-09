#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include "libft.h"
#include "list.h"
#include "ls_list.h"
#include "sort_alg.h"
#include "ls_aff.h"
#include "options.h"
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


int ls_count_int_lks(char *path) //seulement activé pour ls -l
{
    DIR *dir;
    struct dirent *entry;

    size_t i = 0;

    if(!path)
        return 0;
    if(!(dir = opendir(path)))
        return 0;
    while(entry = readdir(dir))
    {
        if(ft_strcmp(entry->d_name, "..") != 0 && ft_strcmp(entry->d_name, ".") != 0)
            i++;
    }
    return i; 
    
}

void *ft_ls(char *path, ls_flags *flags)
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

    int internal_lks;

    int path_counter = ft_strlen(path);

    if(!path || !flags)
        return NULL;
    if(!(dir = opendir(path))) // le problème est ici
        return NULL;
    while(entry = readdir(dir))
    {
        if(path[path_counter-1] != '/')
            path_stat = ft_strsjoin(3, path, "/", entry->d_name);
        else
            path_stat = ft_strjoin(path, entry->d_name);

        if(flags->l == 1)
        {
            if(entry->d_type == (int) 4)// nombre internal links
                internal_lks = ls_count_int_lks(path_stat);
            else
                internal_lks = 1;
        }
        if(i == 0)
        {
            if(lstat(path_stat, &file_stat) == 0)
                file = ls_new(&file_stat, entry, path_stat, internal_lks);
            else
            {
                ls_free(pt_file);
                return NULL;
            }
        }
        else
        {
            if(lstat(path_stat, &file_stat) == 0)
                ls_add_back(pt_file, ls_new(&file_stat, entry, path_stat, internal_lks));
            else
            {
                ls_free(pt_file);
                return NULL;
            }
        }


        
        free(path_stat);
        internal_lks = 0;
        i++;
    }

    mergeSort(pt_file);//fonction servant à l'organisation


    curr_file = file;
    
    if(flags->R)
        ft_printf("%s \n", path);

    ls_display_for_all(pt_file, flags);

    if(flags->R)
        ft_putstr("\n\n");
    
    while(curr_file != NULL && flags->R == 1)//option recursif
    {
        if(curr_file->d_type == (char) 4 && ft_strcmp(curr_file->d_name, "..") != 0 && ft_strcmp(curr_file->d_name, ".") != 0 && curr_file->d_name[0] != '.')
            ft_ls(curr_file->path, flags);
        curr_file = curr_file->next;
    }
    
    closedir(dir);
    ls_free(pt_file);
}

int main(int argc, char **argv)
{
    t_list *lst = NULL;
    t_list **alst = &lst;
    ls_flags *flags;

    flags = ls_flags_set(argc, argv);

    if(!(ft_ls(flags->path, flags)))
        ft_putstr("the value you introduce is not correct ! \n\n");

    return 1; 
}
