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
		<< "a: generate 20 sequences and find the average comparisons.\n"
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

		//Let the user input their command.
		setChoice();

		//Procress the command to find out what function to call.
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
	int si; //The size of current sequence.
	si = sort->get_size() - 1;

	switch(choice)
	{
	case 'a':
		averageComparisons();
		break;
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
	int s, input = 0; //s is the size of the sequence and input is the value for each element
	vector<int> *seq;
	cout << "Size of sequence: ";
	cin >> s;

	//If the users input is invalid.
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
	int input = 1; //The size of the sequence.
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

	//Procress which sorting method the user wants to use.
	switch(in)
	{
	case 'i':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->insertionSort();
			cout << "Sequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	case 's':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->selectionSort();
			cout << "Sequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	case 'm':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->mergeSort(0, i-1);
			cout << "Sequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	case 'q':
		for (int i = 1; i <= input; i++)
		{
			delete sort;
			sort = new Sorter(i);
			sort->quickSort(0, i-1);
			cout << "Sequence of size " << i << " : ";
			sort->printLess();
		}
		break;
	default:
		cout << "ERROR: INVALID INPUT";
	}
	
}

void Menu::averageComparisons()
{
	//The size of sequences to be sorted
	int n[7] = {100, 200, 400, 800, 1600, 3200, 6400};
	int average = 0; //The average comparisons for n sequence to be sorted.
	cout << "Selection Sort Averages\n";
	for(int i = 0; i < 7; i++)
	{
		int runningSum = 0; //The sum of all comparisons.
		for(int j = 1; j <= 20; j++)
		{
			delete sort;
			sort = new Sorter(n[i]);
			sort->selectionSort();
			runningSum += sort->get_counter(); //Add counter to running sum.
		}
		average = runningSum / 20;
		cout << "Size of Sequence [" << n[i] << "], Average comparisons: "
			<< average << ".\n";
	}

	cout << "\nInsertion Sort Averages\n";

	for(int i = 0; i < 7; i++)
	{
		int runningSum = 0;
		for(int j = 1; j <= 20; j++)
		{
			delete sort;
			sort = new Sorter(n[i]);
			sort->insertionSort();
			runningSum += sort->get_counter();
		}
		average = runningSum / 20;
		cout << "Size of Sequence [" << n[i] << "], Average comparisons: "
			<< average << ".\n";
	}

	cout << "\nMerge Sort Averages\n";

	for(int i = 0; i < 7; i++)
	{
		int runningSum = 0;
		for(int j = 1; j <= 20; j++)
		{
			delete sort;
			sort = new Sorter(n[i]);
			sort->mergeSort(0, n[i]-1);
			runningSum += sort->get_counter();
		}
		average = runningSum / 20;
		cout << "Size of Sequence [" << n[i] << "], Average comparisons: "
			<< average << ".\n";
	}

	cout << "\nQuick Sort Averages\n";

	for(int i = 0; i < 7; i++)
	{
		int runningSum = 0;
		for(int j = 1; j <= 20; j++)
		{
			delete sort;
			sort = new Sorter(n[i]);
			sort->quickSort(0, n[i]-1);
			runningSum += sort->get_counter();
		}
		average = runningSum / 20;
		cout << "Size of Sequence [" << n[i] << "], Average comparisons: "
			<< average << ".\n";
	}
}






