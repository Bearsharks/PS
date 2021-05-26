/*
* ���ο��� ��� ���� ģ�� 4�� �ִ� �ݿ���
* �ڸ������Ҷ� 1 ģ�� ���� ���� �� 2 ���� �ֺ��� (�����¿�)����ִ� �� 3 ����� ���� ���� ����
* �Էµ����� ������ ���� ���� �Ҷ�, ������ ���ϴ� ����
* 
* �� ��Ǯ���µ� ���ǿ� �´��� Ȯ�� �� ��, �ʱ� mx���� 0���� �ּ� Ʋ�ȴ�. 0�� ���ü��� �ִµ�
* 0���� �ױ� ������ 0�ΰ��� �����ϰ� �ǰ� �׷��� Ʋ���� �ȴ�. �ʱ� mx���� Ȯ������
* 
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void initBoard(vector<vector<bool>>& board, int n) {
	for (int j = 0; j < n + 2; j++) {
		board[0][j] = true;
		board[n + 1][j] = true;
		board[j][0] = true;
		board[j][n + 1] = true;
	}
}
vector<pair<int, int>> getMostLike(map<pair<int, int>, int>& m) {
	int mx = 0;
	vector<pair<int, int>> mostlike;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > mx) {
			mx = iter->second;
			mostlike.clear();
		}
		if (iter->second == mx) {
			mostlike.push_back(iter->first);
		}
	}
	return mostlike;
}
vector<pair<int, int>> getMostEmpty(vector<pair<int, int>>& mostlike, vector<vector<bool>>& board) {
	int mx = 0;
	vector<pair<int, int>> mostempty;
	for (auto curpos = mostlike.begin(); curpos != mostlike.end(); curpos++) {
		int emptyadj = 0;
		for (int k = 0; k < 4; k++) {
			int nexti = curpos->first + dx[k];
			int nextj = curpos->second + dy[k];
			if (board[nexti][nextj] == false) emptyadj++;
		}
		if (emptyadj > mx) {
			mx = emptyadj;
			mostempty.clear();
		}
		if (emptyadj == mx) {
			mostempty.push_back(*curpos);
		}
	}
	return mostempty;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n * n + 1, vector<int>(4));
	vector<pair<int, int>> pos(n * n + 1, { 0,0 });
	vector<vector<bool>> board(n + 2, vector<bool>(n + 2));
	initBoard(board, n);
	for (int i = 0; i < n * n; i++) {
		int cur;
		cin >> cur;
		vector<int>& like = v[cur];
		cin >> like[0] >> like[1] >> like[2] >> like[3];
		map<pair<int, int>, int> m;
		for (int j = 0; j < 4; j++) {
			//like��ġ�� pos���� ã�Ƽ� �� ��ġ �����¿찡 ����ٸ� �ĺ��� ����
			pair<int, int> likepos = pos[like[j]];
			if (likepos.first == 0 && likepos.second == 0) continue;
			for (int k = 0; k < 4; k++) {
				int nexti = likepos.first + dx[k];
				int nextj = likepos.second + dy[k];
				if (board[nexti][nextj] == false) m[{nexti, nextj}]++;
			}
		}
		pair<int, int> mypos = { 987654321, 987654321 };
		if (!m.empty()) {
			//���� ū ���� ���� �͵��� ���͸���
			vector<pair<int, int>> mostlike = getMostLike(m);
			
			//�� �� ���� �ֺ��� �� ���� ���� ������ ���͸���
			vector<pair<int, int>> mostempty = getMostEmpty(mostlike, board);
			
			//���� ���� ����� ���� ���� ��
			for (pair<int, int> p : mostempty) {
				mypos = min(mypos, p);
			}
			
		}
		else {
			//�տ��� �ڷ� ���鼭 �� �� �߿� �ֺ� �� ���� ���� ���� ���� �� ó������ 4���� ��ٸ� Ż����
			int mx = -1;
			for (int k = 1; k <= n && mx < 4; k++) {
				for (int h = 1; h <= n && mx < 4; h++) {
					if (board[k][h] == false) {
						int curempty = 0;
						for (int t = 0; t < 4; t++) {
							int nexti = k + dx[t];
							int nextj = h + dy[t];
							if (board[nexti][nextj] == false) curempty++;
						}
						if (mx < curempty) {
							mx = curempty;
							mypos = { k,h };
						}
					}					
				}
			}
		}
		pos[cur] = mypos;
		
		board[mypos.first][mypos.second] = true;
	}

	//��ȣ�� ���
	int answer = 0;
	for (int i = 1; i <= n * n; i++) {
		set<pair<int, int>> s;
		pair<int, int> mypos = pos[i];
		s.insert({ mypos.first - 1, mypos.second });
		s.insert({ mypos.first, mypos.second + 1 });
		s.insert({ mypos.first + 1, mypos.second });
		s.insert({ mypos.first, mypos.second - 1 });
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			cnt += s.count(pos[v[i][j]]);
		}
		if (cnt > 0) answer += pow(10, cnt - 1);
	}
	cout << answer;

	return 0;
}