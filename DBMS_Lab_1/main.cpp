#include "helpers.h"

vector<pair<int, student>> student_data;
vector<pair<int, book>> books;
vector<pair<pair<int, int>, issue>> issue_record;

int main()
{
    read_from_files();
    while (1)
    {
        system("clear");
        cout << "Choose an option from below : " << endl;
        cout << " 1 : New Student entry" << endl; // assuming no two students will ever have same admission number so not checking for that
        cout << " 2 : New Book Entry" << endl;    // assuming the same for books
        cout << " 3 : Issue a book" << endl;
        cout << " 4 : List all the Books" << endl;
        cout << " 5 : Return Book" << endl;
        cout << " 6 : Exit" << endl;
        int choice;
        cout << " Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            new_student();
            break;
        
        case 2:
            new_book();
            break;
            
        case 3:
            issue_book();
            break;
        
        case 4:
            List_Books();
            break;

        case 5:
            return_book();
            break;

        default:
            write_to_files();
            exit(0);
        }
    }
}