/// <ID>C001</ID>
/// <date>2020/11</date>
/// <summary>
/// �Ӽ�������һ��С�ڵ���1000��������x
/// �����ƽ������Ϊ��������������������1000
/// �����0��������������һ������ֱ��С�ڵ���1000
/// </summary>
/// <input>1������</input>
/// <output>�����У�0����ƽ����</output>
/// <sample>
/// 1200
/// 0
/// 1000
/// 31
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int x;
	(void)scanf("%d", &x); //�������� input a integer
	while (x > 1000 || x <= 0)
	{
		printf("0\n");
		(void)scanf("%d", &x); //������һ������ Accept next input
	}
	printf("%d\n", (int)sqrt(x));
	return 0;
}
