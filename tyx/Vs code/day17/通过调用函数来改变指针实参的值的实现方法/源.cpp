#include <stdio.h>
int main()
{
	void swap(int* p1, int* p2);
	int a, b;
	int* pointer_1, * pointer_2;
	scanf_s("%d,%d", &a, &b);
	pointer_1 = &a;
	pointer_2 = &b;
	if (a < b)
		swap(pointer_1, pointer_2);
	printf("max=%d, min=%d\n", a, b);
	return 0;
}
void swap(int* p1, int* p2)
{
	int* p;
	p = &*p1;
	&*p1 = &*p2;
	&*p2 = p;
	/*���ֱ������ۣ���ַ���޷��޸ĵģ�ֻ�ܸı��ַ�ϱ�����ֵ���ڵ��ú���ʱ��ʵ�λᱻ�����ββ��洢���µĵ�ַ����������µĵ�ַ�ǿ��Դ洢��һ�����ĵ�ַ�ġ�
	�����������ָ��*��ָ���βΣ���ʱ������һ�����ĵ�ַ�����Ϳ����ҵ��洢��ԭ�����������޸ĸñ�������ʱ����ͨ��&*�ٴ�ȡ����ԭ�����ĵ�ַ��
	��Ȼ���ǣ�ʵ��֤������ַ�޷����޸ġ�*/
}