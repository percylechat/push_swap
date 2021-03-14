#include "push_swap.h"

char    *line_cpy(char *str, char *line)
{
    int len;
    int i;

    len = ft_strlen(str);
    i = 0;
    if (!(line = malloc(sizeof(char) * len)))
        return (NULL);
    while (str[i])
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char    *ft_strjoin(char *str1, char *str2)
{
    int i;
    int j;
    int len;
    char *ret;

    i = 0;
    j = 0;
    len = ft_strlen(str1) + ft_strlen(str2);
    if (!(ret = malloc(sizeof(char) * len + 1)))
        return (NULL);
    if (str1)
    {
        while (str1[i])
            ret[i] = str1[i++];
    }
    if (str2)
    {
        while (str2[j])
            ret[i++] = str2[j++];
    }
    ret[len] = '\0';
    return (ret);
}

int     get_next_line(char **line)
{
    char buf[2];
    static char *lo;
    int res;

    res = 1;
    if (!line)
        return (-1);
    while (res == 1 && buf[0] != '\n')
    {
        if((res = read(0, buf, 1)) == -1)
            return (-1);
        buf[1] = '\0';
        lo = ft_strjoin(lo, buf);
        printf("linegnl:%s\n", lo);
    }
    *line = line_cpy(lo, *line);
    free(lo);
    if (res == 1)
        return (1);
    else
        return (0);
}