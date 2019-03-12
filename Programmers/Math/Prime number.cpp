/*
 ========================
   Programmers - �Ҽ�ã��
 ========================

+++++++++++++++++++++++++
'�����佺�׳׽��� ü'�� �̿��Ͽ�
 �����Ͽ���.
+++++++++++++++++++++++++
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int arr[n + 3];
	int cnt = 0;//�ʱ�ȭ
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}//�迭�� ���� ���� �Ҽ��� 2���� �Է� �޴� �� n���� ä���
	for (int i = 2; i*i <= n; i++) {//n���� �� �� �ʿ���� i<=sqrt(n)������ ����.
		/*�������, n==100
		 1*100
		 2*50
		 4*25
		 5*20
		 10*10
		 20*5
		 25*4
		 50*2
		 100*1   �ߺ��Ǳ� ������ �� �ʿ�x
		 */
		if (arr[i] == 0) continue;
		for (int j = i * 2; j <= n; j += i) {//��� ����
			arr[j] = 0;
		}
	}
	for (int k = 2; k <= n; k++) {
		if (arr[k] != 0) cnt++;
	}
	return cnt;
}