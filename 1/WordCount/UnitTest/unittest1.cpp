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
		
		//������ͳ����ȷ�����С������ո����
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

		//���Զ�����ASCII�����ʾ�ַ��ļ���
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
			}

			Assert::AreEqual(asciiCount, 95);
		}

		//�������ȫΪСд
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
					string tmp = line.substr(6, line.length() - 1);
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
			int asciiCount = 0;
			while (getline(out, line))
			{
				if (line[0] == 'w')
				{
					string tmp = line.substr(6, line.length() - 1);
					asciiCount = atoi(tmp.c_str());
				}
				else
				{
					continue;
				}
			}

			Assert::AreEqual(asciiCount, 4);
		}

	};
}