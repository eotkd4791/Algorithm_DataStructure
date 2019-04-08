////////////////////////////////
/*
        BOJ14890 경사로
                              */
////////////////////////////////
/*
구현력을 더 연습해야겠다고 느낀 문제였다.
아직도 문제를 제대로 숙지안하고 코딩에 들어가는
느낌이 없지않다.
주의하자.
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
	for (int i = 0; i < N; i++) {//x축 기준으로 
		int start = field[i][0];
		int cnt = 1;
		for (int j = 0; j < N; j++) {//y축 보기
			if (j == N - 1) {//끝까지 가면 sum++해주고 반복문을 끝낸다.
				sum++;
				break;
			}
			if (start == field[i][j + 1]) { //다음 길이랑 같은 경우
				start = field[i][j + 1]; //비교할 때 기준이 되는 start에 같은 길을 대입한다.
				cnt++;
				continue;
			}

			if (start > field[i][j + 1]) { //다음 길이 더 작음
				if (start - 1 > field[i][j + 1]) break;//1이상 차이나면 반복문 끝냄
				int lcnt = 0;//경사로를 까는 수
				for (int k = j + 1; field[i][k] == field[i][j + 1]; k++) {// 같은 높이인 길에만 경사로를 깔면서 lcnt++
					lcnt++;
				}
				if (lcnt >= L) {//경사로를 L만큼 깔면 진행
					start = field[i][j + lcnt]; //경사로의 끝부분을 start에 대입해주고
					j = j + lcnt - 1;
					cnt = lcnt - L;
					continue;
				}
				else if (lcnt < L) break;//L만큼 못 깔면 반복문을 끝냄
			}

			if (start < field[i][j + 1]) { //다음 길이 더 큼
				if (start + 1 < field[i][j + 1]) break; //1 이상 차이나면 반복문 끝냄
				else if (start + 1 == field[i][j + 1]) {
					if (cnt >= L) {
						start = field[i][j + 1];
						cnt = 1;
						continue;
					}
					else if (cnt < L) break;
				}//뒤에 큰 길이 나오려면 앞에다가 경사로 놔야하는데
			}//크기가 같은 길 갯수가 cnt와 같으므로 위의 경우와 달리 lcnt를 따로 쓰지않는다.
		}
	}

	for (int j = 0; j < N; j++) {//y축을 기준으로
		int start = field[0][j];
		int cnt = 1;
		for (int i = 0; i < N; i++) {// x축을 탐색한다.
			if (i == N - 1) {
				sum++;
				break;
			}
			if (start == field[i + 1][j]) { //다음 길이랑 같음
				start = field[i + 1][j];
				cnt++;
				continue;
			}
			if (start > field[i + 1][j]) { //다음 길이 더 작음
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
			if (start < field[i + 1][j]) { //다음 길이 더 큼
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