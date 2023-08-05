#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Provided n triangles, sort them based on area
//Sample input: 3
//                  7 24 25
//                  5 12 13
//                  3 4 5
//Sample output:    3 4 5
//                  5 12 13
//                  7 24 25

typedef struct triangle triangle;
struct triangle
{
	int a;
	int b;
	int c;
};
//ascending
int area(triangle* t){
    double a1 = (t->a + t->b + t->c);
    return a1*(a1- 2*t->a)*(a1- 2*t->b)*(a1- 2*t->c);
}
int compare(const void* a, const void* b){
    return area((triangle*) a) - area((triangle*) b);
}
void sort_by_area(triangle* tr, int n) {
	qsort(tr, n, sizeof(*tr), compare);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
    printf("*********************\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}