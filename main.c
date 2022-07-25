
#include "bf.h"

int	monitor(int c)
{
	if (c != 43 && c != 45 && c != 32 && c != 46 &&
		c != 44 && c != 91 && c != 93 && c != 60 &&
		c != 62)
		return (0);
	return (1);
}

void	parser(int **buff, char	c)
{
	if (c == '+')
		**buff += 1;
	else if (c == '-')
		**buff -= 1;
	else if (c == '>')
		*buff += 1;
	else if (c == '<')
		*buff -= 1;
	else if (c == '.')
		write(1, &(**buff), 1);
	else if (c == ',')
		**buff = (int) getchar();
}

void	interpreter(char *line)
{
	int	*buff;
	int	i;
	int	j;
	int	*tmp;

	buff = ft_calloc(sizeof(int), BUFFER_SIZE);
	tmp = buff;

	i = 0;
	while (line[i] != '\0')
	{
		if (!monitor((int) line[i]))
		{
			printf("\n\033[91mStopped!\nInvalid instruction\033[0m: '%c'\n", line[i]);
			break ;
		}
		parser(&buff, line[i]);
		if (line[i] == '[')
		{
			j = i;
			i++;
			while (line[i] != ']')
				parser(&buff, line[i++]);
			if (*buff != 0)
			{
				i = j;
				continue ;
			}
		}
		i++;
	}
	free(tmp);
}

int main(void)
{
	char	*line;
	char	*tmp;

	printf("\nWelcome to \033[93mBrainfuck Interpreter\033[0m.\n\nType exit to exit the program.\n\n");
	fflush(0);
	while (1)
	{
		write(1, "> ", 2);
		tmp = get_next_line(0);
		line = ft_replace(tmp, "\n");
		free(tmp);
		if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
			break ;
		interpreter(line);
		free(line);
	}
	free(line);
	return (0);

}
