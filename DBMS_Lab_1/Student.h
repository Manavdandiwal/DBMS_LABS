#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

extern vector<pair<int, book>> books;
class student
{
    string student_name, Class;
    int Admission_number;
    int fine;
    int count;                // number of books issued
    vector<int> books_issued; // book ids of books issued

public:
    student(ifstream &in, bool &flag)
    {
        static int i = 0;
        flag = read_from_file(in, i);
        i++;
    }

    int get_id()
    {
        return Admission_number;
    }

    student(string name, int admission_number, string Class)
    {
        fine = 0;
        count = 0;
        student_name = name;
        Admission_number = admission_number;
        this->Class = Class;
    }

    void book_return(int book_id, int fine = 0)
    {
        count--;
        for (int i = 0; i < books_issued.size(); i++)
        {
            if (books_issued[i] == book_id)
            {
                books_issued.erase(books_issued.begin() + i);
                break;
            }
        }
        this->fine += fine;
        // book has been returned by the student
    }

    bool book_issue(int book_id)
    {
        if (count == 3)
            return false;

        count++;
        books_issued.push_back(book_id);
        return true;
    }

    void write(ofstream &out)
    {
        //out << endl;
        out << student_name << endl;
        out << Class << endl
            << Admission_number << endl
            << fine << endl
            << count << endl;
        for (int i = 0; i < count; i++)
            out << books_issued[i] << endl;
    }

    bool read_from_file(ifstream &in, int i)
    {
        if (i)
            in.ignore();
        if (getline(in, student_name) && getline(in, Class) &&in >> Admission_number >> fine >> count && read_books(in))
            return true;

        return false;
    }

    bool read_books(ifstream &in)
    {
        for (int i = 0; i < count; i++)
        {
            int id;
            if (in >> id)
                books_issued.push_back(id);

            else
                return false;
        }
        return true;
    }
};
