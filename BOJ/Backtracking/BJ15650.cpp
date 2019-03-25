////////////////////////////////
//============================//
//     BOJ15650 N��M (2)      //
//============================//
////////////////////////////////
////////////////////////////////
////////////////////////////////
//////////////////////////////////
/* �񳻸������� ���ؼ� arr[cnt-1]��
�����ϴ� ������ �������ϰ�, �ߺ���
���ϱ� ���� check�� ����ؾ��Ѵ�. */
/////////////////////////////////


#include <iostream>
using namespace std;

int N, M;

void recur(int *arr, bool *check, int cnt) {
	if (cnt == M) {
		
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]+1);
		}
		printf("\n");
		return;
	}
	int st = 0;
	if (cnt != 0) st = arr[cnt - 1];
	for (int i = st; i < N; i++) {
		if (!check[i]) {
			arr[cnt] = i;
			check[i] = 1;
			recur(arr, check, cnt + 1);
			check[i] = 0;
		}
	}
}


int main() {
	scanf("%d%d", &N, &M);
	int arr[10] = {};
	bool check[10] = {};
	recur(arr, check, 0);
	return 0;
}