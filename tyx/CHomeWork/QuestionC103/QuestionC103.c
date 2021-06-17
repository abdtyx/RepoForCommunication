/// <ID>C103</ID>
/// <date>2020/11</date>
/// <summary>
/// ��n��С��Χ��һȦ����1˳���źš�
/// �ӵ�һ���˿�ʼ������1~k��������������k�����˳�Ȧ�ӣ���������µ���ԭ�����ڵڼ��š�
/// </summary>
/// <input>������������1000�����Լ�������k���ո�ָ���</input>
/// <output>������µ��˵ı��</output>
/// <sample>
/// 234 3
/// 230
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Josephus(int num, int chooseNum);

int main()
{
	int n, k;
	(void)scanf("%d%d", &n, &k);
	printf("%d", Josephus(n, k));
	return 0;
}


int Josephus(int num, int chooseNum)
{
	//��ʾС��������
	int boy[1000];
	for (int i = 0; i < num; i++)
	{
		boy[i] = i + 1; //��С�����
	}

	int k = 1; //��k���뿪��С��
	int n = -1; //�����±꣬��һ��Ϊ0��ʾ�ӵ�һ�����ӿ�ʼ����
	while (1)
	{
		//��Ȧ�п�ʼ�޳�
		for (int j = 0; j < chooseNum;)
		{
			n = (n + 1) % num;
			if (boy[n] != 0)
			{
				j++; //�����С������Ȧ�У���μӼ���
			}
		}
		if (k == num)
		{
			break;
		} //����Ѿ�ȫ���޳���ɣ�������ѭ��
		boy[n] = 0;
		k++;
	}
	// break�����ת���ˣ�����ʤ���߱��
	return boy[n];
}
