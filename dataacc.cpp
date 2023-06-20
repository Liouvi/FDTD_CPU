#include "dataacc.h"
#include <string>
#include <iterator>

void dataacc::extract(vector<vector<float>> v, string name)
{
	ofstream output_file(name);
	std::ostream_iterator<float> output_iterator(output_file, "\t");
	for (int i = 0; i < v.size(); i++) {
		copy(v.at(i).begin(), v.at(i).end(), output_iterator);
		output_file << '\n';
	}
}
