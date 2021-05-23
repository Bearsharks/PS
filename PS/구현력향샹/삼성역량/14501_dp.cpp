/*
�ѹ��� �ϳ��� �ϸ� �� �� �ְ�,
���Ͽ� �����ؼ� ���Ͽ� ������ ���� �ϸ� ���� ���� �󸶶�� �˷��� ������,
���� �ִ�� �󸶱��� ���� �ֳ��� ����� ����

�����ѵ� �Ѱ��� �ָ��� ���� ���� �̻����� �ϸ� �ȵɶ��� �б��ؼ� �Ȱ��� �ߴٴ� ��
���� ���ϰ��� �ٲٰų� �ؼ� ������ �ٲٸ� ����ϴٴ� ���̴�.
*/
#include <iostream>
#include <vector>
using namespace std;


vector<int> t(15);
vector<int> p(15);
vector<int> dp(15, -1);
int N;
int f(int k) {
	if (k >= N) return 0;
	int& ret = dp[k];
	if (ret >= 0) return ret;
	ret = 0;
	if (t[k] + k - 1 < N) {
		ret = max(ret, p[k] + f(t[k] + k));		
	}	
	ret = max(ret, f(k + 1));
	return ret;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> p[i];
	}	
	cout << f(0);
	return 0;
}