#include <stdio.h>
void merge(FILE* fp, FILE* fp1, FILE* fp2)
{
	int n1, n2;	/*��������n1, n2�ݴ������ļ�data1��data2�ڵ�Ԫ��ֵ*/
	n1 = getc(fp1);	/*��fp1��ȡһ��Ԫ�ؽ���������n1*/
	n2 = getc(fp2);
	while (feof(fp1) == 0 && feof(fp2) == 0)	/*�ж��Ƿ��ѵ��ļ�β*/
	{
		if (n1 <= n2)
		{
			putc(n1, fp);	/*���n1�Ƚ�С�����n1�浽fp��*/
			n1 = getc(fp1);	/*���Ŷ���һ��n1������*/
		}
		else
		{
			putc(n2, fp);	/*���n2�Ƚ�С�����n2�浽fp��*/
			n2 = getc(fp2);	/*���Ŷ���һ��n1������*/
		}
	}
	if (feof(fp1))	/*�������һ�������ļ��Ѷ�ȡ��ϣ����жϺ�*/
	{
		putc(n2, fp);	/*����һ�������ļ��ڵ�����ȫ���ŵ�fp��*/
		while (1)
		{
			n2 = getc(fp2);
			if (feof(fp2)) break;
			putc(n2, fp);
		}
	}
	else if (feof(fp2))
	{
		putc(n1, fp);
		while (feof(fp1))
		{
			n1 = getc(fp1);
			putc(n1, fp);
		}
	}
}