#include "stdafx.h"
#include <iostream.h>
#include <ap/apstring.h>
#include <ap/apvector.h>
#include <fstream.h>
#include <stdlib.h>
#include <stdio.h>

const char *const filename="products.upc";
/*struct Person{
	apstring name;
	apstring address;
	apstring city;
	apstring state;
	int zip;
	apstring phone;
};*/

struct Products{
	apstring name;
	int quanity;
	apstring upc;
};


void save(const apvector<Products> &pro)
{
	ofstream output(filename);
	for(int i=0;i<pro.length();i++)
	{
		output<<pro[i].upc<<' '<<pro[i].quanity<<' '<<pro[i].name<<endl;
	}
}

bool loadproducts(apvector<Products> &pro)
{
	pro.resize(1);
	ifstream product(filename,ios::nocreate);
	if(product.fail())
		return false;
	int count=0;
	while(product>>pro[count].upc>>pro[count].quanity)
	{
		getline(product,pro[count].name);
		count++;
		pro.resize(count+1);
	}
	pro.resize(count);
	return true;
}

void addproduct(apvector<Products> &pro)
{
	apstring temp,name;
	int qua;
	cout<<"Enter the upc==>";
	cin>>temp;
	cin.ignore(100,'\n');
	cout<<"Enter the quanity==> ";
	cin>>qua;
	cin.ignore(100,'\n');
	cout<<"Enter the name==> ";
	getline(cin,name);
	int leng=pro.length();
	pro.resize(leng+1);
	pro[leng].name=name;
	pro[leng].quanity=qua;
	pro[leng].upc=temp;
	save(pro);
}

int main(int argc, char* argv[])
{
	apvector<Products> products;
	bool loaded=loadproducts(products);
	if(!loaded)
	{
		cout<<"An error has acured!!!";
		exit(1);
	}
	addproduct(products);
	
	return 0;
}
