#include <iostream>
#include <vector>
#include <fstream>
#define _15_days 1296000
using namespace std;

extern vector<pair<int, student>> student_data;
extern vector<pair<int, book>> books;
class issue
{
    int student_id; // to whom this book is issued
    int book_id;    // which book is being issued
    time_t issue_time;

public:
    issue(ifstream &file, bool &flag)
    {
        flag = read_from_file(file);
    }
    issue(int student_id, int book_id, bool &issued)
    {
        auto it = student_data.begin();
        for (it; it != student_data.end(); it++)
        {
            auto& [id, data] = *(it);
            if (id == student_id)
                break;
        }
        auto &[id, person] = *it;
        book *curr = NULL;
        for (auto &[id, tmp] : books)
        {
            if (id == book_id)
            {
                curr = &tmp;
                break;
            }
        }
        if (curr == NULL || curr->get_count() == 0 || !person.book_issue(book_id))
        {
            issued = false;
        }

        else
        {
            this->student_id = student_id;
            this->book_id = book_id;
            issue_time = time(0);
            issued = true;
            curr->issue();
            cout << "Book issued successully." << endl;
            cout << "You are to return this book within 15 days else fine will be imposed for each day." << endl;
        }
    }

    bool return_book()
    {
        auto it = student_data.begin();
        for (it; it != student_data.end(); it++)
        {
            auto [id, data] = *(it);
            if (id == student_id)
                break;
        }

        time_t curr_time = time(0);
        int fine = 0;
        if (curr_time - issue_time > _15_days) // time passes is greater than or equal to 15 days
        {
            cout << "You are returning this book after the bound time. You will face fine for that." << endl;
            cout << "This fine will be added to your fee." << endl;
            fine = (curr_time - issue_time - _15_days) / (3600 * 24); // fine is 1rs per day (not so much)
        }

        cout << "Thank you for returning the book." << endl;

        auto &[id, person] = *it;
        person.book_return(book_id, fine);

        for (int i = 0; i < books.size(); i++)
        {
            if (book_id == books[i].first)
            {
                books[i].second.returned();
            }
        }
    }

    bool read_from_file(ifstream &input)
    {
        if (input >> book_id >> student_id >> issue_time)
            return true;

        return false;
    }

    void write(ofstream &out)
    {
        out << book_id << endl;
        out << student_id << endl;
        out << issue_time << endl;
    }

    pair<int, int> get_id()
    {
        return {student_id, book_id};
    }
};