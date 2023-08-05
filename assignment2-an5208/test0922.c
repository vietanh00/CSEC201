#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
    int sum_b = 0, sum_g = 0;
    for(int i = 0; i < number_of_students; i++){
        if(i%2 == 1){
            sum_g += marks[i];
        }
        else{
            sum_b += marks[i];
        }
    }
    
    if (gender == 'g'){
        return sum_g;
    }
    else{
        return sum_b;
    }
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}