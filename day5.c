#include <stdio.h>

// Simple system using struct
typedef struct {
    char First_Name[30];
    char Last_Name[30];
    char course[30];
    float mediane;
} Student;

void pushingStudents(Student tab[], int num){
    int i = 0;
    while(i<num){
        printf("\n------ Student ------%d :\n", i+1);
        printf("First Name : ");
        scanf("%s", &tab[i].First_Name);
        printf("Last Name :");
        scanf("%s", &tab[i].Last_Name);
        printf("First course : ");
        scanf("%s", &tab[i].course);
        printf("mediane : ");
        scanf("%f", &tab[i].mediane);
        i++;
    }
};


int main() {
    Student students[20];
    int num;

    printf("==================== Student Storage Program====================\n");

    printf("\nHow many students do you have in the class: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("You have %d student(s). I cannot execute this program.\n", num);
        return 0;
    }
    // if num >=1 execute the program 
    // function push th students
    pushingStudents(students, num);
    return 0;
}