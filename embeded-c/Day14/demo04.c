#include<stdio.h>

typedef enum type{
	BAT, BALL, ALL
}ptype_t;

typedef struct{
	char name[20];
	int age;
	ptype_t type;
	int matches;
}player_t;

char *to_string(ptype_t type)
{
	switch(type)
	{
		case BAT:	return "Batsman";
		case BALL:	return "Bolwer";
		case ALL:	return "All Rounder";
	}
	return NULL;
}


void print_player(player_t *p)
{
	printf("Player : %s %d %s %d\n", p->name, p->age, to_string(p->type), p->matches);
}


int main(void)
{
	player_t arr[3] = {
			{"abc", 28, BAT, 122},
			{"xyz", 26, BALL, 150},
			{"pqr", 29, ALL, 170}
		};

	//arr[i] - player of ith index - player_t
	
	for(int i = 0 ; i < 3 ; i++)
		print_player(&arr[i]);

	return 0;
}




















