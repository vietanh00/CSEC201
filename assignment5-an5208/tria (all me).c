#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
struct index{
    int area;
    int ind;
};
//ascending
int compare(const void *ptrx, const void *ptry){
    const struct index *px = ptrx;
    const struct index *py = ptry;
    return px->area - py->area; //return x - y
}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int swap_ind;
    int *areas = malloc(n * sizeof(int));
    triangle* tr_copy = malloc(n * sizeof(triangle));
    struct index *index_ar = malloc(n * sizeof(struct index));
    int a, b, c, p;
    for (int i = 0; i<n ; i++){
        a = tr[i].a;
        b = tr[i].b;
        c = tr[i].c;
        p = (a + b + c);
        areas[i] = p*(p-2*a)*(p-2*b)*(p-2*c);
        index_ar[i].area = areas[i];
        index_ar[i].ind = i;
        tr_copy[i] = tr[i];
    }
    qsort(index_ar, n, sizeof(struct index), compare);

    for(int i = 0; i< n; i++){
        swap_ind = index_ar[i].ind;
        tr[i] = tr_copy[swap_ind];
    } 
}

int main()