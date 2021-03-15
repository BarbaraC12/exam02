#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

static char	*join_char(char *str, char c)
{
	int i = 0;
	char *out = malloc(ft_strlen(str) + 2);
	if (!out)
		return NULL;
	while (str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = c;
	out[i + 1] = 0;
	free(str);
	return out;
}

int	get_next_line(char **line)
{
	char buff[1];
	int ret = 1;

	*line = malloc(1);
	**line = 0;
	while (ret > 0)
	{
	      ret = read(0, buff, 1);
	      if (buff[0] == '\n')
		      break;
	      *line = join_char(*line, buff[0]);
	}
	return ret;
}
