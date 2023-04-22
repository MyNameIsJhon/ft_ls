#include "libft.h"
#include "ls_list.h"
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>

ls_files* merge(ls_files* left, ls_files* right)
{
    ls_files* result = NULL;
    
    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    
    if(ft_strcmp(left->a_name, right->a_name) <= 0)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void split(ls_files* source, ls_files** frontRef, ls_files** backRef)
{
    ls_files* fast;
    ls_files* slow;
    slow = source;
    fast = source->next;
    
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void mergeSort(ls_files** headRef)
{
    ls_files* head = *headRef;
    ls_files* left;
    ls_files* right;
    
    if((head == NULL) || (head->next == NULL))
        return;
    
    split(head, &left, &right);
    
    mergeSort(&left);
    mergeSort(&right);
    
    *headRef = merge(left, right);
}