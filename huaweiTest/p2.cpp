#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<iomanip>
#include<algorithm>

using namespace std;

bool cmp(const string &s1, const string &s2) {
	if (s1[0] == s2[0])
		return s1.size() > s2.size();
	else
		return s1[0] < s2[0];
}

int p2() {
	string s;
	cin >> s;
	vector<int> upper(26, 0);
	vector<int> lower(26, 0);
	for (auto c : s) {
		if (c >= 'a'&& c <= 'z')
			lower[c - 'a']++;
		else if (c >= 'A' && c <= 'Z')
			upper[c - 'A']++;
	}

	//dp
	int maxLength = 0;
	int maxLeft = 0, maxRight = -1;
	int left = 0;
	int length = 0;
	vector<string> res;
	while (true) {
		length = 0;
		maxLength = 0;
		maxLeft = 0;
		maxRight = -1;
		left = 0;
		for (int i = 0; i < 26; i++) {
			if (upper[i] != 0 && lower[i] != 0) {
				length++;
				if (maxLength < length) {
					maxLeft = left;
					maxRight = i;
					maxLength = length;
				}
			}
			else {
				left = i + 1;
				length = 0;
			}
		}
		if (maxLeft > maxRight)
			break;
		res.push_back("");
		for (int i = maxLeft; i <= maxRight; i++) {
			res.back().push_back(i + 'A');
			res.back().push_back(i + 'a');
			//printf("%c%c", i + 'A', i + 'a');
			upper[i]--;
			lower[i]--;
		}
		//cout << endl;
	}
	if (res.size() != 0) {
		sort(res.begin(), res.end(), cmp);
		for (auto s : res) {
			cout << s << endl;
		}
	}
	else cout << "Not Found";
	return 0;
}