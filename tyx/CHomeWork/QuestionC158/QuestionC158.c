/*�û�����һ���ַ��������ַ����е�����λ����
���ַ�����ĸ���е�˳�������԰�˳�򱣴�����λ���ϡ�
����teacher��t, a, h, r�������Ϊa, h, r, t��
�����ַ���Ϊ��aehcret��
�����ʽ������С��100���ַ�����
���������λ�õ��ַ��������ַ���

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

int main()
{
	char inStr[200] = { 0 };
	(void)scanf("%s", inStr);
	int len = strlen(inStr);
	len = len % 2 == 0 ? len - 1 : len;
	for (int i = 0; i < len; i += 2)
	{
		for (int j = len - 1; j > i; j -= 2)
		{
			if (inStr[j] < inStr[j - 2])
			{
				int temp = inStr[j];
				inStr[j] = inStr[j - 2];
				inStr[j - 2] = temp;
			}
		}
	}
	printf("%s", inStr);
	return 0;
}
