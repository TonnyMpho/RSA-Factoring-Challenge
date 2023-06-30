#include <stdio.h>
#include <stdlib.h>
/**
 * factorization - Factorizing numbers into a product of two smaller numbers
 * @n: number to factorize
 * Return: Nothing
 */
void factorization(ssize_t n)
{
	ssize_t n1, n2;

	for (n1 = 2; n1 <= n / 2; n1++)
	{
		n2 = n / n1;

		if ((n1 * n2) == n)
		{
			printf("%zd=%zd*%zd\n", n, n2, n1);
			break;
		}
	}
}

/**
 * main - Entry point
 * @argc: argument counter
 * @argv: arguments array
 * Return: 0 sucess
 */
int main(int argc, char *argv[])
{
	ssize_t num;
	size_t len;
	char *buffer;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_SUCCESS);
	}

	while (getline(&buffer, &len, file) != -1)
	{
		num = atoi(buffer);
		factorization(num);
	}

	free(buffer);
	fclose(file);

	return (0);
}
