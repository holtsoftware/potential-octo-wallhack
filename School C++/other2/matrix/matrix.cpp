// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <ap/apmatrix.h>
#include <ap/apstring.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream.h>
#include <math.h>
#include <conio.h>

struct condition{
	apstring good;
	apstring bad;
	apstring nr;
};

double abs(double a)
{
	if(a<0)
		return(a*=-1);
	else
		return(a);
}
void readgc(apstring b,apvector<condition> &a,int d)
{
		char c,t='l';
		cout<<"Enter "<<b<<" Condition (G)ood, (B)ad, (N)eeds Repair ==> "<<endl;
		c=getch();
		c=toupper(c);
		switch(c){
		case 'G':
			a[d].good="X";
			t='t';
			break;
		case 'B':
			a[d].bad="X";
			t='t';
			break;
		case 'N':
			t='t';
			a[d].nr="X";
			break;
		case '\n':
			t='t';
			break;
		}
}

void table(ofstream &out,int cav,apstring atsp)
{
	apstring comments,sutm,name,time;
	apmatrix<double> we(cav,2,0);
	apvector<condition> gc(21);
	for(int ini=0;ini<21;ini++)
	{
		gc[ini].good="&nbsp;";
		gc[ini].bad="&nbsp;";
		gc[ini].nr="&nbsp;";
	}
	out<<"<table border=\"0\" width=\"100%\">\n"
		<<"<tr><td>";
	if(atsp=="Yes"||atsp=="yes"||atsp=="Y"||atsp=="y")
	{
		for(int t=0;t<cav;t++)
		{
			cout<<"Enter cavity #"<<t+1<<"\'s F.A. Part weight ==> ";
			cin>>we[t][0];
			cout<<"Enter cavity #"<<t+1<<"\'s Act. Part weight ==> ";
			cin>>we[t][1];
		}
		out<<"<table width=50% border=\"1\">\n";
		out<<"<tr><td>WEIGHT OF THE PARTS IN GRAMS</td></tr></table>\n";
		out<<"<table width=50% border=\"1\"><tr><td>&nbsp;</td><td>F.A. PART<BR>WEIGHT</TD><TD>ACT. PART<BR>WEIGHT</TD><TD>DIFFERENCE</TD></TR>\n";
		for(int k=0;k<cav;k++)
		{
			out<<"\t<tr><td>CAV.#"<<k+1<<"</td><td>"<<we[k][0]<<"</td><td>"<<we[k][1]<<"</td><td>"<<abs(we[k][0]-we[k][1])<<"</td></tr>\n";
		}
		
	}
	readgc("Puller Strap",gc,0);
	readgc("Mold Plates",gc,1);
	readgc("Parting Line Surface",gc,2);
	readgc("Vents",gc,3);
	readgc("Leader Pins",gc,4);
	readgc("Leader Pin Bushings",gc,5);
	readgc("Sucker Pins",gc,6);
	readgc("Core Pins",gc,7);
	readgc("Ejector Pins",gc,8);
	readgc("Ejector System",gc,9);
	readgc("Cam Pins",gc,10);
	readgc("Sliders",gc,11);
	readgc("Lifters",gc,12);
	readgc("Sprue/Runner",gc,13);
	readgc("Gates",gc,14);
	readgc("Stripper",gc,15);
	readgc("Cooling System",gc,16);
	readgc("Electrical System",gc,17);
	readgc("Hydraulic System",gc,18);
	readgc("Unscrewing System",gc,19);
	readgc("Core Pull System",gc,20);
	cout<<endl<<endl;
	cin.ignore(100,'\n');
	cout<<"Enter Comments ect. ==> ";
	getline(cin,comments);
	out<<"</table></td><td><table border=\"1\"><tr><td>COMMENTS\\INCOMPLETE REPAIRS\\CHANGES</td></tr>\n"
		<<"<tr><td>"<<comments<<"</td></tr></table></tr>\n";
	out<<"<tr><td>\n<table width=\"50%\" border=\"1\">\n"
		<<"\t<tr><td>GENERAL CONDITION</td><td>GOOD</td><td>BAD</td><td>NEEDS<BR>REPAIRS</td></tr>\n"
		<<"\t<tr><td>PULLER STRAP</td><td>"<<gc[0].good<<"</td><td>"<<gc[0].bad<<"</td><td>"<<gc[0].nr<<"</td></tr>\n"
		<<"\t<tr><td>MOLD PLATES</td><td>"<<gc[1].good<<"</td><td>"<<gc[1].bad<<"</td><td>"<<gc[1].nr<<"</td></tr>\n"
		<<"\t<tr><td>PARTING LINE SURFACE</td><td>"<<gc[2].good<<"</td><td>"<<gc[2].bad<<"</td><td>"<<gc[2].nr<<"</td></tr>\n"
		<<"\t<tr><td>VENTS</td><td>"<<gc[3].good<<"</td><td>"<<gc[3].bad<<"</td><td>"<<gc[3].nr<<"</td></tr>\n"
		<<"\t<tr><td>LEADER PINS</td><td>"<<gc[4].good<<"</td><td>"<<gc[4].bad<<"</td><td>"<<gc[4].nr<<"</td></tr>\n"
		<<"\t<tr><td>LEADER PIN BUSHINGS</td><td>"<<gc[5].good<<"</td><td>"<<gc[5].bad<<"</td><td>"<<gc[5].nr<<"</td></tr>\n"
		<<"\t<tr><td>SUCKER PINS</td><td>"<<gc[6].good<<"</td><td>"<<gc[6].bad<<"</td><td>"<<gc[6].nr<<"</td></tr>\n"
		<<"\t<tr><td>CORE PINS</td><td>"<<gc[7].good<<"</td><td>"<<gc[7].bad<<"</td><td>"<<gc[7].nr<<"</td></tr>\n"
		<<"\t<tr><td>EJECTOR PINS</td><td>"<<gc[8].good<<"</td><td>"<<gc[8].bad<<"</td><td>"<<gc[8].nr<<"</td></tr>\n"
		<<"\t<tr><td>EJECTOR SYSTEM</td><td>"<<gc[9].good<<"</td><td>"<<gc[9].bad<<"</td><td>"<<gc[9].nr<<"</td></tr>\n"
		<<"\t<tr><td>CAM PINS</td><td>"<<gc[10].good<<"</td><td>"<<gc[10].bad<<"</td><td>"<<gc[10].nr<<"</td></tr>\n"
		<<"\t<tr><td>SLIDERS</td><td>"<<gc[11].good<<"</td><td>"<<gc[11].bad<<"</td><td>"<<gc[11].nr<<"</td></tr>\n"
		<<"\t<tr><td>LIFTERS</td><td>"<<gc[12].good<<"</td><td>"<<gc[12].bad<<"</td><td>"<<gc[12].nr<<"</td></tr>\n"
		<<"\t<tr><td>SPRUE / RUNNER</td><td>"<<gc[13].good<<"</td><td>"<<gc[13].bad<<"</td><td>"<<gc[13].nr<<"</td></tr>\n"
		<<"\t<tr><td>GATES</td><td>"<<gc[14].good<<"</td><td>"<<gc[14].bad<<"</td><td>"<<gc[14].nr<<"</td></tr>\n"
		<<"\t<tr><td>STRIPPER</td><td>"<<gc[15].good<<"</td><td>"<<gc[15].bad<<"</td><td>"<<gc[15].nr<<"</td></tr>\n"
		<<"\t<tr><td>COOLING SYSTEM</td><td>"<<gc[16].good<<"</td><td>"<<gc[16].bad<<"</td><td>"<<gc[16].nr<<"</td></tr>\n"
		<<"\t<tr><td>ELECTRICAL SYSTEM</td><td>"<<gc[17].good<<"</td><td>"<<gc[17].bad<<"</td><td>"<<gc[17].nr<<"</td></tr>\n"
		<<"\t<tr><td>HYDRAULIC SYSTEM</td><td>"<<gc[18].good<<"</td><td>"<<gc[18].bad<<"</td><td>"<<gc[18].nr<<"</td></tr>\n"
		<<"\t<tr><td>UNSCREWING SYSTEM</td><td>"<<gc[19].good<<"</td><td>"<<gc[19].bad<<"</td><td>"<<gc[19].nr<<"</td></tr>\n"
		<<"\t<tr><td>CORE PULL SYSEM</td><td>"<<gc[20].good<<"</td><td>"<<gc[20].bad<<"</td><td>"<<gc[20].nr<<"</td></tr>\n"
		<<"</table>\n";
	
	
	cout<<"What is mold set up to make? ==> ";
	getline(cin,sutm);
	out<<"</td><td><table border=\"1\"><tr><td>WHAT IS MOLD SET UP TO MAKE?</td></tr>\n"
		<<"<tr><td>"<<sutm<<"</td></tr></table></td></tr></table></td></tr>\n";
	cout<<"Work done by ==> ";
	getline(cin,name);
	cout<<"Total Job Time ==> ";
	getline(cin,time);
	out<<"<p align=\"right\">\n"
		<<"<u>WORK DONE BY:"<<name
		<<"<br>\nTOTAL JOB TIME:"<<time<<endl;
}

