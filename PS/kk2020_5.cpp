#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int N;
//vector<vector<int>> frame;
int frame[10][10];

bool isBo(int x, int y) {
	if (0 > x || x > N || 0 > y || y > N) return false;
	return frame[x][y] & 2;
}
bool isPil(int x, int y) {
	if (0 > x || x > N || 0 > y || y > N) return false;
	return frame[x][y] & 1;
}

bool isOk(int x, int y) {
	if (0 > x || x > N || 0 > y || y > N) return true;
	bool result = true;
	if (frame[x][y] & 1) {//����̸�
		bool cur = (y == 0) || isBo(x, y) || isBo(x - 1, y) || isPil(x, y - 1);
		result = result && cur;
	}
	if (frame[x][y] & 2) {//���̸�
		bool cur = isPil(x, y - 1) || isPil(x+1, y - 1) || (isBo(x+1, y) && isBo(x - 1, y));
		result = result && cur;
	}
	return result;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	//frame.assign(n+1, vector<int>(n+1));
	N = n;
	int size = build_frame.size();
	for (int i = 0; i < size; i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int kind = build_frame[i][2];
		int dobuild = build_frame[i][3];
		//1�̸� ��� 2�̸� �� 3�̸� �Ѵ�.
		if (kind == 0 && dobuild == 1) {//��� �����
			if (y == 0 || isBo(x,y) || isBo(x-1,y)|| isPil(x,y-1)) {//�ٴ��̰ų� ���纸�ų� ������ ���ų� �Ʒ� ����̶�� ���� �� �ִ�.
				frame[x][y] = frame[x][y] | 1;
			}
		}
		else if (kind == 1 && dobuild == 1) {//�� �����
			if (isPil(x, y - 1) || isPil(x + 1, y - 1) || ( isBo(x-1,y) && isBo(x+1,y) )) {//�翷�� ���ų� �Ʒ��� ����� �ְų� ������ �Ʒ��� ����� �ִٸ�  ���� �� �ִ�.
				frame[x][y] = frame[x][y] | 2;
			}
		}
		else if (kind == 0 && dobuild == 0) {//��� ����
			frame[x][y] = frame[x][y] & 2;
			bool good = isOk(x, y+1) && isOk(x-1, y+1);
			if(!good) frame[x][y] = frame[x][y] | 1;
		}
		else {//�� ����
			frame[x][y] = frame[x][y] & 1;
			bool good = isOk(x, y) && isOk(x-1, y) && isOk(x + 1, y);
			if (!good) frame[x][y] = frame[x][y] | 2;
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (frame[i][j]) {
				if (frame[i][j] & 1) answer.push_back({ i,j,0 });
				if (frame[i][j] & 2) answer.push_back({ i,j,1 });
			}

		}
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<vector<int>> inp(8);
	/*inp[0] = { 0,0,0,1 };
	inp[1] = { 2,0,0,1 };
	inp[2] = { 4,0,0,1 };
	inp[3] = { 0,1,1,1 };
	inp[4] = { 1,1,1,1 };
	inp[5] = { 2,1,1,1 };
	inp[6] = { 3,1,1,1 };
	inp[7] = { 2,0,0,0 };
	inp[8] = { 1,1,1,0 };
	inp[9] = { 2,2,0,1 };*/
	inp[0] = { 1,0,0,1 };
	inp[1] = { 1,1,1,1 };
	inp[2] = { 2,1,0,1 };
	inp[3] = { 2,2,1,1 };
	inp[4] = { 5,0,0,1 };
	inp[5] = { 5,1,0,1 };
	inp[6] = { 4,2,1,1 };
	inp[7] = { 3,2,1,1 };
	//inp[8] = { 1,1,1,0 };
	//inp[9] = { 2,2,0,1 };
	vector<vector<int>> res = solution(5, inp);
	return 0;
}