//��n��ѧ����ÿ��ѧ�������ݰ���ѧ�š����������ſεĳɼ������ԴӼ�������n��ѧ�������ݣ�
///���ܳɼ���С�������򣬴�ӡ����ѧ�š����������ſγɼ����ܳɼ��ĳɼ�����������ʱ�����ݴӼ������롣��
//���룺��1��Ϊ����n������n�б�ʾn���˵���Ϣ������ѧ�š������������ſεĳɼ���ÿ�е����ݼ��ÿո������
//�����n�У���ʾn���˵���Ϣ������ѧ�š����������ſεĳɼ����ܳɼ������ݼ�һ���ո�ĩβ�޿ո�
//Cui Shuning (��������2020/11

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

typedef struct _GradeList
{
	char id[20];
	char name[30];
	int course01;
	int course02;
	int course03;
	int total;
} GradeList;

void GradeBubble(GradeList* glist, int n);

int main()
{
	GradeList glist[100];
	int n;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%s%s%d%d%d",
		      glist[i].id, glist[i].name, &glist[i].course01,
		      &glist[i].course02, &glist[i].course03);
		glist[i].total = glist[i].course01 + glist[i].course02 + glist[i].course03;
	}

	GradeBubble(glist, n);

	for (int i = 0; i < n; i++)
	{
		printf("%s %s %d %d %d %d\n",
		       glist[i].id, glist[i].name, glist[i].course01,
		       glist[i].course02, glist[i].course03, glist[i].total);
	}
	return 0;
}


/// <summary>
/// ���ܳɼ�����
/// </summary>
/// <param name="glist">�ɼ���</param>
/// <param name="n">����</param>
void GradeBubble(GradeList* glist, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (glist[j].total < glist[j - 1].total)
			{
				GradeList temp = glist[j];
				glist[j] = glist[j - 1];
				glist[j - 1] = temp;
			}
		}
	}
}
