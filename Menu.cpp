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
		<< "g: to generate random sequences of sizes going to n.\n"
		<< "c: create a sequence with integers given by user.\n"
		<< "p: print the sequence of integers.\n"
		<< "l: clear screen.\n"
		<< "x: exit program.\n"
		<< "\nSorting Methods\n"
		<< "i: use the insertion sort method to sort the sequence of integers.\n"
		<< "m: use the merge sort method to sort the sequence of integers.\n"
		<< "s: use the selection sort method to sort the sequence of integers.\n"
		<< "q: use the quick sort method to sort the sequence of integers.\n";

		cout << "Command: ";
		setChoice();
		processChoice();
		cout << '\n';
	} while (choice != 'x');
}

void Menu::setChoice()
{
		cin >> choice;
}

void Menu::processChoice()
{
	int si;
	si = sort->get_size() - 1;

	switch(choice)
	{
	case 'r': 
		generateRandomSeq();
		break;
	case 'g':
		generateRandomSeqTo();
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
		sort->mergeSort(0, si);
		cout << "sort->mergeSort!!\n";
		break;
	case 's':
		sort->selectionSort();
		cout << '\n';
		break;
	case 'l':
		system("CLS");
		break;
	case 'q':
		sort->quickSort(0, si);
		cout << '\n';
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
	if (cin.fail())
	{
		cout << "INVALID INPUT!!\n";
		cin.clear();
		s = 1;
	}
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
	if (cin.fail())
	{
		cout << "INVALID INPUT!!\n";
		cin.clear();
		cin.ignore(1);
		input = 1;
	}

	delete sort;
	sort = new Sorter(input);

}

void Menu::generateRandomSeqTo()
{
	int input = 1;
	char in = ' ';
	cout << "How many sequences do you want to create up to?: ";
	cin >> input;
	if(cin.fail())
	{
		cout << "INVALID INPUT!!\n";
		cin.clear();
		input = 1;
	}
	cout << "What method would you like to us ((i)nsertion, "
		<<"(s)election, (m)erge, or (q)uick sort?: ";
	cin >> in;

	switch(in)
	{
	case 'i':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->insertionSort();
			cout << "\nSequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	case 's':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->selectionSort();
			cout << "\nSequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	case 'm':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->mergeSort(0, i-1);
			cout << "\nSequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	case 'q':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->quickSort(0, i-1);
			cout << "\nSequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	default:
		cout << "ERROR: INVALID INPUT";
	}
	
}








