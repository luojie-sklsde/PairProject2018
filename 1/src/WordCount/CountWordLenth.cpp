#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include<vector>
#include<map>
#include "CountWordLenth.h"
#include <sstream>
using namespace std;

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

//词组统计：能统计文件夹中指定长度的词组的词频
int wordGroupCount(const string &fileName, int m, map<string, int> &wordGroupMap)
{
	ifstream reader(fileName);
	vector<string> words;
	if (!reader.is_open())
	{
		cout << "open file error!" << endl;
		return -1;
	}
	ostringstream tmp;
	tmp << reader.rdbuf();
	string testStr = tmp.str();

	map<string, int> wordCounter;
	string word = "";
	for (int i = 0; i<testStr.length(); ++i)
	{
		char c = testStr[i];
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || ((c >= 97 && c <= 122)))//judge whether c is a number or character
		{
			word += c;
		}
		else//not valid character
		{
			if (word.length() >= 4)//is a word
			{
				transform(word.begin(), word.end(), word.begin(), (int(*)(int))tolower);
				words.push_back(word);
			}
			word = "";
		}
	}
	for (int i = 0; i<words.size() - m + 1; ++i)
	{
		string wordgroup_temp;
		for (int j = i; j <m + i; ++j)
		{
			if (j == m + i - 1)
			{
				wordgroup_temp += words[j];
			}
			else
			{
				wordgroup_temp += words[j] + ' ';
			}
		}

		if (wordGroupMap.find(wordgroup_temp) == wordGroupMap.end())

		{

			wordGroupMap[wordgroup_temp] = 1;

		}

		else

		{

			wordGroupMap[wordgroup_temp] += 1;

		}
	}
	reader.close();
	return 0;

}