/*���ڿ� �ǵڿ��� NULL���ڰ� �´ٴ� ���� �������.
�Ǿ��� ��ĭ�̸� 0���� �����ؼ� ��ĭ�� �� cnt�� �÷ȴ�.
�Ǿ��� ���ڸ� 1�� �����ؼ� cnt �� �÷Ȱ�, 
�ǵڰ� ��ĭ�̸� ������ cnt�� �ϳ� ���ҽ��״�.
str[str_len-1]���� NULL���ڰ� ���ԵǾ��ִ�.*/
#include <iostream>
#include <cstring>
using namespace std;
char str[1000001];
int str_len, cnt=1;

int main() {
	fgets(str, 1000001, stdin);
	str_len = strlen(str);
	if (str[0] == ' ') cnt = 0;
	for (int i = 0; i < str_len; i++) {
		if (str[i] == ' ') cnt++;
	}
	if (str[str_len - 2] == ' ') cnt--;
	printf("%d", cnt);
	return 0;
}