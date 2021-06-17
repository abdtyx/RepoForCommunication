/// <ID>C067</ID>
/// <date>2020/11</date>
/// <summary>
/// д������������λ�ֽڸ�ʽ���磬���û�����82668634ʱ������Ӧ�����82,668,634��
/// </summary>
/// <input>������</input>
/// <output>��λ�ֽ��ʽ</output>
/// <sample>
/// 82668634
/// 82,668,634
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n;
	(void)scanf("%d", &n);

	char num[200];
	int i = 0;

	while (n)
	{
		if ((i + 1) % 4 == 0) //�Ӷ��ŵ�λ��
		{
			num[i++] = ',';
		}
		num[i++] = n % 10 + '0'; //����ת�ַ�
		n = n / 10;
	}

	for (int j = i - 1; j >= 0; j--) //�������
	{
		printf("%c", num[j]);
	}
	return 0;
}
