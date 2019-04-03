
////////////////////////////////////////
/*
 BOJ6549 ������׷����� ���� ū ���簢��
                                      */
////////////////////////////////////////

/*
Segment tree�� Ȱ���Ͽ� ������ �ɰ���
���� ���� ����� ���̰� �ּҰ� �Ǵ� �ε�����
���ؼ� �ִ밡 �Ǵ� ���簢���� ���̸� ���ϴ� ��������.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		tree[node] = start;
	else
	{
		int mid = (start + end) / 2;
		init(arr, tree, node * 2, start, mid);
		init(arr, tree, node * 2 + 1, mid + 1, end);

		// �� �������� ����� ���̰� ���� ���� ���� ��忡 �־��ش�.
		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

// �������� ���� �ּ��� ������ ���� ���ϱ�
int query(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) // left--right�� ������ �Ѵ� �����  -1 ��ȯ
		return -1;

	if (left <= start && end <= right)
		return tree[node]; // left--right ������ start�� end�� ������ tree[node]�� ��ȯ�Ѵ�.

	int mid = (start + end) / 2;
	int m1 = query(arr, tree, node * 2, start, mid, left, right);
	int m2 = query(arr, tree, node * 2 + 1, mid + 1, end, left, right); //������

	if (m1 == -1)
		return m2;

	else if (m2 == -1)
		return m1;

	else
	{
		if (arr[m1] <= arr[m2])
			return m1;			//������ ������ ���� �ε����� ����� ������ �ּҰ��� �Ǵ� �ε����� ��ȯ�Ѵ�.
		else
			return m2;
	}
}

long long getMax(vector<int> &arr, vector<int> &tree, int start, int end)
{
	int n = arr.size();
	int m = query(arr, tree, 1, 0, n - 1, start, end); //query�Լ����� ��ȯ�� �ε��� ��


	long long area = (long long)(end - start + 1)*(long long)arr[m]; //n=���� m�� �������̰� ����Ǿ��ִ� �迭�� �ε���


	if (start <= m - 1)
	{
		long long tmp = getMax(arr, tree, start, m - 1);//�� �������� ������ 

		if (area < tmp)
			area = tmp; // �ִ밪�� area�� �����Ѵ�.
	}
	//�ձ���

	if (m + 1 <= end)
	{
		long long tmp = getMax(arr, tree, m + 1, end);
		if (area < tmp)
			area = tmp;
	}

	//�ޱ���
	return area; //���� ���� ��ȯ
}

int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		vector<int> arr(n);


		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);


		int h = (int)(ceil(log2(n)));
		int tree_size = pow(2, (h + 1));

		vector<int> tree(tree_size);


		init(arr, tree, 1, 0, n - 1);

		printf("%lld\n", getMax(arr, tree, 0, n - 1));
	}

	return 0;
}
