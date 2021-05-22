/*
�迭���� �ΰ��� ����µ� �ΰ��� �Ȱ��� �� ��� 1�� ���ϴ� ����
��� ���Ӻκй迭 �������� ���� �� ������ ���Ͻÿ�.

���Ӻκй迭���� �ִµ� � ���Ӻκй迭�� �� ���� ���Ҹ� ���ؼ� ũ�Ⱑ �ϳ� �� ū consubarr�� ���� �� �ִ�.
�� consubarr�� �߰��� ���Ұ� �������� ������ ���Ҷ� �ٸ��ٸ� �� consubarr�� �信 �⿩�ϴ� ��ŭ�� �������� �Ȱ���.
���� ���ٸ�, �������� �ִ� �ſ��� ������ ���� �ϳ��� �߰��Ǽ� ���ܳ� ��ŭ�� �����ָ� �� ���� ���̴�.
�� ���ܳ� ��ŭ�� �󸶳� �ϱ� ���� i��°�� �߰� �Ǿ��� j��°�� �ִ³༮�� ���ٸ�
ji j-1 i j-2 i ... 1 i �� j�� ��ŭ�� �� ���ܳ� ���̴�.
�׷��ϱ� ���� �༮�� ������ �� �� �����Ƿ� ���� �༮�� ������ŭ�� ���� ���ܳ� ���̴�.
dp[i] = dp[i-1] + sigma(j) * arr[i] == arr[j]�̰�
���� sigma(dp)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n ;
		vector<int> v(n);
		for (int i = 0; i < n;i++) {
			cin >> v[i];
		}
		vector<long long> dp(n);
		
		unordered_map<int, long long> m;
		dp[0] = 0;
		m[v[0]] = 1;
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i - 1] + m[v[i]];
			m[v[i]] += i+1;
		}
		long long answer = 0;
		for (long long l : dp) {
			answer += l;
		}
		cout << answer << "\n";
	}
	return 0;
}