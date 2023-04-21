#include "libft.h"
#include "ls_list.h"
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>

void ls_mid_colums_order(ls_files **pt_file , ls_files **ptt_file)
{
    size_t lslen;
    ls_files *file = *pt_file;

    lslen = ls_size(pt_file) / 2;

    

    while(lslen--)
    {
        
    }
}