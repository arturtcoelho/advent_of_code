#include <stdio.h>

// PART 1:
// int main(int argc, char const *argv[])
// {
// 	int n;
// 	long soma = 0;
// 	scanf("%d", &n);
// 	while (n){
// 		soma += n/3 -2;
// 		scanf("%d", &n);
// 	}
// 	printf("%ld\n", soma);
// 	return 0;
// }

// PART 2:
int main()
{
	int n, soma = 0;
	scanf("%d", &n);
	while(n){
		do
		{
			n = (n/3) - 2;
			if (n>=0)
				soma += n;
		}
		while(n >= 0);
		scanf("%d", &n);
	}
	printf("%d\n", soma);
	return 0;
}