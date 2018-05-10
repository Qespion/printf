/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:15:47 by oespion           #+#    #+#             */
/*   Updated: 2018/05/06 11:31:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 10
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>

typedef struct	s_list
{
	va_list			ap;
	void			*str;
	int				precision;
	int				width;
	int				negative;
	int				positive;
	int				zeros;
	int				blank;
	int				sharp;
}				t_list;

typedef struct	s_struct
{
	char		*str;
}				t_struct;

void			ft_putchar(char c);
int				ft_atoi(const char *str);
void			ft_putstr(char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_isalpha(int c);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
int				ft_isascii(int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_isprint(int c);
void			*ft_memset(void *b, int c, size_t len);
char			**ft_strsplit(char const *s, char c);
int				ft_toupper(int c);
char			*ft_strstr(const char *big, const char *little);
int				ft_tolower(int c);
void			ft_putnbr(int nb);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strfjoin(char const *s1, char const *s2);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_sort_int(int *lst, size_t len);
int				ft_power(int n, int power);
int				ft_abs(int nb);
int				ft_is_lowercase(char *str);
int				ft_is_uppercase(char *str);
void			ft_free_tab(char **tab);
int				get_next_line(const int fd, char **line);
void			ft_printf(const char *format, ...);
void			ft_get_arg(char letter, t_list *printef);
void			prints(t_list *printef);
void			printnb(t_list *printef);
void			printchar(t_list *printef);
void			printhexa(t_list *printef);
const char		*end_of_int(const char *str);
void			ft_putnbrn(t_list *printef);
void			ft_putstrn(t_list *printef);
void			ft_putcharn(t_list *printef);
t_list			*create_struct(void);
#endif
