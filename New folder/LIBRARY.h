//          Made By Talha Yunus
//                  (2020497) (2020408) (2020493)

#include <iostream>
#include <cstring>
#include "CERR.h"
#include <windows.h>
using namespace std;


//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------


class CBook{

    // A doubly Linked List
    struct Node{
        int ID; char* BookName; char* author; 
        char* ISBN; int price; int pages;
        char* IssuedBy; char* IssuedOn; char* ReturnDate;
    
        //Next and Previous pointer to keep track of the nodes in the List
        Node *next, *prev;


        //overloaded constructors
        Node(int ID=0, char* BookName=NULL, char* author=NULL, char* ISBN=NULL, int price=0, int pages=0, 
        char* IssuedBy=0, char* IssuedOn=NULL, char* ReturnDate=NULL)
        : next(NULL) , prev(NULL) {
            BookName = new char;
            author = new char;
            ISBN = new char;
            IssuedBy = new char;
            IssuedOn = new char;
            ReturnDate = new char;
            Node::ID = ID;
            Node::BookName = BookName;
            Node::author = author;
            Node::ISBN = ISBN;
            Node::price = price;
            Node::pages = pages;
            Node::IssuedBy = IssuedBy;
            Node::IssuedOn = IssuedOn;
            Node::ReturnDate = ReturnDate;
        }

        Node(const Node& obj){
            BookName = new char;
            author = new char;
            ISBN = new char;
            IssuedBy = new char;
            IssuedOn = new char;
            ReturnDate = new char;
            Node::ID = obj.ID; 
            Node::BookName = obj.BookName; 
            Node::author = obj.author; 
            Node::ISBN = obj.ISBN; 
            Node::price = obj.price; 
            Node::pages = obj.pages;
            Node::IssuedBy = obj.IssuedBy; 
            Node::IssuedOn = obj.IssuedOn; 
            Node::ReturnDate = obj.ReturnDate;
            Node::next = obj.next; 
            Node::prev = obj.prev;
        }

        Node(const Node* obj){
            BookName = new char;
            author = new char;
            ISBN = new char;
            IssuedBy = new char;
            IssuedOn = new char;
            ReturnDate = new char;
            Node::ID = obj->ID; 
            Node::BookName = obj->BookName; 
            Node::author = obj->author; 
            Node::ISBN = obj->ISBN; 
            Node::price = obj->price; 
            Node::pages = obj->pages;
            Node::IssuedBy = obj->IssuedBy; 
            Node::IssuedOn = obj->IssuedOn; 
            Node::ReturnDate = obj->ReturnDate;
            Node::next = obj->next; 
            Node::prev = obj->prev;
        }


        //ALL GETTERS
        int getID() {return Node::ID;} 
        char* getBookName() {return Node::BookName;} 
        char* getauthor() {return Node::author;} 
        char* getISBN() {return Node::ISBN;} 
        int getprice() {return Node::price;} 
        int getpages() {return Node::pages;} 
        char* getIssuedBy() {return Node::IssuedBy;} 
        char* getIssuedOn() {return Node::IssuedOn;} 
        char* getReturnDate() {return Node::ReturnDate;}


        //ALL SETTERS
        void setID(int& ID) {Node::ID = ID;} 
        void setBookName(char* BookName) {Node::BookName = BookName;} 
        void setauthor(char* author) {Node::author = author;} 
        void setISBN(char* ISBN) {Node::ISBN = ISBN;} 
        void setprice(int& price) {Node::price = price;} 
        void setpages(int& pages) {Node::pages = pages;} 
        void setIssuedBy(char* IssuedBy) {Node::IssuedBy = IssuedBy;} 
        void setIssuedOn(char* IssuedOn) {Node::IssuedOn = IssuedOn;} 
        void setReturnDate(char* ReturnDate) {Node::ReturnDate = ReturnDate;}
        void setAll(int ID, char* BookName, char* author, char* ISBN, int price, int pages, 
                    char* IssuedBy, char* IssuedOn, char* ReturnDate){
            Node::ID = ID;
            Node::BookName = BookName;
            Node::author = author;
            Node::ISBN = ISBN;
            Node::price = price;
            Node::pages = pages;
            Node::IssuedBy = IssuedBy;
            Node::IssuedOn = IssuedOn;
            Node::ReturnDate = ReturnDate;
        }
    };

    //head and tail pointer  //head = first Node       tail = Last Node
    //totalBooks is used to keep track of total Nodes
    Node *head, *tail;
    int totalBooks;


    public:

    //initialization
    CBook() : head(NULL) , tail(NULL) , totalBooks(0) {}


