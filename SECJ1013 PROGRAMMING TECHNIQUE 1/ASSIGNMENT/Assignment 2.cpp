#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void getInput (int &, int &, int &, int &);
void outCarInfo(int, int, int, int, double);
double calcInstallment(double, double, double, int);

const string models[6] = {"Ativa", "Aruz", "Bezza", "Myvi", "Alza", "Axia"};
const string variants[6][5] = {
	{"1.0L X TURBO (CVT)", "1.0L H TURBO (CVT)", "1.0L AV TURBO (CVT)"},
	{"1.5 AV (Auto)", "1.5 X (Auto)"},
	{"1.3 AV (Auto)", "1.3 X (Auto)", "1.0 G (Auto)", "1.0 G (Manual)"},
	{"1.5L AV (CVT)", "1.5L H (CVT)", "1.5L X (CVT)", "1.3L G (CVT)", "1.3L G (CVT)(Without PSDA)"},
	{"1.5L AV (D-CVT)", "1.5L H (D-CVT)", "1.5L X (D-CVT)"},
	{"1.0L AV (D-CVT)", "1.0L SE (D-CVT)", "1.0L X (D-CVT)", "1.0L G (D-CVT)", "1.0L E (5MT)"}
};

const string colourAtiva[2][3] = {
	{"Metallic", "Special Metallic"},
	{"Metallic", "Special Metallic", "Tone Special Metallic (Black Roof)"}
};

const double priceAtiva[3][3][4] = {
	{{62500, 64500, 59980, 58650}},
	{{67300, 69300, 64410, 63080}, {67800, 69800, 64900, 63570}},
	{{72600, 74600, 69360, 68030}, {73100, 75100, 69850, 68520}, {73400, 75400, 70130, 68800}}
};

const double priceOthers[5][5][4] = {
	{{77900, 79900, 71800, 70900}, {72900, 74900, 67400, 66500}},
	{{49980, 51980, 49580, 48280}, {43980, 45980, 44180, 42980}, {36580, 38580, 36780, 35580}, {34580, 36580, 34580, 33380}},
	{{59900, 61900, 58810, 58010}, {54900, 56900, 53980, 53180}, {50900, 52900, 50050, 49250}, {48500, 50500, 47860, 47060}, {46500, 48500, 45860, 45060}},
	{{75500, 78000, 73930, 72600}, {68000, 70500, 66980, 65650}, {62500, 65000, 61610, 60280}},
	{{49500, 51500, 50090, 48490}, {44000, 46000, 44590, 42990}, {40000, 42000, 40590, 38990}, {38600, 40600, 39190, 37590}, {22000, 22000, 22000, 22000}}
};

const string regions[4] = {"Peninsular Malaysia", "East Malaysia", "Labuan", "Langkawi"};

int main (){
	char option;
	
    do{
        
        int model=0,variant=0,region,colour=0,years,down_payment;
		double price=0,interest_rate;
        
		cout<<"Perodua Car Loan Calculator\n"  << endl;
        getInput (model, variant, colour, region);
        
        if (model == 0)
        {
        	price = priceAtiva[variant][colour][region];// price
		}
		else if (model != 0)
		{
			price = priceOthers[model-1][variant][region];// price
		}
		

		//display car info
        outCarInfo (model, variant, region, colour, price);
        
    
		cout<<"\nDown Payment (MYR): ";
		cin>>down_payment;
		cout<<"Interest Rate (%): ";
		cin>>interest_rate;
		cout<<"Repayment period (in years): ";
		cin>>years;
		
		cout << "\nMONTHLY INSTALLMENT (MYR) : " << round(calcInstallment(price, down_payment, interest_rate, years)) << endl;
		
        cout<<"\nDo you want to enter other data? [Y @ N]: ";
        cin>>option;
        cout<<"\n";

    }while(option == 'Y');
    
    	cout<<"Thank you :)\n";
        

}

void getInput (int &model, int &variant, int &colour, int &region){
	
	//model
    cout<<"Model [1-Ativa, 2-Aruz, 3-Bezza, 4-Myvi, 5-Alza, 6-Axia]: ";
    cin>>model; 
    model--;
    
    //variant
    cout << "Variants [";
    if ((model == 0) || (model == 4))
    {
    	for (int i=0; i<3; i++)
		{
			cout << i+1 << " - " <<variants[model][i] << "  ";
		}
		
	}
	else if (model == 1)
	{
		for (int i=0; i<2; i++)
		{
			cout << i+1 << " - " <<variants[model][i] << "  ";
		}
	}
	else if (model == 2)
	{
		for (int i=0; i<4; i++)
		{
			cout << i+1 << " - " <<variants[model][i] << "  ";
		}
	}
	else if ((model == 3) || (model == 5))
	{
		for (int i=0; i<5; i++)
		{
			cout << i+1 << " - " <<variants[model][i] << "  ";
		}
	}
	cout << "] : ";
	cin >> variant;
	variant--;
	
	//colour Ativa
	if (model == 0)
	{
		if (variant == 1)
		{
			cout << "Paint Type [ ";
			for (int i=0; i<2; i++)
			{
				cout << i+1 << " - " <<colourAtiva[variant][i] << "  ] : ";
			}
			cin >> colour;
			colour--;
		}
		else if (variant == 2)
		{
			cout << "Paint Type [ ";
			for (int i=0; i<3; i++)
			{
				cout << i+1 << " - " <<colourAtiva[variant][i] << "  ] : ";
			}
			cin >> colour;
			colour--;                                              	
		}
	}


	//region
	cout<<"Region [1-Peninsular Malaysia, 2-East Malaysia, 3-Labuan, 4-Langkawi]: ";
    cin>>region;
    region--;
}

void outCarInfo (int model, int variant, int region, int colour, double price)
{
	cout << "\nCar Info" << endl;
	cout << "Model: " << models[model] << endl;
	cout << "Variant: " << variants[model][variant] << endl;
	cout << "Region: " << regions[region] << endl;
	if (model == 0)
	{
		if (variant == 0)
			cout << "Paint Type: Metallic" << endl;
		else if (variant != 0)
		{
			cout << "Paint Type: " << colourAtiva[variant][colour] << endl;
		}
	}
	cout << "Price (MYR): " << fixed << setprecision(2) << price << endl;
}

	
double calcInstallment(double p, double d, double r, int y)
{
	double installment = ((p - d) + ((p - d) * (r/100) * y)) / y / 12;
	
	return installment;
}