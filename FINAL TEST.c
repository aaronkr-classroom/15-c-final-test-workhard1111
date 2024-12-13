#include <stdio.h>

#define MAX_COUNT 3 // ���� ��� ������ ģ�� �ִ� ��

typedef char NAME_TYPE[14]; // 13�ڱ��� + NULL����
typedef unsigned short int US;


int AddFriend(NAME_TYPE* p_name, US* korean,
	float* math, float* english, unsigned int fullscore,unsigned int everage, unsigned int rank,int count) {
	// �Է� ������ �ִ� ���� �Ѿ����� üũ��
	if (count < MAX_COUNT) {
		printf("\n���ο� ģ�� ������ �Է��ϼ���\n");
		printf(" �̸�: ");
		scanf_s("%s", *(p_name + count), sizeof(*(p_name + count)));

		printf(" ���� ����: ");
		scanf_s("%hu", korean + count);

		printf(" ���� ����: ");
		scanf_s("%f", math + count);

		printf(" ���� ����: ");
		scanf_s("%f", english + count);

		printf("�Է��� �Ϸ��߽��ϴ�.\n\n");
		return 1;
	}
	else { // �Է� ������ �ִ� ���� �Ѿ��� �� ������ �����
		printf("�ִ� �ο��� �ʰ��Ͽ� �Է��� �� �� �����ϴ�.\n");
		printf("�ִ� %d������� ���� �����մϴ�.\n\n", MAX_COUNT);
		return 0;
	}
}

void ShowFriendList(NAME_TYPE* p_name, US* korean,
	float* math, float* english, int* fullscore, int* everage,int* rank, int* count) {

	if (count > 0) {
		printf("\n���� Ȯ��\n");
		printf("==========================================\n");
		printf(" �̸�  ����  ����  ����  ����  ���  ���\n");
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
	else { // ��ϵ� ģ���� ������ ������ �����
		printf("\n��ϵ� ģ���� �����ϴ�!\n\n");
	}
}

int main(void) {
	// �迭 ����ϱ�
	NAME_TYPE name[MAX_COUNT];
	US korean[MAX_COUNT];
	float math[MAX_COUNT];
	float english[MAX_COUNT];
	double fullscore[MAX_COUNT];
	double everage[MAX_COUNT];
	double rank[MAX_COUNT];

	int  menu_num;

	// ���� ����: ����ڰ� 3�� ������ break ������ �����Ŵ
	while (1) {
		// �޴��� ȭ�鿡 �����
		printf("\t[ �޴� ]\t\n");
		printf("===========================\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� Ȯ��\n");
		printf("3. ����\n");
		printf("===========================\n");
		printf("����(1~5): ");
		scanf_s("%d", &menu_num);

		// while������ ������ �ڴ�....
		if (menu_num == 3) break;

		switch (menu_num) {
		case 1:
			/*
			AddFriend �Լ��� 1�� ��ȯ�ϸ� ����������
			ģ�� ������ �߰��� ���Դϴ�. ���� 1��
			��ȯ ���� ���� ��ϵ� ģ�� ���� ������ŵ�ϴ�.
			*/
			if (AddFriend(name, korean, math, english, fullscore, everage, rank))
				
			break;
		case 2:
			ShowFriendList(name, korean, math, english, fullscore, everage, rank);
			
		default:
			// ��ȣ�� ��ȿ���� ���� ��쿡 ���� �޽����� �����
			printf("1~3 ��ȣ�� ������ �� �ֽ��ϴ�!!\n\n");
		}
	}

	return 0;
}