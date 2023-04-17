#ifndef LS_LIST 
#define LS_LIST

typedef struct ls_files{

    struct dirent *entry;
    struct stat *file_stat;

    char *path; // path à allouer en cas de -R

    struct ls_files *next;
    
} ls_files;

ls_files *ls_new(struct stat *file_stat, struct dirent *entry, char *pathfile);
ls_files *ls_last(ls_files **pt_files);
void ls_add_back(ls_files **pt_files, ls_files *file);
void ls_free(ls_files **pt_files);

#endif