////////////////////////////////
/*
        BOJ14890 ����
                              */
////////////////////////////////
/*
�������� �� �����ؾ߰ڴٰ� ���� ��������.
������ ������ ����� �������ϰ� �ڵ��� ����
������ �����ʴ�.
��������.
*/
#include <iostream>
using namespace std;

int N, L;
int field[105][105];

int main() {
	int sum = 0;
	scanf("%d%d", &N, &L);
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
				int lcnt = 0;//���θ� ��� ��
				for (int k = j + 1; field[i][k] == field[i][j + 1]; k++) {// ���� ������ �濡�� ���θ� ��鼭 lcnt++
					lcnt++;
				}
				if (lcnt >= L) {//���θ� L��ŭ ��� ����
					start = field[i][j + lcnt]; //������ ���κ��� start�� �������ְ�
					j = j + lcnt - 1;
					cnt = lcnt - L;
					continue;
				}
				else if (lcnt < L) break;//L��ŭ �� ��� �ݺ����� ����
			}

			if (start < field[i][j + 1]) { //���� ���� �� ŭ
				if (start + 1 < field[i][j + 1]) break; //1 �̻� ���̳��� �ݺ��� ����
				else if (start + 1 == field[i][j + 1]) {
					if (cnt >= L) {
						start = field[i][j + 1];
						cnt = 1;
						continue;
					}
					else if (cnt < L) break;
				}//�ڿ� ū ���� �������� �տ��ٰ� ���� �����ϴµ�
			}//ũ�Ⱑ ���� �� ������ cnt�� �����Ƿ� ���� ���� �޸� lcnt�� ���� �����ʴ´�.
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
				int lcnt = 0;
				for (int k = i + 1; field[k][j] == field[i + 1][j]; k++) {
					lcnt++;
				}
				if (lcnt >= L) {
					start = field[i + lcnt][j];
					i = i + lcnt - 1;
					cnt = lcnt - L;
					continue;
				}
				else if (lcnt < L) break;
			}
			if (start < field[i + 1][j]) { //���� ���� �� ŭ
				if (start + 1 < field[i + 1][j]) break;
				else if (start + 1 == field[i + 1][j]) {
					if (cnt >= L) {
						start = field[i + 1][j];
						cnt = 1;
						continue;
					}
					else if (cnt < L) break;
				}
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}