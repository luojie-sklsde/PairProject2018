#include<iostream>
#include "PairProject.h"
using namespace std;

int main(int argc, char*argv[])
{



	WordOperation mywordoperation;

	int i = 0;

	////¶ÁÈ¡²ÎÊý
	
	for (i = 1; i < argc + 1; i++)
	{
		
		if (string(argv[i]) == "-i")
		{
			mywordoperation.isi = true;
			cout << argv[i + 1] << endl;
			mywordoperation.ipath = string(argv[i + 1]);
			cout << mywordoperation.ipath << endl;
		}
		else if (string(argv[i]) == "-o")
		{
			mywordoperation.iso = true;
			mywordoperation.opath = string(argv[i + 1]);
			cout << mywordoperation.opath << endl;
	
		}
		else if (string(argv[i]) == "-m")
		{
			mywordoperation.ism = true;
			mywordoperation.m_number = atoi(argv[i + 1]);

		}
		else if (string(argv[i]) == "-n")
		{
			mywordoperation.isn = true;
			mywordoperation.n_number = atoi(argv[i + 1]);
			cout << mywordoperation.n_number << endl;
		}

	}

	//cout << mywordoperation.ipath << endl;
	mywordoperation.Operation(mywordoperation.ipath);

	return 0;

}
