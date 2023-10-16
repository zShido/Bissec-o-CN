#include <iostream>
#include <cmath>
#include <fstream>
#define n 50

using namespace std;

float calc (float x){
	double lg;
	lg = log10(x);
	return ((x*lg)-1);
}

int main()
{
	int k=0;
	float finicio, meio, fmeio, a=2 , b=3, prec=0.1;

	ofstream outputfile("Tabela.txt");

	if (outputfile.is_open()){
	if (fabs(b-a)<prec){
    	cout << a << endl;
	}else{
    	while(fabs(b-a)>prec && k<n){
        	k++;
        	finicio = calc(a);
        	meio = (a+b)/2;
        	fmeio = calc(meio);

			outputfile << "Interação " << k << ":\t a = " << a << "\t b = " << b << "\t meio = " << meio << "\t k = " << k << endl;

        	if(finicio*fmeio<0){
            	b=meio;
        	}else{
            	a=meio;
        	}
    	}
	}
    
	cout << meio << endl << k << endl;

	outputfile.close();
	
	}else {
		cerr << "Erro ao abrir o arquivo" << endl;
	}
    
	return 0;
}