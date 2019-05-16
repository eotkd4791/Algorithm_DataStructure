////////////////////////////////////////
/*
   DFS Topological Ordering(Sorting)

////////////////////////////////////////

## DFS�� �̿��� �������� ���� ##

check�迭�� White(0), Gray(1), Black(2)
�� ���� ������ Ư���� ����Ͽ� cycle������
�˻��ϰ�, ����Ŭ�� �����ϸ� '�������� ����'
��� ������ ����ϰ� ����Ŭ�� �������� ������
�������ĵ� ����� ������ ����Ѵ�.

�ڷᱸ�� ���Ḯ��Ʈ�� �����ؼ� ���͸� ����Ʈ��
�����ϴ� ������ �ؾ߰ڴ�.
*/


#include <iostream>
#include <vector>
using namespace std;

int V, E;
int time;
int check[10];
int discover[10];
int finish[10];
int arr[10];
int ii;
bool cycle_exist;
vector<vector<int> > adj(10);

void DFS(int v) {
	check[v] = 1;
	discover[v] = ++time;

	int adjacent = adj[v].size();
	for (int j = 0; j < adjacent; j++) {
		int w = adj[v][j];
		if (check[w] == 0) { //white
			check[w] = 1;
			DFS(w);
		}
		if (check[w] == 1) { //gray
			cycle_exist = 1;
			return;
		}
		if (check[w] == 2) { //black
			continue;
		}
		
	}
	finish[v] = ++time;
	check[v] = 2;
	arr[ii++] = v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) {
		if (check[i] == 0) {
			DFS(i);
		}
	}

	if (cycle_exist) {
		cout << "�������� ����\n";
	}
	else {
		for (int i = V - 1; i >= 0; i--) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}