#include <stdio.h>
void radix(int data[], int size)
{
	int i, j, k, n, m;
	for (n = 1; n <= 100; n = n * 10)	/* nΪ�������Ӹ�λ����ʼ���� */
	{
		int tmp[10][100] = { 0 };
/* �����ݴ����飬[0��9λ��][���ݸ���]���������ݾ�Ϊ0 */
		for (i = 0; i < size; i++)
		{
			m = (data[i] / n) % 10;
/* mΪnλ����ֵ����36ȡʮλ�� (36/10)%10=3 */
			tmp[m][i] = data[i];/* ��data[i]��ֵ�ݴ���tmp�� */
		}
		k = 0;
		for ( i = 0; i < 10; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (tmp[i][j] != 0)
					/* ��һ��ʼ����tmp={0}���ʲ�Ϊ0�߼�Ϊ */
				{
					data[k] = tmp[i][j];
					/* data�ݴ���tmp���ֵ����tmp���ֵ�� */
					k++;								/* ��data[ ]�� */
				}
			}
		}
		printf("����%3dλ�������", n);
		//showdata(data, size);
	}
}