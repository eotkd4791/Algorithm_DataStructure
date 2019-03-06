#include <iostream>
#include <cstring>
using namespace std;

int arr[4][8]; //��Ϲ���[��ȣ][�̻�]
int k; //ȸ����
int turn[4];   //�� ��Ϲ����� ȸ�������� �����ϴ� �迭
int num, dir; //��Ϲ��� ��ȣ, ȸ������

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &num, &dir);
		num -= 1; // �迭�� �ε���=��Ϲ��� ��ȣ -1
		turn[num] = dir; //��Ϲ��� ��ȣ -1 �� �ε����� ���, ����dir ����
		for (int i = num - 1; i >= 0; i--) {//�Է¹��� ��Ϲ����� ���ʿ� �ִ� ��Ϲ���
			if (arr[i][2] != arr[i + 1][6]) {
				turn[i] = -turn[i + 1];
			}
			else break;//�´��� ���� ���Ƽ� ���� ���� ��
		}
		for (int i = num + 1; i < 4; i++) {//�Է¹��� ����� �����ʿ� �ִ� ��Ϲ���
			if (arr[i][6] != arr[i - 1][2]) {
				turn[i] = -turn[i - 1];
			}
			else break;// �� ��ϰ� ȸ������ ������ �����ʿ� �ִ� ��ϵ� ȸ������ �ʴ´�.
		}
		for (int n = 0; n < 4; n++) {
			if (turn[n] == 0) continue;//�����ִ� ��Ϲ����� ȸ����Ű�� �ʰ� ��������.
			if (turn[n] == 1) {
				int tmp = arr[n][7];
				for (int m = 7; m >= 1; m--) {
					arr[n][m] = arr[n][m - 1];
				}//1������ ������ tmp�� ������ ���� ���� ����.
				arr[n][0] = tmp;
			}
			else if (turn[n] == -1) {
				int tmp = arr[n][0];
				for (int m = 0; m < 7; m++) {
					arr[n][m] = arr[n][m + 1];
				}
				arr[n][7] = tmp;
			}
		}
		memset(turn, 0, sizeof(turn));
	}
	int result = 0;
	int sum = 1;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1) result += sum;
		sum *= 2;
	}
	printf("%d\n", result);
	return 0;
}
