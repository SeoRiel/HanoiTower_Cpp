#include <iostream>
#include <stdio.h>

#pragma warning(disable : 4996)

void Hanoi(int mNumber, int mFrom, int mTmp, int mTo);

int main()
{
	int number;					// ������ ���� ����
	scanf("%d", &number);   // ���� ���� �Է�
	Hanoi(number, 1, 2, 3);  // �Լ� 

	return 0;
}

// �ϳ��� �Լ� ���� : ���� ����, 1, 2, 3�� ����
// ����Լ� ���
void Hanoi(int mNumber, int mFrom, int mTmp, int mTo)
{
	// �Űܾ��� ������ �ϳ� ������ ��, mFrom -> mTo�� �̵�
	if (mNumber == 1)
	{
		printf("1 : %d -> %d \n", mFrom, mTo);
	}
	else
	{
		// ����Լ��� �̿��� mNumber �� ���� �� �� �̵�
		Hanoi(mNumber - 1, mFrom, mTo, mTmp);					// mFrom -> mFrom, mTmp -> mTo
		printf("%d : %d -> %d \n", mNumber, mFrom, mTo);
		Hanoi(mNumber - 1, mTmp, mFrom, mTo);					// mFrom -> mTmp, mFrom -> mTmp
	}
}