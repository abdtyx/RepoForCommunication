/// <ID>C014</ID>
/// <date>2020/11</date>
/// <summary>
/// �ҳ�[m, n]��Χ����7�ı������7��ȫ����������m��nΪ������
/// </summary>
/// <input>2����������m��n</input>
/// <output>�����У����������</output>
/// <sample>
/// 20 30
/// 21��7�ı���
/// 27�Ǵ�7����
/// 28��7�ı���
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int m, n;
	(void)scanf("%d%d", &m, &n);

	for (int i = m; i <= n; i++)
	{
		if (i % 7 == 0)
		{
			printf("%d��7�ı���\n", i);
		}
		int k = i;

		//���ÿһλ�Ƿ���7
		//Check whether each bit has 7
		while (k)
		{
			if (k % 10 == 7)
			{
				printf("%d�Ǵ�7����\n", i);
				//As long as one is 7
				break; //ֻҪ��һ����7����
			}
			k /= 10;
		}
	}
	return 0;
}
