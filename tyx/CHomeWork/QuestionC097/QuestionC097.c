/*��������ĸ��������ɵ��ַ���s��t������������100���ַ�����
�����ַ���s�г��֣���δ���ַ���t�г��ֵ��ַ�(���ִ�Сд)
���һ���µ��ַ�������u�У�u���ַ���ԭ�ַ������ַ�˳�����У�
��ȥ���ظ��ַ������u����s�е��ַ���t�ж����ֹ������#��
���磺��s = "112345"��t = "2467"ʱ��u = "1135"����s = "12", t = "12", ���"#"
���룺�����ַ������м��ÿո������scanf("%s%s", s, t);
����������

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Search(char* str, char ch);

int main()
{
	char s[100], t[100], u[100] = {0};
	(void)scanf("%s%s", s, t);
	int si = 0, ui = 0;
	while (s[si])
	{
		if (Search(t, s[si]) == -1)
		{
			u[ui++] = s[si];
		}
		si++;
	}

	printf("%s", u[0] == 0 ? "#" : u);
	return 0;
}

/// <summary>
/// ����һ���ַ��Ƿ���һ������
/// </summary>
/// <param name="str">���ҵ��ַ���</param>
/// <param name="ch">���ҵ��ַ�</param>
/// <returns>���ҵ������±꣨��0��ʼ�����ص�һ���ҵ����±꣩û�У�����-1</returns>
int Search(char* str, char ch)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			return i;
		}
		i++;
	}
	return -1;
}
