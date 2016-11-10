#include <fcntl.h>
#include "pars.h"

/*int		check_map()
{
}*/
void	conv(char *line, int j, t_tamere *e)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(line, " ");
	while (split[i])
	{
		e->map[j][i] = ft_atoi(split[i]);
		i++;
	}
}

int		ft_pars(t_tamere *e)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**split;
	int		**map;

	if (!(fd = open(O_RDONLY, fd)))
		return (0);
	i = 0;
	j = 0;
	line = NULL;
	while (get_next_line(fd, &line) != 0)
		j++;
	e->lig = j;
	split = ft_strsplit(line, " ");
	while (split[i])
		i++;
	e->col = i;
	e->map = (int **)malloc(sizeof(int *) * j);
	j = 0;
	while (get_next_line(fd, &line) != 0)
	{
		conv(line, j, e);
		j++;
	}
	return (0);
}

int		main(void)
{
	t_tamere	*e;

	e = (t_tamere *)malloc(sizeof(t_tamere));
	ft_pars(e);
	return (0);
}
