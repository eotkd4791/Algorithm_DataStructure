////////////////////////////////////////
/*
   BFS Topological Ordering(Sorting)

////////////////////////////////////////

## BFS�� �̿��� �������� ���� ##

Indegree�� ������ 0�� ��带 ť�� Ǫ���ϰ�
BFS�Լ��� ȣ���Ѵ�.
ť�� Ǫ���Ǿ� �ִ� ���� ������ ������
Indegree������ ���ҽ�Ű�鼭 Indegree������ 
0�� �Ǵ� ������ �ٽ� Ǫ���ϴ� ������� 
�����Ѵ�. ����Ŭ�� �ִٸ� Indegree������ 0��
�ƴ� ��尡 ��� 2���� �����ϹǷ�
ť�� ���̻��� Ǫ���� �߻����� �ʾƼ� 
BFS�Լ��� �����.
pop�Ǵ� ������ ������� �����س��� �迭�� 
������ ������ ����� ������ ���� �ʴٸ�
����Ŭ�� �����Ͽ� ���������� �Ұ����� ����̹Ƿ�
"�������� ����"��� ������ ����Ѵ�.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;
int check[10];
int ind[10];
int arr[10];
int ii;
queue<int> q;
vector<vector<int> > v(100);

void BFS() {
	while (!q.empty()) {
		int oq = q.front();

		int sz = v[oq].size(); 
			for (int i = 0; i < sz; i++) {
				int idx = v[oq][i];
				ind[idx]--;
				if (ind[idx] == 0)
					q.push(idx);
			}
		arr[ii++] = oq;
		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}

	for (int i = 1; i <= V; i++)
		if (ind[i] == 0) q.push(i);
	BFS();

	if (arr[V - 1] == 0) cout << "�������� ����" << "\n";
	else {
		for (int i = 0; i < V; i++) {
			cout << arr[i] << ' ';
		}
	}
	return 0;
}