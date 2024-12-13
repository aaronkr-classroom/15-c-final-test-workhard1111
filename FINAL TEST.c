#include <stdio.h>

#define MAX_COUNT 3 // 성적 등록 가능한 친구 최대 수

typedef char NAME_TYPE[14]; // 13자까지 + NULL무자
typedef unsigned short int US;


int AddFriend(NAME_TYPE* p_name, US* korean,
	float* math, float* english, unsigned int fullscore,unsigned int everage, unsigned int rank,int count) {
	// 입력 가능한 최대 수를 넘었는지 체크함
	if (count < MAX_COUNT) {
		printf("\n새로운 친구 정보를 입력하세요\n");
		printf(" 이름: ");
		scanf_s("%s", *(p_name + count), sizeof(*(p_name + count)));

		printf(" 국어 점수: ");
		scanf_s("%hu", korean + count);

		printf(" 영어 점수: ");
		scanf_s("%f", math + count);

		printf(" 수학 점수: ");
		scanf_s("%f", english + count);

		printf("입력을 완료했습니다.\n\n");
		return 1;
	}
	else { // 입력 가능한 최대 수를 넘었을 때 오류를 출력함
		printf("최대 인원을 초과하여 입력을 할 수 없습니다.\n");
		printf("최대 %d명까지만 관리 가능합니다.\n\n", MAX_COUNT);
		return 0;
	}
}

void ShowFriendList(NAME_TYPE* p_name, US* korean,
	float* math, float* english, int* fullscore, int* everage,int* rank, int* count) {

	if (count > 0) {
		printf("\n성적 확인\n");
		printf("==========================================\n");
		printf(" 이름  국어  영어  수학  총점  평균  등수\n");
		printf("==========================================\n");
		for (int i = 0; i < count; i++) {
			printf("%-14s  %d  %d  %d  %d  %.1f  %d\n",
				*(p_name + i),
				*(korean + i),
				*(math + i),
				*(english + i),
				*(fullscore + i),
				*(everage + i),
				*(rank + i));
		}
	}
	else { // 등록된 친구가 없으면 오류를 출력함
		printf("\n등록된 친구가 없습니다!\n\n");
	}
}

int main(void) {
	// 배열 사용하기
	NAME_TYPE name[MAX_COUNT];
	US korean[MAX_COUNT];
	float math[MAX_COUNT];
	float english[MAX_COUNT];
	double fullscore[MAX_COUNT];
	double everage[MAX_COUNT];
	double rank[MAX_COUNT];

	int  menu_num;

	// 무한 루프: 사용자가 3을 누르면 break 문으로 종료시킴
	while (1) {
		// 메뉴를 화면에 출력함
		printf("\t[ 메뉴 ]\t\n");
		printf("===========================\n");
		printf("1. 성적 입력\n");
		printf("2. 성적 확인\n");
		printf("3. 종료\n");
		printf("===========================\n");
		printf("선택(1~5): ");
		scanf_s("%d", &menu_num);

		// while문에서 나가야 겠다....
		if (menu_num == 3) break;

		switch (menu_num) {
		case 1:
			/*
			AddFriend 함수가 1을 반환하면 정상적으로
			친구 정보가 추가왼 것입니다. 따라서 1을
			반환 했을 때만 등록된 친구 수를 증가시킵니다.
			*/
			if (AddFriend(name, korean, math, english, fullscore, everage, rank))
				
			break;
		case 2:
			ShowFriendList(name, korean, math, english, fullscore, everage, rank);
			
		default:
			// 번호가 유효하지 않은 경우에 오류 메시지를 출력함
			printf("1~3 번호만 선택할 수 있습니다!!\n\n");
		}
	}

	return 0;
}