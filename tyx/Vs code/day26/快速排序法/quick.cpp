#include <stdio.h>
void quick(int d[], int size, int lf, int rg)
{
	int i, j, tmp;
	int lf_idx;
	int rg_idx;
	int t;
	int process = 0;
				/*1:��һ����ֵΪd[lf]*/
	if (lf < rg)
	{
		lf_idx = lf + 1;
		rg_idx = rg;
step2:
		printf("[�������%d]=> ", process++);
		for (t = 0; t < size; t++)
			printf("[%2d] ", d[t]);
		printf("\n");
		for (i = lf + 1; i <= rg; i++)	/*2:���������ҳ�һ����ֵ����d[lf]��*/
		{
			if (d[i] >= d[lf])
			{
				lf_idx = i;
				break;
			}
			lf_idx++;
		}
		for (j = rg; j >= lf + 1; j--)	/*3:���������ҳ�һ����ֵС��d[lf]��*/
		{
			if (d[j] <= d[lf])
			{
				rg_idx = j;
				break;
			}
			rg_idx--;
		}
		if (lf_idx < rg_idx)				/*4-1:��lf_idx<rg_idx*/
		{									/*��d[lf_idx]��d[rg_idx]����*/
			tmp = d[lf_idx];
			d[lf_idx] = d[rg_idx];
			d[rg_idx] = tmp;
			goto step2;						/*4-2:������ִ�в���2*/
		}
		if (lf_idx >= rg_idx)				/*5-1:��if_idx���ڵ���rg_idx*/
		{									/*��d[lf]��d[rg_idx]����*/
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
						/*5-2:����rg_idxΪ��׼��ֳ���������*/
			quick(d, size, lf, rg_idx - 1);	/*�Եݹ鷽ʽ�ֱ�Ϊ���������������*/
			quick(d, size, rg_idx + 1, rg);	/*ֱ���������*/
		}
	}
}