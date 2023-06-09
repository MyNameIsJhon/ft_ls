#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <time.h>
#include "libft.h"
#include "list.h"
#include "ls_list.h"

char *ft_strdup_time(const char *s)// me crée une chaine de caractere alloué (important de free !)
{
    char *str;
    int i = 0;
    size_t n = ft_strlen((char*) s);

    if(!(str = (char*) malloc((sizeof(char) * n) + 1)))
        return NULL;
    ft_memmove((void*) str, (const void*) s, n);

    str[n-1] = '\0';
    
    return str;
}



ls_files *ls_new(struct stat *file_stat, struct dirent *entry, char *path, int internal_lks)
{
    ls_files *file;
    struct passwd *userInfos;

    if(!file_stat || !entry)
        return NULL;
    if(!(file = (ls_files*) malloc(sizeof(ls_files))))
        return  NULL;

    file->path = NULL;
    ft_strcpy(file->d_name, entry->d_name);
    file->d_type = entry->d_type;
    file->st_uid = file_stat->st_uid;
    file->st_gid = file_stat->st_gid;
    file->st_size = file_stat->st_size;
    file->st_atim = file_stat->st_atime;
    file->str_time = ft_strdup_time(ctime((const __time_t*) &file->st_atim));
    file->a_name = ft_strdup(file->d_name);
    ft_str_tolower(file->a_name);
    file->st_perm = file_stat->st_mode;

    file->int_links = internal_lks;
    

    userInfos = getpwuid(file->st_uid);
    file->pw_name = ft_strdup(userInfos->pw_name);

    file->path = ft_strdup(path);

    file->next = NULL;
    
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

size_t ls_size(ls_files **pt_file)
{
    ls_files *file;
    size_t i = 0;

    file = *pt_file;

    while(file != NULL)
    {
        file = file->next;
        i++;
    }

    return i ;
}

void ls_add_back(ls_files **pt_files, ls_files *file)
{
    ls_files *curs = NULL;

    if(!(*pt_files) || !file)
        return;
    curs = ls_last(pt_files);

    curs->next = file;
}

void ls_add_front(ls_files **pt_files, ls_files *file)
{
    if(!(*pt_files) || !file)
        return;
    file->next = *pt_files;
    pt_files = &file;
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
    ls_files *file = *pt_files;
    ls_files *next_file;

    while (file) {
        next_file = file->next;
        free(file->pw_name);
        free(file->path);
        free(file->str_time);
        free(file->a_name);
        free(file);
        file = next_file;
    }
    *pt_files = NULL;
}