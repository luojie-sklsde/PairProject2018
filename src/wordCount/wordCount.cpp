// wordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <regex>
#include <algorithm>


using namespace std;

int main()
{
	size_t size_characters=0;
	size_t size_words=0;
	size_t size_lines=0;

	string line;
	string word;
	regex word_regex("\\s+");
	
	vector<string> lines;
	vector<string> words;
	ifstream in("myinput.txt",ios::in);
	if (!in.good())
	{
		cout << "failed!" << endl;
	}
	while (!in.eof())
	{
		getline(in,line);
		lines.push_back(line);
		regex_token_iterator<string::iterator> i(line.begin(), line.end(), word_regex, -1);
		regex_token_iterator<string::iterator> end;
		while (i != end)
		{
			string tmp = *i;
			if (tmp.size() > 3)//
			{
				size_characters = size_characters + tmp.size();
			    words.push_back(tmp);
		    }
			i++;
		}
	}
	size_lines = lines.size();
	size_words = words.size();
	
	/*
	auto  v1 = lines.begin();
	while (v1 != lines.end()) {
		cout  << *v1 << endl;
		v1++;
	}
	auto  v2 = words.begin();
	while (v2 != words.end()) {
		cout << *v2 << endl;
		v2++;
	}
	*/
	
	cout << "characters:" << size_characters << endl;
	cout << "words:" << size_words << endl;
	cout << "lines:" << size_lines << endl;
	
    return 0;
}

