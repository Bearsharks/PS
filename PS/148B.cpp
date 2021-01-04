#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	double ft = c / vp;//�� �ð�
	double ct = vp * t / (vd - vp); //����½ð�
	double ot = ct + t;//������� �ð�
	double pp = ot * vp;//������ġ	

	do {
		ans++;
		double wt = ct + f;//����ð� ���� �ð� â�� �ִ½ð�
		ct = (vp * wt + pp) / (vd - vp);
		ot += wt + ct;
		pp = ot * vp;
	} while (ft > ot);

	cout << ans;
	return 0;
}