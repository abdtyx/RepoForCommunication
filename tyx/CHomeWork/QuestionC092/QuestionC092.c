/*��д���򣬽�s��ָ�ַ����г����±꣨��0��ʼ��Ϊ������
ͬʱasciiֵҲΪ�������ַ�֮�⣬����������ַ���ɾ����
����ʣ���ַ����γɵ�һ���´�����t��ָ��һ�������в���ʾ��
��û�������������ַ�����ʾ��#�����ַ������Ȳ�����200.
���룺���Ȳ�����200���ַ������޿ո񣩡�
������������ַ�����

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	char inputStr[200];
	char t[200] = {0};
	(void)scanf("%s", inputStr);

	int i = 0, j = 0; //2��������±�ָʾ
	while (inputStr[i])
	{
		if (i % 2 == 1 && inputStr[i] % 2 == 1)
		{
			t[j++] = inputStr[i];
		}
		i++;
	}
	printf("%s", t[0] ? t : "#");
	return 0;
}
