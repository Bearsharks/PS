#include <iostream>
#include <vector>
using namespace std;
/*
	���ڿ��� TMT�� �������� �̷��� �ִ��� Ȯ���ϴ� ����
	������� TTMTMT�� ���� MTT�� �Ұ���
	
	�� M�� ���ؼ� �翷�� T�� ��Ī �� �� �ִ����� Ȯ���Ѵ�.
	���� T�� T�� �´����� M�� ���� ������
	���ʿ��� ���������� �ϳ��� M�� ��Ī���Ѱ��� �ɰͰ���.
	�� T���� ��� ����ڿ� ���� T���� ù��° M�� ���� ����� ������T���� �ϳ��� ��Ī��Ű�� �� �� ����.

	���� �׷��� ���� �׸���� ���̵Ǵ� ���� ������ �ڿ� �װ��� ���� ������ �°� ������ų�� ������ ���̸�
	Ÿ������ ���� �� �� �ִ�. 
	
	�ϴ� �׸���� �� �� Ư�� m�� ���ʿ� �ִ� �Ϳ��� �ϳ� ���� �����ʿ� �ִ� �� �ȿ��� �ϳ� ���� 
	�� �� �ϳ��� �׷������� �Ǿ��ִ�.
	�信�� ���� ���ʿ� �ִ� ���� �ƴ϶� �ٸ� ���� ����ٸ�, ���� ���ʿ� �ִ� ������ �ٲ㵵 ��������.
	�ֳ��ϸ� �信�� mi�� ���ʿ� �ִ� ���߿� �ϳ� �����, �װ��� mj�� ���ʿ� �ִ� ���̱⵵ �ϱ� ������ (i<j)
	���� ���ʿ� �ִ� ���� �ƴ϶�� ���� ���ʿ� �ִ� ������ �ٲٰ� ���� T�� mj���� �ָ� �Ǳ� �����̴�. �׷��� ���� �ȴ�.
	�������� ��쵵 �׷���.

 */
bool isok(int n, string str) {
	vector<pair<int, int>> v;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'T') {
			v.push_back({ i,0 });
		}
		else {
			if (v.size() > cur) {
				v[cur].second = i;
				cur++;
			}
			else {
				return false;
			}
		}
	}
	
	if (v.size() != cur * 2) return false;
	cur--;
	while (cur >= 0) {
		if(v[cur--].second > v.back().first) return false;
		v.pop_back();
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		int l = -1;
		int r = n;
		if (isok(n, str)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}	
		
	}
	return 0;
}