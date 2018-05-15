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
	int				increment;
	int				nbout;
	int				precision;
	int				width;
	int				negative;
	int				positive;
	int				zeros;
	int				blank;
	int				neg;
	int				sharp;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
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
char			*ft_toupper(char *str);
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
void			ft_sort_int(int *lst, size_t len);
int				ft_power(int n, int power);
int				ft_abs(int nb);
int				ft_is_lowercase(char *str);
int				ft_is_uppercase(char *str);
void			ft_free_tab(char **tab);
int				get_next_line(const int fd, char **line);
int				ft_printf(const char *format, ...);
void			ft_get_arg(char letter, t_list *p);
void			prints(t_list *p);
void			printnb(t_list *p);
void			printhexa(t_list *p, int maj);
const char		*end_of_int(const char *str);
void			ft_putnbrn(t_list *p, int nbr);
void			ft_putstrn(t_list *p, char *str);
void			ft_putcharnf(t_list *p);
void			ft_putcharn(t_list *p, char c);
t_list			*create_struct(void);
char			*ft_convert_base(unsigned int nb, int base);
void			printbinary(t_list *p);
void			write_with_precision(char *str, t_list *p);
void			ft_puthexan(t_list *p, char *hexa, int oct);
t_list			*reset_struct(t_list *p);
int				int_len(unsigned int nb, int base);
int				ft_int_len(unsigned int nb);
void			printunsigned(t_list *p);
void			ft_putnbru(unsigned int nb);
void			ft_putnbrnu(t_list *p, unsigned int nbr);
void			ft_get_width(t_list *p, unsigned int nbr);
void			printoctal(t_list *p, int maj);
void			ft_gwidth(char *hexa, t_list *p, int oct);

#endif
