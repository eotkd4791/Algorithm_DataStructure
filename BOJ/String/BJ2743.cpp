/*scanf�� fgets������
fgets�� ������ ���Եȴ�.
�׷��� fgets�� �̿��� �ڵ忡�� -1�� �����.
���� fgets�� NULL���� �Ӹ� �ƴ϶�, 
������ ���� ���� ������ �迭�� ũ�⸦
�ٲ�� �ߴ�.*/

#include <iostream>
#include <cstring>
using namespace std;
char word[101];
int str_len;

int main() {
	scanf("%s", word);
	str_len = strlen(word);
	printf("%d", str_len);
	return 0;
}
//
//
//
//
#include <iostream>
#include <cstring>
using namespace std;
char word[102];
int str_len;

int main() {
	fgets(word, 102, stdin);
	str_len = strlen(word) - 1;
	printf("%d\n", str_len);
	return 0;
}