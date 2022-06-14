// C_task_6v2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <string>
#include <list>
#include <vector>

using namespace std;

//template <class MyStruct, class Alloc = allocator<MyStruct>> class list;

struct MyStruct
{
    string name = " ";
    int age = 0;
    char gender = ' ';
    int ID = -1;

    void PrintAll()
    {
        cout << "ID: ";
        cout << ID;
        cout << "; Name: ";
        cout << name;
        cout << "; Age: ";
        cout << age;
        cout << "; Gender: ";
        cout << gender << endl;
    }
};

int main()
{

    //const int n = 3;
    string command;
    //MyStruct* arrStruct = new MyStruct[10];
    list<MyStruct> myList;
   
    char cmd = 's';
    int lastElement = -1;
    for (bool a = true; a;)
    {
        cout << "Enter command: ";
        cin >> command;
        //if (command != "-add" ) { continue; }
        if (command == "-add") cmd = 'a';
        if (command == "-printAll") cmd = 'p';
        if (command == "-print") cmd = 'i';
        if (command == "-delete") cmd = 'd';
        if (command == "-exit") cmd = 'e';
        switch (cmd)
        {
        case 'a':
        {
            MyStruct newStruct;

            cout << "Enter name: ";
            cin >> newStruct.name;
            cout << "Age: ";
            cin >> newStruct.age;
            cout << "Gender: ";
            cin >> newStruct.gender;

            newStruct.ID = lastElement + 1;

            //arrStruct[lastElement + 1] = newStruct;
            myList.push_back(newStruct);
            lastElement++;
        }
        break;
        case 'p':
        {
            MyStruct someStruct;
            for (list<MyStruct>::iterator it = myList.begin(); it != myList.end(); it++)
            {
                //arrStruct[i].PrintAll();
                someStruct = *it;
                someStruct.PrintAll();
            }
        }
        break;
        case 'd':
        {
            MyStruct clearedStruct;
            int id;
            cout << "Enter the index of struct: ";
            cin >> id;
            MyStruct someStruct;

            list<MyStruct>::iterator it = myList.begin();
            
            for (; it != myList.end(); it++)
            {

                someStruct = *it;
                if (someStruct.ID == id) {
                    break;
                }
            }

            myList.erase(it);
            //arrStruct[id] = clearedStruct;

        }
        break;
        case 'e':
        {
            a = false;
        }
        break;
        case 'i':
        {
            int id;
            cout << "Enter ID to print: ";
            cin >> id;
            MyStruct someStruct;

            list<MyStruct>::iterator it = myList.begin();

            for (; it != myList.end(); it++)
            {

                someStruct = *it;
                if (someStruct.ID == id) {
                    break;
                }
            }

            someStruct.PrintAll();

            //arrStruct[id].PrintAll();
        }
        break;
        }
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
