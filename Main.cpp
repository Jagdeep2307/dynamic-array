/*
 * Main.cpp
 *
 *  Created on: 19-Mar-2021
 *      Author: jagdeep
 */
#pragma GCC optimize("O1")
#include<iostream>
#include "Array.h"
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	fstream FIN("/home/jagdeep/workspace/BMG_DSep/ServerData/01/data.txt",ios::in);
	fstream FOUT("tmp.txt",ios::out);
	if(!FIN.is_open())
	{
		return -1;
	}
	if(!FOUT.is_open())
		{
			return -1;
		}
	string line;
	vector<string> vect;
	//Array<string> vect;
	/*int  i = 0;
	cout << vect.size() <<" "<< vect.capacity() << endl;
	while(i < 10)
	{
		vect.push_back(i);
		++i;
	}
	cout << "size of vector before insert =>>:" << vect.size()<<endl;
	i=0;
		while(i < vect.size())
		{
			cout << vect[i]<<endl;
			i++;
		}
    cout << "insert element ..>\n";
    vect.insert(vect.begin()+5,23);
    vect.insert(vect.end()-1,65);

    i=0;
	while(i < vect.size())
	{
		cout << vect[i]<<endl;
		i++;
	}
	cout << "size of vector after insert =>>:" << vect.size()<<endl;
	int j=0;
	*/
	int j=0;
    while(getline(FIN,line))
	{
		vect.push_back(line);
	   // if(j== 1000)
	   // break;
		++j;
	}
    cout << "Count of records is file is " << j << endl;

	int i=0;
	while(i < vect.size())
	{
		FOUT<< vect[i]<<endl;
		++i;
	}
	//Array<int> vect2;
	//vector<int> vect2;
	cout << vect.size()<<endl;

	FOUT.close();
	FIN.close();
return 0;
}




