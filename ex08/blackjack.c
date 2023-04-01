#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INVALID_ARG 22
#define SUCCESS 0

void	error_msg(void) {
	printf("Hand is wrong, the values accepted are ");
	printf("\e[1;33m\"A23456789TJDK\"\e[0m\n");
}

void	normalize_hand(char *hand) {
	size_t	i = 0;

	while (hand[i])
	{
		hand[i] = toupper(hand[i]);
		i++;
	}
}

void	validate_hand(char *hand) {
	size_t	i = 0;

	while (hand[i])
	{
		if (strchr("A23456789TJDK", hand[i]) == NULL)
		{
			error_msg();
			exit(INVALID_ARG);
		}
		i++;
	}
}

void	is_a_blackjack(char *hand) {
	size_t	i = 0;
	size_t	sum = 0;

	while (hand[i])
	{
		if (hand[i] == 'A' && sum + 11 <= 21)
			sum += 11;
		else if (hand[i] == 'A')
			sum += 1;
		else if (hand[i] == 'T' || hand[i] == 'J' || hand[i] == 'D' || hand[i] == 'K')
			sum += 10;
		else
			sum += hand[i] - '0';
		i++;
	}

	if (sum > 21)
		printf("%zu\n", sum);
	else
		printf("Blackjack!\n");
}

int	main(int ac, char **av) {
	if (ac != 2 || av[1] == NULL || av[1][0] == '\0')
		return (printf("Invalid hand\n"), INVALID_ARG);

	normalize_hand(av[1]);
	validate_hand(av[1]);
	is_a_blackjack(av[1]);

	return (SUCCESS);
}
