#include <iostream>
#include <fstream>

#include "brent.h"

using std::cout;
using std::endl;
using std::cerr;

void print_table(const Brent & tbl){

	for(int i = 0; i < tbl.data_vec.size(); i++){
		cout << i << ":  ";
		if(tbl.data_vec[i].valid){
			cout << tbl.data_vec[i].data <<  "     " << tbl.find_num_probes(tbl.data_vec[i].data);
		}
		cout << endl;
	}

	cout << endl << "Average # of probes: " << tbl.find_average_num_probes() << endl;
}

int main(){

	std::ifstream fin("numbers");
	int number;
	int cnt = 0;

	Brent tbl(11);

	while(fin >> number){
		tbl.insert(number);
	}
	cout << endl << "---Tables---" <<endl;
	print_table(tbl);

	fin.close();

	return 0;
}
