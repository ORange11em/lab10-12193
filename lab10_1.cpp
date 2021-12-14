#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

double interest(double PB,double In){
	return PB*(In/100);
}

double PB,In,Pm,NB;

int main(){	
	cout << "Enter initial loan: ";
	cin >> PB;
	cout << "Enter interest rate per year (%): ";
	cin >> In;
	cout << "Enter amount you can pay per year: ";
	cin >> Pm;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	double T,Pa;
	int i=1;
	while (NB>=0){
	cout << fixed << setprecision(2); 
	cout << setw(13) << left << i;
	i++;
	cout << setw(13) << left << PB;
	cout << setw(13) << left << interest(PB,In);
	T=PB+interest(PB,In);
	cout << setw(13) << left <<T;
		if (Pm<T){
			cout << setw(13) << left << Pm;
			NB = T-Pm;
			cout << setw(13) << left << NB;
		}else{
			Pa =Pm-(Pm-T);
			cout << setw(13) << left << Pa;
			NB =Pa-Pa;
			cout << setw(13) << left << NB;
			break;
		}
	cout << "\n";
	PB=NB;
	}
	return 0;
}
