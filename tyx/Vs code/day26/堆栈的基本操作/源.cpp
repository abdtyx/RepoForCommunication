int* create()
{
	int stack[MAXSTACK] = { 0 };
	return stack;
}
int isEmpty()
{
	if (top == -1) return 1;
	else return 0;
}
int push(int data)
{
	if (top >= MAXSTACK)
	{
		printf("��ջ�������޷��ټ���\n");
		return 0;
	}
	else
	{
		stack[++top] = data;
		return 1;
	}
}
int pop()
{
	if (isEmpty())
		return -1;
	else
		return stack[top--];
}
int main()
{
	
}