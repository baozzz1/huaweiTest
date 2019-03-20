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
class Stateflow {
public:
	void read() {
		string s;
		vector<string> input;
		while (cin >> s)
			input.push_back(s);
		vector<vector<string>> res;
		if (input.empty()) return;

		string temp;
		for (auto str : input) {
			res.push_back(vector<string>());
			temp.clear();
			for (auto c : str) {
				if (c == '|') {
					res.back().push_back(temp);
					temp.clear();
				}
				else
					temp.push_back(c);
			}
			res.back().push_back(temp);
		}
		root(res);
	}

	void root(const vector<vector<string>>& res) {
		for (auto vec : res)
			process(vec);
	}

	void process(const vector<string> &oneEvent) {
		//if (oneEvent.size() != 3) return;
		int index1 = 0;
		for (int i = 1; i <= 4; i++){
			if (EventSouce[i] == oneEvent[0])
				index1 = i;
			break;
		}
		if (index1 == 0) return;

		int index2 = 0;
		for (int i = 1; i <= 6; i++)
			if (Event[i] == oneEvent[2]) {
				index2 = i;
				break;
			}

		if (index2 == 0) return;
		//try {
		//	targets.at(oneEvent[1]);
		//}
		//catch (out_of_range) {
		//	targets[oneEvent[1]] = 0;
		//}

		switch(index1) {
		case 1:
			if (index2 != 1 && index2 != 6)
				return;
			else if (index2 == 1) {
				if (targets[oneEvent[1]] >= 1 && targets[oneEvent[1]] <= 6)
					return;
				cout << oneEvent[1] << "|submitted;";
				targets[oneEvent[1]] = 1;
			}
			else if (index2 == 6) {
				if (targets[oneEvent[1]] >= 1 && targets[oneEvent[1]] <= 4){
					cout << oneEvent[1] << "|killed;";
					targets[oneEvent[1]] = 6;
				}
				else return;
			}
			break;
		case 2:
			if (index2 != 2 && index2 != 5)
				return;
			else if (index2 == 2) {
				if (targets[oneEvent[1]] != 1)
					return;
				cout << oneEvent[1] << "|scheduled;";
				targets[oneEvent[1]] = 2;
			}
			else if (index2 == 5) {
				if (targets[oneEvent[1]] != 4)
					return;
				cout << oneEvent[1] << "|finished;";
				targets[oneEvent[1]] = 5;
			}
			break;
		case 3:
			if (index2 != 4)
				return;
			if (targets[oneEvent[1]] != 2)
				return;
			cout << oneEvent[1] << "|running;";
			targets[oneEvent[1]] = 4;
			break;
		case 4:
			if (index2 != 3)
				return;
			if (targets[oneEvent[1]] != 2)
				return;
			cout << oneEvent[1] << "|allocated;";
			targets[oneEvent[1]] = 3;
			break;
		}
	}

	unordered_map<string, int> targets;

	const vector<string> EventSouce = {" ", "RmApp","ResouceScheduler","ApplicationMasterLauncher","RmContainer" };
	const vector<string> Event = { " ",  "start","app_accepted","container_allocated","launched","finished","kill" };
	const vector<string> state = { " ",  "submitted","scheduled","allocated","running","finished","killed" };
};

//30%
int p3() {
	Stateflow s; s.read();
	return 0;
}