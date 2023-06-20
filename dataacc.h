#ifndef DATAACC_H
#define DATAACC_H
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class dataacc
{
public:
	void extract(vector<vector<float>> v, string name);

	friend class simsetup;
};

#endif