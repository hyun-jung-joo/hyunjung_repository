#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
typedef struct student Student;

struct cClass {
	int num;
	Student s[40];
};
typedef struct cClass CClass;

void printClass(CClass* sp)
{
	int i;

	for (i = 0; i < sp->num; i++) {
		printf("%s\t", sp->s[i].name);
		printf("%d\t%d\t%d\n", sp->s[i].midterm, sp->s[i].final, sp->s[i].average);
	}
}

void printStudent(Student* pAll) 
{
	printf("%s\t", pAll->name);
	printf("%d\t%d\t%d\n", pAll->midterm, pAll->final, pAll->average);
}

void readClass(CClass* sp)
{
	int i;

	for (i = 0; i < sp->num; i++) {
		printf("Enter student name: ");
		scanf("%s", sp->s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &sp->s[i].midterm, &sp->s[i].final);
	}
}

void calculateClassAverage(CClass* sp)
{
	int i;

	for (i = 0; i < sp->num; i++) {
		sp->s[i].average = (sp->s[i].midterm + sp->s[i].final) / 2;
	}
}

void calculateAll(CClass* cp, Student* pAll)
{
	int i;

	for (i = 0; i < cp->num; i++) {
		pAll->midterm += cp->s[i].midterm;
		pAll->final += cp->s[i].final;
		pAll->average += cp->s[i].average;
	}

	pAll->midterm /= cp->num; // cp->num 학생수 만큼 나누기
	pAll->final /= cp->num;
	pAll->average /= cp->num;
}


int main(void)
{
	CClass cp;

	Student all = { "All", 0, 0, 0 };

	printf("Enter a number of student:");
	scanf("%d", &cp.num);

	readClass(&cp);

	calculateClassAverage(&cp);

	printf("\n 이름\t 중간\t 학기말\t 평균\n");
	printClass(&cp);

	calculateAll(&cp, &all);
	printf("----------------------------------\n");
	printStudent(&all);
}