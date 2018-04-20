/**
	Copyright (c) 2018
	S1 Teknik Informatika Offering A 2017
	Fakultas Teknik
	Universitas Negeri Malang

	Aidil Arif Budiman			170535629557
	Bhimantoro Suryo Admodjo	170535629519
	Fitriana Kurniawati			170535629535
	Gwinny Tirza Rarastri		170535629512

**/
#include <iostream>
#include <math.h> //header fungsi cos

using namespace std;

double radian(double degree){ //konversi sudut ke radian
	while (degree>=360){ //antara 0<= sudut < 360
		degree-=360;
	}
	if (degree>180){ //antara 0<=sudut<=180
		degree=180-degree;
	}
	const long double phi = 3.141592653589793238462643383279502884;
	const long double rumus = phi/180;
	return degree*rumus;
}

double faktorial(int n){ //mencari nilai faktorial
	if ((n==0)||(n==1))
		return 1;
	else
		return (n*faktorial(n-1));
}

double cosinus(double rad){ //nilai cosinus dengan operasi baris maclaurin
	double sum = rad;
	sum = 1.0;
	double sign = 1.0;
	for (int i=2; i<=6; i+=2){
		sum = sum - (sign*(pow(rad,i))/faktorial(i));
		sign = sign*(-1);
	}
	return sum;
}

main(){
	double x; //sudut cosinus dalam derajat
	cout<<"Masukkan sudut : ";cin>>x;
	double rad = radian(x);
	double maclaurin = cosinus(rad);
	double builtin = cos(rad);
	cout.precision(8);
	cout
	<<"\nHasil :\n"
	<<"cos maclaurin\t: "<<maclaurin
	<<"\ncos built-in\t: "<<builtin
	<<"\nselisih\t\t: "<<builtin-maclaurin;
	return 0;
}
