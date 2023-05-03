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

int valid_flags(char c, ls_flags *flags);
ls_flags *ls_flags_init();
ls_flags *ls_flags_set(int argc, char **argv);

#endif