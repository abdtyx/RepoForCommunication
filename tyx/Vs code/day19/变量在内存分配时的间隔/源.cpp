#include <stdio.h>
int main()
{
	char a, b, c;
	char* ptr_a = &a, * ptr_b = &b, * ptr_c = &c;
	printf("a�ĵ�ַ�ǣ�%d\nb�ĵ�ַ�ǣ�%d\nc�ĵ�ַ�ǣ�%d\n", ptr_a, ptr_b, ptr_c);
	return 0;
}