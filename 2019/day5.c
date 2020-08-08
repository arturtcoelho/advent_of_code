#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ADD 1
#define MULT 2
#define SCAN 3
#define PRINT 4
#define JT 5
#define JF 6
#define SLT 7
#define SEQ 8
#define HALT 99


void add(int *v, int i, int *op);
void mult(int *v, int i, int *op);
void scan(int *v, int i, int *op);
void print(int *v, int i, int *op);
int jumptrue(int *v, int i, int *op);
int jumpfalse(int *v, int i, int *op);
void setlessthan(int *v, int i, int *op);
void setequal(int *v, int i, int *op);

void set_opcode(int *v, int i, int *op);

// PART 1/2:
int main(int argc, char const *argv[])
{
	int opcode, tam;

	int op[4], *v;

	scanf("%d", &tam);
	v = (int*)malloc(tam*sizeof(int));
	for (int i = 0; i < tam; ++i)
		scanf("%d", (v+i));

	int ip = 0;
	while(v[ip] != HALT){
		set_opcode(v, ip, op);

		switch (op[0]){
			case ADD: //add
				add(v, ip, op);
				ip += 4;
				break;
			case MULT: //mult
				mult(v, ip, op);
				ip += 4;
				break;
			case SCAN: //scan
				scan(v, ip, op);
				ip += 2;
				break;
			case PRINT: //print
				print(v, ip, op);
				ip += 2;
				break;
			case JT:
				ip += jumptrue(v, ip, op);
				break;
			case JF:
				ip += jumpfalse(v, ip, op);
				break;
			case SLT:
				setlessthan(v, ip, op);
				ip += 4;
				break;
			case SEQ:
				setequal(v, ip, op);
				ip += 4;
				break;
			default: 
				printf("erro\n");
				exit(1);
		}
	}
	printf("\n");
	return 0;
}

void add(int *v, int i, int *op){
	int a, b;

	a = op[1]?v[i+1]:v[v[i+1]];

	b = op[2]?v[i+2]:v[v[i+2]];

	v[v[i+3]] = a + b;
}

void mult(int *v, int i, int *op){
	int a, b;

	a = op[1]?v[i+1]:v[v[i+1]];

	b = op[2]?v[i+2]:v[v[i+2]];

	v[v[i+3]] = a * b;
}

void scan(int *v, int i, int *op){
	scanf("%d", &v[v[i+1]]);
}

void print(int *v, int i, int *op){
	printf("%d, ", op[1]?v[i+1]:v[v[i+1]]);
}

int jumptrue(int *v, int i, int *op){
	int a, b;

	a = op[1]?v[i+1]:v[v[i+1]];

	b = op[2]?v[i+2]:v[v[i+2]];

	if (a)
		return b-i;
	return 3;
}

int jumpfalse(int *v, int i, int *op){
	int a, b;

	a = op[1]?v[i+1]:v[v[i+1]];

	b = op[2]?v[i+2]:v[v[i+2]];

	if (!a)
		return b-i;
	return 3;
}

void setlessthan(int *v, int i, int *op){
	int a, b;

	a = op[1]?v[i+1]:v[v[i+1]];

	b = op[2]?v[i+2]:v[v[i+2]];

	v[v[i+3]] = (a < b?1:0);
}

void setequal(int *v, int i, int *op){
	int a, b;

	a = op[1]?v[i+1]:v[v[i+1]];

	b = op[2]?v[i+2]:v[v[i+2]];

	v[v[i+3]] = (a==b);
}

void set_opcode(int *v, int ip, int *op){
		int opcode = v[ip];
		op[0] = opcode%100;
		opcode = opcode/100;
		op[1] = opcode%10;
		opcode = opcode/10;	
		op[2] = opcode%10;
		opcode = opcode/10;	
		op[3] = opcode%10;
		opcode = opcode/10;	
}