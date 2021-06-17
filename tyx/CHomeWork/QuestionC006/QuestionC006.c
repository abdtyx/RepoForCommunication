/// <ID>C006</ID>
/// <date>2020/11</date>
/// <summary>
/// ��ҵ���ŵĽ������������ɡ�������ڻ����10��Ԫʱ���������10%��
/// �������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������8%��
/// 20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��
/// 40��60��֮��ʱ���� 40��Ԫ�Ĳ��֣������3%��
/// 60��100��֮��ʱ������60��Ԫ�Ĳ��֣������2%��
/// ����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɡ�
/// ��д���������û���������������Ž���������
/// </summary>
/// <input>һ������</input>
/// <output>һ������</output>
/// <sample>
/// 12233478
/// 121700
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	long long profit;
	(void)scanf("%lld", &profit);
	if (profit <= 100000)
	{
		printf("%d", (int)(profit * 0.1));
		//������ѽ��ǿ��ת��Ϊ�����Ļ�������һ�����棻
		//�þ�����Ժ��Բ���Ӱ���������н��
		//If you do not cast the result to an integer, there will be a warning;
		//The warning can be ignoredand does not affect the running result of the program
		//printf("%d", profit * 0.1);
	}
	else if (profit > 100000 && profit <= 200000)
	{
		printf("%d", (int)(100000 * 0.1 + (profit - 100000) * 0.08));
	}
	else if (profit > 200000 && profit <= 400000)
	{
		printf("%d", (int)(100000 * 0.1 + 100000 * 0.08 + (profit - 200000) * 0.05));
	}
	else if (profit > 400000 && profit <= 600000)
	{
		printf("%d", (int)(100000 * 0.1 + 100000 * 0.08 + 200000 * 0.05
			       + (profit - 40000) * 0.03));
	}
	else if (profit > 600000 && profit <= 1000000)
	{
		printf("%d", (int)(100000 * 0.1 + 100000 * 0.08 + 200000 * 0.05
			       + 220000 * 0.03 + (profit - 600000) * 0.02));
	}
	else if (profit > 1000000)
	{
		printf("%d", (int)((100000 * 0.1 + 100000 * 0.08 + 200000 * 0.05
			       + 20000 * 0.03 + 400000 * 0.02 + profit - 100000) * 0.01));
	}
	return 0;
}
