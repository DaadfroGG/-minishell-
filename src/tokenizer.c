#include <minishell.h>

t_arg *new_arg(void)
{
    t_arg *new;

    new = malloc(sizeof(t_arg));
    if (!new)
        return (NULL);
    new->arg = NULL;
    new->type = 0;
    new->right = NULL;
    new->left = NULL;
    return (new);
}