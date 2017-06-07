#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int data(){
	string hit;
	double string, dom_n;
	double allN[] = {4,7,10,13,16,19,21,24,27,30,33,36,39,42,45,48,51,54,57,60};
	for (int n : allN) {
		std::ifstream fp(Form("180517_OM%d_2250M_CPU_data.txt",n));
		if (fp.is_open()) {
			std::ofstream fout(Form("Dom_%d.txt",n));
			if (!fout.is_open())	std::cerr << "Cannot open fout\n";
				std::string line;
				while (std::getline(fp, line))
				{
					stringstream linestream(line);
					linestream >> hit;
					linestream >> string;
					linestream >> dom_n;
					//cout << hit << " " << string << " " << dom_n << endl;	
					if (string == 2 && dom_n == n){
						fout << line << "\n";
						//cout << line << endl;
					}
				}
				fout.close();
				cout << "Dom _ " << n << " -> Data Reduction is Done." << endl;
			//	if (! fout) std:cerr << "Error writing\n";
			//	if (!fp.eof()) std::cerr << "Error reading\n";
			}
		fp.close();
	}
	return 0;
}
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int data(){
	int allN[] = {4,7,10,13,16,19,21,24,27,30,33,36,39,42,45,48,51,54,57,60};
	for (int n : allN) {
		std::ifstream fp(Form("180517_OM%d_2250M_CPU_data.txt", n));
		if (fp.is_open()) {
			std::ofstream fout(Form("Dom_%d",n));
			if (!fout.is_open())	std::cerr << "Cannot open fout\n";
				std::string line;
				while (std::getline(fp, line)){
					if (line[4] == '2' && line[6] == '4'){
						fout << line << "\n";
						//cout << line << endl;
					}
				}//wow!
				fout.close();
				if (! fout) std:cerr << "Error writing\n";
				if (!fp.eof()) std::cerr << "Error reading\n";
			}
	}
	return 0;
}
*/
/*int data(){
	//std::basic_ifstream;
	//std::stringstream;
	int n[20]= {4,7,10,13,16,19,21,24,27,30,33,36,39,42,45,48,51,54,57,60};
	//Float_t a[n] = {4,7,10,13,16,19,21,24,27,30,33,36,39,42,45,48,51,54,57,60};
	std::ifstream fp;
	std::ofstream fo;

	 // Open reading file using fp.open function
	 // Reading each line in whole file
	 // Take specific line what i want and then save another text file. (using ofstream fout("*") and fout << ''' << "\n" )
	 // Close the result file and reading file.

	for(int i=0; i<sizeof(n); i++)
	{
		fp.open(Form("180517_OM%d_2250M_CPU_data.txt",n[i]));
		//fp.open("180517_OM04_2250M_CPU_data.txt");

		char line[200];
		if(fp.fail())
		{
			std::cout << "No file" << endl;
			return 0;
		}
		if(fp.is_open())
		{
			ofstream fout(Form("c_dom%d.txt",n[i]));
			while (fp.getline(line, sizeof(line)))
			{
				if(line[4] == '2' && line[6] == '4')
				{
					fout<<line<<"\n";
					//cout << line << endl; This line is for the checking that this function doing well.
				}
			}
			fout.close();
		}
		fp.close();

	}
	return 0;
}
*/
