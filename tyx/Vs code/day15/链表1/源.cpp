#include <stdio.h>
#include <stdlib.h>
int main()
{
	float* piVal = (float*)malloc(sizeof(float));
	*piVal = 3.14159;
	int* piCal = (int*)malloc(sizeof(int));
	*piCal = 1000;
	printf("piVal ��ָ��ĵ�ַ����Ϊ %f\n\n", *piVal);
	printf("piCal ��ָ��ĵ�ַ����Ϊ %d\n\n", *piCal);
	free(piVal);
	free(piCal);
	return 0;
}