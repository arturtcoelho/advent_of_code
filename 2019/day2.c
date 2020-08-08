#include <stdio.h>
#include <stdlib.h>


// PART 1:
// int main(int argc, char const *argv[])
// {
// 	int op, tam, *v;

// 	scanf("%d", &tam);
// 	v = (int*)malloc(tam*sizeof(int));
// 	for (int i = 0; i < tam; ++i)
// 		scanf("%d", (v+i));

// 	int i = 0;
// 	while(v[i] != 99){
// 		switch (v[i]){
// 			case 1:
// 				v[v[i+3]] = v[v[i+2]] + v[v[i+1]];
// 				break;
// 			case 2:
// 				v[v[i+3]] = v[v[i+2]] * v[v[i+1]];
// 				break;
// 		}
// 		i += 4;
// 	}
// 	printf("%d\n", i);
// 	printf("%d\n", v[0]);
// 	return 0;
// }

// PART 2:

void copia(int *v, int *cp, int tam){
	for (int i = 0; i < tam; ++i)
		cp[i] = v[i];
}

int try(int *v, int result){
	int i = 0;
	while(v[i] != 99){
		switch (v[i]){
			case 1:
				v[v[i+3]] = v[v[i+2]] + v[v[i+1]];
				break;
			case 2:
				v[v[i+3]] = v[v[i+2]] * v[v[i+1]];
				break;
		}
		i += 4;
	}
	return (v[0] == 19690720);
}

int main(int argc, char const *argv[])
{
	int op, tam, *v, *cp;

	scanf("%d", &tam);
	v = (int*)malloc(tam*sizeof(int));
	cp = (int*)malloc(tam*sizeof(int));
	for (int i = 0; i < tam; ++i){
		scanf("%d", (v+i));
		cp[i] = v[i];
	}

	int noun, verb;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			copia(v, cp, tam);
			cp[1] = i;
			cp[2] = j;
			if (try(cp, 19690720)){
				noun = i;
				verb = j;
			}
		}
	}
	printf("%d\n", 100*noun+verb);

	return 0;
}