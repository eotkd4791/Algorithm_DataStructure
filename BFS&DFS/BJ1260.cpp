//-DFS & BFS �����ϴ� ���� BJ1260-
//������ ����N, ������ ����M, Ž���� �����ϴ� ��V.
//adj[1]��2��3��4
//adj[2]��1��4
//adj[3]��1��4
//adj[4]��1��2��3
//
//Vector�Լ��� �̿��ؼ� �׷����� �����. <main�Լ�>

#include <iostream>
#include <algorithm>									//sort
#include <cstring>										//visited�迭 �ʱ�ȭ memset
#include <queue>										//BFS�� �����ϱ� ���� �ʿ��� queue
#include <vector>										//�� �߱�
using namespace std;

int N, M, V, a, b;
int visited[1005];
queue <int> q;				
vector <vector <int>> adj(1005);

void DFS (int now) {											//DFS ���̿켱Ž�� �Լ�
	visited[now] = 1;											//visited�迭�� dp���� check�迭ó�� �̿��Ѵ�. �̹� �湮������ 1 �ƴϸ� 0.
	printf("%d ", now);
	for (int i = 0; i <adj[now].size(); i++) {				//adj���͹迭�� ũ�⸸ŭ for���� ������.
		int next = adj[now][i];
		if (visited[next] == 0) DFS(next);					//�湮���� �ʾҴٸ� next�� �Ű�������� �Լ��� ������.
	}
}

void BFS(int start) {												//BFS �ʺ�켱Ž�� �Լ�
	visited[start] = 1;										
	q.push(start);													//q.push�Լ��� �̿��� �Ű������� ���� ���� Queue�� �����Ѵ�.
	while (q.empty() == 0) {									//q.empty�Լ��� Queue�� �ƹ��͵� ���ٸ� 1, ������ �ִٸ� 0�� ��ȯ�Ѵ�.
		int now = q.front();										//Queue�� �ƹ��͵� ���������� �ݺ����� �����Ѵ�.
		q.pop();														//q.pop�Լ��� �̿��ؼ� Queue�� ���� ���ڸ��� ��(���Ӱ� ������ �Ǵ� ����)�� ���ش�.
		printf("%d ", now);										
		for (int i = 0; i <adj[now].size(); i++) {
			int next = adj[now][i];
			if (visited[next] == 0) {
				visited[next] = 1;
				q.push(next);										//Queue���� �������� Ž���� �������� �� �ְ�, ��� Ž���� ������ Queue�� �������,
			}															//while���� ���������� �ȴ�.
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);													//������ ��ǥ a,b�� push_back�Լ��� �̿��Ͽ� �������ش�.
		adj[b].push_back(a);													
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());								//���� ���ʴ�� �Էµ��� �ʰų� �湮������ ���̴� ���� �����ϱ����� �����Ѵ�.
	}																				//adj�� ����ִ� ������ �ε������� �����ϱ� ���ؼ� for���ȿ��� �����Ѵ�.
	DFS(V);
	printf("\n");
	memset(visited, 0, sizeof(visited));								//BFS���� ���� visited�迭 �ʱ�ȭ
	BFS(V);
	printf("\n");
	return 0;
}