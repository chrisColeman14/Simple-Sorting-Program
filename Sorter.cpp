#include "Sorter.h"

using namespace std;

Sorter::Sorter(int size)
{
	counter = 0;
	srand(time(NULL));

	//Initialize seq
	for(int i = 0; i < size; i++)
		seq.push_back(rand()%100);
}

Sorter::Sorter()
{
	counter = 0;
	srand(time(NULL));
	
	//Initialize seq
	for(int i = 0; i < 11; i++)
		seq.push_back(rand()%100);
}	

void Sorter::print()
{
	// Prints every integer in the vector seq
	for(int i = 0; i < seq.size()-1; i++)
		cout << seq[i] << ", ";
	// Print seperate so the sequence doesn't have a comma hanging at the end
	cout << seq[seq.size()-1] << "\n\n";
	if(counter >= 0)
		cout << "Comparisons: " << counter << '\n';
}

void Sorter::printLess()
{
	if (counter >= 0)
		cout << "Comparisions: " << counter << '\n';
}

void Sorter::insertionSort()
{
	int i = 0, j = 0, temp = 0;
	// Iterate through the entire vector<int> seq
	if (seq.size() > 1)
	{
		for (i = 1; i < seq.size(); i++)
		{
			j = i;
			while (j > 0 && seq[j - 1] > seq[j])
			{
				counter++;
				temp = seq[j];
				seq[j] = seq[j - 1];
				seq[j - 1] = temp;
				j = j - 1;
			}
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

void Sorter::quickSort(int left, int right)
{

	int i = left, j = right;
	int tmp;
	int pivot = seq[(left + right) / 2];

	//Partition
	while (i <= j) {
		while (seq[i] < pivot)
			i++;
		while (seq[j] > pivot)
			j--;
		if (i <= j) {
			counter++;
			tmp = seq[i];
			seq[i] = seq[j];
			seq[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(left, j);

	if (i < right)
		quickSort(i, right);

}

vector<int>* Sorter::getSeq()
{
	return &seq;
}

void Sorter::merge(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// create temp vectors
	vector<int> L;
	vector<int>	R;

	for (int i = 0; i < n1; i++)
		L.push_back(0);
	for (int i = 0; i < n2; i++)
		R.push_back(0);

	//Copy data to temp vectors L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = seq[l + i];
	for (j = 0; j < n2; j++)
		R[j] = seq[m + 1 + j];

	// Merge the temp vectors back into the original
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		counter++;
		if (L[i] <= R[j])
		{
			seq[k] = L[i];
			i++;
		}
		else
		{
			seq[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[]
	while (i < n1)
	{
		seq[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[]
	while (j < n2)
	{
		seq[k] = R[j];
		j++;
		k++;
	}
}

void Sorter::mergeSort(int l, int r)
{
	if (l < r)
	{

		//avoids overflow for
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(l, m);
		mergeSort(m + 1, r);

		merge(l, m, r);
	}
}

int Sorter::get_size()
{
	return seq.size();
}

int Sorter::get_counter()
{
	return counter;
}