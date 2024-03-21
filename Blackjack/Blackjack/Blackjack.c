
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char* cardMark(int ca); //�J�[�h�̃}�[�N
char* cardNumber(int ca2); //�J�[�h�̐��̊֐�
int YourcardPoint(int ca3); //���Ȃ��̓��_�̊֐�
int DealercardPoint(int ca4, int DS); //�f�B�[���[�̓��_�̊֐�

int main() {
	int card[52];
	int i;
	int a; //��
	int num;
	int yourSum; //���Ȃ��̍��v
	int dealerSum = 0; //�f�B�[���[�̍��v
	int comand;
	int yourCount = 4; //���Ȃ��������J�[�h
	int dealerCount = 2; //�f�B�[���[�������J�[�h


	printf("���������������������u���b�N�W���b�N�ւ悤�����I��������������������\n");
	printf("�Q�[�����J�n���܂��B\n");

	//0�`51��1�`52�����
	for (i = 0; i < 52; i++) {
		card[i] = i + 1;
	}

	//�V���b�t������
	srand((unsigned int)time(NULL));
	for (i = 0; i < 52; i++) {
		num = rand() % 52;

		a = card[i];
		card[i] = card[num];
		card[num] = a;
	}

	//���Ȃ��̈�����1�E2���ڂ̃J�[�h
	printf("���Ȃ��̈������J�[�h��%s%s�ł��B\n", cardMark(card[0]), cardNumber(card[0]));
	printf("���Ȃ��̈������J�[�h��%s%s�ł��B\n", cardMark(card[1]), cardNumber(card[1]));
	yourSum = YourcardPoint(card[0]) + YourcardPoint(card[1]);

	if (yourSum == 21) {
		printf("�i�`�������u���b�N�W���b�N�I���Ȃ��̏����ł��B\n");

		printf("�u���b�N�W���b�N�I���I�܂��V��łˁ�\n");

		return 0;
	}

	//�f�B�[���[�̈�����1�E2���ڂ̃J�[�h
	printf("�f�B�[���[�̈������J�[�h��%s%s�ł��B\n", cardMark(card[2]), cardNumber(card[2]));
	printf("�f�B�[���[��2���ڂ̃J�[�h�͕�����܂���B\n");
	dealerSum = DealercardPoint(card[2], dealerSum) + DealercardPoint(card[3], dealerSum);

	printf("���Ȃ��̌��݂̓��_��%d�ł��B\n", yourSum);


	//�J�[�h�������܂����H
	while (yourSum < 21) {
		printf("�J�[�h�������܂����H�����ꍇ��Y���A�����Ȃ��ꍇ��N����͂��Ă�������\n");
		comand = getchar(); // ������ǂݎ��
		while (getchar() != '\n'); // ���s�������̂Ă�

		if (comand == 'Y') { //comand �� int �^�ł���Ȃ���AASCII�R�[�h�l�Ƃ��� 'Y' �� 'N' ���g���Ĕ�r�ł���̂́A getchar() �֐���������ASCII�R�[�h�l��Ԃ�����
			printf("���Ȃ��̈������J�[�h��%s%s�ł��B\n", cardMark(card[yourCount]), cardNumber(card[yourCount]));

			yourSum = yourSum + YourcardPoint(card[yourCount]);
			printf("���Ȃ��̌��݂̓��_��%d�ł��B\n", yourSum);
			yourCount++;
		}
		else if (comand == 'N') {
			break;
		}
		else {
			printf("������x���͂��Ă��������B\n");
		}
	}

	//���Ȃ��̓��_��21�E21�ȏ�
	if (yourSum == 21) {
		printf("�u���b�N�W���b�N�I���Ȃ��̏����ł��B\n");

		printf("�u���b�N�W���b�N�I���I�܂��V��łˁ�\n");

		return 0;
	}

	else if (yourSum > 21) {
		printf("���Ȃ��̕����ł��B\n");

		printf("�u���b�N�W���b�N�I���I�܂��V��łˁ�\n");

		return 0;
	}

	printf("�f�B�[���[��2���ڂ̃J�[�h��%s%s�ł����B\n", cardMark(card[3]), cardNumber(card[3]));


	//�f�B�[���[��17�ȏ�ɂȂ�܂�

	if (dealerSum <= 17) {
		for (i = yourCount; i < 52; i++) {
			if (dealerSum <= 17) {
				dealerCount++;
				dealerSum = dealerSum + DealercardPoint(card[i], dealerSum);
				printf("�f�B�[���[��%d���ڂ̃J�[�h��%s%s�ł����B\n", dealerCount, cardMark(card[i]), cardNumber(card[i]));
			}
		}
	}

	printf("�f�B�[���[�̓��_��%d�ł��B\n", dealerSum);


	//����

	if (dealerSum > 21) {
		printf("���Ȃ��̏����ł��B\n");

		printf("�u���b�N�W���b�N�I���I�܂��V��łˁ�\n");

		return 0;
	}

	else {

		if (yourSum > dealerSum) {
			printf("���Ȃ��̏����ł��B\n");
		}
		else if (yourSum < dealerSum) {
			printf("�f�B�[���[�̏����ł��B\n");
		}
		else {
			printf("���������ł��B\n");
		}

		printf("�u���b�N�W���b�N�I���I�܂��V��łˁ�\n");

		return 0;
	}
}


