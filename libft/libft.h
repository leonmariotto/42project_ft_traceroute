/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:22:32 by llenotre          #+#    #+#             */
/*   Updated: 2020/09/04 22:59:50 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

# define FALSE	0
# define TRUE	1

# define STDIN	0
# define STDOUT	1
# define STDERR	2

void			**ft_arrdup(void **arr, const size_t content_size);
char			**ft_arrdup_str(char **arr);
void			ft_arrfree(void **arr);
void			**ft_arrinsert(void **arr, void *element);
size_t			ft_arrlen(void **arr);
void			**ft_arrremove(void **arr, const size_t index);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *s);
size_t			ft_intlen(int i);

char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
	size_t len);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(const char c);

int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(const size_t n, ...);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ft_min(const int i, const int j);
int				ft_max(const int i, const int j);
int				ft_pow(int n, unsigned int factor);
int				ft_sqrt(int n);
int				ft_fibonacci(int n);
int				ft_factorial(int n);

void			ft_swap(int *a, int *b);
void			ft_sort(void **arr, size_t size, int (*f)(void*, void*));

char			*ft_get_filename(const char *path);
char			*ft_path_merge(const char *p1, const char *p2);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstnew_nodup(void *content, size_t content_size);
size_t			ft_lstsize(const t_list *lst);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstpush(t_list **lst, t_list *new);
t_list			*ft_lstget(t_list *lst, const size_t index);
t_list			*ft_lstback(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstrev(t_list **lst);

int				ft_str_isdigit(const char *str);
void			default_del(void *content, size_t content_size);

/*
** Pedro's functions
*/
int				ft_atoibase(const char *s, const char *base);
int				ft_isblank(int c);
int				ft_isupper(int c);
char			*ft_itoabase(int n, const char *base);
size_t			ft_nbrlen(int n);
void			ft_putnstr_fd(int fd, int n, ...);
void			ft_putnstr(int n, ...);
int				ft_strcmp_casinsens(const char *s1, const char *s2);
char			*ft_strrev(char *s);
int				ft_islower(int c);
char			*ft_strnulljoin(const char *s1, const char *s2);

/*
** Leon's functions
*/

char			**ft_lsttoarr(t_list *lst);
t_list			*ft_arrtolst(char **arr);

/*
** Linda's functions
*/

t_list			*t_listdup(t_list *lst);

#endif
