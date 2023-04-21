#ifndef LS_LIST 
#define LS_LIST

typedef struct ls_files{

    char d_name[255];//entry
    unsigned char d_type;

    __uid_t st_uid;//lstat
    __gid_t st_gid;
    __off_t st_size;

    char *pw_name;//pw..
    char *pw_group;

    char *path; // path à allouer en cas de -R

    struct ls_files *next;
    
} ls_files;

ls_files *ls_new(struct stat *file_stat, struct dirent *entry, char *path);
ls_files *ls_last(ls_files **pt_files);
void ls_add_back(ls_files **pt_files, ls_files *file);
void ls_read(ls_files **pt_files, char *opts);
void ls_free(ls_files **pt_files);

#endif