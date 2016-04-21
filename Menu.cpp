#include "Menu.h"

using namespace std;

Menu::Menu()
{
	const int SIZE = 32;
	sort = new Sorter(SIZE);
	choice = ' ';
}

Menu::Menu(int size)
{
	sort = new Sorter(size);
	choice = ' ';
}

void Menu::printMenu()
{
	do 
	{
		cout << "Commands\n=============\n"
		<< "r: generate random sequence of n size.\n"
		<< "c: create a sequence with integers given by user.\n"
		<< "p: print the sequence of integers.\n"
		<< "i: use the insertion sort method to sort the sequence of integers.\n"
		<< "m: use the merge sort method to sort the sequence of integers.\n"
		<< "s: use the selection sort method to sort the sequence of integers.\n"
		<< "q: use the quick sort method to sort the sequence of integers.\n"
		<< "l: clear screen.\n"
		<< "x: exit program.\n";

		cout << "Command: ";
		setChoice();
		processChoice();
	} while (choice != 'x');
}

void Menu::setChoice()
{
		cin >> choice;
}

void Menu::processChoice()
{
	switch(choice)
	{
	case 'r': 
		generateRandomSeq();
		break;
	case 'c':
		createSequence();
		break;
	case 'p': 
		sort->print();
		break;
	case 'i':
		sort->insertionSort();
		cout << '\n';
		break;
	case 'm':
		cout << "m\n";
	case 's':
		sort->selectionSort();
		cout << "\n";
		break;
	case 'l':
		system("CLS");
		break;
	case 'q':
		cout << "q\n";
		break;
	case 'x':
		cout << "Thanks for using this program!!\n";
		break;
	default:
		cout << "ERROR: INVALID INPUT\n";
	}

}

void Menu::createSequence()
{
	int s, input = 0;
	vector<int> *seq;
	cout << "Size of sequence: ";
	cin >> s;
	delete sort;
	sort = new Sorter(s);
	seq = sort->getSeq();
	
	seq->clear();

	for(int i = 0; i < s; i++)
	{
		cout << "Enter the value for element " << i << ": ";
		cin >> input;
		seq->push_back(input);
	}
}

void Menu::generateRandomSeq()
{
	int input = 1;
	cout << "Size of sequence: ";
	cin >> input;

	delete sort;
	sort = new Sorter(input);

}








