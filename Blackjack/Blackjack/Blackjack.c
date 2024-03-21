
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char* cardMark(int ca); //カードのマーク
char* cardNumber(int ca2); //カードの数の関数
int YourcardPoint(int ca3); //あなたの得点の関数
int DealercardPoint(int ca4, int DS); //ディーラーの得点の関数

int main() {
	int card[52];
	int i;
	int a; //空き
	int num;
	int yourSum; //あなたの合計
	int dealerSum = 0; //ディーラーの合計
	int comand;
	int yourCount = 4; //あなたが引くカード
	int dealerCount = 2; //ディーラーが引くカード


	printf("☆★☆★☆★☆★☆★ブラックジャックへようこそ！☆★☆★☆★☆★☆★\n");
	printf("ゲームを開始します。\n");

	//0～51に1～52入れる
	for (i = 0; i < 52; i++) {
		card[i] = i + 1;
	}

	//シャッフルする
	srand((unsigned int)time(NULL));
	for (i = 0; i < 52; i++) {
		num = rand() % 52;

		a = card[i];
		card[i] = card[num];
		card[num] = a;
	}

	//あなたの引いた1・2枚目のカード
	printf("あなたの引いたカードは%s%sです。\n", cardMark(card[0]), cardNumber(card[0]));
	printf("あなたの引いたカードは%s%sです。\n", cardMark(card[1]), cardNumber(card[1]));
	yourSum = YourcardPoint(card[0]) + YourcardPoint(card[1]);

	if (yourSum == 21) {
		printf("ナチュラルブラックジャック！あなたの勝ちです。\n");

		printf("ブラックジャック終了！また遊んでね★\n");

		return 0;
	}

	//ディーラーの引いた1・2枚目のカード
	printf("ディーラーの引いたカードは%s%sです。\n", cardMark(card[2]), cardNumber(card[2]));
	printf("ディーラーの2枚目のカードは分かりません。\n");
	dealerSum = DealercardPoint(card[2], dealerSum) + DealercardPoint(card[3], dealerSum);

	printf("あなたの現在の得点は%dです。\n", yourSum);


	//カードを引きますか？
	while (yourSum < 21) {
		printf("カードを引きますか？引く場合はYを、引かない場合はNを入力してください\n");
		comand = getchar(); // 文字を読み取る
		while (getchar() != '\n'); // 改行文字を捨てる

		if (comand == 'Y') { //comand が int 型でありながら、ASCIIコード値として 'Y' や 'N' を使って比較できるのは、 getchar() 関数が文字のASCIIコード値を返すため
			printf("あなたの引いたカードは%s%sです。\n", cardMark(card[yourCount]), cardNumber(card[yourCount]));

			yourSum = yourSum + YourcardPoint(card[yourCount]);
			printf("あなたの現在の得点は%dです。\n", yourSum);
			yourCount++;
		}
		else if (comand == 'N') {
			break;
		}
		else {
			printf("もう一度入力してください。\n");
		}
	}

	//あなたの得点が21・21以上
	if (yourSum == 21) {
		printf("ブラックジャック！あなたの勝ちです。\n");

		printf("ブラックジャック終了！また遊んでね★\n");

		return 0;
	}

	else if (yourSum > 21) {
		printf("あなたの負けです。\n");

		printf("ブラックジャック終了！また遊んでね★\n");

		return 0;
	}

	printf("ディーラーの2枚目のカードは%s%sでした。\n", cardMark(card[3]), cardNumber(card[3]));


	//ディーラーが17以上になるまで

	if (dealerSum <= 17) {
		for (i = yourCount; i < 52; i++) {
			if (dealerSum <= 17) {
				dealerCount++;
				dealerSum = dealerSum + DealercardPoint(card[i], dealerSum);
				printf("ディーラーの%d枚目のカードは%s%sでした。\n", dealerCount, cardMark(card[i]), cardNumber(card[i]));
			}
		}
	}

	printf("ディーラーの得点は%dです。\n", dealerSum);


	//勝負

	if (dealerSum > 21) {
		printf("あなたの勝ちです。\n");

		printf("ブラックジャック終了！また遊んでね★\n");

		return 0;
	}

	else {

		if (yourSum > dealerSum) {
			printf("あなたの勝ちです。\n");
		}
		else if (yourSum < dealerSum) {
			printf("ディーラーの勝ちです。\n");
		}
		else {
			printf("引き分けです。\n");
		}

		printf("ブラックジャック終了！また遊んでね★\n");

		return 0;
	}
}


//マークの関数
char* cardMark(int ca) {

	static char ma[16];

	if ((ca - 1) / 13 == 0) {
		strcpy_s(ma, sizeof(ma), "スペードの");
	}
	else if ((ca - 1) / 13 == 1) {
		strcpy_s(ma, sizeof(ma), "クラブの");
	}
	else if ((ca - 1) / 13 == 2) {
		strcpy_s(ma, sizeof(ma), "ハートの");
	}
	else if ((ca - 1) / 13 == 3) {
		strcpy_s(ma, sizeof(ma), "ダイヤの");
	}
	else {
		strcpy_s(ma, sizeof(ma), "エラー");
	}

	return ma;
}



////マークの関数
//char* cardMark(int ca) {
//
//	static char ma[16];
//
//	char* mark[4] = { "スペードの" ,"クラブの" ,"ハートの" ,"ダイヤの" };
//
//		strcpy_s(ma, sizeof(ma), mark[(ca - 1) / 13]);
//
//	return ma;
//}



//カードの数の関数
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


//あなたの得点の関数
int YourcardPoint(int ca3) {

	int num2;

	//カードが11・12か13
	if (ca3 % 13 > 10 || ca3 % 13 == 0) {
		return 10;
	}
	//カードがエース
	else if (ca3 % 13 == 1) {

		printf("1点を選ぶ場合は1、11点を選ぶ場合は11を入力してください\n");
		scanf_s(" %d", &num2);
		while (getchar() != '\n'); //getchar() 関数は標準入力から1文字ずつ文字を読み取る

		if (num2 == 1) {
			return 1;
		}
		else if (num2 == 11) {
			return 11;
		}
	}
	//カードが2・3・4・5・6・7・8・9・10
	else {
		return ca3 % 13;
	}

	return 0;
}



//ディーラーの得点の関数
int DealercardPoint(int ca4, int DS) {

	int num3 = 0;

	//カードが11・12か、13
	if (ca4 % 13 > 10 || ca4 % 13 == 0) {
		return 10;
	}
	//カードがエース
	else if (ca4 % 13 == 1) {

		//ディーラーが11を選んだ時17を超えなければランダムで1か11
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

		//ディーラーが11を選んだら17を超えるなら1を選ぶ
		else if (DS + 11 > 17) {
			return 1;
		}
	}

	//カードが2・3・4・5・6・7・8・9・10
	else {
		return ca4 % 13;
	}

	return 0;
}