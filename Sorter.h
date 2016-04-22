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

	/*
		COMMENTS

		@param an unorgainzed sequence of numbers as a vector<int>
	*/
	void selectionSort();

	void quickSort(int left, int right);

	void merge(int l, int m, int r);

	void mergeSort(int l, int r);

	vector<int>* getSeq();

	int get_size();

	void printLess();

private:
	vector<int> seq; // A sequence of ints
	int counter;
};
#endif