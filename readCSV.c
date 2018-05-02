//Reads a CSV of format
//<char[13]>, <char[30]>, <char>, <int>, <char>, <float>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char idno[14];
	char name[30];
	char gender;
	int age;
	char res_status;
	float cgpa;
	char emailaddress[40];
} STUD; 

typedef struct { int size; STUD *studPtr;} ELEM_STRUCT;

void populateStudentDetails(STUD *s, char x);
void printData(STUD *s, int items);
ELEM_STRUCT readCSV();


int main(){
	ELEM_STRUCT a = readCSV();
	//printf("\nIN MAIN(): %p\t%d\n", a.studPtr, a.size);
	printData(a.studPtr, a.size);
	return 0;
}

ELEM_STRUCT readCSV(){
	char x;
	STUD *retPtr;
	int no = 0;
	while((x = getchar()) != EOF) {
		printf("%c\n", x);
		if(no == 0){ 
			printf("%d\n", no + 1);
			retPtr = (STUD*)malloc(sizeof(STUD));
			no++;
		}
		else{
			retPtr = (STUD*)realloc(retPtr, sizeof(STUD) * (++no));	
			printf("%d\n", no);
		}
		populateStudentDetails(retPtr + no - 2, x);
	}
	//printf("\nOUT OF WHILE LOOP IN READCSV()");
	ELEM_STRUCT a;
	a.size = no;
	a.studPtr = --retPtr;
	//printf("\nREAD CSV SUCCESSFULLY");
	//printf("\nRETURNED: %p\t%p\n", retPtr, a.studPtr);
	return a;
}

void populateStudentDetails(STUD *s, char idMissing) {
	s->idno[0] = idMissing;	
	scanf("%[^,]", s->idno + 1);
	printf("Input: %s\n", s->idno);
	getchar();
	scanf("%[^,]", s->name);
	printf("Input: %s\n", s->name);
	getchar();
	s->gender = getchar();
	printf("Input: %c\n", s->gender);
	getchar();
	scanf("%d", &s->age);
	printf("Input: %d\n", s->age);
	getchar();
	s->res_status = getchar();
	printf("Input: %c\n", s->res_status);
	getchar();
	scanf("%f", &s->cgpa);
	getchar();
	printf("Input: %f\n", s->cgpa);
}

void printData(STUD *s, int items) {
	//printf("\nIN PRINTDATA() FUNCTION\n");
	//printf("\nRECIEVED: %p\t", s);
	for(int i = 0; i < items; i++) {
		printf("%s\t%s\t%c\t%d\t%c\t%f\n",(s+i)->idno,(s+i)->name,(s+i)->gender,(s+i)->age,(s+i)->res_status,(s+i)->cgpa);
	}
	//printf("\nOUT OF PRINTDATA() FUNCTION\n");
}
