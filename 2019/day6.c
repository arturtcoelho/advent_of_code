#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char s[4];
} str_t;

int numorbs(str_t *v1, str_t *v2, char *current, int tam){
	int i = 0;
	while(strcmp(v2[i].s, current) && (i < tam)){
		i++;
	}

	if (!strcmp(current, "COM")){
		return 0;
	}
	
	return 1 + numorbs(v1, v2, v1[i].s, tam);
}

// PART 1
// int main()
// {
// 	int tam;
// 	scanf("%d", &tam);
// 	str_t *v1, *v2;
// 	v1 = (str_t*) malloc(tam * sizeof(str_t));
// 	v2 = (str_t*) malloc(tam * sizeof(str_t));

// 	for (int i = 0; i < tam; ++i){
// 		scanf("%s %s", v1[i].s, v2[i].s);
// 	}

// 	int orbs = 0;
// 	for (int i = 0; i < tam; ++i){
// 		orbs += numorbs(v1, v2, v2[i].s, tam);
// 	}

// 	printf("%d\n", orbs);

// 	free(v1);
// 	free(v2);
// 	return 0;
// }

// PART 2
int main()
{
	int tam, tamy = 0, tams = 0;
	scanf("%d", &tam);
	str_t *v1, *v2, *vy, *vs;
	v1 = (str_t*) malloc(tam * sizeof(str_t));
	v2 = (str_t*) malloc(tam * sizeof(str_t));

	vy = (str_t*) malloc(tam * sizeof(str_t));
	vs = (str_t*) malloc(tam * sizeof(str_t));

	for (int i = 0; i < tam; ++i){
		scanf("%s %s", v1[i].s, v2[i].s);
	}

	int i = 0;
	while(strcmp(v2[i].s, "YOU"))
		i++;
	int you = i;

	i = 0;
	while(strcmp(v2[i].s, "SAN"))
		i++;
	int san = i;

	str_t current;
	current = v1[you];
	while(strcmp(current.s, "COM")){
		vy[tamy] = current;
		tamy++;
		i = 0;
		while(strcmp(v2[i].s, current.s) && i < tam)
			i++;
		current = v1[i];
	}

	current = v1[san];
	while(strcmp(current.s, "COM")){
		vs[tams] = current;
		tams++;
		i = 0;
		while(strcmp(v2[i].s, current.s) && i < tam)
			i++;
		current = v1[i];
	}

	for (int i = 0; i < tams; ++i)
	{
		printf("%s\n", vs[i].s);
	}
	// printf("\n");
	// printf("\n");
	// for (int i = 0; i < tamy; ++i)
	// {
	// 	printf("%s\n", vy	[i].s);
	// }
	// printf("\n");

	// int j;
	// for (i = 0; i < tamy && strcmp(vy[i].s, vs[j].s); ++i){
	// 	for (j = 0; j < tams && strcmp(vy[i].s, vs[j].s); ++j){

	// 	}
	// }

	// printf("i:%d, j:%d\n", i, j);

	free(v1);
	free(v2);
	return 0;
}