#include <iostream>
#include<math.h>
using namespace std;

int arr1[7] = {};		
int arr2[7] = {};		//�Է� ���� �� �� �ڸ������ ����
int tmp1[7] = {};
int tmp2[7] = {};		//tmp1,tmp2 �� ������ ���� �ӽ� �迭(ó�� �Է��� ���ڷ� �ٽ� ����ϱ� ���ؼ� �����ص�)
double min_num[2] = {};		//�ּڰ� �����ϱ� ���� �迭
double MAX_num[2] = {};		//�ִ� �����ϱ� ���� �迭 (pow�Լ� ������ ���������� ��)

int min(void) {
	for (int i = 0; i < 7; i++) {
		if (arr1[i] == 6)
			tmp1[i] = 5;
		min_num[0] += tmp1[i] * pow(10, i);  //������ ���п��� �ٲ� ���� ������ ������
	}
	for (int j = 0; j < 7; j++) {
		if (arr2[j] == 6)
			tmp2[j] = 5;
		min_num[1] += tmp2[j] * pow(10, j);
	}

	return min_num[0] + min_num[1];
}												//�ּҰ� ���ϴ� �Լ�

int MAX(void) {
	for (int i = 0; i < 7; i++) {
		if (arr1[i] == 5)
			arr1[i] = 6;
		MAX_num[0] += arr1[i] * pow(10,i);
	}
	for (int j = 0; j < 7; j++) {
		if (arr2[j] == 5)
			arr2[j] = 6;
		MAX_num[1] += arr2[j] * pow(10,j);	
	}
	 
	return MAX_num[0] + MAX_num[1];
}												//�ִ밪 ���ϴ� �Լ�


int main() {
	int num[2] = {};							//�Է� ���� �μ�
	
	for (int i = 0; i < 2; i++)
		scanf_s("%d", &num[i]);					//�μ��� �Է� ����
	
	


	for (int i = 0; i < 7; i++) {
		arr1[i] = num[0] % 10;
		num[0] /= 10;							//1�� �ڸ� ���ں��� �迭�� ����
	}


	for (int i = 0; i < 7; i++) {
		arr2[i] = num[1] % 10;
		num[1] /= 10;
	}

	for (int i = 0; i < 7; i++) {
		tmp1[i] = arr1[i];
		tmp2[i] = arr2[i];
	}

	printf("%d %d\n", min(), MAX());
	return 0;
}