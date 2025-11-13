#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    float grade;
} Analyzer;

// Function to add students
void add(Analyzer *analyze, int getSize) {
    int i = 0;
    printf("\nLet's add your students!\n");
    while (i < getSize) {
        printf("\nStudent %d\n", i + 1);
        printf("→ Name: ");
        scanf("%s", analyze[i].name);
        printf("→ Grade: ");
        scanf("%f", &analyze[i].grade);
        i++;
    }
}

// Function to show grades >= 10
void gradePlus(Analyzer *analyze, int getSize) {
    int i = 0;
    printf("\nStudents with grades >= 10:\n");
    while (i < getSize) {
        if (analyze[i].grade >= 10) {
            printf("%s | %.2f\n", analyze[i].name, analyze[i].grade);
        }
        i++;
    }
}

// Function to show grades < 10
void gradeMin(Analyzer *analyze, int getSize) {
    int i = 0;
    printf("\nStudents with grades < 10:\n");
    while (i < getSize) {
        if (analyze[i].grade < 10) {
            printf("X %s | %.2f\n", analyze[i].name, analyze[i].grade);
        }
        i++;
    }
}

// Function to calculate average
void average(Analyzer *analyze, int getSize) {
    int i = 0;
    float avrg = 0;
    while (i < getSize) {
        avrg += analyze[i].grade;
        i++;
    }
    printf("\nClass average: %.2f\n", avrg / getSize);
}

// Main function
int main() {
    Analyzer *analyze;
    int size;

    printf("📚 How many students are in your class? ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Hmm... %d students? Let's try again later!\n", size);
        return 0;
    }

    analyze = malloc(sizeof(*analyze) * size);

    if (analyze == NULL) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    add(analyze, size);
    gradePlus(analyze, size);
    gradeMin(analyze, size);
    average(analyze, size);

    free(analyze);
    printf("\n Program finished successfully. Goodbye!\n");
    return 0;
}
