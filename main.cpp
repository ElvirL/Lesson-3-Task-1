/*
1. Ведомость учёта
Что нужно сделать
Вы уже создавали программу чтения и записи ведомости. Теперь её нужно обобщить и дополнить использованием структур.
Формат ведомости прежний:
• сначала — имя и фамилия получателя денег,
• далее — дата выдачи в формате ДД.ММ.ГГГГ,
• затем — сумма выплаты в рублях.
Данные разделяются пробелами. В конце каждой записи должен быть перевод строки. Структура данных должна соответствовать этому формату.

При старте программы пользователь отправляет команду: list или add. Команда list осуществляет чтение из файла ведомости, как и прежде, 
только уже в структуры данных, и отображает их на экране.
Команда add добавляет новую запись в конец ведомости.

Советы и рекомендации
• Чтобы определить, где заканчивается файл, используйте функцию file.eof().
• Из-за завершающего переноса строки при чтении данных из файла стоит отдельно прочитать имя получателя денег. 
Если после чтения имени получателя денег признак file.eof() принял значение true, значит, файл закончился.
• Используйте вектор структур. Для выбора команды потребуется подобная конструкция:

if (command == "list")
{
…
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
        cout << "Файл не открыт" << endl;
    }
    file.close();
}

void add_new_person(person* p){
    ofstream file("salary.txt", ios::app);
    if (file.is_open()){
        file << p->name << " " << p->surname << " " << p->date << " " << p->salary << endl;
    }
    else {
        cout << "Файл не открыт"<< endl;
    }

    file.close();
}

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Введите команду list или add: ";
    string command;
    cin >> command;
    while (command != "list" && command != "add"){
        cout << "Введите команду list или add: ";
        cin >> command;
    }

    if (command == "list"){
        print_salary();
    }
    else {
        person p;
        cout << "Введите имя: ";
        string name;
        cin >> name;
        p.name = name;

        cout << "Введите фамилию: ";
        string surname;
        cin >> surname;
        p.surname = surname;

        cout << "Введите дату: ";
        string date;
        cin >> date;
        p.date = date;

        cout << "Введите зарплату: ";
        int salary;
        cin >> salary;
        p.salary = salary;

        add_new_person(&p);
    }
}