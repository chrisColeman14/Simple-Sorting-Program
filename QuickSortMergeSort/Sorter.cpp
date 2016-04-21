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

	/* partition */

	while (i <= j) {
		counter++;
		while (seq[i] < pivot)
			i++;
		while (seq[j] > pivot)
			j--;
		if (i <= j) {
			tmp = seq[i];
			seq[i] = seq[j];
			seq[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
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

	/* create temp arrays */
	vector<int> L;
	vector<int>	R;

	for (int i = 0; i < n1; i++)
		L.push_back(0);
	for (int i = 0; i < n2; i++)
		R.push_back(0);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = seq[l + i];
	for (j = 0; j < n2; j++)
		R[j] = seq[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
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

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		seq[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
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

		// Same as (l+r)/2, but avoids overflow for
		// large l and h
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