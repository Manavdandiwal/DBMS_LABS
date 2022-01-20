#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

extern void gotoxy(int, int);
class book
{
    int copies;
    int book_id;
    string title, author, domain;
    int edition;

public:
    book(ifstream &in, bool &flag)
    {
        flag = read(in);
    }

    book(string title, string author, string domain, int edition, int book_id, int copies)
    {
        this->title = title;
        this->author = author;
        this->domain = domain;
        this->edition = edition;
        this->book_id = book_id;
        this->copies = copies;
    }

    book()
    {
        cout << "ID : ";
        cin >> book_id;
        cout << "Title : ";
        cin.ignore();
        getline(cin, title);
        cout << "Author : ";
        getline(cin, author);
        cout << "Domain : ";
        getline(cin, domain);
        cout << "Edition : ";
        cin >> edition;
        cout << "Copies available :- ";
        cin >> copies;
    }

    bool read(ifstream &input)
    {
        if (input >> copies >> book_id && input.ignore() && getline(input, title) && getline(input, author) && getline(input, domain) && input >> edition)
            return true;

        return false;
    }

    void List_book(vector<int> &x_coor, int line)
    {
        int i = 0;
        gotoxy(x_coor[i++], line);
        cout << book_id;
        gotoxy(x_coor[i++], line);
        cout << title;
        gotoxy(x_coor[i++], line);
        cout << author;
        gotoxy(x_coor[i++], line);
        cout << domain;
        gotoxy(x_coor[i++], line);
        cout << edition;
        gotoxy(x_coor[i++], line);
        cout << copies;
    }

    void write(ofstream &out)
    {
        out << copies << endl;
        out << book_id << endl;
        out << title << endl;
        out << author << endl;
        out << domain << endl;
        out << edition << endl;
    }

    int get_count()
    {
        return copies;
    }

    int get_id()
    {
        return book_id;
    }

    void returned()
    {
        copies++;
    }

    void issue()
    {
        copies--;
    }
};