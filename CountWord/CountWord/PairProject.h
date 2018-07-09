#pragma once

#include<fstream>
#include <string>
#include<iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
#define MAXNUMBER 10245
#define _CRT_SECURE_NO_DEPRECATE



bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
	return p1.second > p2.second;
}

class WordOperation
{
public:

	bool isi = false;
	bool ism = false;
	bool isn = false;
	bool iso = false;

	string ipath = "";
	string opath = "";
	int m_number = 0;
	int n_number = 0;

	string ResultPath = "C:\\Users\\Ahu\\Desktop\\result.txt";

	vector<pair<string, int> >FrequentArray;
	map<string, int> WordFrequent;


	void Operation(string file);
	bool isseparator(char c);									///判断该字符是不是分割符
	bool ischar(char c);					   				    ///判断其是不是字符,包含标点符号，空格等符号
	bool isneedchar(char c);						            ///判断该字符是不是0-1；A-Z；a-z
	bool iswordstart(char c);								    ///判断该字符是不是单词的首个开头
	bool isthreechar(char a, char b, char c);					///判断这个单词前四个字符是英文字符
	bool isfirstcharofword(char c, int index);
//	bool cmp(const pair<string, int> &p1, const pair<string, int> &p2);
	string bigtosmall(char buf[]);								///字符串大写转小写
	int getcharnumber();
	int getlinenumber();
	int getwordnumber();


private:

	int Charmumer = 0;
	int LineNumber = 0;
	int WordNumber = 0;
	
};

int WordOperation::getcharnumber()
{
	return Charmumer;
}

int WordOperation::getlinenumber()
{
	return LineNumber;
}

int WordOperation::getwordnumber()
{
	return WordNumber;
}

bool WordOperation::isseparator(char c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))
		return false;
	else
		return true;
}


bool WordOperation::ischar(char c)
{
	///可显示的字符
	if ((c > 32) && (c < 127))
		return true;
	else
		return false;
}


bool WordOperation::iswordstart(char c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		return true;
	else
		return false;
}


bool WordOperation::isthreechar(char a, char b, char c)
{
	bool ta = false;
	bool tb = false;
	bool tc = false;
	bool td = false;


	if (((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z')))
		ta = true;

	if (((b >= 'A') && (b <= 'Z')) || ((b >= 'a') && (b <= 'z')))
		tb = true;

	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		tc = true;


	if ((ta == true) && (tb == true) && (tc == true))
		return true;
	else
		return false;

}

bool WordOperation::isfirstcharofword(char c, int index)
{
	//需要判断char c 是不是可显示的字符（非标点符号）

	if (index == 0)        //代表该字符在内容中的位置，如果是处于第一个位置，肯定是首字母
		return true;
	else
	{
		//判断该字符的前一个位置是不是一个分隔符

		//char c代表的就是这个前一个字符

		if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))       ///该前一个字符是可显示的英文字符，故不是分隔符
			return false;
		else
			return true;
	}
}


bool WordOperation::isneedchar(char c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))       ///该前一个字符是可显示的英文字符，故不是
		return true;
	else
		return false;
}


string WordOperation::bigtosmall(char buf[])
{
	int length = int(strlen(buf));
	string smallletter;
	char c;

	for (int i = 0; i < length; i++)
	{
		if ((buf[i] >= 'A') && (buf[i] <= 'Z'))
		{
			c = buf[i] + ('a' - 'A');
			smallletter.push_back(c);
		}
		else
			smallletter.push_back(buf[i]);
	}
	return smallletter;
}


