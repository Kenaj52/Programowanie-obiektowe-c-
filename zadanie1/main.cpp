// lekcja_2
// zadanie_1

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

struct Student
{
public:
    string name;
    string surname;
    int number;
};
Student *group;
int l;
void get_students();
void uppercase();
void check_number(int);
void show_students();
void save_list();

int main() {
    cout<<"Podaj liczbe studentow: ";
    cin>>l;
    group=new Student[l];
    get_students();
    uppercase();
    show_students();
    save_list();
    delete[] group;
    return 0;
}

void get_students(){
    string name;
    string surname;
    int number;

    for(int i=0;i<l;i++){
        cout<<"Podaj kolejno imie nazwisko i numer albumu: "<<endl;
        cin>>name>>surname>>number;
        group[i].number=number;
        group[i].name=name;
        group[i].surname=surname;
       if(number<100000 || number>999999){
           check_number(i);
       }
    }
}

void uppercase(){
    for(int i=0;i<l;i++) {
        group[i].name[0] = toupper( group[i].name[0]);
        group[i].surname[0] = toupper(group[i].surname[0]);
    }
}
void check_number(int i){
    do{
        cout<<"Numer jest za krotki lub za długi powinien zawierac 6 cyfr."<<endl<<"Podaj jeszcze raz poprawny numer: ";
        cin>>group[i].number;
    }while(group[i].number<100000 || group[i].number>999999);
}
void show_students(){
    for(int i=0;i<l;i++) {
        cout << group[i].name << " ";
        cout << group[i].surname << " ";
        cout << group[i].number << " ";
        cout <<endl;
    }
}
void save_list(){
    fstream file;
    file.open("students.txt",ios::out);

    for(int i=0;i<l;i++) {
        file << group[i].name << " ";
        file << group[i].surname << " ";
        file << group[i].number << " ";
        file <<endl;
    }
    file.close();
}