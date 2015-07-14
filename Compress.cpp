#include<iostream>
#include<fstream>
#include<string>>
using namespace std;

int main()
{
	// Reading input file
	cout << "Enter a file name to open: " << endl;
	string filename;
	cin >> filename;
	ifstream in_file;
	in_file.open(filename.c_str());
	if(in_file.fail())
	{
		cout << "Error opening the file" << endl;
	}
	else
	{
		//executing the program code 2
		cout << "change" << endl;
		in_file.close();
	}
	
	
	return 0;
}
