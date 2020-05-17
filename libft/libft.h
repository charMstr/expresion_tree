/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:37:31 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:57:52 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}					t_dlist;

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putbits_fd(char c, int fd);
void				ft_putbytes_fd(void *thing, int sizeof_thing, \
		int sizeof_elem, int fd);

void				ft_free(void **ptr);
void				*ft_calloc(size_t count, size_t size);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_swap(void *thing_1, void *thing_2, int size_of_thing);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strichr(const char *str, char c);
int					ft_stristr(const char *str, char *stack);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
char				*ft_strrev(char *str);
int					ft_atoi(const char *str);
int					ft_size_num_base(int num, int base);

char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcdel(char **str, size_t index);
int					ft_strcadd(char **str, char c, size_t index);
int					ft_strappend(char **str, char c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_itoa_base(int number, int base);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_stringify(char *line);
char				**ft_split(char const *s, char c);

char				**ft_array_dup(char **array);
void				*ft_array_free(char ***ptr, int k);
int					ft_array_len(const char **array);
char				**ft_array_add(char **array, char *str);
t_list				*ft_array_to_lst(const char **array);
void				ft_array_debug(char **str);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_cmp(t_list **alst, t_list *new, int (*cmp)());
t_list				*ft_lstget_front(t_list **alst);
t_list				*ft_lstget_back(t_list **alst);
t_list				*ft_lstget_cmp(t_list **alst, void *content_ref, int (*cmp)());
void				ft_lstdel_front(t_list **alst, void	(*del)(void *));
void				ft_lstdel_back(t_list **alst, void	(*del)(void *));
void				ft_lstdel_cmp(t_list **alst, void *data_ref, int (*cmp)(),\
		void (*del)(void *));
void				ft_lstuniq(t_list **alst, int (*cmp)(), \
		void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstiter_cmp(t_list *lst, void (*f)(void *), \
		int (*cmp)(), void *content_ref);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstfind(t_list *alst, void *content_ref, int (*cmp)());
t_list				*ft_lstrev(t_list *lst);
void				ft_lstsort(t_list **alst, int (*cmp)());
void				ft_lstmerge(t_list **alst1, t_list *lst2, int (*cmp)());
int					ft_lstloop_proof(t_list *turtle);
t_dlist				*ft_lst_to_dlst(t_list *lst, void *(*dup_content)(void *),\
		void (*del)(void *));

t_dlist				*ft_dlstnew(void *content);
void				ft_dlstadd_back(t_dlist **alst, t_dlist *new);
void				ft_dlstadd_front(t_dlist **alst, t_dlist *new);
t_dlist				*ft_dlstfirst(t_dlist *lst);
t_dlist				*ft_dlstlast(t_dlist *lst);
void				ft_dlstclear(t_dlist **lst, void (*del)(void *));
void				ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void				ft_dlstdel_back(t_dlist **head, void (*del)(void*));
void				ft_dlstdel_front(t_dlist **head, void (*del)(void*));

#endif
