#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a;
	double no = 0, yes = 0;
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < 1000; i++)
	{
		a = rand() % 2;
		if (a)
		{
			no = no + 1;
			yes = yes + 1;
		}
		else
		{
			yes = yes + 1;
		}
	}
	printf("��һ�γ鲻���ĸ�����%2.3f%", 100 * no / (yes + no));
	printf("�鵽up�ĸ�����%2.3f%", 100 * yes / (yes + no));
	return 0;
}