void check(apstring output,apstring &name)
{
	char yesorno;
	do{
		cout<<output<<name<<"\nis this correct (Y or N)==> "<<endl;
		yesorno=getch();
		yesorno=toupper(yesorno);
		if(yesorno=='N')
		{
			cout<<"Enter "<<output<<" ==> ";
			getline(cin,name);
		}
	}while(yesorno!='Y');

}

void savefile()
{
	apstring copan="Orbat",atsp=" ",material=" ",ct=" ",faparts=" ",lml=" ",cycle=" ",in="&nbsp;",pn=" ",ge="&nbsp;",mn=" ",ma="&nbsp;",date="1-5-1999",pname="n/a";
	char choice;
	int cav;
	cout<<"Enter the Company Name ==> ";
	getline(cin,copan);
	cout<<"What type of maintenace (I)nspection,(G)eneral, or (M)ajor ==>";
	cin>>choice;
	choice=toupper(choice);
	switch(choice){
	case 'I':
		in="X";
		break;
	case 'G':
		ge="X";
		break;
	case 'M':
		ma="X";
		break;
	}
	cin.ignore(100,'\n');
	cout<<"Enter the date that it was maintened ==> ";
	getline(cin,date);
	cout<<"Enter the Part Name ==> ";
	getline(cin,pname);
	cout<<"Enter the Mold Number ==> ";
	getline(cin,mn);
	cout<<"Enter the Part Number ==> ";
	getline(cin,pn);
	cout<<"Enter the Cyles (Last Run) ==> ";
	getline(cin,cycle);
	cout<<"Enter the Date On First Article Parts ==> ";
	getline(cin,faparts);
	cout<<"Enter the Date On Last Maintenance Log ==> ";
	getline(cin,lml);
	cout<<"Enter Number of Cavities ==> ";
	cin>>cav;
	cin.ignore(100,'\n');
	cout<<"Enter Est. Cycle Time ==> ";
	getline(cin,ct);
	cout<<"Enter the Material Used ==> ";
	getline(cin,material);
	cout<<"Are There Sample Parts ==> ";
	getline(cin,atsp);
	check("Company Name ",copan);
	check("Date ",date);
	check("Part Name ",pname);
	check("Mold Number ",mn);
	check("Part Number ",pn);
	check("Cycles (Last Run) ",cycle);
	check("Date on First Article Parts ",faparts);
	check("Date on Last Maintenance Log ",lml);
	check("Est. Cycle Time ",ct);
	check("Material ",material);
	check("Are There Sample Parts? ",atsp);
	apstring folder="c:\\windows\\profiles\\adam\\desktop\\"+pname+'-'+date+".html";
	ofstream out(folder.c_str());
	out<<"<html>\n";
	out<<"<title>"<<copan<<" - "<<pname<<" - "<<date<<"</title>\n"
		<<"<body bgcolor=\"#00ff00\">\n"
		<<"<u>PREVENTITIVE MAINTENACE LOG &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
		<<"COMPANY NAME "<<copan<<endl
		<<"<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TYPE OF MAINTENACE&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;INSPE.("<<in<<")&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GENERAL("<<ge<<")&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MAJOR("<<ma<<")<br><!INSPE.("<<in<<") GENERAL("<<ge<<") MAJOR("<<ma<<")>\n"
		<<"\n<br>DATE "<<date;
	for(int e=date.length();e<100;e++)
		out<<"&nbsp;";
	out <<"MOLD NUMBER "<<mn
		<<"\n<br>PART NAME "<<pname;
	for(int a=pname.length();a<87;a++)
		out<<"&nbsp;";
	out <<"PART NUMBER "<<pn
		<<"\n<br>CYCLES (LAST RUN) "<<cycle
		<<"\n<br>DATE ON FIRST ARTICLE PARTS "<<faparts;
	for(int w=faparts.length();w<56;w++)
		out<<"&nbsp;";
	out <<"\nCAVITIES "<<cav
		<<"\n<br>DATE ON LAST MAINTENANCE LOG "<<lml;
	for(int d=lml.length();d<49;d++)
		out<<"&nbsp;";
	out<<"\nEST. CYCLE TIME "<<ct<<"<br></u>";
	for(int t=0;t<116;t++)
		out<<"&nbsp;";
	out	<<"\n<u>MATERIAL "<<material
		<<"\n<br>ARE THERE SAMPLE PARTS? "<<atsp<<"</u>";
	table(out,cav,atsp);
		
	out <<"</body>\n"
		<<"</html>\n";


}
void main()
{
	savefile();
}


