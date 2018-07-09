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
	bool isseparator(char c);									///�жϸ��ַ��ǲ��Ƿָ��
	bool ischar(char c);					   				    ///�ж����ǲ����ַ�,���������ţ��ո�ȷ���
	bool isneedchar(char c);						            ///�жϸ��ַ��ǲ���0-1��A-Z��a-z
	bool iswordstart(char c);								    ///�жϸ��ַ��ǲ��ǵ��ʵ��׸���ͷ
	bool isthreechar(char a, char b, char c);					///�ж��������ǰ�ĸ��ַ���Ӣ���ַ�
	bool isfirstcharofword(char c, int index);
//	bool cmp(const pair<string, int> &p1, const pair<string, int> &p2);
	string bigtosmall(char buf[]);								///�ַ�����дתСд
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
	///����ʾ���ַ�
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
	//��Ҫ�ж�char c �ǲ��ǿ���ʾ���ַ����Ǳ����ţ�

	if (index == 0)        //������ַ��������е�λ�ã�����Ǵ��ڵ�һ��λ�ã��϶�������ĸ
		return true;
	else
	{
		//�жϸ��ַ���ǰһ��λ���ǲ���һ���ָ���

		//char c����ľ������ǰһ���ַ�

		if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))       ///��ǰһ���ַ��ǿ���ʾ��Ӣ���ַ����ʲ��Ƿָ���
			return false;
		else
			return true;
	}
}


