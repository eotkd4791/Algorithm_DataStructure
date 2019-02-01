#include <iostream>
using namespace std;

int Binary_Search(int arr[], int length, int target) { //�迭 �̸�, ����, ã���� �ϴ� ��
	int first = 0;				//Ž�� ���� �ε��� ��
	int last = length - 1;	//Ž�� ������ �ε��� ��
	int mid;						//Ž���� ���ذ�, �ѹ� Ž���Ŀ� ���� �缳���� ���� ����

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid]) return mid;	
		else {
			if (target < arr[mid]) last = mid - 1;
			else first = mid + 1;
		}
	}
	return -1;					 //Ž������-ã�� ���� ���� ���� ���� �� -1��ȯ
}
int main() {
	int arr[] = { 1,3,5,7,9 };
	int idx=0;
	printf("%d ", arr[]);
	idx = Binary_Search(arr, sizeof(arr) / sizeof(int), n);
	if (idx == -1) printf("ã�� ���� ���� ���� �����ϴ�.\n");
	else printf("Ÿ���� ����Ǿ� �ִ� �ε����� %d �Դϴ�.\n", idx);
	
	idx = Binary_Search(arr, sizeof(arr)/sizeof(int), 4);
	if (idx == -1) printf("ã�� ���� ���� ���� �����ϴ�.\n");
	else printf("Ÿ���� ����Ǿ� �ִ� �ε����� %d �Դϴ�.\n", idx);
	return 0;
}//����Ž���� ������������ ������ �Ǿ��ִ� ���¿��� �ؾ��Ѵ�.