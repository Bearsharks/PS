/*
�κ��� 1���� Ÿ�� n���� ������ �� 2n���� ��Ʈ�� ����
Ÿ�µ� �׸��� �̵� ��ǥ�� �������� ���.
ȸ�� Ÿ�� ������ ����ĭ�� �κ��� ���� �������� ������ �κ��� ��ĭ���� ���� �ݺ��Ҷ�
0�� �������� k�� �̻��̸� ����ȴ�. ����ɶ����� ��� �ϴ°�?
*/

#include <iostream>
#include <vector>
using namespace std;

int getidx(int src, int n) {
	src = src % n;
	return (src < 0)? n+src : src;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(2 * n);
	vector<bool> isEmpty(2 * n, true);
	for (int i = 0; i < 2*n; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	int t = 0;
	while (cnt < k) {
		t++;
		int start = getidx(-t, 2 * n);
		int end = getidx(start + n-1, 2 * n);
		if (!isEmpty[end]) isEmpty[end] = true;		
		for (int i = end; i != start && cnt < k; i = getidx(i - 1, 2 * n)) {
			if (isEmpty[i]) continue;

			int next = getidx(i + 1, 2 * n);
			if (isEmpty[next] && v[next]) {
				isEmpty[i] = true;
				isEmpty[next] = false;
				v[next]--;
				if (v[next] < 1) cnt++;
				if (next == end) isEmpty[next] = true;
			}
		}
		if (v[start] > 0) {
			v[start]--;
			isEmpty[start] = false;
			if (v[start] == 0) cnt++;
		}
	}
	cout << t;
	return 0;
}