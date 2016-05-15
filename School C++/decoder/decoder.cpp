#include <iostream.h>
#include <fstream.h>
#include <ap/apstring.h>
//Immortal King's Stone Crusher

void main()
{
	char todec;
	apstring filename,sfilename;
	fstream infile;
	fstream ofile;
	cout<<"Enter the file name."<<endl;
	getline(cin,filename);

	int k;
	//for(int i=1;i<256;i++)
	//{
		infile.open(filename.c_str(),ios::in);
		sfilename=filename+'.'+".txt";
		ofile.open(sfilename.c_str(),ios::out);
		k=1;
		while(!infile.eof())
		{
			infile>>todec;
			ofile<<char(int(todec)+k);
			k++;
		}
		infile.close();
		ofile.close();
	//}
}
