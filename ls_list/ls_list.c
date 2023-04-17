#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"
#include "list.h"
#include "ls_list.h"

ls_files *ls_new(struct stat *file_stat, struct dirent *entry, char *pathfile)
{
    ls_files *file;

    if(!file_stat || !entry)
        return NULL;
    if(!(file = ((ls_files*) malloc(sizeof(ls_files)))))
        return NULL;

    file->entry = entry;
    file->file_stat = file_stat;
    file->path = ft_strdup(pathfile);
    file->next = NULL;
    
    return file;
}

ls_files *ls_last(ls_files **pt_files)
{
    ls_files *file = *pt_files;

    while(file->next != NULL)
        file = file->next;
    return file;
}

void ls_add_back(ls_files **pt_files, ls_files *file)
{
    ls_files *curs = ls_last(pt_files);

    if(*pt_files == NULL)
    {
        *pt_files = file;
        return;
    }
    curs->next = file;
}

void ls_free(ls_files **pt_files)
{
    ls_files *file = NULL;

    while((file = ls_last(pt_files)) != NULL)
        free(file);
    free(file);
}