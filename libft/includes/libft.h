/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:49:34 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 14:13:43 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK "\033[22;31m"
# define GREEN "\033[22;32m"
# define BROWN "\033[22;33m"
# define BLUE "\033[22;34m"
# define MAGENTA "\033[22;35m"
# define CYAN "\033[22;36m"
# define GRAY "\033[22;37m"
# define DARK_GRAY "\033[01;30m"
# define LIGHT_RED "\033[01;31m"
# define LIGHT_GREEN "\033[01;32m"
# define YELLOW "\033[01;33m"
# define LIGHT_BLUE "\033[01;34m"
# define LIGHT_MAGENTA "\033[01;35m"
# define LIGHT_CYAN "\033[01;36m"
# define WHITE "\033[01;37m"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy (void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_ncat(char *dest, const char *src, size_t n1, size_t n2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *str, const char *tofind, size_t len);
char			*ft_epur(char *line, char c);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_lowercase(char **res);
void			ft_uppercase(char **res);
int				ft_match(char *s1, char *s2);
int				ft_nbdigit(int value, int base);
int				ft_nb_word(char **tab);
int				ft_abs(int nb);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strsubdel(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoindel(char *s1, const char *s2);
char			*ft_strjoinddel(char *s1, char *s2);
char			*ft_strnjoinddel(char *s1, char *s2, int len1, int len2);
char			*ft_strnjoindel(char *s1, char *s2, int len1, int len2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar(char c);
void			ft_putchare(char c);
void			ft_putstr(char const *s);
int				ft_putnstr(char *s, size_t len);
void			ft_puterr(char *s);
void			ft_puterrnl(char *s);
void			ft_putcolor(char *str, char *color);
void			ft_putcolornl(char *str, char *color);
char			*ft_itoa(int n);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_uitoa_base(uintmax_t value, int base);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbrcolor(int nb, char *color);
void			ft_putnbrcolornl(int nb, char *color);
void			ft_swapstr(char **s1, char **s2);
void			*ft_realloc(void *ptr, int old, int new);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_lstaddlast(t_list **alst, t_list *new);
void			ft_putlst(t_list *lst);
int				ft_power(int n, int p);
int				ft_sqrt(int nb);
t_list			*ft_strsplitlist(char const *s, char c);
int				ft_issort(int *tab, int length, int (*f)(int, int));
void			ft_list_sort(t_list	**begin_list, int(*cmp)());
void			ft_list_reverse(t_list **begin_list);
void			ft_list_clear(t_list **begin_list);
int				ft_list_size(t_list *begin_list);
t_list			*ft_list_at(t_list *begin_list, unsigned int i);

#endif
