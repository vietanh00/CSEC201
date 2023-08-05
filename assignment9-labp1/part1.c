#include< stdio.h>

int main() {
	int array[] = { 10, 20, 30 };
	char first[] = "Hello World!";
	char second[] = "Hi there!";
	printf("first = %s at %p\n", first, first);
	printf("second = %s at %p\n", second, second);
	scanf("%s", second);
	//Input that causes overflow as specified: 40 characters, then ABCDEFGH
	printf("first = %s\n", first);
	printf("second = %s\n", second);
	return 0;
}