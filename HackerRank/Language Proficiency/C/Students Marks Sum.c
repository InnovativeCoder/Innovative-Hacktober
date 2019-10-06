#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int marks_summation(int* marks, int num, char gender) {
  //Write your code here.
  int i;
    if(gender == 'b')
        i = 0;
    else
        i = 1;

    int sum=0;

    for(; i<= num; i+=2)
    {
        sum+= *(marks+i);
    }

    return sum;

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