/*���� Ÿ�ϰ� ���� Ÿ���� ���踦 �ľ��ϰ� ������ ����� ���ѷ����� ���ȴ�.
ó���� R+B�� ����� ���ϴٰ� �ȵǼ� R�� ����θ� �����ؼ� Ǯ�ԵǾ���.
printf�� ������ �ٲٸ� Ʋ�ȴٰ� �����µ� �� �׷����� �𸣰ڴ�.*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int R, B = 0; //B=(L-2)(W-2),  B=wl  //R=2(W+L)-4,  R=2(w+l)+4
	int l = 1;	//l,w != 1,2 
	int w = 1;  //l=L-2, w=W-2
	
	scanf("%d%d", &R, &B);
	while (1) {
		if (B % l == 0) {
			w = B / l;
			if (R == 2 * (l + w) + 4) {
				printf("%d %d\n", w + 2, l + 2);
				break;
			}
		}
		l++;
	}
	return 0;
}