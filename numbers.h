/*************************************************************************
	A little class that holds a dynamic array of numbers.
	I have provided a start here, you need to write the function
		implementations. DO NOT remove the byte_count lines that are
		already in a few of the functions.


    John Dolan			Spring 2013		CS2401 Lab Assignment 4
	Patricia Lindner	Fall 2021
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <algorithm>

size_t byte_count = 0;
class Numbers{
    public:
		Numbers(); //Constructor
		~Numbers(); //Deconstructor
		void operator = (const Numbers& other); //Assigment Operator

		//Helpers
		void add(unsigned long item);
		void resize();
		void remove_last();
		void display(std::ostream& outs);

		//Getter
		unsigned long* reveal_address()const;

    private: 
		unsigned long * data;
		std::size_t used;
		std::size_t capactity;
};

Numbers::Numbers(){

	byte_count += 5*sizeof(unsigned long);
	used = 0;
	capactity = 5;
	data = new unsigned long[capactity];
}

Numbers::~Numbers() {
	delete []data;
	std::cout << "Note: Array memory deleted as it has left scope." << std::endl;
	byte_count = byte_count - (capactity * sizeof(unsigned long));
}

void Numbers::operator = (const Numbers& other) {
	//Check to make sure they are not already copied.
	if (this == &other) {
		return;
	}
	//Deletes memory then copies.
	delete []data;
	used = other.used;
	capactity = other.capactity;
	data = new unsigned long[capactity];
	for (size_t i = 0; i < used; i++) {
		data[i] = other.data[i];
	} 
}

void Numbers::add(unsigned long item){
	if (used == capactity) {
		resize();
	}
	data[used] = item;
	used++;
}

void Numbers::resize(){
	byte_count += 5*sizeof(unsigned long);

	unsigned long * tmp;
	tmp = new unsigned long[capactity + 5];

	for (std::size_t i = 0; i < used; i++) {
		tmp[i] = data[i];
	}
	delete []data;
	data = tmp;
	capactity += 5;
}

void Numbers::remove_last(){
	if (used >= 1) {
		unsigned long * tmp;
		tmp = new unsigned long[capactity];
		for (std::size_t i = 0; i < used - 1; i++) {
			tmp[i] = data[i];
		}
		delete []data;
		data = tmp;
		used--;
	}
	else {
		std::cout << "Error: Your array is already empty!\n";
	}
}

void Numbers::display(std::ostream& outs){
	for (std::size_t i = 0; i < used; i++) {
		//if else for formatting purposes.
		if (i == 0) {
			std::cout << data[i] << std::endl;
		}
		else {
		std::cout << std::endl << data[i] << std::endl;
		}
		std::cout << used << std::endl << capactity << std::endl;
	}
}

// You can leave this function alone
unsigned long *Numbers::reveal_address()const{
	return data;
}