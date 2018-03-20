#ifndef MENU_H
#define MENU_H
#include "Sorter.h"
#include <vector>
#include <iostream>

class Menu
{
public:

	/* 
		Default Constructor for Menu.
		INITIALIZES:
			const int SIZE = 32
			sort
			choice = ' '
	*/
	Menu();

	/*
		Constructor that take in a size that will be passed through to the Sorter object.

		@param
		int size: the size of the sequence the user wishes to create.
	*/
	Menu(int size);

	//Prints a menu detailing out every command that can be used in the program.
	void printMenu();
	
	//A setter function for choice.
	void setChoice();

	//Puts the choice through a switch statement.
	void processChoice();

	//Allows the user to create a sequence of their choice.
	void createSequence();

	//Creates a random sequence with a size given by the user.
	void generateRandomSeq();

	//Generates random sequences of size given by the user to n given by the user.
	void generateRandomSeqTo();

	/*
		Generates the average comparisons for n = {100, 200, 400, 800, 1600, 3200, 6400}
		for each sorting method.
	*/
	void averageComparisons();

private:
	char choice; //The command the user inputs.
	Sorter *sort; //The Sorter object that handles the sequences of integers.
};

#endif