#ifndef SORTER_H
#define SORTER_H
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

class Sorter
{
public:
	/* 
		Constructor that sets seq = sequence
		
		@param an unorgainzed sequence of numbers as a vector<int>
	*/
	Sorter(int size);

	// Default constructor that will push back 10 random numbers in seq
	Sorter();

	/*
		Sorts a random sequence of integers as a vector<int>
		Using insertion sort method, moves one element at a time and compares that element to all elements before it until sorted

		@param an unorgainzed sequence of numbers as a vector<int>
	*/
	void insertionSort();

	
	// Prints every element inside of seq
	void print();

    //A sort that runs in O(n) time.
	void selectionSort();

	/*
		A sort that runs in O(n^2) time.
		
		@param
		int left: the left most index
		int right: the right most index
	*/
	void quickSort(int left, int right);

	/*
		A crucial part to merge where you spilt up the work of sorting with recurrsion
		that runs in O(n) time.
		
		@param
		int l: the left most index
		int r: the right most index
		int m: the middle index
	*/
	void merge(int l, int m, int r);

	/*
		A sort that runs in O(n^2) time.
		
		@param
		int left: the left most index
		int right: the right most index
	*/
	void mergeSort(int l, int r);

	//Accessor Function for vector<int>* seq
	vector<int>* getSeq();

	//Accessor function for vector<int>* seq->size()
	int get_size();

	//Accessor function for int counter
	int get_counter();

	//Prints only the comparisons the sort makes, not the contents of the sequence
	void printLess();

private:
	vector<int> seq; // A sequence of ints
	int counter; //Comparisons made in a sort
};
#endif