    //it will delete all the nodes made and free the memory at the end
    ~CBook(){
        totalBooks = 0;
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
        head = NULL;
        tail = NULL;
    }
    
    //Simply outputs all the Books
    void PrintAll(){
        Node *temp;
        temp = head;

        for(int i=0; i<totalBooks; i++){
            cout<<"\n\n\nBOOK ID: "<<temp->ID<<"\n\n\tBOOKNAME: "<<temp->BookName<<"\tAUTHOR: "<<temp->author
            <<"\tISBN: "<<temp->ISBN<<"\tPRICE: "<<temp->price<<"\tPAGES: "<<temp->pages
            <<"\n\n\tISSUED BY: "<<temp->IssuedBy<<"\tISSUED ON: "<<temp->IssuedOn<<"\tRETURN DATE: "<<temp->ReturnDate
            <<endl<<endl;
            temp = temp->next;
        }
    }


    //Prints a specific Book with a specific ID
    void PrintSome(int ID){
        Node *temp = head;
        bool found = false;

        //iterate through the List 
        for(int i=0; i<totalBooks; i++){
            if(temp->ID == ID){
                cout<<"\n\n\nBOOK ID: "<<temp->ID<<"\n\n\tBOOKNAME: "<<temp->BookName<<"\tAUTHOR: "<<temp->author
                <<"\tISBN: "<<temp->ISBN<<"\tPRICE: "<<temp->price<<"\tPAGES: "<<temp->pages
                <<"\n\n\tISSUED BY: "<<temp->IssuedBy<<"\tISSUED ON: "<<temp->IssuedOn<<"\tRETURN DATE: "<<temp->ReturnDate
                <<endl<<endl;
                found = true;
                return;
            }
            //Moves to next node
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nNOT FOUND\n\n";
        }
    }


    //there are two Add functions (overloaded)
    //It simply add a node (adds a new book)
    void Add(int ID, char* BookName, char* author, char* ISBN, int price, int pages, 
        char* IssuedBy, char* IssuedOn, char* ReturnDate){
        Node *temp;
        temp = new Node;

        Node *temp2 = head;
        for(int i=0; i<totalBooks; i++){
            if(temp2->ID == ID){
                cout<<"\n\nBOOK ID ALREADY EXISTS\n\n";
                return;
            }
            temp2 = temp2->next;
        }
        temp->ID = ID;
        temp->BookName = BookName; 
        temp->author = author;
        temp->ISBN = ISBN;
        temp->price = price;  
        temp->pages = pages; 
        temp->IssuedBy = IssuedBy; 
        temp->IssuedOn = IssuedOn;  
        temp->ReturnDate = ReturnDate;

        temp->next = NULL;

        //If the List is empty And the new node is going to be a head
        if(head==NULL){
            head = temp;
            tail = temp;
            temp->prev = NULL;
        }
        //If the List is not empty
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        totalBooks++;
        cout<<"\n\nNew Book Added\n\n";
    }

    //It copies all the book of object 1 to object 2
    void operator=(CBook& books){
        Node* temp1;
        Node* temp2;

        temp1 = this->head;
        temp2 = books.head;

        this->DeleteAll();

        int totalBooks2 = books.gettotalBooks();

        for(int i=0; i<totalBooks2; i++){
            
            this->Add(temp2->ID, temp2->BookName, temp2->author, temp2->ISBN, temp2->price, temp2->pages, 
                        temp2->IssuedBy, temp2->IssuedOn, temp2->ReturnDate);

            temp2 = temp2->next;
        }
    }

    //It copies all the Data of one Node to the Node which calls the function
    void Copy(CBook& book, int ID){
        bool found = false;
        Node *temp = book.gettail();

        //checks if the provided ID is present in the List
        while(temp){
            if(temp->ID == ID){
                found=true;
                break;
            }
            temp = temp->prev;
        }

        //if ID is present the it simply copies it to the node
        if (found==true){
            Add(temp->ID, temp->BookName, temp->author, temp->ISBN, temp->price, temp->pages, 
        temp->IssuedBy, temp->IssuedOn, temp->ReturnDate);
        }
        else{
            cout<<"\n\nNOT FOUND\n\n";
        }
    } 