//�}�[�N�̊֐�
char* cardMark(int ca) {

	static char ma[16];

	if ((ca - 1) / 13 == 0) {
		strcpy_s(ma, sizeof(ma), "�X�y�[�h��");
	}
	else if ((ca - 1) / 13 == 1) {
		strcpy_s(ma, sizeof(ma), "�N���u��");
	}
	else if ((ca - 1) / 13 == 2) {
		strcpy_s(ma, sizeof(ma), "�n�[�g��");
	}
	else if ((ca - 1) / 13 == 3) {
		strcpy_s(ma, sizeof(ma), "�_�C����");
	}
	else {
		strcpy_s(ma, sizeof(ma), "�G���[");
	}

	return ma;
}



////�}�[�N�̊֐�
//char* cardMark(int ca) {
//
//	static char ma[16];
//
//	char* mark[4] = { "�X�y�[�h��" ,"�N���u��" ,"�n�[�g��" ,"�_�C����" };
//
//		strcpy_s(ma, sizeof(ma), mark[(ca - 1) / 13]);
//
//	return ma;
//}



//�J�[�h�̐��̊֐�
char* cardNumber(int ca2) {

	static char ca[3];

	if (ca2 % 13 == 0) {
		strcpy_s(ca, sizeof(ca), "K");
	}

	else if (ca2 % 13 == 12) {
		strcpy_s(ca, sizeof(ca), "Q");
	}

	else if (ca2 % 13 == 11) {
		strcpy_s(ca, sizeof(ca), "J");
	}

	else if (ca2 % 13 == 1) {
		strcpy_s(ca, sizeof(ca), "A");
	}

	else {
		_itoa_s(ca2 % 13, ca, sizeof(ca), 10);
	}

	return ca;
}


//���Ȃ��̓��_�̊֐�
int YourcardPoint(int ca3) {

	int num2;

	//�J�[�h��11�E12��13
	if (ca3 % 13 > 10 || ca3 % 13 == 0) {
		return 10;
	}
	//�J�[�h���G�[�X
	else if (ca3 % 13 == 1) {

		printf("1�_��I�ԏꍇ��1�A11�_��I�ԏꍇ��11����͂��Ă�������\n");
		scanf_s(" %d", &num2);
		while (getchar() != '\n'); //getchar() �֐��͕W�����͂���1������������ǂݎ��

		if (num2 == 1) {
			return 1;
		}
		else if (num2 == 11) {
			return 11;
		}
	}
	//�J�[�h��2�E3�E4�E5�E6�E7�E8�E9�E10
	else {
		return ca3 % 13;
	}

	return 0;
}



//�f�B�[���[�̓��_�̊֐�
int DealercardPoint(int ca4, int DS) {

	int num3 = 0;

	//�J�[�h��11�E12���A13
	if (ca4 % 13 > 10 || ca4 % 13 == 0) {
		return 10;
	}
	//�J�[�h���G�[�X
	else if (ca4 % 13 == 1) {

		//�f�B�[���[��11��I�񂾎�17�𒴂��Ȃ���΃����_����1��11
		if (DS + 11 <= 17) {
			srand((unsigned int)time(NULL));
			num3 = rand() % 2;

			if (num3 == 1) {
				return 1;
			}
			else if (num3 == 0) {
				return 11;
			}
		}

		//�f�B�[���[��11��I�񂾂�17�𒴂���Ȃ�1��I��
		else if (DS + 11 > 17) {
			return 1;
		}
	}

	//�J�[�h��2�E3�E4�E5�E6�E7�E8�E9�E10
	else {
		return ca4 % 13;
	}

	return 0;
}