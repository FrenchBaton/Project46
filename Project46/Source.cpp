#include<iostream>
#include<list>
using namespace std;

class Student
{
	string name;
	double middleScore;
public:
	Student() {
		name = "NAME";
		middleScore = 0;
	}

	Student(string n, double ms) {
		name = n;
		middleScore = ms;
	}

	double GetScore() { return middleScore; }

	void Print() {
		cout << "Name: " << name << "\nScore: " << middleScore << endl;
		cout << endl;
	}
};

class Book
{
	string title;
	string autor;
	int pages;
public:
	Book() {
		title = "T";
		autor = "A";
		pages = 0;
	}

	Book(string t, string a, int p) {
		title = t;
		autor = a;
		pages = p;
	}

	string GetTitle() { return title; }

	void Print() {
		cout << "Title: " << title << "\nAutor: " << autor << "\nPages: " << pages << endl;
		cout << endl;
	}

	bool operator==(const Book& b) const {
		return title == b.title;
	}
};


int main() {
	list<Student> lst;
	lst.push_back(Student("N1", 11));
	lst.push_back(Student("N2", 5));
	lst.push_back(Student("N3", 9));
	lst.push_back(Student("N4", 12));
	lst.push_back(Student("N5", 4));

	list<Book> lst2;
	lst2.push_back(Book("B1", "A", 11));
	lst2.push_back(Book("B2", "A", 5));
	lst2.push_back(Book("B3", "A", 9));
	lst2.push_back(Book("B4", "A", 9));
		
	
	for (auto Iter = lst.begin(); Iter != lst.end(); Iter++)
	{
		(*Iter).Print();
	}
	cout << endl;

	list<Student>::iterator ptr;

	for (auto Iter = lst.begin(); Iter != lst.end(); Iter++)
	{
		if (Iter == lst.begin() || (*Iter).GetScore() > (*ptr).GetScore()) ptr = Iter;
	}
	(*ptr).Print();
	cout << endl;

	for (auto Iter = lst2.begin(); Iter != lst2.end(); Iter++)
	{
		(*Iter).Print();
	}
	cout << endl;

	string deleteTitle = "B3";
	for (auto Iter = lst2.begin(); Iter != lst2.end(); Iter++)
	{
		if ((*Iter).GetTitle() == deleteTitle) 
		{
			lst2.remove(*Iter);
			break;
		}
	}
	for (auto Iter = lst2.begin(); Iter != lst2.end(); Iter++)
	{
		(*Iter).Print();
	}
	cout << endl;

	cout << endl;
	return 0;
}