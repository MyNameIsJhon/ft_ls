#include <libft.h>

char *recup_opt(int argc, char **argv)
{
    char *opt;
    char *opt_cp;

    int i = 1;

    opt = ft_strdup(argv[0]);

    while(i < argc)
    {
        opt_cp = ft_strjoin(opt, argv[i]);
        free(opt);
        opt = ft_strdup(opt_cp);
        free(opt_cp);
        i++;
    }

    return opt;
}

