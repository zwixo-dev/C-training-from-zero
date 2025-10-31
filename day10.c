#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Vowels: a, e, i, o, u
void checkingVowels(char random[], int size){
    char vowels[5] = {'a','e','i','o','u'};
    int i = 0, k = 0;
    int count = 0;

    while (i < size) {
        k = 0; // reset k for every new character
        while (k < 5) {
            if (random[i] == vowels[k] || random[i] == vowels[k] - 32) { // lowercase or uppercase
                count++;
            }
            k++;
        }
        i++;
    }

    printf("\nThe number of vowels in '%s' is: %d\n", random, count);
}

int main() {
    printf("In process to execute the program...\n");
    sleep(2);

    char random[100];
    printf("Write the word: ");
    scanf("%s", random);

    int size = strlen(random);
    printf("Checking...\n");
    sleep(2);

    checkingVowels(random, size);

    return 0;
}