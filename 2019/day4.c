#include <stdio.h>
#include <stdlib.h>

int clear_first(int *v, int i){
	if (i-1 < 0)
		return 1;
	if (v[i-1] == v[i])
		return 0;
	return 1;
}

int clear_after(int *v, int i){
	if (i+2 > 5)
		return 1;
	if (v[i+2] == v[i])
		return 0;
	return 1;
}

int valid_passw(int pass){
	int v[6];
	int i;
	for (i = 1; i <= 6; ++i){
		v[6-i] = pass % 10;
		pass /= 10;
	}

	i = 0;
	while(i < 5 && v[i] <= v[i+1])
		i++;

	if (i != 5)
		return 0;

	i = 0;
	while(i < 5){
		if (v[i] == v[i+1]){
			if (clear_first(v, i) && clear_after(v, i))
				return 1;
		}
		i++;
	}

	return 0;
}

int main()
{
	int rbeg, rend;
	scanf("%d%d", &rbeg, &rend);
	int numpass = 0;

	for (int i = rbeg; i < rend; ++i)
		if (valid_passw(i))
			numpass++;

	printf("%d\n", numpass);

	return 0;
}