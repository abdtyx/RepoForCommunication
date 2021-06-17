//��дһ�����򣬶���n���û������͵绰���룬
//���������ֵ�˳�����к�
//����û��������͵绰���룬n�Ӽ������롣
//
//Cui Shuning (��������2020/11

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

typedef struct _PhoneList
{
	char name[30];
	char phoneNum[20];
} PhoneList;

void PhoneBubble(PhoneList* plist, int n);

int main()
{
	PhoneList plist[100];
	int n;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%s%s", plist[i].name, plist[i].phoneNum);
	}
	PhoneBubble(plist, n);

	for (int i = 0; i < n; i++)
	{
		printf("%s %s\n", plist[i].name, plist[i].phoneNum);
	}
	return 0;
}

/// <summary>
/// ���������ֵ�������
/// </summary>
/// <param name="plist">�绰���뱾</param>
/// <param name="n">����</param>
void PhoneBubble(PhoneList* plist, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (strcmp(plist[j].name, plist[j - 1].name) < 0)
			{
				PhoneList temp = plist[j];
				plist[j] = plist[j - 1];
				plist[j - 1] = temp;
			}
		}
	}
}
