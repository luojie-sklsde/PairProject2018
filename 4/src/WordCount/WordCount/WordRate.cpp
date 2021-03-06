#include "stdafx.h"
#include <map>     
#include <fstream>     
#include <iostream>     
#include <string> 
#include<vector>
#include<algorithm>
using namespace std;
class CountChar
{
public:
	int coutAllNumber(char*inputfilename) {
		ifstream infile;
		infile.open(inputfilename);
		char c;
		int count = 0;
		infile >> noskipws;
		while (!infile.eof())
		{
			infile >> c;
			count++;
		}
		infile.close();
		return count;
	}

};
class CountWord {
public:

	int countWord(char*inputfile)
	{
		string word;
		vector<string> words;
		vector<int> cnt_word;
		ifstream ifs;
		ifs.open(inputfile);
		while (ifs>>word) {
			if(word!=" ")
				words.push_back(word); 
			}


	    return words.size();


	}


};
class WordRate {
	typedef pair<string, int> PAIR;
	struct cmp
	{
		bool operator() (const PAIR& P1, const PAIR& P2)
		{
			return P1.second > P2.second;
		}
	};
public:
	void display_map(map<string, int> &wmap)
	{
		map<string, int>::const_iterator map_it;
		map<string, int>::iterator iter_it;
		vector<PAIR>vec_it;
		ofstream ofs;
		int num;
		for (iter_it = wmap.begin(); iter_it != wmap.end();iter_it++)
		{
			vec_it.push_back(*iter_it);
		}
		sort(vec_it.begin(), vec_it.end(), cmp());
		ofs.open("d://result.txt");
		cout << "你想知到前多少个词频最高的单词?(提醒：输入不能超过" << vec_it.size() - 1 << "个哦):";
		cin >> num;
		cout << "前" << num << "个词频最高的单词和词频如下：" << endl;
		for(int k=0;k<num;k++)
			if (vec_it[k].first.length() >= 4) {
				cout << vec_it[k].first << "  " << vec_it[k].second << endl;
			}
		cout << "所有单词的词频情况请查看Result.txt文件" << endl;
		if (ofs.is_open()) {
			for (int i = 0;i < vec_it.size();i++) {
				ofs << vec_it[i].first << "  " << vec_it[i].second << endl;
			}
		}
		ofs.close();
	}
};
int main()
{
	string szTemp;
	map<string, int> wmap;
	ifstream ifs;
	char inputfile[] = "d://input.txt";
	CountChar countchar;
	cout << "input.txt文本中共有" << countchar.coutAllNumber(inputfile) << "个字符" << endl;
	CountWord countword;
	cout << "input.txt文本中共有" << countword.countWord(inputfile) << "个单词"<<endl;
	ifs.open("d://input.txt");
	if (!ifs.is_open()) {
		cout << "error";
	}
	while (ifs >> szTemp) {
		transform(szTemp.begin(), szTemp.end(), szTemp.begin(), ::tolower);
		if(szTemp.substr(szTemp.length()-1,1)==","||szTemp.substr(szTemp.length() - 1, 1) == ".")
		wmap[szTemp.substr(0,szTemp.size()-2)]++;
	}
	ifs.close();
	WordRate wordrate;
	wordrate.display_map(wmap);
	return 0;
}



