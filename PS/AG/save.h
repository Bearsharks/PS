#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
* 
#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	//cout.setf(ios::fixed);
	//cout.precision(5);
	return 0;
}
//printf("%.9f %.9f\n", cur.first, cur.second);
//scanf("%lf %lf %d", &a, &d, &n);
//v[1~n]���� longest increasing subsequence�� ���ϴ� �˰�����
vector<int> ans = { -1,INT_MAX };
for (int i = 1; i <= n; i++) {
    int min = 0;
    int max = ans.size()-1;
    while (min < max) {
        int mid = (min + max) / 2;

        if (ans[mid] < v[i]) {
            min = mid + 1;
        }
        else if (ans[mid] > v[i])  {
            max = mid;
        }
        else {
            break;
        }
    }
    if (max == ans.size() - 1) {
        ans.push_back(INT_MAX);
    }
    ans[max] = v[i];
}

int isvisit[50][50] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
vector<string> v(50);

bool dfs(pair<int, int> start, pair<int, int> cur) {
	isvisit[cur.first][cur.second] = 1;
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + dx[i];
		int nexty = cur.second + dy[i];
		if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m
            && !isvisit[nextx][nexty] && dfs(start, { nextx, nexty }) )
        {
			return true;
		}
	}
	return false;
}

//�ߺ����� n H i = n + i - 1 C i
int maxn = 1010;
void getcombi(int maxn){
	vector<vector<long long>> combi(maxn,vector<long long>(maxn));
	combi[0][0] = 1;
	for (int i = 1; i < maxn; i++) {
		combi[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			combi[i][j] = (combi[i - 1][j] + combi[i - 1][j - 1]);
		}
	}
}

	//�κ��� ����� m���� ���ϴ�
	for (int i = 1; i <= n; i++) {
		v[i] += v[i - 1];
	}
	int cur = 1;
	for (int i = n-m+1; i <= n; i++) {
		save[cur] = v[i] - v[cur-1];
		cur++;
	}

	����
	#include <random>
	random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	mt19937 gen(rd());

	// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	uniform_int_distribution<int> dis(0, 500);
*/

vector<int> sp(vector<vector<pair<int,int>>> graph, int start) {
	vector<int> result(graph.size(),INT_MAX);
	result[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		pair<int,int> cur = pq.top();
		pq.pop();
		int cost = -cur.first;
		int curidx = cur.second;
		if (cost > result[curidx]) continue;

		for (pair<int,int> adj : graph[curidx]) {
			if (result[adj.second] > cost + adj.first) {
				result[adj.second] = cost + adj.first;
				pq.push({ -(cost + adj.first), adj.second });
			}
		}
	}
	
	return result;
}

vector<int> getpartialmatch(string& n) {
	int begin = 1;
	int matched = 0;
	vector<int> res(n.size());
	while (begin + matched < n.size()) {
		if (n[begin + matched] == n[matched]) {
			matched++;
			res[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - res[matched-1];
				matched = res[matched - 1];
			}
		}
	}
}
vector<int> kmps(string& h, string& n) {

}

const int MAX_V = 501;
int V;
vector<pair<int, int>> adj[MAX_V];

bool bellmanFord(int src) {
	//���� ����Ŭ�� �ִٸ� ���͸� ��ȯ�Ұ���
	vector<int> upper(V, 987654321);
	upper[src] = 0;
	bool updated;

	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for (int here = 0; here < V; ++here) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) return true;
	return false;
}

//v�� �ڱ��ڽ����� ���� ���� 0���� �ʱ�ȭ�Ǿ��־��
//���������� infinity�� �Ǿ����
void fw(vector<vector<int>>& v) {
	int n = v.size();
	for (int c = 0; c < n; c++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = min(v[i][c] + v[c][j], v[i][j]);
			}
		}
	}
}