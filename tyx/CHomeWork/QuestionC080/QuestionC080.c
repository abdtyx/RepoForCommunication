/*��5�����ʵĵ��ʱ�""reserve"", ""replace"", ""core"", ""nature, "" ""literature""��
��д�����ڵ��ʱ��в��ҵ��ʣ����ҵ�������ʾYES�����Ҳ�������ʾNO�����Ҳ����ִ�Сд��
���룺һ����ʾ���ʵ��ַ�����
�����YES��NO��
����1��
RESERVE
YES
����2��
change
NO

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int StrSearch(char words[][30], int n, char word[]);

int main()
{
	char words[5][30] = {"reserve", "replace", "core", "nature", "literature"};
	char word[30];
	(void)scanf("%s", word);
	printf("%s", StrSearch(words, 5, _strlwr(word)) == -1 ? "NO" : "YES");
	return 0;
}

int StrSearch(char words[][30], int n, char word[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(words[i], word) == 0)
		{
			return i;
		}
	}
	return -1;
}
