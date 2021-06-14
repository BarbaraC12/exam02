#include <unistd.h>

void ft_union(int argc, char **argv)
{
	int tab[255] = {0};
	int i, j;

	if (argc == 3)
	{	
		i = 1;
		while (i < 3)
		{
			j = 0;	
			while (argv[i][j])
			{	
				if (!tab[(unsigned char)argv[i][j]])
				{
					tab[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

void ft_inter(int argc, char **argv)
{
	int tab[255] = {0};
	int i, j;

	if (argc == 3)
	{
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !tab[(unsigned char)argv[i][j]])
					tab[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && tab[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					tab[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}	
	}
	write(1, "\n", 1);
}

int main(int argc, char *argv[])
{
	ft_inter(argc, argv);
	ft_union(argc, argv);

	return 0;
}

