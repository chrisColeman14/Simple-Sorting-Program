#include "Sorter.h"

using namespace std;

Sorter::Sorter(int size)
{
	counter = 0;
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		seq.push_back(rand()%100);
}

Sorter::Sorter()
{
	counter = 0;
	srand(time(NULL));
	for(int i = 0; i < 11; i++)
		seq.push_back(rand()%100);
}	

void Sorter::print()
{
	// Prints every integer in the vector seq
	for(int i = 0; i < seq.size(); i++)
		cout << seq[i] << ", ";
	// Print seperate so the sequence doesn't have a comma hanging at the end
	cout << seq[seq.size()-1] << "\n\n";
	if(counter != 0)
		cout << "Comparisons: " << counter << '\n';
}

void Sorter::insertionSort()
{
	int i = 0, j = 0, temp = 0;
	// Iterate through the entire vector<int> seq
	for(i = 1; i < seq.size(); i++)
	{
		j = i;
		while(j > 0 && seq[j-1] > seq[j])
		{
			counter++;
			temp = seq[j];
			seq[j] = seq[j-1];
			seq[j-1] = temp;
			j = j-1;
		}
	}

}

void Sorter::selectionSort()
{
	int i = 0, j = 0;

	for(j = 0; j < seq.size(); j++)
	{
		int min = j;
		for (i = j+1; i < seq.size(); i++)
		{
			if(seq[i] < seq[min])
			{
				counter++;
				int temp = seq[min];
				seq[min] = seq[i];
				seq[i] = temp;
			}
		}
	}
}

void Sorter::mergeSort()
{

}

vector<int>* Sorter::getSeq()
{
	return &seq;
}