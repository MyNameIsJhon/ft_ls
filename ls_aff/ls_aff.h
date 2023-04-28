#ifndef LS_AFF
#define LS_AFF

#include "options.h"

void ls_display_all(ls_files **pt_file);
void ls_display(ls_files **pt_file);
void ls_display_list(ls_files **pt_file);
void ls_user_display(ls_flags *flags, ls_files **pt_files);

#endif