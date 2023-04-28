#ifndef OPTIONS_C
#define OPTIONS_C


typedef struct ls_flags{

    int l;
    int R;
    int a;
    int r;
    int t;

    char *path;

} ls_flags;

ls_flags *ls_flags_init();
void ret_ls_flags(char c, ls_flags *flags);
void ls_flags_set(char *str, ls_flags *flags);
ls_flags *ls_rec_flags_all(int argc, char **argv);
void free_flags(ls_flags *flags);

#endif