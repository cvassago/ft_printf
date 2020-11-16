/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:41:02 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/30 17:02:56 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	save_line(char **line, char **arr)
{
	size_t	i;
	char	*tmp;

	i = -1;
	if (*arr == NULL)
		return (0);
	while ((*arr)[++i] != '\n')
	{
		if ((*arr)[i] == '\0')
		{
			*line = ft_strdup(*arr);
			ft_strdel(arr);
			return (i == 0 ? 0 : 1);
		}
	}
	*line = ft_strsub(*arr, 0, i);
	tmp = ft_strsub(*arr, i + 1, ft_strlen(*arr) - i - 1);
	ft_strdel(arr);
	*arr = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;
	static char	*arr[OPEN_MAX];

	if (fd > OPEN_MAX || fd < 0 || read(fd, buf, 0) || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		tmp = ft_strjoin(arr[fd], buf);
		free(arr[fd]);
		arr[fd] = tmp;
		if (ft_strchr(arr[fd], '\n'))
			break ;
	}
	return (save_line(line, &arr[fd]));
}
