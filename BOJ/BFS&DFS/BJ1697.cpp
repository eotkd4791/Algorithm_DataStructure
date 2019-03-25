/*
====================
  BOJ1697 ���ٲ���
====================
/////////////////////
1���� �ٸ�������
���� ��������.
////////////////////
*/

#include <iostream>
#include <queue>
#define INF 100001
using namespace std;

int N, K;
int time;
int check[INF];
queue<int> q;

int BFS() {
	q.push(N);
	check[N] = 1;

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		if (now == K) return check[now] - 1;

		if (now + 1 < INF && check[now + 1] == 0) {
			check[now + 1] = check[now] + 1;
			q.push(now + 1);
		}

		if (now - 1 >= 0 && check[now - 1] == 0) {
			check[now - 1] = check[now] + 1;
			q.push(now - 1);
		}

		if (now * 2 < INF && check[now * 2] == 0) {
			check[now * 2] = check[now] + 1;
			q.push(now * 2);
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	printf("%d", BFS());
	return 0;
}