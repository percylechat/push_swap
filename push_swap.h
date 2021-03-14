#ifndef PUSH_SWAP

# define PUSH_SWAP

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_pile t_pil;
struct s_pile{
    int *pile_a;
    int *pile_b;
    int len_a;
    int len_b;
};

/*
**rotate
*/
void rotate_b(t_pil *p);
void rotate_a(t_pil *p);
void	rrotate_b(t_pil *p);
void	rrotate_a(t_pil *p);
int dispatch_r(char *str, t_pil *p);

/*
**push
*/
int	    inc_pil_a(t_pil *p);
int	    inc_pil_b(t_pil *p);
int	    dec_pil_b(t_pil *p);
int	    dec_pil_a(t_pil *p);

/*
**push2
*/
void	push_a(t_pil *p);
void	push_b(t_pil *p);
int	    dispatch_p(char *str, t_pil *p);

/*
**swap
*/
int swap(t_pil *p, int c);
int	dispatch_s(char *str, t_pil *p);

/*
**error
*/
int ft_error(char *str);
int ft_error_free(char *str, int *pile);
int ft_error_free_st(char *str, t_pil *p);
int ft_isdigit_complete(char *str);
int check_size(char *str);

/*
**GNL
*/
char    *line_cpy(char *str, char *line);
char    *ft_strjoin(char *str1, char *str2);
int     get_next_line(char **line);

/*
**libft_utils
*/
int     ft_strlen(char *s);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		ft_strcmp(const char *s1, const char *s2);


# endif