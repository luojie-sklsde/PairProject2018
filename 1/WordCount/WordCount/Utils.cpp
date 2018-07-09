#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "Core.h"
#include "CountWordLenth.h"

using namespace std;

void writeTXT(const string &inFileName, int m, int n, const string &outFileName){

	
	//cout << outFileName << endl;
	ofstream myfile(outFileName, ios::out);
	
	if (!myfile)
	{
		cout << "error£¡";
	}
	else
	{
		vector<pair<string, int>> wordCounter;
		countWordFrequency(inFileName, wordCounter, n);
		myfile << "characters:" << countChar(inFileName) << endl;
		myfile << "words:" << countWord(inFileName) << endl;
		myfile << "lines:" << lineCount(inFileName) << endl;
		for (auto iter = wordCounter.cbegin(); iter != wordCounter.cend(); ++iter)
		{
			myfile << "<" << iter->first << ">" << ":" << iter->second << endl;//each word count
		}
		map<string, int> wordGroupMap;
		if (m != 0){
			wordGroupCount(inFileName, m, wordGroupMap);
			for (auto it = wordGroupMap.begin(); it != wordGroupMap.end(); it++)
			{
				//std::cout << it->first << " " << it->second.c_str() << std::endl;
				myfile << it->first << ":" << it->second << endl;
			}
		}
		
					
		myfile.close();
	}
}