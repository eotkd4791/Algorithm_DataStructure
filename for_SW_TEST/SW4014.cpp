////////////////////////////////
/*
        SWEA4014 Ȱ�ַΰǼ�
                              */
////////////////////////////////

#include <iostream>
using namespace std;

int T,N X;
int field[105][105];

int main() {
	int sum = 0;
	scanf("%d%d", &N, &X);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {//x�� �������� 
		int start = field[i][0];
		int cnt = 1;
		for (int j = 0; j < N; j++) {//y�� ����
			if (j == N - 1) {//������ ���� sum++���ְ� �ݺ����� ������.
				sum++;
				break;
			}
			if (start == field[i][j + 1]) { //���� ���̶� ���� ���
				start = field[i][j + 1]; //���� �� ������ �Ǵ� start�� ���� ���� �����Ѵ�.
				cnt++;
				continue;
			}

			if (start > field[i][j + 1]) { //���� ���� �� ����
				if (start - 1 > field[i][j + 1]) break;//1�̻� ���̳��� �ݺ��� ����
				int xcnt = 0;//���θ� ��� ��
				for (int k = j + 1; field[i][k] == field[i][j + 1]; k++) {// ���� ������ �濡�� ���θ� ��鼭 xcnt++
					xcnt++;
				}
				if (xcnt >= X) {//���θ� X��ŭ ��� ����
					start = field[i][j + xcnt]; //������ ���κ��� start�� �������ְ�
					j = j + xcnt - 1;
					cnt = xcnt - X;
					continue;
				}
				else if (xcnt < X) break;//X��ŭ �� ��� �ݺ����� ����
			}

			if (start < field[i][j + 1]) { //���� ���� �� ŭ
				if (start + 1 < field[i][j + 1]) break; //1 �̻� ���̳��� �ݺ��� ����
				else if (start + 1 == field[i][j + 1]) {
					if (cnt >= X) {
						start = field[i][j + 1];
						cnt = 1;
						continue;
					}
					else if (cnt < X) break;
				}//�ڿ� ū ���� �������� �տ��ٰ� ���� �����ϴµ�
			}//ũ�Ⱑ ���� �� ������ cnt�� �����Ƿ� ���� ���� �޸� xcnt�� ���� �����ʴ´�.
		}
	}

	for (int j = 0; j < N; j++) {//y���� ��������
		int start = field[0][j];
		int cnt = 1;
		for (int i = 0; i < N; i++) {// x���� Ž���Ѵ�.
			if (i == N - 1) {
				sum++;
				break;
			}
			if (start == field[i + 1][j]) { //���� ���̶� ����
				start = field[i + 1][j];
				cnt++;
				continue;
			}
			if (start > field[i + 1][j]) { //���� ���� �� ����
				if (start - 1 > field[i + 1][j]) break;
				int xcnt = 0;
				for (int k = i + 1; field[k][j] == field[i + 1][j]; k++) {
					xcnt++;
				}
				if (xcnt >= X) {
					start = field[i + xcnt][j];
					i = i + xcnt - 1;
					cnt = xcnt - X;
					continue;
				}
				else if (xcnt < X) break;
			}
			if (start < field[i + 1][j]) { //���� ���� �� ŭ
				if (start + 1 < field[i + 1][j]) break;
				else if (start + 1 == field[i + 1][j]) {
					if (cnt >= X) {
						start = field[i + 1][j];
						cnt = 1;
						continue;
					}
					else if (cnt < X) break;
				}
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}