/// <ID>C136</ID>
/// <date>2020/11</date>
/// <summary>
/// ÿ��һ��ʼ����һ���ڻ�����ǩ�ֵ��˻���ţ����һ��ǩ�ֵ��˻������š�
/// ����ǩ���ļ�¼����Ӧ���ҵ����쿪�ź����ŵ��ˡ�
/// ÿ���˵�ǩ��ʱ���������ǩ��ʱ�䣬����û��������ͬʱǩ����ǩ�ˡ�
/// </summary>
/// <input>һ��ļ�¼����¼��������M��ͷ��M�Ǽ�¼���������M�У�ÿ�еĸ�ʽΪ��
/// ID_number Sign_in_time Sign_out_time��
/// ����ʱ����HH : MM:SS��ʽ������ID number��һ��������15���ַ����ַ�����
/// </input>
/// <output>��һ����������쿪�������ŵ���Ա��ID�š�������ID�ű�����һ���ո����</output>
/// <sample>
/// 4 
/// CS200111 09:20 : 22 17 : 00 : 01
/// CS200001 09 : 20 : 00 17 : 30 : 00
/// CS301010 09 : 21 : 00 17 : 30 : 59
/// CS301213 09 : 23 : 00 12 : 00 : 00
/// CS200001 CS301010
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#pragma warning(disable:6001)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

typedef struct _record
{
	char name[20];
	char inTime[20];
	char outTime[20];
}Record;

int main()
{
	Record record[30];
	int m;
	(void)scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		(void)scanf("%s%s%s", record[i].name, record[i].inTime
		      , record[i].outTime);
	}

	char name[20];
	strcpy(name, record[0].name);
	char time[20];
	strcpy(time, record[0].inTime);

	//Ѱ����������
	for (int i = 1; i < m; i++)
	{
		if (strcmp(time, record[i].inTime) > 0)
		{
			strcpy(name, record[i].name);
			strcpy(time, record[i].inTime);
		}
	}

	printf("%s", name);

	//Ѱ�������뿪��
	strcpy(name, record[0].name);
	strcpy(time, record[0].outTime);

	for (int i = 1; i < m; i++)
	{
		if (strcmp(time, record[i].outTime) < 0)
		{
			strcpy(name, record[i].name);
			strcpy(time, record[i].outTime);
		}
	}
	printf(" %s", name);
	return 0;
}
