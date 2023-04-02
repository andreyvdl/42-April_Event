#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INVALID_ARG 22
#define SUCCESS 0
#define FALSE 0
#define TRUE 1

size_t	biggest_word(char *arg)
{
	size_t	i = 0;
	size_t	j;
	size_t	max = 0;

	while (arg[i] != '\0')
	{
		j = 0;
		while (isspace(arg[i + j]) == FALSE && arg[i + j] != '\0')
			j++;
		if (j > max)
			max = j;
		if (arg[i + j] == '\0')
			break;
		else
			i += j;
		i++;
	}
	return (max);
}

void	no_word_line(size_t max) {
	size_t	i = 0;

	write(STDOUT_FILENO, "*", 1);
	while (i < max + 2)
	{
		write(STDOUT_FILENO, "*", 1);
		i++;
	}
	write(STDOUT_FILENO, "*", 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	print_words(char *arg, size_t max) {
	size_t	i = 0;
	size_t	j;
	size_t	k = 0;

	while (arg[i] != '\0')
	{
		j = 0;
		write(STDOUT_FILENO, "*", 1);
		write(STDOUT_FILENO, " ", 1);
		while (isspace(arg[i + j]) == FALSE && arg[i + j] != '\0')
		{
			write(STDOUT_FILENO, &arg[i + j], 1);
			j++;
		}
		k = max - j;
		while (k > 0)
		{
			write(STDOUT_FILENO, " ", 1);
			k--;
		}
		write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, "*", 1);
		write(STDOUT_FILENO, "\n", 1);
		if (arg[i + j] == '\0')
			break;
		else
			i += j;
		i++;
	}
}

void	print_frame(char *arg) {
	size_t	max = biggest_word(arg);

	if (arg == NULL || arg[0] == '\0')
		return ;
	no_word_line(max);
	print_words(arg, max);
	no_word_line(max);
}

int	main(int ac, char **av) {
	if (ac < 2)
		return (INVALID_ARG);

	size_t	i = 1;

	while (av[i])
	{
		print_frame(av[i]);
		i++;
	}

	return (SUCCESS);
}
