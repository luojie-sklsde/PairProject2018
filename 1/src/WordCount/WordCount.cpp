// WordCount.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Core.h"
#include <string>
#include "CountWordLenth.h"
#include <streambuf>
#include <sstream>
#pragma comment(lib, "lib/Core.lib")  
using namespace std;


int main(int argc, char* argv[])
{


	string fileName = ".\\testTxt\\asciiCount_in.txt";
	int m = 0;
	int n = 10;
	string output = "result.txt";
	vector<string> str;
	for (int i = 0; i<argc; ++i)
	{
		//cout<<argv[i]<<endl;
		str.push_back(argv[i]);
	}
	auto iter = std::find(str.begin(), str.end(), "-i");
	if (iter != str.end())
	{
		//cout<<*(iter+1)<<endl;
		fileName = *(iter + 1);
		//cout << fileName << endl;
	}
	auto iter1 = std::find(str.begin(), str.end(), "-m");
	if (iter1 != str.end())
	{

		string s = *(iter1 + 1);
		stringstream stream(s);
		stream >> m;
		// cout << m << endl;
	}

	auto iter6 = std::find(str.begin(), str.end(), "-n");
	if (iter6 != str.end())
	{

		string s = *(iter6 + 1);
		stringstream stream(s);
		stream >> n;
		// cout << n << endl;
	}

	auto iter2 = std::find(str.begin(), str.end(), "-o");
	if (iter2 != str.end())
	{
		output = *(iter2 + 1);
		// cout << output << endl;
	}


	writeTXT(fileName, m, n, output);

	return 0;
}