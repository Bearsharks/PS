#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		if (k == 1) {
			cout << s << "\n";
			continue;
		}
		if (n % k) {
			cout << -1 << "\n";
			continue;
		}
		map<int, int> m;
		for (int i = 0; i < k; i++) {
			m[s[i]]++;
		}


		for (map<int, int>::iterator iter = m.begin(); iter != m.end();iter++) {
			iter->second *= (n / k - 1);
		}

		bool isok = true;
		for (int i = k; i < n; i++) {
			map<int,int>::iterator iter = m.lower_bound(s[i]);
			if (iter == m.end()) {
				//���� ���ڰ� ���� ��� ���ں��� ū���
				string cp = s.substr(k,i);
				//ó�� ���� ������� substr�� ���� ������ ���ڿ��� ���ؼ� (next_permu)
				next_permutation(s.begin() + k, s.begin() + i);
				bool issame = cp == s.substr(k, i);
				//���� ������ �ڹ��ڿ��δ� ó�� �Ұ���
				if (issame) {
					isok = false;
					break;
				}				
				//�ٸ��� �ڿ� ������ �ٿ��� �����
				for (pair<int, int> p : m) {
					for (int j = 0; j < p.second; j++) {
						s[i++] = p.first;
					}
				}
				break;
			}
			else if (iter->first != s[i]) {
				//���� ���ڰ� �չ��ڿ��� Ư�� ���� ���� �������
				s[i] = iter->first;//������ڸ� Ư�����ڷ� ����� �ڿ��� ������ �ٿ��� ���
				iter->second--;
				for (pair<int, int> p : m) {
					for (int j = 0; j < p.second; j++) {
						s[++i] = p.first;
					}
				}
				break;
			}
			if (--iter->second == 0) m.erase(iter);
		}
		if (isok) cout << s << "\n";
		else {
			//���� ���ڿ��� ó�� �Ұ����ϸ�
			//���� ���ڿ��� �ٲ㼭 ó����
			int cur = k - 1;
			while (s[cur] == 'z') {
				cur++;
			}
			s[cur]++;
			string piece = s.substr(0, k);
			cout << piece;
			sort(piece.begin(), piece.end());
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < (n / k)-1; j++) {
					cout << piece[i];
				}				
			}
			cout << "\n";
		}		
	}
	return 0;
}