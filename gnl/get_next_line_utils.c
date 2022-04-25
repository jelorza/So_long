/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:48:57 by jelorza-          #+#    #+#             */
/*   Updated: 2022/02/01 17:00:45 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_join(char *rest_buff, char *buff, int bit_counter)
{
	char	*str_joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (bit_counter == 0 && !rest_buff)
	{
		free(rest_buff);
		return (NULL);
	}
	if (rest_buff == NULL)
	{
		str_joined = malloc(sizeof(char) * (ft_strlen(buff) + 1));
		while (buff[i])
		{
			str_joined[i] = buff[i];
			i++;
		}
		str_joined[i] = 00;
	}
	else
		str_joined = ft_str_joined(rest_buff, buff);
	return (str_joined);
}

int	ft_find_char(char *rest_buff, char c)
{
	size_t	i;

	i = 0;
	if (!rest_buff)
		return (1);
	while (rest_buff[i] != 00)
	{
		if (rest_buff[i] == c)
			return (0);
		i++;
	}	
	return (1);
}

char	*ft_str_joined(char *rest_buff, char *buff)
{
	char	*str_joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str_joined = malloc((ft_strlen(rest_buff) + ft_strlen(buff) + 1));
	while (rest_buff[i])
	{
		str_joined[i] = rest_buff[i];
		i++;
	}
	while (buff[j])
	{
		str_joined[i] = buff[j];
		i++;
		j++;
	}
	str_joined[i] = 00;
	free(rest_buff);
	return (str_joined);
}
