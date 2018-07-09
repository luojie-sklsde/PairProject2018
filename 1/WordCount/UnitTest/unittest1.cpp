#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		//测试行统计正确：空行、包含空格的行
		TEST_METHOD(lineCount_is_OK)
		{
			fstream out("..\\WordCount\\result.txt", ios::in);

			string line;
			int lineCount = 0;
			while (getline(out, line))
			{
				if (line[0] == 'l')
				{
					string tmp = line.substr(6, line.length() - 1);
					lineCount = atoi(tmp.c_str());
				}
			}

			Assert::AreEqual(lineCount, 7);
		}

		//测试对所有ASCII码可显示字符的计数
		TEST_METHOD(asciiCount_is_OK)
		{
			fstream out("..\\WordCount\\result.txt", ios::in);

			string line;
			int asciiCount = 0;
			while (getline(out, line))
			{
				if (line[0] == 'c')
				{
					string tmp = line.substr(11, line.length() - 1);
					asciiCount = atoi(tmp.c_str());
				}
				else
				{
					continue;
				}
			}

			Assert::AreEqual(asciiCount, 95);
		}

		//测试输出全为小写
		TEST_METHOD(allLow_is_OK)
		{
			fstream out("..\\WordCount\\result.txt", ios::in);

			string line;
			bool allLow = true;
			while (getline(out, line))
			{
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] < 'a' || line[i] > 'z')
					{
						allLow = false;
					}
				}
			}

			Assert::IsTrue(allLow);
		}

		TEST_METHOD(noASCII_is_OK)
		{
			fstream out("..\\WordCount\\result.txt", ios::in);

			string line;
			int asciiCount = 0;
			while (getline(out, line))
			{
				if (line[0] == 'w')
				{
					string tmp = line.substr(11, line.length() - 1);
					asciiCount = atoi(tmp.c_str());
				}
			}

			Assert::AreEqual(asciiCount, 0);
		}

		TEST_METHOD(specialASCII_is_OK)
		{
			fstream out("..\\WordCount\\result.txt", ios::in);

			string line;
			int asciiCount = 0;
			while (getline(out, line))
			{
				if (line[0] == 'c')
				{
					string tmp = line.substr(11, line.length() - 1);
					asciiCount = atoi(tmp.c_str());
				}
				else
				{
					continue;
				}
			}

			Assert::AreEqual(asciiCount, 99);
		}

		TEST_METHOD(bible_is_OK)
		{
			fstream out("..\\WordCount\\result.txt", ios::in);
			
			string line;
			int asciiCount = 0;
			while (getline(out, line))
			{
				if (line[0] == 'c')
				{
					string tmp = line.substr(11, line.length() - 1);
					asciiCount = atoi(tmp.c_str());
				}
				else
				{
					continue;
				}
			}

			Assert::AreEqual(asciiCount, 4332554);
		}

		TEST_METHOD(rightCut_is_OK)//not finished
		{
			fstream out("..\\WordCount\\result.txt", ios::in);

			string line;
			bool clex = false;
			int i = 4;
			while (getline(out, line))
			{
				if (--i) continue;
				string word = line.substr(0, 7);
				string tmp = line.substr(9, line.length() - 1);
				int number = atoi(tmp.c_str());
				if (word == "yuqin666" && number == 190)
					clex = true;
			}

			Assert::IsTrue(clex);
		}

	};
}