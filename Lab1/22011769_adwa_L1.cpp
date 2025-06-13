

/*
ID: 22011769
NAME: NUR ADWA NAYLI BINTI ZULKAINI
*/





#include <iostream>
using namespace std;

int main()
{
    struct Student{
        int id;
        string name;
        int contact;
        string email;
    };
    
    Student students[5];
    for (int i=0; i<5; i++){
        cout<< "enter id: ";
        cin>> students[i].id;
        
        cout<<"enter name: ";
        cin>> students[i].name;
        
        cout<<"contact: ";
        cin>>students[i].contact;
        
        cout<< "enter email: ";
        cin>> students[i].email;
        
        cout<<"************************************";
        
        cout<<"\n\n"<< "Student "<< i+1 << "\n"<< "ID: "<< students[i].id <<"\n" <<
        "NAME: "<< students[i].name<<"\n"<<"CONTACT: "<< students[i].contact<<"\n" 
        << "EMAIL: "<< students[i].email<< "\n\n";
        
        cout<<"************************************\n\n";
        
    }
};
    
    // Student s1;
    
    // s1.id=22011769;
    // s1.name= "adwa";
    // s1.contact= 016333;
    // s1.email= "yada@gmail.com";
    
    // cout<< "name is "<< s1.name;
