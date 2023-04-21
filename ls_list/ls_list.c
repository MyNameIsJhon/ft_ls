#include <dirent.h>

#include <pwd.h>
#include <sys/stat.h>
#include "libft.h"
#include "list.h"
#include "ls_list.h"

ls_files *ls_new(struct stat *file_stat, struct dirent *entry, char *path)
{
    ls_files *file;
    struct passwd *userInfos;

    if(!file_stat || !entry)
        return NULL;
    if(!(file = (ls_files*) malloc(sizeof(ls_files))))
        return  NULL;
        
    ft_strcpy(file->d_name, entry->d_name);
    file->d_type = entry->d_type;
    file->st_uid = file_stat->st_uid;
    file->st_gid = file_stat->st_gid;
    file->st_size = file_stat->st_size;

    userInfos = getpwuid(file->st_uid);
    file->pw_name = strdup(userInfos->pw_name);

    file->path = ft_strdup(path);
    
    return file;
}

ls_files *ls_last(ls_files **pt_files)
{
    ls_files *file = *pt_files;

    while(file->next != NULL)
    {
        file = file->next;
    }
    return file;
}

void ls_add_back(ls_files **pt_files, ls_files *file)
{
    ls_files *curs = NULL;

    if(!(*pt_files) || !file)
        return;
    curs = ls_last(pt_files);

    curs->next = file;
}

void ls_read(ls_files **pt_files, char *opts)
{
    ls_files *file = *pt_files;

    while(file != NULL)
    {
        file = file->next;
    }
}

void ls_free(ls_files **pt_files)
{
    ls_files *file = NULL;

    while((file = ls_last(pt_files)) != NULL)
        free(file);
    free(file);
}