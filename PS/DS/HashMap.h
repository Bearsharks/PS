#pragma once
#include <vector>
using namespace std;

//directory HashMap
template <class T1, class T2>
class HashMap {
public:
	//get
	T2 get(T1 key) {
		pair<int, int>& idxpair = mappingTable[getKey(key)];
		for (pair<T1, T2> p : hashtable[idxpair.first]) {
			if (p.first == key) return p.second;
		}
		set(key, NULL);
		return NULL;
	}
	//set
	void set(T1 key, T2 val) {
		pair<int, int> mappingInfo = mappingTable[getKey(key)];
		for (pair<T1, T2>& p : hashtable[mappingInfo.first]) {
			if (p.first == key) {
				p.second = val;
				return;
			}
		}

		hashtable[mappingInfo.first].push_back({ key,val });
		while (hashtable[mappingInfo.first].size() > BUCKET_SIZE) {			
			if (mappingInfo.second >= hashsize) {
				//����ϴ� �ڸ����� ���� �ؽ����̺������� ���ٸ� ���丮�� 2�� �ø�
				for (int i = 0; i < hashsize; i++) {
					mappingTable.push_back(mappingTable[i]);
				}
				hashsize *= 2;
				hashtable.resize(hashsize);
			}
			//�������̺� ���� ���� ��Ŷ�� ���� ������ ������Ʈ
			for (int i = mappingInfo.first; i < hashsize; i += 2 * mappingInfo.second) {
				mappingTable[i] = { mappingInfo.first,  mappingInfo.second * 2 };
			}
			for (int i = mappingInfo.first + mappingInfo.second; i < hashsize; i += 2 * mappingInfo.second) {
				mappingTable[i] = { mappingInfo.first + mappingInfo.second, mappingInfo.second * 2 };
			}
			
			vector<pair<T1, T2>> cp = hashtable[mappingInfo.first];
			hashtable[mappingInfo.first].clear();

			for (pair<T1, T2> p : cp) {
				hashtable[mappingTable[getKey(p.first)].first].push_back(p);
			}
			
			//�ٽ� �����÷ΰ� �߻��ߴٸ� ���� �ݺ����� ���� �� �ֵ��� �����÷ΰ� ���� ��Ŷ������ ����
			if (hashtable[mappingInfo.first + mappingInfo.second].size() > BUCKET_SIZE) {
				mappingInfo = mappingTable[mappingInfo.first + mappingInfo.second];
			}
			else {
				mappingInfo = mappingTable[mappingInfo.first];
			}
		}
	}
private:
	const int PN = 23;
	const int BUCKET_SIZE = 10;
	vector<pair<int, int>> mappingTable = { {0,4},{1,4},{2,4},{3,4} };

	vector<vector< pair<T1, T2> > > hashtable = vector<vector< pair<T1, T2> > >(4, vector< pair<T1, T2> >());
	int hashsize = 4;
	unsigned int getKey(T1 _name) {
		return std::hash<T1>{}(_name)*PN % hashsize;
	}
	
};