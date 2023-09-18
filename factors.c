#include <stdio.h>
/**
 * factorize - Factorize a number into two smaller numbers.
 * @n: The number to factorize.
 */
void factorize(int n)
{
	int p = 2;

	while (p * p <= n)
	{
		if (n % p == 0)
		{
			int q = n / p;

			printf("%d=%d*%d\n", n, p, q);
			return;
		}
		p++;
	}
	printf("%d=%d*%d\n", n, n, 1);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	int n;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		return (1);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}
	while (fscanf(file, "%d", &n) != EOF)
	{
		if (n > 1)
		{
			factorize(n);
		}
	}
	fclose(file);
	return (0);
}
