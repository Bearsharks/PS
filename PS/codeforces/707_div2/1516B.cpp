#include <iostream>
#include <vector>
using namespace std;
/*
�迭���� ���� ���� �ΰ��� xor�ؼ� �ϳ��� ����� ���� �ݺ��ؼ�
��� ���ҵ��� �����ϰ� ���� �� �ִ°�?
��� xor���� �� 0�� �Ǹ� �����ϰ� ���� �� �ִ� ��
�׷��� �ʴٸ� ���Ҹ� 3���� ��������� �����ϰ� ���� �� �ִ� �� Ȯ��
�迭�� �������� �ɰ��� ��� ����� �õ�������, ��� �����ϸ� ���� �ƴϸ� �Ұ���

�ָ��ؾ�����
���� 2���� 3���� �׻� ���� �� �ִٴ� ���� �߰��ϱ� �ֳ��ϸ� 4�� 5��... �� ������ �ȴٸ�
¦������� �ΰ��� ���� 0���� ����� �ֱ� ������ 
Ȧ�� ����� ���°� ���� �θ� �ΰ��� ���� �� �ֱ� ������

���� �Ǵ� ���� 2�� �� �� �ִٸ� ��� xor �ϸ� 0�� �ȴٴ� ��
a xor a = 0 �̱� ������

a xor b xor b  = a��� ������ �ִ�.
�ᱹ xorƯ���� �� �˸� ����� �ذ��Ҽ� �ִ� ��������.
*/
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> xordp(n);
		long long test = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			test = test ^ v[i];
			xordp[i] = test;
		}
		if (test == 0) {
			cout << "YES\n";
			continue;
		}

		bool result = false;
		for (int i = 0; i < n - 2 && !result; i++) {
			long long test1 = xordp[i];			
			for (int j = i+1; j < n - 1; j++) {
				long long test2 = xordp[j] ^ xordp[i];
				long long test3 = xordp[n-1] ^ xordp[j];
				if (test1 == test2 && test2 == test3) {
					result = true;
					break;
				}
			}			
		}
		if (result) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}		
	}

	return 0;
}