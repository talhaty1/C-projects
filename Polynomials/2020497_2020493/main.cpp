//          2020497   Talha yunus                           2020493    Taha Sarwat
#include <iostream>
#include "LINKED_LIST.cpp"
#include <fstream>
using namespace std;

class Polynomial{
    double *array;
    List list;
    int total_polynomials, total_variables;
    int choice;

    public:
    Polynomial(){
        do{
            cout<<"\nWich data structure to use to store the polynomials\n\n"
                <<"\t1. USE ARRAY\n"
                <<"\t2. USE LINKED LIST"
                <<"\n\nENTER YOUR CHOICE:\n";
            cin>>choice;
            if(!cin){
                cin.ignore(1000,'\n');
                cin.clear();
            }
        }while(choice != 1 && choice != 2);
    }
    ~Polynomial(){
        delete[] array;
    }

    void readFile(){
        char *fileName;
        ifstream read;
        cout<<"\nENTER THE NAME OF THE FILE: ";
        cin>>fileName;
        read.open(fileName);
        read>>total_polynomials;
        read>>total_variables;
        if(choice == 1){
            array = new double[total_variables];
        }
        add(read);
        read.close();
    }

    void display(){
        cout<<"\nRESULT:\n";
        if(choice == 1){
            for(int i=0; i<total_variables; i++){
                if(i != total_variables-1){
                    if(array[i]>=0)
                        cout<<array[i]<<"x^"<<i<<" + ";
                    else
                        cout<<array[i]<<"x^"<<i<<" - ";
                }
                else
                    cout<<array[i]<<"x^"<<i<<endl;
            }
        }
        else{
            for(int i=0; i<total_variables; i++){
                if(i != total_variables-1 ){
                    if(list[i]>=0)
                        cout<<list[i]<<"x^"<<i<<" + ";
                    else
                        cout<<list[i]<<"x^"<<i<<" - ";
                }
                else
                    cout<<list[i]<<"x^"<<i<<endl;
            }
        }
        cout<<"\n\n";
    }

    void add(ifstream &read){
        if(choice == 1){
            double *temp;
            temp = new double[total_variables];
            for(int i=0; i<total_variables; i++){
                array[i]=0;    
            }
            for(int j=0; j<total_polynomials; j++){
                for(int i=0; i<total_variables; i++){
                    read>>temp[i]; 
                }
                for(int i=0; i<total_variables; i++){
                    array[i] += temp[i];
                }
            }
            delete[] temp;
        }
        else{
            double temp;
            for(int i=0; i<total_variables; i++){
                list.insert(0,0);    
            }
            for(int j=0; j<total_polynomials; j++){
                List tempList1;
                List tempList2;
                for(int i=0; i<total_variables; i++){
                    read>>temp;
                    tempList1.insert(temp,i);
                }
                for(int i=0; i<total_variables; i++){
                    tempList2.insert(list[i],i);
                }
                for(int i=0; i<total_variables; i++){
                    list.pop();
                }
                for(int i=0; i<total_variables; i++){
                    list.insert(tempList1[i] + tempList2[i], i);
                }
            }
        }
    }
    
    void saveResult(){
        ofstream output;
        output.open("result_addition.txt");
        if(choice == 1){
            for(int i=0; i<total_variables; i++){
                if(i != total_variables-1){
                    if(array[i]>=0)
                        output<<array[i]<<"x^"<<i<<" + ";
                    else
                        output<<array[i]<<"x^"<<i<<" - ";
                }
                else
                    output<<array[i]<<"x^"<<i<<endl;
            }
        }
        else{
            for(int i=0; i<total_variables; i++){
                if(i != total_variables-1 ){
                    if(list[i]>=0)
                        output<<list[i]<<"x^"<<i<<" + ";
                    else
                        output<<list[i]<<"x^"<<i<<" - ";
                }
                else
                    output<<list[i]<<"x^"<<i<<endl;
            }
        }
        output.close();
    }
};

int main(){
    Polynomial p;
    p.readFile();
    p.display();
    p.saveResult();
}