#ifndef LS_AFF
#define LS_AFF

#include "options.h"

void ls_display(ls_files **pt_file);
void ls_display_all(ls_files **pt_file);
void ls_display_list(ls_files **pt_file, ls_flags *flags);
void ls_display_for_all(ls_files **pt_file, ls_flags *flags);

#endif