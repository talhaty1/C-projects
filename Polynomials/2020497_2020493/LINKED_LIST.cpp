#include <iostream>
using namespace std;

class List{
    double num;
    int power;
    List* previous;
    List* head;
    int total;

    public:
    List(){
        head=NULL;
        total = 0;
    }

    void insert(double _num, int _power){
        List* insert = new List;
        insert->num = _num;
        insert->power = _power;
        insert->previous = head;
        head = insert;
        total++;
    }
    friend ostream& operator<<(ostream &output, List &list){
        if(list.head==NULL){
            output<<"\nempty List\n";
            return output;
        }

        List* temp = list.head;

        while(temp!=NULL){
            output<<temp->num<<"x^"<<temp->power<<"  ";
            temp= temp->previous;
        }
        return output;
    }
    void pop(){
        if(head != NULL){
            head=head->previous;
            total--;
        }
    }

    int size(){
        return total;
    }

    double operator[](int i){
        if(this->head==NULL){   
            cout<<"\nempty List\n";
            return 0;
        }
        if(i<0 || i >total){
            cout<<"\nout of range\n";
            return 0;
        }
        List* temp = this->head;
        int j = total;
        j--;
        while(temp!=NULL){
            if(j == i){
                return temp->num;
            }
            temp = temp->previous;
            j--;
        }
    }
};