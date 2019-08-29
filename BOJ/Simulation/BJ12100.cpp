#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N,MAX; 
int field[22][22];
int tmp[22][22];
vector<int> v;
// 0:�� 1:�� 2:�� 3:��

void play() {
	memcpy(field, tmp, sizeof(tmp));
	for (int i = 0; i < 5; i++) {
		if (v[i] == 0) {//��
			for (int j = 0; j < N; j++) {//�����̵�
				for (int i = 0; i < N - 1; i++) {
					for (int k = i + 1; k < N; k++) {
						if (field[i][j] != 0) {
							if (field[i][j] == field[k][j]) {
								field[i][j]+=field[k][j];
								field[k][j] = 0;
								break;
							}
							else if (field[k][j] == 0)
								continue;
							else
								break;
						}
						else {
							field[i][j] = field[k][j];
							field[k][j] = 0;
						}
					}
				}
			}
		}
		if (v[i] == 1) {//��
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j >= 1; j--) {
					for (int k = j - 1; k >= 0; k--) {
						if (field[i][j] != 0) {
							if (field[i][j] == field[i][k]) {
								field[i][j] +=field[i][k];
								field[i][k] = 0;
								break;
							}
							else if (field[i][k] == 0)
								continue;
							else 
								break;
						}
						else {
							field[i][j] = field[i][k];
							field[i][k] = 0;
						}
					}
				}
			}
		}
		if (v[i] == 2) {//��
			for (int j = 0; j < N; j++) {//�����̵�
				for (int i = N - 1; i >= 1; i--) {
					for (int k = i - 1; k >= 0; k--) {
						if (field[i][j] != 0) {
							if (field[i][j] == field[k][j]) {
								field[i][j] +=field[k][j];
								field[k][j] = 0;
								break;
							}
							else if (field[k][j] == 0)//������ 0�� �ƴѵ� (���� �ִµ�) 
								continue;
							else 
								break;
						}
						else {
							field[i][j] = field[k][j];
							field[k][j] = 0;
						}
					}
				}
			}
		}
		if (v[i] == 3) {//��
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N - 1; j++) {
					for (int k = j + 1; k < N; k++) {
						if (field[i][j] != 0) {
							if (field[i][j] == field[i][k]) {
								field[i][j] += field[i][k];
								field[i][k] = 0;
								break;
							}
							else if (field[i][k] == 0)
								continue;
							else
								break;
						}
						else {
							field[i][j] = field[i][k];
							field[i][k] = 0;
							
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			MAX = max(MAX, field[i][j]);
	return;
}

void picked(int now) {
	if (now == 5) {
		play();
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			v.push_back(i);
			picked(now + 1);
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> field[i][j];
			tmp[i][j] = field[i][j];
		}
	}
	picked(0);
	cout << MAX;
	return 0;
}