    //overloaded 
    //It adds a new Node
    void Add(){
        Node *temp;
        temp = new Node;
        bool found = false;

        //this loops checks if the ID given by the user is already present in the List
        //Because the ID is unique in list 
        //if ID is already present in the List then it will ask the user to enter the ID again
        do{
            found = false;
            cout<<"\n\n\nBOOK ID: ";
            CERR(temp->ID);

            Node *temp2 = head;
            for(int i=0; i<totalBooks; i++){
                if(temp2->ID == temp->ID){
                    cout<<"\n\nBOOK ID ALREADY EXISTS\tTRY DIFFERENT ID\n\n";
                    found = true;
                    break;
                }
                temp2 = temp2->next;
            }
        }while(found);
        
        cout<<"\n\nBOOK NAME: ";
        CERR(temp->BookName);
        cout<<"\n\nAUTHOR: ";
        CERR(temp->author);
        cout<<"\n\nISBN: ";
        CERR(temp->ISBN);
        cout<<"\n\nPRICE: ";
        CERR(temp->price);
        cout<<"\n\nPAGES: ";
        CERR(temp->pages);
        cout<<"\n\nISSUED BY: ";
        CERR(temp->IssuedBy);
        cout<<"\n\nISSUED ON: ";
        CERR(temp->IssuedOn);
        cout<<"\n\nRETURN DATE: ";
        CERR(temp->ReturnDate);
        
        temp->next = NULL;
        //if the List is already Empty then the Node to be added will become head and tail both
        if(head==NULL){
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        //if the List is not empty
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        totalBooks++;
        cout<<"\n\nNew Book Added\n\n";
    }


    //Sort the Books with respect to the ID in Ascending order
    void Sort_A(){
        //If there is only one Node then there is not need to sort it
        if(totalBooks==1){
            return;
        }

        //declare all the variables 
        //the nodes will remain at the same position that is the next and previous addresses will not change
        //only the data will be changed from one node to other

        int ID; char* BookName; char* author; char* ISBN; int price; int pages; 
        char* IssuedBy; char* IssuedOn; char* ReturnDate;
        BookName = new char;
        author = new char;
        ISBN = new char;
        IssuedBy = new char;
        IssuedOn = new char;
        ReturnDate = new char;

        Node *temp1;
        Node *temp2;
        
        //compare two nodes ID using Bubble sort Algorithm
        //if they are in wrong order then swap the data in them
        for(int i=0; i<totalBooks-1; i++){
            temp1 = head;
            temp2 = head->next;
            
            for(int j=0; j<totalBooks-1; j++){
                if(j > 0)
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                
                if(temp1->ID > temp2->ID){
                    ID = temp2->ID;
                    BookName = temp2->BookName;
                    author = temp2->author;
                    ISBN = temp2->ISBN;
                    price = temp2->price;
                    pages = temp2->pages;
                    IssuedBy = temp2->IssuedBy;
                    IssuedOn = temp2->IssuedOn;
                    ReturnDate = temp2->ReturnDate;

                    temp2->setAll(temp1->ID, temp1->BookName, temp1->author, temp1->ISBN, temp1->price, temp1->pages,
                    temp1->IssuedBy, temp1->IssuedOn, temp1->ReturnDate);

                    temp1->ID = ID;
                    temp1->BookName = BookName;
                    temp1->author = author;
                    temp1->ISBN = ISBN;
                    temp1->price = price;
                    temp1->pages = pages;
                    temp1->IssuedBy = IssuedBy;
                    temp1->IssuedOn = IssuedOn;
                    temp1->ReturnDate = ReturnDate; 
                }
            }    
        }
    }


    //Sort the Books with respect to the ID in Descending order
    //compare two nodes ID using Bubble sort Algorithm
    //if they are in wrong order then swap the data in them
    //same as above Sort_A() Function
    void Sort_D(){
        if(totalBooks==1){
            return;
        }
        int ID; char* BookName; char* author; char* ISBN; int price; int pages; 
        char* IssuedBy; char* IssuedOn; char* ReturnDate;
        BookName = new char;
        author = new char;
        ISBN = new char;
        IssuedBy = new char;
        IssuedOn = new char;
        ReturnDate = new char;

        Node *temp1;
        Node *temp2;
        
        for(int i=0; i<totalBooks-1; i++){

            temp1 = head;
            temp2 = head->next;
            
            for(int j=0; j<totalBooks-1; j++){
                if(j > 0)
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                
                if(temp1->ID < temp2->ID){
                    ID = temp2->ID;
                    BookName = temp2->BookName;
                    author = temp2->author;
                    ISBN = temp2->ISBN;
                    price = temp2->price;
                    pages = temp2->pages;
                    IssuedBy = temp2->IssuedBy;
                    IssuedOn = temp2->IssuedOn;
                    ReturnDate = temp2->ReturnDate;

                    temp2->setAll(temp1->ID, temp1->BookName, temp1->author, temp1->ISBN, temp1->price, temp1->pages,
                    temp1->IssuedBy, temp1->IssuedOn, temp1->ReturnDate);

                    temp1->ID = ID;
                    temp1->BookName = BookName;
                    temp1->author = author;
                    temp1->ISBN = ISBN;
                    temp1->price = price;
                    temp1->pages = pages;
                    temp1->IssuedBy = IssuedBy;
                    temp1->IssuedOn = IssuedOn;
                    temp1->ReturnDate = ReturnDate; 
                }
            }    
        }
    }

    void DeleteAll(){
        totalBooks = 0;
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
        head = NULL;
        tail = NULL;
    }

    void Delete(int ID){
        Node *temp = head;

        

        //Go through the List to get the Node for which the ID is equal to the Node ID
        for(int i=0; i<totalBooks; i++){
            if(temp->ID == ID){
                //if there is only one node
                //Then the head will be equal to tail
                if(head == tail){
                    delete temp;
                    head = NULL;
                    tail = NULL;
                    totalBooks = 0;
                    return;
                }

                //if the node to remove is the last node that is Tail
                //then change the tail to previous Node
                else if(temp->next == temp){
                    tail = temp->prev;
                    tail->next = temp->prev;
                }

                //If the node to remove is the head 
                //then change the head to the next node
                else if(temp->prev == NULL){
                    head = temp->next;
                    head->prev = NULL;
                }

                //if the node to remove is somewhere in the middle of the list
                else{
                    Node* tempPrev = temp->prev;
                    Node* tempNext = temp->next;
                    tempPrev->next = tempNext;
                    tempNext->prev = tempPrev;
                }

                totalBooks--;
                //delete the node which was just removed
                delete temp;
                cout<<"\n\nDeleted Successfully\n\n";
                return;
            }
            temp = temp->next;
        }
    }
    

    //All GETTER FUNCTIONS
    int gettotalBooks(){
        return CBook::totalBooks;
    }
    Node* gethead(){
        return head;
    }
    Node* gettail(){
        return tail;
    }
};


//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------


class CBookList{

