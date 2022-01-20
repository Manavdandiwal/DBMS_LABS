#include <iostream>
#include <vector>
#include <string>
#include "getch.h"
#include "book.h"
#include "Student.h"
#include "issued.h"
using namespace std;

extern vector<pair<int, student>> student_data;
extern vector<pair<int, book>> books;
extern vector<pair<pair<int, int>, issue>> issue_record;

void read_from_files()
{
    bool flag = true;
    ifstream file("Student_info.txt");
    while (flag)
    {
        student tmp(file, flag);
        if (flag)
            student_data.push_back(make_pair(tmp.get_id(), tmp));
    }
    file.close();
    flag = true;
    file.open("Books_info.txt");
    while (flag)
    {
        book tmp(file, flag);
        if (flag)
            books.push_back(make_pair(tmp.get_id(), tmp));
    }
    file.close();
    flag = true;
    file.open("Issue_info.txt");
    while (flag)
    {
        issue tmp(file, flag);
        if (flag)
            issue_record.push_back(make_pair(tmp.get_id(), tmp));
    }
}

void write_to_files()
{
    ofstream file;
    file.open("Student_info.txt");
    for (auto& [id, tmp] : student_data)
        tmp.write(file);
    file.close();

    file.open("Books_info.txt");
    for (auto& [id, tmp] : books)
        tmp.write(file);
    file.close();

    file.open("Issue_info.txt");
    for (auto& [id, tmp] : issue_record)
        tmp.write(file);
    file.close();
}

void List_Books()
{
    system("clear");
    vector<int> x_coor = {1, 7, 30, 50, 65, 75};
    int line = 1;
    int i = 0;
    gotoxy(x_coor[i++], line);
    cout << "ID";
    gotoxy(x_coor[i++], line);
    cout << "Title";
    gotoxy(x_coor[i++], line);
    cout << "Author";
    gotoxy(x_coor[i++], line);
    cout << "Domain";
    gotoxy(x_coor[i++], line);
    cout << "Edition";
    gotoxy(x_coor[i++], line);
    cout << "Copies available";

    line++;
    for (auto &[id, tmp] : books)
    {
        tmp.List_book(x_coor, line);
        line++;
    }
    gotoxy(1, line + 1);
    cout << "Press any key to continue..." << endl;
    getch();
    getch();
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void new_student()
{
    string name, Class;
    int student_id; // admission number

    cin.ignore();
    cout << "Enter the students name : ";
    getline(cin, name);
    cout << "Enter student's admission number : ";
    cin >> student_id;
    cin.ignore();
    cout << "Enter student's class : ";
    getline(cin, Class);

    student new_student(name, student_id, Class);
    student_data.push_back(make_pair(student_id, new_student));
    cout << "Press any key to continue..." << endl;
    getch();
}

void new_book()
{
    book tmp;
    books.push_back({tmp.get_id(), tmp});
    cout << "Press any key to continue..." << endl;
    getch();
    getch();
}

void issue_book()
{
    int student_id, book_id;
    cout << "Student's Admission number : ";
    cin >> student_id;
    cout << "Book ID of book being issued : ";
    cin >> book_id;
    bool issued = false;
    issue tmp(student_id, book_id, issued);
    if (issued)
        issue_record.push_back(make_pair(tmp.get_id(), tmp));

    else
    {
        cout << "Sorry, this book cannot be issued right now." << endl;
    }
    cout << "Press any key to continue..." << endl;
    getch();
    getch();
}

void return_book()
{
    pair<int, int> issue_id;
    cout << "Student's Admission number : ";
    cin >> issue_id.first;
    cout << "Book ID : ";
    cin >> issue_id.second;
    int pos = -1;
    for (int i = 0; i < issue_record.size(); i++)
    {
        if (issue_record[i].first == issue_id)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Issue record not found" << endl;
        return;
    }

    issue &curr = issue_record[pos].second;
    curr.return_book();
    issue_record.erase(issue_record.begin() + pos);
    cout << "Returned Successfully" << endl;
    cout << "Press any key to continue..." << endl;
    getch();
    getch();
}