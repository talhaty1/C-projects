//                  MADE BY TALHA YUNUS (2020497)

#include <iostream>
#include <cstring>
#include <windows.h>
#include "LIBRARY.h"
using namespace std;


int main(){
    CBook Book;
    CBookList List;
    CStudent Std;
    CLibrary Library;
    int BookID, ListID, StudentID;
    int choice;
    int option = 0;
    do{
        cout<<"\n\t______________________________\n"
            <<"\t|                            |\n"
            <<"\t|         1. Student.        |\n"
            <<"\t|                            |\n"
            <<"\t|         2. Book.           |\n"
            <<"\t|                            |\n"
            <<"\t|         3. List.           |\n"
            <<"\t|                            |\n"
            <<"\t|         4. Library.        |\n"
            <<"\t|                            |\n"
            <<"\t|         5. Exit            |\n"
            <<"\t|                            |\n"
            <<"\t------------------------------\n"
            <<"\n\nENTER YOUR CHOICE: ";
        CERR(choice);

        do{
            system("pause");
            system("cls");
            if(choice == 1){
                cout<<"\n\n\t\t\tStudent Sub-Menu\n\n";
                cout<<"\n\t_____________________________________________\n"
                    <<"\t|                                            |\n"
                    <<"\t|         1. Add New Student.                |\n"
                    <<"\t|                                            |\n"
                    <<"\t|         2. Delete Existing Student.        |\n"
                    <<"\t|                                            |\n"
                    <<"\t|         3. Show particular student.        |\n"
                    <<"\t|                                            |\n"
                    <<"\t|         4. Show all Students.              |\n"
                    <<"\t|                                            |\n"
                    <<"\t|         0. Back                            |\n"
                    <<"\t|                                            |\n"
                    <<"\t----------------------------------------------\n"
                    <<"\n\nENTER YOUR CHOICE: ";
                CERR(option);

                switch(option){
                    case 1:
                        Std.Add();
                        break;
                    case 2:
                        cout<<"\n\nEnter Student ID: ";
                        CERR(StudentID);
                        Std.Delete(StudentID);
                        break;
                    case 3:
                        cout<<"\n\nEnter Student ID: ";
                        CERR(StudentID);
                        Std.PrintSome(StudentID);
                        break;
                    case 4:
                        Std.PrintAll();
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"\n\nEnter correct option!!! TRY AGAIN\n";
                }
            }
            else if(choice == 2){
                cout<<"\n\n\t\t\tBook Sub-Menu\n\n";
                cout<<"\n\t_________________________________________________\n"
                    <<"\t|                                                |\n"
                    <<"\t|         1. Add New Book.                       |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         2. Delete Existing Book                |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         3. Show particular Book.               |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         4. Show all Books.                     |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         5. Sort Books in Ascending order.      |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         6. Sort Books in Descending order      |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         0. Back                                |\n"
                    <<"\t|                                                |\n"
                    <<"\t--------------------------------------------------\n"
                    <<"\n\nENTER YOUR CHOICE: ";
                CERR(option);

                switch(option){
                    case 1:
                        Book.Add();
                        break;
                    case 2:
                        cout<<"\n\nEnter Book ID: ";
                        CERR(BookID);
                        Book.Delete(BookID);
                        break;
                    case 3:
                        cout<<"\n\nEnter Book ID: ";
                        CERR(BookID);
                        Book.PrintSome(BookID);
                        break;
                    case 4:
                        Book.PrintAll();
                        break;
                    case 5:
                        Book.Sort_A();
                        cout<<"\n\nSoted !\n\n";
                        break;
                    case 6:
                        Book.Sort_D();
                        cout<<"\n\nSoted !\n\n";
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"\n\nEnter correct option!!! TRY AGAIN\n\n";
                }
            }
            else if(choice == 3){
                cout<<"\n\n\t\t\tList Sub-Menu\n\n";
                cout<<"\n\t_________________________________________________\n"
                    <<"\t|                                                |\n"
                    <<"\t|         1. Add New List.                       |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         2. Add New Node.                       |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         3. Delete Existing List.               |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         4. Show particular List.               |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         5. Show all Books.                     |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         6. Delete book from list and           |\n"
                    <<"\t|            assign book to another list.        |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         7. Sort List in Ascending order        |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         8. Sort List in Descending order       |\n"
                    <<"\t|                                                |\n"
                    <<"\t|         0. Back                                |\n"
                    <<"\t|                                                |\n"
                    <<"\t--------------------------------------------------\n"
                    <<"\n\nENTER YOUR CHOICE: ";
                CERR(option);
                switch(option){
                    case 1:
                        cout<<"\n\nEnter List ID: ";
                        CERR(ListID);
                        List.AddList(ListID);
                        break;
                    case 2:
                        cout<<"\n\nEnter List ID: ";
                        CERR(ListID);
                        List.AddNode(ListID);
                        break;
                    case 3:
                        cout<<"\n\nEnter List ID: ";
                        CERR(ListID);
                        List.Delete(ListID);
                        break;
                    case 4:
                        cout<<"\n\nEnter List ID: ";
                        CERR(ListID);
                        List.PrintSome(ListID);
                        break;
                    case 5:
                        List.PrintAll();
                        break;
                    case 6:
                        int ListIDnew;
                        bool found;
                        cout<<"\n\nEnter List ID from which you want to delete a book: ";
                        CERR(ListID);
                        cout<<"\n\nEnter Book ID: ";
                        CERR(BookID);
                        cout<<"\n\nEnter new List ID: ";
                        CERR(ListIDnew);
                        found = List.Copy(ListID, ListIDnew, BookID);
                        if(found==true)
                            List.DeleteNode(ListID, BookID);
                        break;
                    case 7:
                        List.Sort_A();
                        cout<<"\n\nSorted Successfully\n\n";
                        break;
                    case 8:
                    List.Sort_D();
                    cout<<"\n\nSorted Successfully\n\n";
                    break;
                    case 0:
                        break;
                    default:
                        cout<<"\n\nEnter correct option!!! TRY AGAIN\n\n";
                }
            }
            else if(choice == 4){
                 cout<<"\n\n\t\t\t\tLibrary Sub-Menu\n\n";
                cout<<"\n\t___________________________________________________________\n"
                    <<"\t|                                                          |\n"
                    <<"\t|         1. Issue a book.                                 |\n"
                    <<"\t|                                                          |\n"
                    <<"\t|         2. Return a book.                                |\n"
                    <<"\t|                                                          |\n"
                    <<"\t|         3. Print which books have been issued.           |\n"
                    <<"\t|                                                          |\n"
                    <<"\t|         4. Print the books issued by a specific Student. |\n"
                    <<"\t|                                                          |\n"
                    <<"\t|         0. Back                                          |\n"
                    <<"\t|                                                          |\n"
                    <<"\t------------------------------------------------------------\n"
                    <<"\n\nENTER YOUR CHOICE: ";
                CERR(option);
                switch(option){
                    case 1:
                        cout<<"\n\nEnter Student ID: ";
                        CERR(StudentID);
                        Library.Issue(StudentID);
                        break;
                    case 2:
                        cout<<"\n\nEnter Student ID: ";
                        CERR(StudentID);
                        Library.Return(StudentID);
                        break;
                    case 3:
                        Library.PrintIssued();
                        break;
                    case 4:
                        cout<<"\n\nEnter Student ID: ";
                        CERR(StudentID);
                        Library.Print(StudentID);
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"\n\nEnter correct option!!! TRY AGAIN\n\n";
                }
            }

        } while(option);
        system("pause");
        system("cls");
    } while(choice!=5);
}