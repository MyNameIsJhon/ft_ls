#ifndef LS_LIST 
#define LS_LIST

#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>


typedef struct ls_files{

    char d_name[255];//entry
    char *a_name;
    unsigned char d_type;

    int st_perm;
    int int_links;

    __uid_t st_uid;//lstat
    __gid_t st_gid;
    __off_t st_size;


    char *pw_name;//pw..
    char *pw_group;

    __time_t st_atim; //nombre de seconde écoulé depuis le 1er janvier 1970
    char *str_time;

    char *path ;// path à allouer en cas de -R

    struct ls_files *next;
    
} ls_files;

ls_files *ls_new(struct stat *file_stat, struct dirent *entry, char *path);
ls_files *ls_last(ls_files **pt_files);
size_t ls_size(ls_files **pt_file);
void ls_add_back(ls_files **pt_files, ls_files *file);
void ls_add_front(ls_files **pt_files, ls_files *file);
void ls_read(ls_files **pt_files, char *opts);
void ls_free(ls_files **pt_files);

#endif