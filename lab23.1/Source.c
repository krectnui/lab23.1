#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
struct list
{
	int number;
	char name[80];
	struct listitem* next;
};
typedef struct list list;
struct list* addelem(list* lst, int number, char name[80]);
struct list* init(int a, char name[80]);
struct list* deletehead(list* root);
void listprint(list* lst);

int main() {
	setlocale(LC_ALL, "RUS");
	list* vars = init(15, "David");
	addelem(vars, 2, "Sara");
	listprint(vars);
}
struct list* init(int a, char name[80])
{
	struct list* lst;

	lst = (struct list*)malloc(sizeof(struct list));
	lst->number = a;
	strcpy(lst->name, name);
	lst->next = NULL;
	return(lst);
}
struct list* addelem(list* lst, int number, char name[80])
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next;
	lst->next = temp;
	temp->number = number;
	strcpy(temp->name, name);
	temp->next = p;
	return(temp);
}
struct list* deletehead(list* root)
{
	struct list* temp;
	temp = root->next;
	free(root);
	return(temp);
}
void listprint(list* lst)
{
	struct list* p;
	p = lst;
	while (p != NULL) {
		printf("Имя %s Число %d \n", p->name, p->number);
		p = p->next;
	}
}