void shell(int data[], int size)
{
	int i;		/*iΪɨ�����*/
	int j;		/*��j����λ�Ƚϵ�Ԫ��*/
	int k = 1;	/*k��ӡ����*/
	int tmp;	/*tmp�����ݴ�����*/
	int jmp;	/*�趨λ���λ����*/
	jmp = size / 2;
	while (jmp != 0)
	{
		for (i = jmp; i < size; i++)
		{
			tmp = data[i];
			j = i - tmp;
			while (tmp < data[j] && j >= 0)	/*��������*/
			{
				data[j + jmp] = data[j];
				j = j - jmp;
			}
			data[jmp + j] = tmp;
		}
		jmp = jmp / 2;	/*����ѭ����*/
	}
}