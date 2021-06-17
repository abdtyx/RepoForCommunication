/// <ID>C041</ID>
/// <date>2020/11</date>
/// <summary>
/// �����ڵ�С��ʲô��ϲ������������������Ҳ����ˣ����ų��⣩��
/// ���磺С�����1234������4321���� - 1234���� - 4321��
/// ��230����032(032 = 32)���� - 230���� - 032(-032 = -32)��
/// ���ڣ�С������һЩa + b��a - b����Ŀ(a, bΪ�����Ҳ���ǰ��0)��
/// ���������Щ��Ŀ��ȷ�Ĵ𰸣����ܲ³�С�������õ�ʲô����
/// </summary>
/// <input>��������x, y(-1000000��1000000), x��ʾa + b����ȷ�𰸣�y��ʾa - b����ȷ�𰸡�</input>
/// <output>��������s t��֮����һ���ո�ֿ�������s��ʾС�����õ���a + b�𰸣�t��ʾС�����õ���a - b��</output>
/// <sample>
/// 45 78
/// -45 77
/// </sample>
/// <sample>
/// -78 90
/// -42 54
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Resverse(int x);

int main()
{
	int x, y;
	(void)scanf("%d%d", &x, &y);
	int a = (x + y) / 2;
	int b = (x - y) / 2;
	a = a > 0 ? Resverse(a) : -Resverse(-a);
	b = b > 0 ? Resverse(b) : -Resverse(-b);
	printf("%d %d", a + b, a - b);
	return 0;
}

/// <summary>
/// ��x��ת����123��תλ321
/// Invert x, such as 123 inverts to 321
/// </summary>
/// <param name="x">����ת����</param>
/// <returns>��ת��Ľ��</returns>
int Resverse(int x)
{
	int resx = 0;
	while (x)
	{
		resx = resx * 10 + x % 10;
		x /= 10;
	}
	return resx;
}
