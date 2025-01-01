#include <iostream>
using namespace std;

void dispStatus (int);
void getInput (int &,int &,int &,int &);
void dispOutput(int);
int calcAverage (int,int);

int main (){
    string state_name,highest_state;
    int num_total_cases,new_cases,total_death,total_recovered;
    int active_cases,total_active_cases=0,num_of_states=0;
    string repeat;
    int highest=-1;
    int avrg;

    do{
        cout<<"<<<<<<<<<<<<<< DATA >>>>>>>>>>>>> \n";
        cout<<"State name     : ";
        getline(cin,state_name);
	
		
        getInput (num_total_cases,new_cases,total_death,total_recovered);
		cin.ignore();
		
        cout<<"\n";
        cout<<"<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>\n";
        
        active_cases = num_total_cases + new_cases - total_death - total_recovered;
        cout<<"Active cases   : "<<active_cases<<endl;

        dispOutput(active_cases);
      
        cout<<"\n";
        cout<<"Press <ENTER> to continue...";
        
        repeat=cin.get();
		cout<<"\n";
        
        num_of_states+=1;
        total_active_cases = total_active_cases + active_cases;

        if(active_cases>highest){
            highest=active_cases;
            highest_state=state_name;
        }

    }while(repeat=="\n");

    cout<<"\n";
    cout<<"<<<<<<<<< ACTIVE CASES >>>>>>>>>>\n";
    cout<<"Total  : "<<total_active_cases<<endl;
    cout<<"Highest: "<<highest<<" ("<<highest_state<<")"<<endl;

    avrg=calcAverage (num_of_states,total_active_cases);
    cout<<"Average for "<<num_of_states<<" states: "<<avrg<<endl;
}

void getInput (int &a,int &b,int &c,int &d){

    cout<<"Total cases    : ";
    cin>>a;

    cout<<"New cases      : ";
    cin>>b;

    cout<<"Total death    : ";
    cin>>c;

    cout<<"Total recovered: ";
    cin>>d;
}

void dispOutput(int active_cases){
   
    dispStatus (active_cases);

}

void dispStatus (int actC){

    if(actC>40){
        cout<<"Status         : "<<"Red zone\n";
        }

    else if ((actC>=21)&&(actC<=40)){
        cout<<"Status         : "<<"Orange zone\n";
    }

    else if ((actC>=1)&&(actC<=20)){
        cout<<"Status         : "<<"Yellow zone\n";
    }
   
    else {
        cout<<"Status         : "<<"Green zone\n";
    }
}

int calcAverage (int num_of_states,int total_active_cases){

    int avrg;
    avrg = total_active_cases/num_of_states;

    return avrg;

}
