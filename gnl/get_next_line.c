#include "get_next_line.h"

char	*joinchar(char *line, char buff)
{
	int		i = 0;
	char 	*tmp;
	
	while (line[i])
		i++;
	if (!(tmp = malloc(i + 1)))
		return NULL;
	i = 0;
	while (line[i]) {
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = buff;
	tmp[i + 1] = 0;
	return tmp;
}	

int	get_next_line(char **line)
{
	int		ret;
	char	buff;

	if (!(*line = malloc(1)))
		return -1;
	(*line)[0] = 0;
	while (ret = read(0, &buff, 1)){
		if (ret == -1) {
			free(*line);
			return (ret);
		}
		else if (ret == 1) {
			if (buff == '\n') {
				*line = joinchar(*line, 0);
				return (ret);
			}
			else
				*line = joinchar(*line, buff);
		}
	return ret
}
