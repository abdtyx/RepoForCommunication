/*��дһ�����򣬴Ӽ����ж���һ�����ִ���
 *����תΪ���ֵ�СдӢ�ﵥ������������234�������two three four����
 *���룺һ������
 *������ÿո������Ӣ�Ļ����ʣ�Сд��
 *������
 *234
 *two three four
 *
 *Cui Shuning (��������2020/11
 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	const char word[][30] = {
		"zero", "one", "two", "three",
		"four", "five", "six", "seven", "eight", "nine"
	};
	char inStr[100];
	(void)scanf("%s", inStr);
	
	printf("%s", word[inStr[0] - '0']);
	for (int i = 1;  i < strlen(inStr); i++)
	{
		printf(" %s", word[inStr[i] - '0']);
	}
	return 0;
}
