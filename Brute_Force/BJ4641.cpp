/*�Է� ���� �迭�� ���� 0�� �κб��� cnt�� ���� ���� �̻��ϰ� ���Դ�.
ã���� ����ߴ�. ���� for���� ���ǽ��� 0�� �ƴҶ��� 
���� �ٲ㼭 �ùٸ� ���� ����� �´�. 
�׸��� �迭 �����Ҷ� �޸𸮸� �����ְ� �����ؾ߰ڴ�.
15�� �����ؼ� Ʋ�ȴ�.
�̹� ������ �Ǽ�.*/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int arr[16] = {};
	int cnt = 0;
	int i = 0;

	while (1) {
		for (i = 0; i < 16; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] == 0 || arr[i] == -1) break;		//for�� Ż��
		}
		if (arr[i] == -1) break;						//���ѷ��� Ż��

		if (arr[i] == 0) {								//0�϶� ����Ʈ�� �ʱ�ȭ��.
			for (int k = 0; arr[k] != 0; k++) {			
				for (int j = 0; arr[j] != 0; j++) {
					if (arr[j] == arr[k] * 2) {
						cnt++;
						break;
					}
				}
			}
			printf("%d\n", cnt);
			cnt = 0;
			memset(arr, 0, sizeof(arr));			//�迭, cnt, i�� �ʱ�ȭ
			
		}
	}
	return 0;
}