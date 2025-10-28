#include <stdio.h>
#include <string.h>
// Simple system using struct
typedef struct {
    char First_Name[30];
    char Last_Name[30];
    char course[30];
    float mediane;
} Student;
// pushing students
void pushingStudents(Student tab[], int num){
    int i = 0;
    while(i<num){
        printf("\n------ Student ------%d :\n", i+1);
        printf("First Name : ");
        scanf("%s", tab[i].First_Name);
        printf("Last Name :");
        scanf("%s", tab[i].Last_Name);
        printf("course : ");
        scanf("%s", tab[i].course);
        printf("mediane : ");
        scanf("%f", &tab[i].mediane);
        i++;
    }
};

// show the table 

void showArrayStudents(Student tab[], int num){
    int i = 0;
    printf("================= student Liste =================\n");
    while(i< num){
        printf("%s %s | course : %s | mediane : %f", tab[i].First_Name, tab[i].Last_Name, tab[i].course, tab[i].mediane );
        printf("\n");
        i++;
    }
};

//search for a student 

int search(Student tab[], int num, char F_Name[]){
    int i = 0;
    while(i<num){
        if(strcmp(tab[i].First_Name, F_Name) == 0){
            return i;
        }
        i++;
    }
    return -1;
}

// How many students have a median >= 10
int greatMedaine(Student tab[], int num) {
    int i = 0;
    int cpt = 0; // counting
    while (i < num) {
        if (tab[i].mediane >= 10) {
            cpt++;
        }
        i++;
    }
    return cpt;
}

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
     // function show
    showArrayStudents(students, num);
    //counting function 
    printf("\n==== The number of students with median >= 10 is: %d", greatMedaine(students, num));

    // function search for a student
    
    char name[30];
    
    printf("\n====>Search for student name : ");
    scanf("%s", name);
    
    int studentNameExist = search(students, num, name);
    
    if(studentNameExist != -1){
        printf("\n Student exist : %s | %s | mediane: %.2f",students[studentNameExist].First_Name, 
       students[studentNameExist].Last_Name, 
       students[studentNameExist].mediane);
    } else{
        printf("This name doesn't exist ;( !");
    }
    return 0;
}