/*NAME:TAN XIN TIAN
  SEC:03
  NO.MATRIC:A24CS0198
  DATE:14 NOV 2024*/

#include <iostream>
using namespace std;

int main(){

char option;

do{

	int num,digit;
	int sum=0;
	
	cout<<"Enter an integer number:";
	cin>>num;
	
	do{
		
		digit = num % 10;
		sum= sum + digit;
		num=num /10;
		
		if (num>0){
			cout<<digit<<"+";
		}
		else{
			cout<<digit<<"="<<sum<<endl;
		}
	
	}while(num>0);
	
	cout<<sum;
		
	if(sum%2==0)
	{
		if ((sum % 4==0) && (sum % 5==0) && (sum % 3==0)){
			cout<<" is even number & multiple of 3,4 & 5"<<endl;
			
		}
		
		else if  ((sum % 3==0) && (sum % 4==0)){
			cout<<" is even number & multiple of 3 & 4"<<endl;
		
		}
		
		else if  ((sum % 3==0) && (sum % 5==0)){
			cout<<" is even number & multiple of 3 & 5"<<endl;
		
		}
		
		else if  ((sum % 4==0) && (sum % 5==0)){
			cout<<" is even number & multiple of 4 & 5"<<endl;
		
		}
		
		else if  (sum % 3==0){
			cout<<" is even number & multiple of 3"<<endl;
		
		}
		
		else if  (sum % 4==0){
			cout<<" is even number & multiple of 4"<<endl;
		}
			
		else if  (sum % 5==0){
			cout<<" is even number & multiple of 5"<<endl;
		}
		
		else{
			cout<<" is even number"<<endl;
		}
	}
	
	else{
		
		if((sum % 3==0) && (sum % 5==0)){
			cout<<" is odd number & multiple of 3 & 5"<<endl;
		}
		
		else if  (sum % 3==0){
			cout<<" is odd number & multiple of 3"<<endl;
		}
		
		else if  (sum % 5==0){
			cout<<" is odd number & multiple of 5"<<endl;
		}
		
		else{
			cout<<" is odd number"<<endl;
		}
	}
	
	cout<<"\nDo you want to calculate again?Enter 'y' or 'n':";
	cin>>option;
	cout<<"\n";
		
}while(option=='y');
	
	
	return 0;
}