#include "brent.h"
#include <iostream>

//Author: Mehmet Semdin Aktay - 20190702102
//Date: 27.11.2022

using std::cout;
using std::endl;


Brent::Brent(int table_size){
	data_vec.resize(table_size,entry());
}


void Brent::insert(int new_data){
	
	int line = new_data % data_vec.size();
	int inc = new_data / data_vec.size();
	if (inc == 0) inc = 1;

	if(data_vec.at(line).valid==false){
		data_vec.at(line).data=new_data;
		data_vec.at(line).valid=true;
	}
	else if(data_vec.at((line+(inc))%data_vec.size()).valid == false){
		data_vec.at((line + inc)%data_vec.size()).data = new_data;
		data_vec.at((line + inc)%data_vec.size()).valid = true;
	}
	else{
		int s = 1;
		int destination = (line+inc)%data_vec.size();

		//s
		while(data_vec.at(destination).valid){
			destination = (destination+inc)%data_vec.size();
			s++;
		}
	
		int final_dest = 0;
		int final_data = 0;
		int replace_dest = 0;
		bool flag = true; //if i+j<s or not
		for(int i=0;i<s;i++){

			int temp_dest = (line + inc*i)%data_vec.size();
			int temp_data = data_vec.at( temp_dest ).data;

			int temp_inc = temp_data /data_vec.size();
			if(temp_inc == 0){temp_inc=1;}

			temp_dest = (temp_dest + temp_inc)%data_vec.size();
			int j=1;

			while(data_vec.at(temp_dest).valid){
				j++;
				temp_dest = (temp_dest + temp_inc)%data_vec.size();
			}

			if(i+j<s){
				flag=false;
				s=i+j;
				final_data = temp_data;
				final_dest = temp_dest;
				replace_dest  = (line + inc*i)%data_vec.size();
			}
		}

		if(flag){
			data_vec.at(destination).data = new_data;
			data_vec.at(destination).valid = true;
		}
		else{
			data_vec.at(replace_dest).data = new_data;
			data_vec.at(final_dest).data = final_data;
			data_vec.at(final_dest).valid = true;
		}
	}

}



int Brent::find_num_probes(int key) const{
	int count = 1;
	int line = key % data_vec.size();
	int inc = key / data_vec.size();
	if (inc == 0) inc = 1;

	while(data_vec.at(line).data != key){
		line = (line + inc) % data_vec.size();
		count++;
	}

	return count;
}



double Brent::find_average_num_probes() const{
    double sum = 0.0;

    for(int i=0;i<data_vec.size();i++)
       sum += find_num_probes(data_vec.at(i).data);

    
	double average = sum/11;
    return average;

}