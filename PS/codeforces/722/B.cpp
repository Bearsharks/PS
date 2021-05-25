/*
* ��Ǯ�ȴ� ������ �ִ밪�� ������ �߸� ��ұ� ������ 10 ^ 9 �� 987654321���� ũ��
* 1e9+1�� �߾�� �ߴ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int firstpositive = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int mn = 1e9 + 1;
		int first = 0;
		for (int i = 1; i < n; i++) {
			mn = min(abs(v[i] - v[i - 1]), mn);
			first = i;
			if (v[i] > 0) break;
		}
		if (v[first] <= mn) cout << first + 1 << "\n";
		else cout << first << "\n";
	}
	return 0;
}