
/*��ȭ�� ã�� ������ �ʹ� �������, �� ���� ������ �ʿ��ϴٰ� �����Ѵ�.*/

#include <iostream>
using namespace std;

int dp[1001];
int check[1001];

int tile_cnt(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (check[n] != 0) 
		return dp[n];
	check[n] = 1;
	dp[n] = ((tile_cnt(n - 1))%10007 + (2 * tile_cnt(n - 2))%10007)%10007; //������ ��½�
	return dp[n];
}

int main() {
	int N = 0;
	scanf("%d", &N);
	printf("%d\n", tile_cnt(N)%10007);
	return 0;
}