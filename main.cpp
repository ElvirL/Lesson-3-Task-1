/*
1. ��������� �����
��� ����� �������
�� ��� ��������� ��������� ������ � ������ ���������. ������ � ����� �������� � ��������� �������������� ��������.
������ ��������� �������:
� ������� � ��� � ������� ���������� �����,
� ����� � ���� ������ � ������� ��.��.����,
� ����� � ����� ������� � ������.
������ ����������� ���������. � ����� ������ ������ ������ ���� ������� ������. ��������� ������ ������ ��������������� ����� �������.

��� ������ ��������� ������������ ���������� �������: list ��� add. ������� list ������������ ������ �� ����� ���������, ��� � ������, 
������ ��� � ��������� ������, � ���������� �� �� ������.
������� add ��������� ����� ������ � ����� ���������.

������ � ������������
� ����� ����������, ��� ������������� ����, ����������� ������� file.eof().
� ��-�� ������������ �������� ������ ��� ������ ������ �� ����� ����� �������� ��������� ��� ���������� �����. 
���� ����� ������ ����� ���������� ����� ������� file.eof() ������ �������� true, ������, ���� ����������.
� ����������� ������ ��������. ��� ������ ������� ����������� �������� �����������:

if (command == "list")
{
�
}
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct person
{
    string name;
    string surname;
    string date;
    int salary;
};

void print_salary(){
    ifstream file("salary.txt");
    if (file.is_open()){
        while (!file.eof()){
            string s;
            getline(file,s);
            cout << s << endl;

        }
    }
    else {
        cout << "���� �� ������" << endl;
    }
    file.close();
}

void add_new_person(person* p){
    ofstream file("salary.txt", ios::app);
    if (file.is_open()){
        file << p->name << " " << p->surname << " " << p->date << " " << p->salary << endl;
    }
    else {
        cout << "���� �� ������"<< endl;
    }

    file.close();
}

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "������� ������� list ��� add: ";
    string command;
    cin >> command;
    while (command != "list" && command != "add"){
        cout << "������� ������� list ��� add: ";
        cin >> command;
    }

    if (command == "list"){
        print_salary();
    }
    else {
        person p;
        cout << "������� ���: ";
        string name;
        cin >> name;
        p.name = name;

        cout << "������� �������: ";
        string surname;
        cin >> surname;
        p.surname = surname;

        cout << "������� ����: ";
        string date;
        cin >> date;
        p.date = date;

        cout << "������� ��������: ";
        int salary;
        cin >> salary;
        p.salary = salary;

        add_new_person(&p);
    }
}