#include "libft.h"
#include "ls_list.h"
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>

ls_files **ls_mid_colums_order(ls_files **pt_file)
{
    size_t lslen;
    ls_files *file = *pt_file;
    ls_files **ptt_file;
    ls_files *t_file;

    int i = 0;

    if(!(*pt_file))
        return NULL;

    lslen = ls_size(pt_file) / 2;

    while(lslen--)
    {
        if(i == 0)
        {
            pt_file = &file->next;
            ptt_file = file;
            file->next = NULL;
        }
        else
        {
            t_file = ls_last(ptt_file);
            file = *pt_file;
            pt_file = &file->next;
            file->next = NULL;
            t_file->next = file;
        }
        i++;
    }

    return ptt_file;

}