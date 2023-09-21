/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:13:40 by franciscogomez    #+#    #+#             */
/*   Updated: 2023/09/21 16:14:51 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define HEXMAX "0123456789ABCDEF"
# define HEXMIN "0123456789abcdef"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

int		ft_strlen(const char *str);
int		ft_isalpha(int x);
int		ft_isdigit(int x);
int		ft_isprint(int x);
int		ft_isascii(int x);
int		ft_isalnum(int x);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strtrim(char const *str, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dest, char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
char	**ft_split(char const *s, char c);
int		    ft_printf(const char *format, ...);
int		    ft_printfc(char c);
int		    ft_printfselect(char c, va_list args);
int		    ft_printfs(char *str);
int		    ft_strlen(const char *str);
int		    ft_printfn(int n);
int		    ft_printfun(unsigned int n);
int		    ft_printfx(unsigned long long n, char *base);
int		    ft_printfp(unsigned long long n);
#endif