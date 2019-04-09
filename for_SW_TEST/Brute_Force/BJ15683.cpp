///////////////////////////////
/*
        BOJ15683 ����
                             */
///////////////////////////////
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int INF = 9999999;
int N, M;
int field[10][10];
int arr[10][10];//�����ϱ����� �迭
int MIN = INF;//�ּҰ�
int num;//CCTV����
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dir[8];//ī�޶��� ������ �����ϴ� �迭, �ε���+1�� ī�޶��� ��ȣ(����)�� �ǹ�
vector<int> v;//ī�޶� ���� �����ϴ� ����
vector<pair<int, int> > xy;//ī�޶� �ִ� ��ǥ(��ġ)�����ϴ� ����

bool OOB(int a, int b) {//���˻�
	if (N > a && a >= 0 && 0 <= b && b < M)
		return true;
	return false;
}

void cpy(int a[10][10], int b[10][10]) {//�ʺ���,�����Ҷ� ���� �Լ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void DFS(int x, int y, int cam, int drt) {
	//pickdir�Լ����� �޾ƿ� ������ CCTV�� ������ field�� 
	//CCTV�� ��� ���� ����ϴ� �Լ�
	if (field[x][y] == 6) return;
	if(field[x][y]==0)
		field[x][y] = cam;

	if (cam == 1) {//CCTV1
		if (drt == 0) {//����0�϶�
			int nx = x + dx[0];
			int ny = y + dy[0];//����� ���� 2����
			if(OOB(nx,ny) && field[nx][ny]!=6)
				DFS(nx, ny, 1, 0);
		}
		if (drt == 1) {//����1�϶�
			int nx = x + dx[1];
			int ny = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 1);
		}
		if (drt == 2) {//����2�϶�
			int nx = x + dx[2];
			int ny = y + dy[2];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 2);
		}
		if (drt == 3) {//����3�϶�
			int nx = x + dx[3];
			int ny = y + dy[3];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
		}
	}
	if (cam == 2) {//CCTV2
		if (drt == 0 || drt == 2) {
			int nx = x + dx[0];
			int ny = y + dy[0];
			int rx = x + dx[2];
			int ry = y + dy[2];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 0);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
		}
		if (drt == 1 || drt==3) {
			int nx = x + dx[1];
			int ny = y + dy[1];
			int rx = x + dx[3];
			int ry = y + dy[3];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 1);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 3);
		}
	}
	if (cam == 3) {//CCTV3
		if (drt == 0) {
			int nx = x + dx[0];
			int ny = y + dy[0];
			int rx = x + dx[3];
			int ry = y + dy[3];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 0);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 3);
		}
		if (drt == 1) {
			int nx = x + dx[0];
			int ny = y + dy[0];
			int rx = x + dx[1];
			int ry = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 0);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 1);
		}
		if (drt == 2) {
			int nx = x + dx[2];
			int ny = y + dy[2];
			int rx = x + dx[1];
			int ry = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 2);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 1);
		}
		if (drt == 3) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[2];
			int ry = y + dy[2];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
		}
	}
	if (cam == 4) {//CCTV4
		if (drt == 0) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[2];
			int ry = y + dy[2];
			int cx = x + dx[0];
			int cy = y + dy[0];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 0);
		}
		if (drt == 1) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[1];
			int ry = y + dy[1];
			int cx = x + dx[0];
			int cy = y + dy[0];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 1);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 0);
		}
		if (drt == 2) {
			int nx = x + dx[1];
			int ny = y + dy[1];
			int rx = x + dx[2];
			int ry = y + dy[2];
			int cx = x + dx[0];
			int cy = y + dy[0];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 1);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 0);
		}
		if (drt == 3) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[2];
			int ry = y + dy[2];
			int cx = x + dx[1];
			int cy = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 1);
		}
	}
	if (cam == 5) {
		int nx = x + dx[3];
		int ny = y + dy[3];
		int rx = x + dx[2];
		int ry = y + dy[2];
		int cx = x + dx[1];
		int cy = y + dy[1];
		int vx = x + dx[0];
		int vy = y + dy[0];
		if (OOB(nx, ny) && field[nx][ny] != 6)
			DFS(nx, ny, 1, 3);
		if (OOB(rx, ry) && field[rx][ry] != 6)
			DFS(rx, ry, 1, 2);
		if (OOB(cx, cy) && field[cx][cy] != 6)
			DFS(cx, cy, 1, 1);
		if (OOB(vx, vy) && field[vx][vy] != 6)
			DFS(vx, vy, 1, 0);
	}//��� ������ CCTV�� �������� �ᱹ�� CCTV1�� ����� ���Ҵ�. �׷��� DFS�Լ� ���� ��, cam�ڸ��� 1�� ����ؼ� �־� ȣ���ߴ�.
}

void ycsm() {//you can't see me �Լ� CCTV�� ������ �� ���� �簢���� ���� �Լ�
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 0) {
				cnt++;
			}
		}
	}
	if (MIN > cnt) MIN = cnt;
	cpy(arr, field);
	return;
}

void CCTV() {//CCTV�� ������ŭ �ݺ����� �����鼭 DFS�Լ��� �Ⱦ� �ִ� �Լ�
	for (int i = 0; i < num; i++) {
		int tmp = v[i];
		DFS(xy[i].first, xy[i].second, tmp, dir[i]);
	}
	ycsm();
	return;
}

void pickdir(int a) {//������ ���� �� �ִ� ��� ����� ���� ���ȣ��� �̾Ƴ��� �Լ�
	if (a == num) {
		CCTV();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir[a] = i;
		pickdir(a + 1);
		dir[a] = 0;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
			if (0 < field[i][j] && field[i][j] < 6) {//CCTV�� ������
				num++;//CCTV���� ����
				v.push_back(field[i][j]);//CCTV ī�޶� ���� ����
				xy.push_back({ i,j });//CCTV ī�޶� ��ǥ
			}
		}
	}
	cpy(field, arr);//�Է¹��� 2���� �迭field�� arr�� �����Ѵ�.
	pickdir(0);//���ȣ���� �̿��� ����Ž������ CCTV���� ��ŭ 0~4 ���� �̾Ƽ� dir�迭�� �����ϴ� �Լ�
	printf("%d\n", MIN);
	return 0;
}