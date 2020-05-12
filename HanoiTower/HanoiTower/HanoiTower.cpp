#include <iostream>
#include <stdio.h>

#pragma warning(disable : 4996)

void Hanoi(int mNumber, int mFrom, int mTmp, int mTo);

int main()
{
	int number;					// 원판의 개수 저장
	scanf("%d", &number);   // 원판 개수 입력
	Hanoi(number, 1, 2, 3);  // 함수 

	return 0;
}

// 하노이 함수 구성 : 원판 개수, 1, 2, 3번 막대
// 재귀함수 사용
void Hanoi(int mNumber, int mFrom, int mTmp, int mTo)
{
	// 옮겨야할 원판이 하나 남았을 때, mFrom -> mTo로 이동
	if (mNumber == 1)
	{
		printf("1 : %d -> %d \n", mFrom, mTo);
	}
	else
	{
		// 재귀함수를 이용한 mNumber 값 감소 및 판 이동
		Hanoi(mNumber - 1, mFrom, mTo, mTmp);					// mFrom -> mFrom, mTmp -> mTo
		printf("%d : %d -> %d \n", mNumber, mFrom, mTo);
		Hanoi(mNumber - 1, mTmp, mFrom, mTo);					// mFrom -> mTmp, mFrom -> mTmp
	}
}