bool WordOperation::isneedchar(char c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))       ///��ǰһ���ַ��ǿ���ʾ��Ӣ���ַ����ʲ���
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
		cout << " �ļ������ڣ�" << endl;
	}

	int wordstart = 0;
	int wordend = 0;
	int wordlength = 0;
	int linelength = 0;


	char wordcontent[100];        ///��ŵ������ʵ�����
	char allwordcontent[100];
	char linecontent[MAXNUMBER];     ///����ĵ�ÿ�ж�ȡ����
		
	///�������ʲ���
	vector<pair<string, int> >FrequentArray;
	map<string, int> WordFrequent;
	map<string, string> Allcontent;         ///��ŵ�����map��WordFrequent�У�ÿһ��key��Ӧ��asicc��С�ĵ���
	

	///���鲿��

	vector<pair<string, int> >FrequentPhraseArray;
	map<string, int> PhraseFrequent;



	int CharNumer = 0;
	int LineNumber = 0;
	int WordNumber = 0;


	///�ļ���δ����
							
	while (!file.eof())
	{
		memset(linecontent, 0, sizeof(linecontent) / sizeof(char));

		file.getline(linecontent, MAXNUMBER - 10, '\n');				/// ��ʾ�����ַ��ﵽMAXNUMBER-10�����������оͽ���  ��һ�����⣬��ѵ�һ������ǰ�Ŀո��������𣿣���������
		LineNumber++;
		linelength = int(strlen(linecontent));
		wordstart = 0;
		wordend = 0;
		i = 0;

		while (i < linelength)
		{

			///�жϸ��ַ��ǲ��ǿ�����ʾ���ַ������ǻ��У�\t���ַ�
			if (ischar(linecontent[i]))
			{
				CharNumer++;

				///�жϸ��ַ��ǲ��ǷǱ��������ַ�

				if (isneedchar(linecontent[i]))
				{

					///�Ǳ궨�ַ���������ʾ��Ӣ���ַ�0-1��A-Z;a-z

					///�жϸ��ַ��ǲ�������һ�����ʵ��ڲ�

					if (isfirstcharofword(linecontent[i - 1], i))                ///��仰����᲻��������⣿�������������i=0��ʱ��
					{
						///���ڵ��ʵ��ڲ�,˵���ǵ��ʵĿ�ͷ

						wordstart = i;          ///ȷ�����ʵ����ַ���λ��		

												///���Ҹõ��ʵĽ���λ��

						for (j = wordstart; j < linelength; j++)
						{
							if (j == linelength - 1)        ///���е����һ���ַ�,�����ڵ�j+1���ַ�,�ʵ�j���ַ����ǵ��ʵĽ���λ��
							{
								wordend = j;
							}
							else
							{
								///��j���ַ����Ƿָ���ţ�����j+1���ַ��Ƿָ��

								///˵�����ʵĽ���λ����j

								if ((isseparator(linecontent[j]) == false) && (isseparator(linecontent[j + 1]) == true))
								{
									wordend = j;
									break;
								}
							}
						}

						///��Ҫ����ȷ���ǲ�������������ĵ��ʿ�ͷ

						///���ȶԳ��Ƚ����ж�

						if (wordend - wordstart >= 3)      ///���ʳ�����������
						{

							///�����ж��ǲ������ĸ�Ӣ���ַ����п�ͷ

							///�������ĸ�Ӣ���ַ����п�ͷ�����ϵ��ʶ���
							if (true == isthreechar(linecontent[wordstart + 1], linecontent[wordstart + 2], linecontent[wordstart + 3]))
							{

								///���и߼���ѡ���windows���Լ�Windows95���ж�

								///��ȡ���ʷ����ֽ�β�Ĳ��֣���windows95->windows;windows32a->windows32a

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

								///��ԭʼ�����У������ֽ�β���ֵ�������ȡ����
								for (k = wordstart; k < lastcharposition + 1; k++)
									wordcontent[k - wordstart] = linecontent[k];
								wordcontent[k - wordstart] = '\0';


								for (k = wordstart; k < wordend + 1; k++)
									allwordcontent[k - wordstart] = linecontent[k];
								allwordcontent[k - wordstart] = '\0';

								string allwordcontent_string = allwordcontent;

								///�����ʽ��д�дתСд
								string newwordcontent = bigtosmall(wordcontent);
							

								///��Hash_map�н��в����Ƿ�����Ѿ��洢��key

								if (WordFrequent.find(newwordcontent) != WordFrequent.end())
								{
									WordFrequent[newwordcontent] += 1;								 ///�Ѿ��洢�����key��Ƶ���ۼ�

																									 ///����Allcontent�����ݣ�ȷ��Allcontent���洢�ĵ���һ����ASICC��С��

									string buf = Allcontent[newwordcontent];

									///��ASCIIС��word�����¶�Ӧmap������

									int comparevalue = 0;
									comparevalue = buf.compare(allwordcontent_string);

									if (comparevalue > 0)
									{
										///�ַ���wordcontent_string��ֵ����buf����Ҫ����Allcontent
										Allcontent[newwordcontent] = allwordcontent_string;
									}

								}
								else
								{
									WordFrequent[newwordcontent] = 1;           ///��һ�δ洢
									Allcontent[newwordcontent] = allwordcontent_string;
								}

								WordNumber++;

							}
						}

						i = wordend + 1;          ///��һ���ַ��Ĳ���λ��
						CharNumer += wordend - wordstart;

					}
				}
				else
					i++;
			}
			else
			{
				///���ַ����ǿ�����ʾ���ַ����ʲ��ǵ��ʵ�һ���֣�ֱ�Ӳ�����һ��λ��
				///		wordend = i;			///������һ���ַ�
				///		i = wordend + 1;
				i++;

			}
		}
	}

	file.close();



	///��map�е�value���մ�С��˳��������

	///��map�е�key��value�ֱ�����һ��pair���͵�vector��

	///Ȼ������vector��sort��������


	for (map<string, int>::iterator it = WordFrequent.begin(); it != WordFrequent.end(); ++it)
	{
		FrequentArray.push_back(make_pair(it->first, it->second));
	}

	sort(FrequentArray.begin(), FrequentArray.end(), cmp);
//	sort(FrequentArray.begin(), FrequentArray.end());


	ofstream resultfile;					//����������  
	

	if (iso == true)
		ResultPath = opath;
	resultfile.open(ResultPath, ios::app);


	///��һ��������TXT�����ÿһ��Сtxt�ĵ�����Ϣ

	///ÿ�������ļ��Ŀ�ͷ


	//д������
	resultfile << "char_number :" << CharNumer << endl;
	resultfile << "line_number :" << LineNumber << endl;
	resultfile << "word_number :" << WordNumber << endl;

	int count_number = 0;

	///ֻ������ʲ�����Ϣ
	if (ism == false)
	{
		///����value��ֵ���������ֻ���Ƶ�ʳ�����ߵ�ʮ������
		for (vector<pair<string, int> >::iterator it = FrequentArray.begin(); it != FrequentArray.end(); ++it)
		{
			if (isn == true)
			{
				///�����˵��ʵ��������

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
		///ֻ������鲿����Ϣ





	}
	

	resultfile << endl << endl;


	//�ر��ļ���


	resultfile.close();

}