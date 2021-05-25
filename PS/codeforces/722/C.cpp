/*
�ּ� �ִ� ������ �� ��庰�� �־�����
�� ���� ����� ������ �־�����,
��忡�� �������� � ���� ���ؼ�, ������ ����� ���鳢���� �� ������ ���̸� ���� �� ���� ���̰�
�׶�, �� ���̵��� ���� �ִ밡 �Ǵ� ���� ���ÿ�

�켱 �ִ� �ּ� �������� ���ٰ� �ߴµ� ��� ��� �ִ� �ּ� �� �� �ϳ��� ����
���̸� �ִ�� �� �� �ִ� �ֳ��ϸ� � ��尡 �߰����� �����ٰ� �ϸ�, ����� �ٸ� ������ ���̰� �پ���.
�׷� �߰� ���� ������, �̵��� �ϳ��� �ֳĴ� ���� ��������
���⼭�� ���̰� �ٰ� ���⼭�� ���̰� �پ �ᱹ ��� �鿡�� ���ر� ������ �ִ� �ּ� ���� �ϳ��� ���
��忡�� ���� �ִ밡 �ȴٴ� ���� �˼� �ִ�.

���⼭ ���� Ÿ���� int�� ��Ƽ� �����÷ΰ� ���ܼ� Ʋ�ȴ�.
�ᱹ ���� c������ ����� �־��µ� �Ҷ� ���� ������ Ȯ���ϰ� ������ Ǯ�
�Ǽ��� �ִ��� �ٿ�����
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<bool> isStart;
vector<pair<ll, ll>> treeNode;
vector<vector<ll>> graph;

pair<ll, ll> dfs(int cur) {
	isStart[cur] = true;
	ll l = 0, r = 0;
	for (ll adj : graph[cur]) {
		if (!isStart[adj]) {
			pair<ll, ll> beauty = dfs(adj);
			
			l += max(abs(treeNode[cur].first - treeNode[adj].first) + beauty.first,
					abs(treeNode[cur].first - treeNode[adj].second) + beauty.second);
			
			r += max(abs(treeNode[cur].second - treeNode[adj].first) + beauty.first,
				abs(treeNode[cur].second - treeNode[adj].second) + beauty.second);
		}
	}
	return { l, r };
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		treeNode.assign(n, {0,0});
		graph.assign(n, vector<ll>());
		for (int i = 0; i < n; i++) {
			cin >> treeNode[i].first >> treeNode[i].second;
		}
		for (int i = 0; i < n-1; i++) {
			ll a, b;
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
			graph[b - 1].push_back(a - 1);
		}
		isStart.assign(n,false);
		pair<ll, ll> beauty = dfs(0);
		cout << max(beauty.first, beauty.second) << "\n";
	}
	return 0;
}