/*
 * Main.cpp
 *
 *  Created on: 19-Mar-2021
 *      Author: jagdeep
 */
#pragma GCC optimize("O1")
#include<iostream>
#include "Array.h"
#include <string>
using namespace std;
int main()
{
	Array<string> testArray(10);
	cout << testArray.size()<<endl;
	cout << testArray.capacity() <<endl;
return 0;
}