void WordOperation::Operation(string Filename)
{


	int i = 0;
	int j = 0;
	int k = 0;


	fstream file;
	file.open(Filename, ios::out | ios::in);

	if (!file)
	{
		cout << " 文件不存在！" << endl;
	}

	int wordstart = 0;
	int wordend = 0;
	int wordlength = 0;
	int linelength = 0;


	char wordcontent[100];        ///存放单个单词的数组
	char allwordcontent[100];
	char linecontent[MAXNUMBER];     ///存放文档每行读取内容
		
	///单个单词部分
	vector<pair<string, int> >FrequentArray;
	map<string, int> WordFrequent;
	map<string, string> Allcontent;         ///存放的是在map中WordFrequent中，每一个key对应的asicc最小的单词
	

	///词组部分

	vector<pair<string, int> >FrequentPhraseArray;
	map<string, int> PhraseFrequent;



	int CharNumer = 0;
	int LineNumber = 0;
	int WordNumber = 0;


	///文件尚未结束
							
	while (!file.eof())
	{
		memset(linecontent, 0, sizeof(linecontent) / sizeof(char));

		file.getline(linecontent, MAXNUMBER - 10, '\n');				/// 表示该行字符达到MAXNUMBER-10个或遇到换行就结束  有一个问题，会把第一个单词前的空格读入进来吗？？？？？？
		LineNumber++;
		linelength = int(strlen(linecontent));
		wordstart = 0;
		wordend = 0;
		i = 0;

		while (i < linelength)
		{

			///判断该字符是不是可以显示的字符，不是换行，\t等字符
			if (ischar(linecontent[i]))
			{
				CharNumer++;

				///判断该字符是不是非标点以外的字符

				if (isneedchar(linecontent[i]))
				{

					///非标定字符，即可显示的英文字符0-1；A-Z;a-z

					///判断该字符是不是属于一个单词的内部

					if (isfirstcharofword(linecontent[i - 1], i))                ///这句话传入会不会出现问题？？？？？？如果i=0的时候
					{
						///不在单词的内部,说明是单词的开头

						wordstart = i;          ///确定单词的首字符的位置		

												///查找该单词的结束位置

						for (j = wordstart; j < linelength; j++)
						{
							if (j == linelength - 1)        ///该行的最后一个字符,不存在第j+1的字符,故第j个字符就是单词的结束位置
							{
								wordend = j;
							}
							else
							{
								///第j个字符不是分割符号，而第j+1个字符是分割符

								///说明单词的结束位置是j

								if ((isseparator(linecontent[j]) == false) && (isseparator(linecontent[j + 1]) == true))
								{
									wordend = j;
									break;
								}
							}
						}

						///需要具体确定是不是我们所定义的单词开头

						///首先对长度进行判断

						if (wordend - wordstart >= 3)      ///单词长度满足条件
						{

							///进行判断是不是以四个英文字符进行开头

							///满足以四个英文字符进行开头，符合单词定义
							if (true == isthreechar(linecontent[wordstart + 1], linecontent[wordstart + 2], linecontent[wordstart + 3]))
							{

								///进行高级的选项，即windows，以及Windows95等判断

								///提取单词非数字结尾的部分，即windows95->windows;windows32a->windows32a

								int lastcharposition;

								for (k = wordend; k >= 0; k--)
								{
									if (!((linecontent[k] >= '0') && (linecontent[k] <= '9')))
									{
										lastcharposition = k;
										break;
									}
								}


								memset(wordcontent, 0, sizeof(wordcontent) / sizeof(char));
								memset(allwordcontent, 0, sizeof(allwordcontent) / sizeof(char));

								///将原始单词中，非数字结尾部分的内容提取出来
								for (k = wordstart; k < lastcharposition + 1; k++)
									wordcontent[k - wordstart] = linecontent[k];
								wordcontent[k - wordstart] = '\0';


								for (k = wordstart; k < wordend + 1; k++)
									allwordcontent[k - wordstart] = linecontent[k];
								allwordcontent[k - wordstart] = '\0';

								string allwordcontent_string = allwordcontent;

								///将单词进行大写转小写
								string newwordcontent = bigtosmall(wordcontent);
							

								///在Hash_map中进行查找是否存在已经存储的key

								if (WordFrequent.find(newwordcontent) != WordFrequent.end())
								{
									WordFrequent[newwordcontent] += 1;								 ///已经存储了这个key，频率累加

																									 ///更新Allcontent的内容，确保Allcontent所存储的单词一定是ASICC最小的

									string buf = Allcontent[newwordcontent];

									///用ASCII小的word来更新对应map中内容

									int comparevalue = 0;
									comparevalue = buf.compare(allwordcontent_string);

									if (comparevalue > 0)
									{
										///字符串wordcontent_string的值大于buf，需要更新Allcontent
										Allcontent[newwordcontent] = allwordcontent_string;
									}

								}
								else
								{
									WordFrequent[newwordcontent] = 1;           ///第一次存储
									Allcontent[newwordcontent] = allwordcontent_string;
								}

								WordNumber++;

							}
						}

						i = wordend + 1;          ///下一个字符的查找位置
						CharNumer += wordend - wordstart;

					}
				}
				else
					i++;
			}
			else
			{
				///该字符不是可以显示的字符，故不是单词的一部分，直接查找下一个位置
				///		wordend = i;			///查找下一个字符
				///		i = wordend + 1;
				i++;

			}
		}
	}

	file.close();



	///对map中的value按照大小的顺序进行输出

	///将map中的key和value分别存放在一个pair类型的vector中

	///然后利用vector的sort函数排序


	for (map<string, int>::iterator it = WordFrequent.begin(); it != WordFrequent.end(); ++it)
	{
		FrequentArray.push_back(make_pair(it->first, it->second));
	}

	sort(FrequentArray.begin(), FrequentArray.end(), cmp);
//	sort(FrequentArray.begin(), FrequentArray.end());


	ofstream resultfile;					//创建个对象  
	

	if (iso == true)
		ResultPath = opath;
	resultfile.open(ResultPath, ios::app);


	///在一个整个的TXT中输出每一个小txt的单词信息

	///每个单独文件的开头


	//写入内容
	resultfile << "char_number :" << CharNumer << endl;
	resultfile << "line_number :" << LineNumber << endl;
	resultfile << "word_number :" << WordNumber << endl;

	int count_number = 0;

	///只输出单词部分信息
	if (ism == false)
	{
		///按照value的值进行输出，只输出频率出现最高的十个单词
		for (vector<pair<string, int> >::iterator it = FrequentArray.begin(); it != FrequentArray.end(); ++it)
		{
			if (isn == true)
			{
				///设置了单词的输出个数

				if (count_number > n_number)
					break;
			}
			else
			{
				if (count_number > 10)
					break;
			}

			if (Allcontent[it->first] != it->first)
			{
				resultfile << Allcontent[it->first] << '\t' << it->second << endl;
			}
			else
			{
				resultfile << it->first << '\t' << it->second << endl;
			}

			count_number++;
		}
	}
	else
	{
		///只输出词组部分信息





	}
	

	resultfile << endl << endl;


	//关闭文件流


	resultfile.close();

}