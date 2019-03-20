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

using namespace std;

int p1() {
	unordered_set<char> num = { '0','1','2','3','4','5','6','7','8','9'};
	unordered_set<char> symbol = { '+','-' };
	string s;
	cin >> s;
	int sum = 0;
	int temp = s[0] - '0';
	bool isAdd = true;
	for (int i = 1; i < s.size(); i++) {
		if (num.find(s[i])!=num.end()) {
			temp *= 10;
			temp += s[i] - '0';
		}
		else if (s[i] == '+') {
			sum += (isAdd?1:-1)*temp;
			temp = 0;
			isAdd = true;
		}
		else if (s[i] == '-') {
			sum += (isAdd ? 1 : -1)*temp;
			temp = 0;
			isAdd = false;
		}
	}
	sum += (isAdd ? 1 : -1)*temp;
	cout << sum;

	return 0;
}