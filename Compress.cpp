#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	// Reading input file
	string word;
	int count =0;
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
		ofstream row_file("row_output.txt");
		if(row_file.is_open())
		{
			
			row_file.close();	
		}
		else
		{
			cout << "Error opening the row file: " << endl;
		}
		/*
		while(in_file >> word)
		{
			count++ ;
			
		}
		int arr[count];
		for(int i =0; i < count; i++)
		{
			arr[i] = word[i];
		}
		*/
		
		in_file.close();
	}
	
	
	return 0;
}

//http://www.cplusplus.com/forum/general/5069/
//http://www.dreamincode.net/forums/topic/247058-writing-a-c-program-to-check-if-a-given-word-is-repeated/page__st__15
//http://stackoverflow.com/questions/16182409/c-remove-duplicate-numbers-from-a-file
