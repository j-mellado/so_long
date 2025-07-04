/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:38:14 by jmellado          #+#    #+#             */
/*   Updated: 2024/11/22 14:35:32 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t count);

#endif
