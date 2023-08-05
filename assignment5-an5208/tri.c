#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a, b, c, p, p1, p2, p3, r;
	scanf("%d%d%d", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    p = (a + b + c)/2;
    printf("p = %d\n", p);
	p1 = p-a;
    p2 = p-b;
    p3 = p-c;
    printf("%d %d %d\n", p1, p2, p3);
    r = p*p1*p2*p3;
	printf("Area: %d", r);
	return 0;
}