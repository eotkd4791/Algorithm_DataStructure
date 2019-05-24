/////////////////////////////
/*
     BOJ15656 N�� M (7)
                           */
/////////////////////////////
/*
������ �ݺ��ڸ� �̿��Ͽ� Ǯ��Ҵ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int ii;
int arr[10];
vector<int> v;

void recur(int cnt) {
	if (cnt == M) {
		for (vector<int> ::iterator iter = v.begin(); iter != v.end(); iter++) {
			cout << *iter << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		v.push_back(arr[i]);
		recur(cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	recur(0);
	return 0;
}