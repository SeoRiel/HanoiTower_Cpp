#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#pragma warning (disable : 4996)

#define MAX 100

void Init_stack();
void Move(int from, int to);
void NonRecursiveFunction(int ringCounter, int from, int by, int to);
int Pop();
int Push(int tryCounter);
int IsStackEmpty();

int stack[MAX];
int top;

int main()
{
	int i = 0;

	printf("\nIf you want to quit enter minus integer.");

	while (true)
	{
		printf("\nEnter height of HANOI tower... -> ");
		scanf("%d", &i);

		if (i <= 0)
		{
			break;
		}

		NonRecursiveFunction(i, 1, 2, 3);
	}

	return 0;
}

// ���� �ʱ�ȭ
void Init_stack()
{
	top = -1;
}

void Move(int from, int to)
{
	printf("\nMove from %d to %d", from, to);
}

// ����� ����� �ϳ���ž
void NonRecursiveFunction(int ringCounter, int from, int by, int to)
{
	int done = 0;
	
	while (!done)
	{
		// ���� ������ �� �� �̻��� ��
		while (ringCounter > 1)
		{
			Push(to);
			Push(by);
			Push(from);
			Push(ringCounter);
			ringCounter--;
			Push(to);
			to = by;
			by = Pop();
		}

		Move(from, to);


		if (!IsStackEmpty())
		{
			ringCounter = Pop();
			from = Pop();
			by = Pop();
			to = Pop();
			Move(from, to);
			ringCounter--;
			from = by;
			by = Pop();
		}
		else
		{
			done = 1;
		}
	}
}

int Pop()
{
	if (top < 0)
	{
		printf("\nCondition : Stack Unoverflow");
		exit(1);
	}

	return stack[top--];
}

// top�� 99���� ũ�� ���� �÷ο� �߻�
int Push(int tryCounter)
{
	if (top >= MAX - 1)
	{
		printf("\nCondition : Stack Overflow");
		exit(1);
	}

	stack[++top] = tryCounter;

	return tryCounter;
}

int IsStackEmpty()
{
	return (top < 0);
}