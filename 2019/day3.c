#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x, y;
} coord_t;

int contem(coord_t c, coord_t *v, int tam){
	int i = 0;
	while(i < tam){
		if (c.x == v[i].x && c.y == v[i].y)
			break;
		i++;
	}
	return i != tam;
}

int main()
{
	char dir;
	int qnt;
	int x = 0, y = 0;
	coord_t c;
	coord_t v[153231];
	int tam = 0;

	do
	{
		scanf("%c", &dir);
		scanf("%d", &qnt);
		if (dir == 'S'){
			//printf("%d\n", qnt);
			break;
		}
		for (int i = 0; i < qnt; ++i)
		{
			if (dir == 'L' || dir == 'R')
			{
				if (dir == 'L')
					x--;
				else
					x++;
			}
			else
			{
				if (dir == 'U')
					y++;
				else
					y--;	
			}
			c.x = x;
			c.y = y;
			v[tam] = c;
			tam++;
		}
	}
	while(qnt);
	// printf("%d\n", tam);
	// for (int i = 0; i < tam; ++i)
	// {
	// 	printf("%d, %d\n", v[i].x, v[i].y);
	// }

	x = 0;
	y = 0;
	int menor = 1000000;

	do
	{
		scanf("%c", &dir);
		scanf("%d", &qnt);
		if (dir == 'S')
			break;
		for (int i = 0; i < qnt; ++i)
		{
			if (dir == 'L' || dir == 'R')
			{
				if (dir == 'L')
					x--;
				else
					x++;
			}
			else
			{
				if (dir == 'U')
					y++;
				else
					y--;	
			}
			c.x = x;
			c.y = y;
			if (contem(c, v, tam)){
				if (abs(c.x)+abs(c.y) <  menor)
					menor = abs(c.x)+abs(c.y);
			}
		}
	}
	while(qnt);
	printf("%d\n", menor);

	return 0;
}
