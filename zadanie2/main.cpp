// lekcja_2
// zadanie_2
#include <iostream>
#include <fstream>
using namespace std;
struct Movies
{
    string title;
    int data;
};
Movies *list;

void get_and_show_list();

int main() {

    get_and_show_list();
    delete[] list;

    return 0;
}

void get_and_show_list(){
    fstream file;
    file.open("movies.txt",ios::in);

    if (file.is_open()) {
        string line, title;
        int date, i=0;
        while (getline(file, line)){
            i++;
        }
        file.clear();
        file.seekg(0, std::ios::beg);
        list=new Movies[i];
        i=0;
        while (getline(file, line)) {
            int len = line.length();
            title = line.substr(0,len-5);
            date = stoi(line.substr(len-5,len-1));
            list[i].title=title;
            list[i].data=date;
            cout<< list[i].title<<" ";
            cout<<list[i].data<<endl;
            i++;
        }
        file.close();
    }
}
