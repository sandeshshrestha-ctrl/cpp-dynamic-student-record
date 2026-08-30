#include <iostream>
using namespace std;

class student
{
    string name;
    long books[10];
    int no = 0;

public:
    void setname(string name);
    string getname();
    void issuebook(long id, int i);
    long getissuedbooks(int i);
    int books_no();
};

void student::setname(string name)
{
    this->name = name;
}

void student::issuebook(long id, int i)
{
    books[i] = id;
    no = i + 1;
}

string student::getname()
{
    return name;
}

int student::books_no()
{
    return no;
}

long student::getissuedbooks(int i)
{
    return books[i];
}

int main()
{
    string name;
    int n1, n2;
    long id;

    cout << "Enter the total no. of students who had taken the book: ";
    cin >> n1;

    // Allocate memory for n1 students
    student *s = new student[n1];

    for (int i = 0; i < n1; i++)
    {
        cout << "Enter the name of the student: ";
        cin >> name;

        s[i].setname(name);

        cout << "Enter the total no. of books borrowed: ";
        cin >> n2;

        for (int j = 0; j < n2; j++)
        {
            cout << "Enter the ID of book no. " << j + 1 << ": ";
            cin >> id;

            s[i].issuebook(id, j);
        }
    }

    for (int i = 0; i < n1; i++)
    {
        cout << "\nThe name of the student is: "
             << s[i].getname() << endl;

        int n3 = s[i].books_no();

        cout << "The IDs of the borrowed books are: ";

        for (int j = 0; j < n3; j++)
        {
            cout << s[i].getissuedbooks(j) << " ";
        }

        cout << endl;
    }

    delete[] s;

    return 0;
}