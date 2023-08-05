#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int coord = n - 1;
    int ab_i = 0, ab_j = 0;
  	for(int i = 0; i < 2*n-1; i++){ 
        for(int j = 0; j < 2*n - 1; j++){
            ab_i = abs(i - coord);
            ab_j = abs(j - coord);
            if(i == coord && j == coord){
                printf("%d ", 1);
            }
            else{
                if(i == coord){
                    printf("%d ", 1 + ab_j);
                }
                else if (j == coord){
                    printf("%d ", 1 + ab_i);
                }
                else { 
                    if(ab_i > ab_j){
                        printf("%d ", 1 + ab_i);
                    }
                    else{
                        printf("%d ", 1 + ab_j);
                    }
                }
            }
        }
        printf("\n");
      }
    return 0;
}