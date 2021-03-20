/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:06:37 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/19 20:11:31 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 50

typedef struct s_pile	t_pil;
struct					s_pile{
	int					*pile_a;
	int					*pile_b;
	int					len_a;
	int					len_b;
};

/*
**pile_handling
*/
int						ft_ko(t_pil *p, int c);
int						check_is_ordered(t_pil *p, int c);
void					start_piles(t_pil *p, int *pile_a, int len_a);
void					print_b(t_pil *p);
void					print_pile(t_pil *p);

/*
**rotate
*/
void					rotate_b(t_pil *p);
void					rotate_a(t_pil *p);
void					rrotate_b(t_pil *p);
void					rrotate_a(t_pil *p);
int						dispatch_r(char *str, t_pil *p);

/*
**push
*/
int						inc_pil_a(t_pil *p);
int						inc_pil_b(t_pil *p);
int						dec_pil_b(t_pil *p);
int						dec_pil_a(t_pil *p);

/*
**push2
*/
int						push_a(t_pil *p);
int						push_b(t_pil *p);
int						dispatch_p(char *str, t_pil *p);

/*
**swap
*/
void					swap(t_pil *p, int c);
int						dispatch_s(char *str, t_pil *p);

/*
**error
*/
int						ft_error(char *str);
int						ft_error_free(char *str, int *pile);
int						ft_error_free_st(char *str, t_pil *p);
int						ft_isdigit_complete(char *str);
int						check_size(char *str);

/*
**GNL
*/
char					*ft_strdup_gnl(const char *src);
char					*ft_strjoin_gnl(char *s1, char *s2);
int						ft_chrlen_gnl(const char *s, char c);
char					*ft_check_reste(char *reste);
char					*ft_substr_gnl(char const *s, int start, int len);
char					*new_buffer(char *buffer, char *reste);
char					*ft_run(char *reste, char *buffer, char **line);
char					*ulti_run(char *reste, char **line, int bs);
char					*ft_run_end(char *reste, char **line);
int						get_next_line(int fd, char **line);

/*
**libft_utils
*/
int						ft_strlen(char *s);
int						ft_isdigit(int c);
int						ft_atoi(char *str);
int						ft_strcmp(const char *s1, const char *s2);

/*
**ft_itoa
*/
char					*ft_itoa(int n);

#endif
