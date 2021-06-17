/// <ID>C032</ID>
/// <date>2020/11</date>
/// <summary>
/// ˮ�ɻ�������ָһ����λ�����������λ���ֵ�������ȷ�õ��ڸ�������
/// �磺153��1 ^ 3��5 ^ 3��3 ^ 3
/// n, m��100 <= n, m < 1000, ���[n, m]֮���ˮ�ɻ�������������û��ˮ�ɻ�������� - 1.
/// </summary>
/// <input>n, m���ÿո����</input>
/// <output>����ˮ�ɻ������ÿո����</output>
/// <sample>
/// 100 500
/// 153 370 371 407
/// </sample>
/// <sample>
/// 100 120
/// -1
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n, m;
	(void)scanf("%d%d", &n, &m);
	int firstFind = 0;
	for (int i = n; i <= m; i++)
	{
		int i0 = i % 10;
		int i1 = (i / 10) % 10;
		int i2 = i / 100;
		if (i == i0 * i0 * i0 + i1 * i1 * i1 + i2 * i2 * i2)
		{
			firstFind++ == 0 ? printf("%d", i) : printf(" %d", i);
		}
	}
	if (firstFind == 0)
	{
		printf("-1");
	}
	return 0;
}
