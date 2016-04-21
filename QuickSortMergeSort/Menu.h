#ifndef MENU_H
#define MENU_H
#include "Sorter.h"
#include <vector>
#include <iostream>

class Menu
{
public:
	Menu();
	Menu(int size);
	void printMenu();
	void setChoice();
	void processChoice();
	void createSequence();
	void generateRandomSeq();
	void generateRandomSeqTo();

private:
	char choice;
	Sorter *sort;
};

#endif