    //This is indented List that is list is inside a list
    //books is a list and Now it is inside Node
    struct Node{
        CBook books; 
        int ListID;

        Node *next;
        Node *prev;

        //Constructors
        Node(CBook books, int ListID=0) :next(NULL), prev(NULL) {
            Node::books = books;
            Node::ListID = ListID;
        }

        Node() : ListID(0), next(NULL), prev(NULL) {}

        //All getters
        CBook getbooks() {return Node::books;} 
        int getListID() {return Node::ListID;}
        
        //All Setters
        CBook setbooks(CBook books) {Node::books = books;} 
        int setListID(int& ListID) {Node::ListID = ListID;}
    };

    Node *head, *tail;
    int totalLists;


    public:

    //destructor
    ~CBookList(){
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
    }

    //constructor
    CBookList() : totalLists(0) {
        head = NULL;
        tail = NULL;
    }


    void PrintAll(){
        Node* temp;
        temp = head;
        for(int i=0; i<totalLists; i++){
            cout<<"\n\n\n\t\t***** LIST ID: "<<temp->ListID<<" *****"<<endl<<endl<<endl;
            temp->Node::books.PrintAll();
            temp = temp->next;
        }
    }


    void PrintSome(int ListID){
        bool found = false;
        Node* temp;
        temp = head;
        //put head in temp and go through the list by comparing the ID
        for(int i=0; i<totalLists; i++){
            if(temp->ListID ==  ListID){
                temp->Node::books.PrintAll();
                found = true;
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nNOT FOUND\n\n";
        }
    }


    //It will sort all the list as well as books in it in ascending order
    void Sort_A(){
        Node *temp3;
        temp3 = new Node;

        
        Node *temp1;
        Node *temp2;
        
        for(int i=0; i<totalLists-1; i++){
            if(totalLists==1){
                break;
            }
            temp1 = head;
            temp2 = head->next;
            
            for(int j=0; j<totalLists-1; j++){
                if(j>0){
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }

                if((temp1->ListID > temp2->ListID)){
                    temp3->Node::ListID = temp2->Node::ListID;
                    temp3->Node::books = temp2->books;

                    temp2->Node::ListID = temp1->Node::ListID;
                    temp2->Node::books = temp1->books;

                    temp1->Node::ListID = temp3->Node::ListID;
                    temp1->Node::books = temp3->books;

                    system("cls");
                }
            }    
        }
        temp1 = head;
        for(int i=0; i<totalLists; i++){
            if(i>0)
                temp1 = temp1->next;
            temp1->Node::books.Sort_A();
        }
    }



    //It will sort all the list as well as books in it in descending order
    void Sort_D(){
        Node *temp3;
        temp3 = new Node;

        
        Node *temp1;
        Node *temp2;
        
        for(int i=0; i<totalLists-1; i++){
            if(totalLists==1){
                break;
            }
            temp1 = head;
            temp2 = head->next;
            
            for(int j=0; j<totalLists-1; j++){
                if(j>0){
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }

                if((temp1->ListID < temp2->ListID)){
                    temp3->Node::ListID = temp2->Node::ListID;
                    temp3->Node::books = temp2->books;

                    temp2->Node::ListID = temp1->Node::ListID;
                    temp2->Node::books = temp1->books;

                    temp1->Node::ListID = temp3->Node::ListID;
                    temp1->Node::books = temp3->books;

                    system("cls");
                }
            }    
        }
        temp1 = head;
        for(int i=0; i<totalLists; i++){
            if(i>0)
                temp1 = temp1->next;
            temp1->Node::books.Sort_A();
        }
    }


    void AddList(int ListID){
        Node* temp;
        temp = new Node;
        Node* temp2 = head;
        bool found = false;
        do{
            found = false;
            temp2 = head;
            for(int i=0; i<totalLists; i++){
                if(temp2->ListID ==  ListID){
                    found = true;
                    cout<<"\n\nLIST ID ALREADY EXISTS\tTRY AGAIN: ";
                    CERR(ListID);
                    break;
                }
                temp2 = temp2->next;
            }
        }while(found);

        temp->ListID = ListID;
        temp->next = NULL;
        if(head==NULL){
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        totalLists++;
        cout<<"\n\nNew List Added\n\n";
    }

    //This will add books to the List which you just made above
    void AddNode(int ListID){
        Node* temp;
        temp = new Node;
        temp = head;
        bool found = false;

        //First it will check if the List ID you just entered is present in the list
        //if yes it will add a new book
        //if not then it will add a new list and then add a new book
        while(found == false){
            for(int i=0; i<totalLists; i++){
                if(temp->ListID == ListID){
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if(found == true){
                temp->Node::books.Add();
                return;
            }
            else{
                cout<<"\n\nLIST ID NOT FOUND\n\n";
                cout<<"\n\nMAKING A NEW LIST FOR YOU\n\n";
                AddList(ListID);   
                temp = head;
            }
        }
    }

    //this will copy items of one Node to Another node
    bool Copy(int ListID_old, int ListID_new, int BookID){
        Node* temp_old = new Node;
        temp_old = head;
        Node* temp_new = new Node;
        temp_new = head;
        bool found1 = false;
        bool  found2 = false;
        for(int i=0; i<totalLists; i++){
            if(temp_old->ListID == ListID_old){
                found1 = true;
                break;
            }
            temp_old = temp_old->next;
        }
        for(int i=0; i<totalLists; i++){
            if(temp_new->ListID == ListID_new){
                found2 = true;
                break;
            }
            temp_new = temp_new->next;
        }
        //if both the list ID you entered are prsent then it will copy the old one to new
        if(found1==true && found2==true){
            temp_new->Node::books.Copy(temp_old->Node::books, BookID);
            return true;
        }
        else{
            if(found1==false && found2==true){
                cout<<"\n\nTHE LIST FROM WHICH YOU WANT TO DELETE THE ITEM NOT FOUND\n\n";
            }
            else if(found1==true && found2==false){
                cout<<"\n\nTHE LIST to WHICH YOU WANT TO MOVE THE ITEM NOT FOUND\n\n";
            }
            else if(found1==false && found2==false){
                cout<<"\n\nBOTH LISTS NOT FOUND\n\n";
            }
            return false;
        }
    }

    int gettotalLists(){
        return totalLists;
    }

    //Simply deletes a List an frees up memory
    void Delete(int ListID){
        Node *temp = head;

        bool found = false;
        for(int i=0; i<totalLists; i++){
            if(temp->ListID == ListID){
                found = true;
                //If the List has only one node
                if(tail==head){
                    delete temp;
                    tail = NULL;
                    head = NULL;
                    totalLists = 0;
                    return;
                }
                //if the node to delete is the tail
                else if(temp->next == temp){
                    tail = temp->prev;
                    tail->next = temp->prev;
                }
                //if the node is head
                else if(temp->prev == NULL){
                    head = temp->next;
                    head->prev = NULL;
                }
                //if the node is somewhere in between
                else{
                    Node* tempPrev = temp->prev;
                    Node* tempNext = temp->next;
                    tempPrev->next = tempNext;
                    tempNext->prev = tempPrev;
                }
                cout<<"\n\nSUCCESSFULLY DELETED\n\n";
                totalLists--;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nLIST ID NOT FOUND\n\n";
        }
    }

    //this wil delete a specific book inside a list
    void DeleteNode(int ListID, int BookID){
        Node *temp = head;
        bool found = false;
        for(int i=0; i<totalLists; i++){
            if(temp->ListID == ListID){
                found = true;
                temp->Node::books.Delete(BookID);
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nLIST ID NOT FOUND\n\n";
        }
    }


    //Simply deletes all the lists and free up memeory
    void DeleteAll(){
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
        cout<<"\n\nDeleted Successfully\n\n";
        totalLists = 0;
    }

};


//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------


class CStudent{
    struct Node{
        int ID; char* StdName; 
        int RollNo; int BooksIssued;

        Node* next, *prev;

        //Constructor
        Node(): ID(0), RollNo(0), BooksIssued(0), next(NULL), prev(NULL) {
            StdName = new char;
        }

        //ALL GETTERS
        int getID() {return Node::ID;} 
        char* getStdName() {return Node::StdName;} 
        int getRollNo() {return Node::RollNo;} 
        int getBooksIssued() {return Node::BooksIssued;}


        //ALL SETTERS
        void setID(int ID) {Node::ID = ID;} 
        void setStdName(char* StdName) {Node::StdName = StdName;} 
        void setRollNo(int RollNo) {Node::RollNo = RollNo;} 
        void setBooksIssued(int BooksIssued) {Node::BooksIssued = BooksIssued;}
    };

    Node* head, *tail;
    int totalStudents;


    public:

    //constructor
    CStudent() : head(NULL), tail(NULL), totalStudents(0) {}


    //destructor
    ~CStudent(){
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
    }

    //ALL GETTERS
    int getBooksIssued() {
        return head->Node::BooksIssued;
    }
    void setBooksIssued(int BooksIssued) {
        head->Node::BooksIssued = BooksIssued;
    }
    int getStudentID(){
        return head->Node::ID;
    }

    //PRINTS ALL THE STUDENTS
    void PrintAll(){
        Node *temp;
        temp = head;

        for(int i=0; i<totalStudents; i++){
            cout<<"\n\n\nSTUDENT ID: "<<temp->ID<<"\n\n\tSTUDENT NAME: "<<temp->StdName<<"\tROLL NO: "<<temp->RollNo
                <<"\tBOOKS ISSUED: "<<temp->BooksIssued
                <<endl<<endl;
            temp = temp->next;
        }
    }


    //Prints a student with a specific ID
    void PrintSome(int ID){
        Node *temp = head;
        bool found = false;
        for(int i=0; i<totalStudents; i++){
            if(temp->ID == ID){
                found = true;
                cout<<"\n\n\nSTUDENT ID: "<<temp->ID<<"\n\n\tSTUDENT NAME: "<<temp->StdName<<"\tROLL NO: "<<temp->RollNo
                    <<"\tBOOKS ISSUED: "<<temp->BooksIssued
                    <<endl<<endl;
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nSTUDENT ID NOT FOUND\n\n";
        }
        return;
    }

    //Adds a student in the list
    void Add(int ID, char* StdName, int RollNo, int BooksIssued){
        Node *temp;
        temp = new Node;
        bool found = false;
        Node *temp2;
        //check if the given ID is already present then it will ask the user to enter a different ID
        do{
            found = false;
            temp2 = head;
            for(int i=0; i<totalStudents; i++){
                if(temp2->ID == ID){
                    cout<<"\n\nSUDENT ID ALREADY EXISTS\tTRY DIFFERENT ID\n\n";
                    CERR(ID);
                    found = true;
                    break;
                }
                temp2 = temp2->next;
            }
        }while(found);
        temp->ID = ID;
        temp->StdName = StdName; 
        temp->RollNo = RollNo;
        temp->BooksIssued = BooksIssued;
       
        temp->next = NULL;
        if(head==NULL){
            head = temp;
            tail = temp;
            temp->prev = NULL;
        }
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        totalStudents++;
        cout<<"\n\nNew Student Added\n\n";
    }

    //Overloaded Add function 
    void Add(int StudentId=0){
        Node *temp;
        temp = new Node;
        bool found = false;
        Node *temp2;

        //check if the given ID is already present then it will ask the user to enter a different ID
        if(StudentId==0){
            do{
                found = false;
                temp2 = head;
                cout<<"\n\n\nSTUDENT ID: ";
                CERR(temp->ID);
                for(int i=0; i<totalStudents; i++){
                    if(temp2->ID == temp->ID){
                        cout<<"\n\nSUDENT ID ALREADY EXISTS\tTRY DIFFERENT ID\n\n";
                        found = true;
                        break;
                    }
                    temp2 = temp2->next;
                }
            }while(found);
        }
        else{
            temp->ID = StudentId;
        }
        
        cout<<"\n\nSTUDENT NAME: ";
        CERR(temp->StdName);
        cout<<"\n\nROLL NO: ";
        CERR(temp->RollNo);
        do{
            cout<<"\n\nBOOKS ISSUED: ";
            CERR(temp->BooksIssued);
            if(temp->BooksIssued>5){
                cout<<"\n\nYou cannot issue more than 5 books at a time\n\n";
            }
        }while(temp->BooksIssued>5);

        temp->next = NULL;
        //if the student to be added in the list is first then the node will become head as well as tail
        if(head==NULL){
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        //if some students are already present in list 
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        totalStudents++;
        cout<<"\n\nNew Student Added\n\n";
    }


    //Simply deletes a student in the list 
    void Delete(int ID){
        Node *temp = head;

        int found = false;
        for(int i=0; i<totalStudents; i++){
            
            if(temp->ID == ID){
                found = true;
                //if only one student is present in the the list 
                if(head == tail){
                    delete temp;
                    head = NULL;
                    tail = NULL;
                    totalStudents = 0;
                    return;
                }
                //if the node to be deleted is the tail
                else if(temp->next == temp){
                    tail = temp->prev;
                    tail->next = temp->prev;
                }
                //if the node to be deleted is the head
                else if(temp->prev == NULL){
                    head = temp->next;
                    head->prev = NULL;
                }
                // if the node is somewhere in between 
                else{
                    Node* tempPrev = temp->prev;
                    Node* tempNext = temp->next;
                    tempPrev->next = tempNext;
                    tempNext->prev = tempPrev;
                }
                totalStudents--;
                delete temp;
                cout<<"\n\nSUCCESSFULLY DELETED\n\n";
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nSTUDENT ID NOT FOUND\n\n";
        }
    }

    int gettotalStudents(){
        return totalStudents;
    }
};


//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------


class CStudentList{
    struct Node{
        CStudent std;
        int ListID;

        Node *next, *prev;

        //Constructor
        Node() : ListID(0), next(NULL), prev(NULL) {}

        //ALL GETTERS
        CStudent getstd(){
            return std;
        }
        int getListID(){
            return ListID;
        }

        //ALL SETTERS
        void setListID(int ListID){
            Node::ListID = ListID;
        }
    };

    Node *head, *tail;
    int totalLists;
    
    
    public:

    //constructor
    CStudentList() : head(NULL), tail(NULL), totalLists(0) {} 


    //destructor which will simply free up the memory at the end
    ~CStudentList(){
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
    }

    //it will print all the lists along with the students in those lists
    void PrintAll(){
        Node* temp;
        temp = head;
        for(int i=0; i<totalLists; i++){
            cout<<"\n\n\t\t***** LIST ID: "<<temp->ListID<<" *****"<<endl<<endl;
            temp->Node::std.PrintAll();
            temp = temp->next;
        }
    }


    //Print a specific List along with the students in that list
    void PrintSome(int ListID){
        Node* temp;
        temp = head;
        bool found = false;
        for(int i=0; i<totalLists; i++){
            if(temp->ListID ==  ListID){
                found = true;
                temp->Node::std.PrintAll();
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nLIST ID NOT FOUND\n\n";
        }
    }


    //Adds a new List only not the students
    void AddList(int ListID){
        Node* temp2 = head;
        bool found = false;
        do{
            found = false;
            for(int i=0; i<totalLists; i++){
                if(temp2->ListID ==  ListID){
                    found = true;
                    cout<<"\n\nLIST ID ALREADY EXIST\tTRY ANOTHER ID: ";
                    CERR(ListID);
                    break;
                }
                temp2 = temp2->next;
            }
        }while(found);
        Node* temp;
        temp = new Node;
        temp->ListID = ListID;
        temp->next = NULL;
        if(head==NULL){
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        cout<<"\n\nNew List Added\n\n";
        totalLists++;
    }

    //Adds new student in the list
    void AddNode(int ListID){
        Node* temp;
        temp = head;
        bool found = false;

        //checks if the list ID is already present
        //if yes it will add a new student in that list
        //if not it will create a new list and then add the student
        while(found == false){
            for(int i=0; i<totalLists; i++){
                if(temp->ListID == ListID){
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if(found == true){
                temp->Node::std.Add();
                return;
            }
            else{
                cout<<"\n\nLIST ID NOT FOUND\n\n";
                cout<<"\n\nADDING NEW LIST FOR YOU\n\n";
                AddList(ListID);
                temp = head;
            }
        }
        return;
    }

    //deletes a complete list along with the students
    void Delete(int ListID){
        Node *temp = head;
        
        bool found = false;
        for(int i=0; i<totalLists; i++){
            if(temp->ListID == ListID){
                found = true;
                if(head == tail){
                    delete temp;
                    head = NULL;
                    tail = NULL;
                    totalLists = 0;
                    return;
                }
                else if(temp->next == temp){
                    tail = temp->prev;
                    tail->next = temp->prev;
                }
                else if(temp->prev == NULL){
                    head = temp->next;
                    head->prev = NULL;
                }
                else{
                    Node* tempPrev = temp->prev;
                    Node* tempNext = temp->next;
                    tempPrev->next = tempNext;
                    tempNext->prev = tempPrev;
                }
                totalLists--;
                cout<<"\n\nList Deleted Successfully\n\n";
                delete temp;
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nLIST ID NOT FOUND\n\n";
        }
    }

    //deletes a student in the specific list
    void DeleteNode(int ListID, int StudentID){
        Node *temp = head;
        bool found = false;
        for(int i=0; i<totalLists; i++){
            if(temp->ListID == ListID){
                found = true;
                temp->Node::std.Delete(StudentID);
                return;
            }
            temp = temp->next;
        }
        if(found == false){
            cout<<"\n\nLIST ID NOT FOUND\n\n";
        }
    }


    //deletes all the lists
    void DeleteAll(){
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
        cout<<"\n\nDeleted Successfully\n\n";
        totalLists = 0;
    }

};


//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------


class CLibrary{

    struct Node{
        CBook books; 
        CStudent std;

        Node* next, *prev;

        //constructor
        Node() :  next(NULL), prev(NULL) {}
    };

    Node* head, *tail;
    int total;

    public:

    //destructor
    CLibrary() : total(0), head(NULL), tail(NULL) {}

    //destructor
    ~CLibrary(){
        Node *tmp;
	    while(tail){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
	    }
    }


    void Issue(int StudentID){
        //if the student has already issued some books then it will add another book to the same student ID
        Node* temp;
        temp = head;
        int ID;
        int BooksIssued;
        int newBooksIssued;
        int oldBooksIssued;
        for(int i=0; i<total; i++){
            ID = temp->Node::std.getStudentID();
            if(StudentID == ID){
                oldBooksIssued = temp->Node::std.getBooksIssued(); 
                cout<<"\n\nENTER THE TOTAL BOOKS YOU WANT TO ISSUE: ";
                CERR(BooksIssued);
                cout<<"\n\nNOW ENTER ALL THE DATA ABOUT THE BOOKS YOU JUST ISSUED\n\n";
                newBooksIssued = BooksIssued + oldBooksIssued;
                temp->Node::std.setBooksIssued(newBooksIssued);
                for(int j=0; j<BooksIssued; j++){
                    cout<<"\n\n\n\t\t\tBOOK #"<<j+1<<"\n";
                    temp->Node::books.Add();
                }
                return;
            }
            temp = temp->next;
        }
        //If the student has issued a book for the first time then it will add a new Student to list and issue the 
        //book
        temp = new Node;
        temp->Node::std.Add(StudentID);
        BooksIssued = temp->Node::std.getBooksIssued();
        cout<<"\n\nNOW ENTER ALL THE DATA ABOUT THE BOOKS YOU JUST ISSUED\n\n";
        for(int j=0; j<BooksIssued; j++){
            cout<<"\n\n\n\t\t\tBOOK #"<<j+1<<"\n";
            temp->Node::books.Add();
        }
        temp->next = NULL;
        if(head==NULL){
            head = temp;
            tail = temp;
            head->prev = NULL;
        }
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        total++;
    }


    //it will delete the specific book from the student record 
    void Return(int StudentID){
        Node* temp;
        temp = head;
        int SID, BID;
        for(int i=0; i<total; i++){
            SID = temp->Node::std.getStudentID();
            if(StudentID == SID){
                temp->Node::books.PrintAll();
                cout<<"\n\nEnter Book ID which you want to return: ";
                CERR(BID);
                temp->Node::books.Delete(BID);
                cout<<"\n\nBOOK RETURNED SUCCESSFULLY\n\n";
                return;
            }
            temp = temp->next;
        }
    }

    // This Function is used to print all the books issued against a specific student
    void Print(int StudentID){
        Node* temp;
        temp = head;
        int ID;
        for(int i=0; i<total; i++){
            ID = temp->Node::std.getStudentID();
            if(StudentID == ID){
                temp->Node::std.PrintAll();
                temp->Node::books.PrintAll();
                return;
            }
            temp = temp->next;
        }
    }

    //Prints all the books which were issued by all the students
    void PrintIssued(){
        Node* temp;
        temp = head;
        for(int i=0; i<total; i++){
            temp->Node::books.PrintAll();
            temp = temp->next;
        }
    }
};
