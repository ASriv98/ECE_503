#ifndef BOOKLIST_H
#define BOOKLIST_H

class Booklist
{

public:
	Booklist();

	int getUserChoice();
	int getUserInput(bool);

	void insert(int mylist[], int num_in_list, int new_element);
	void insert_at(int mylist[], int num_in_list, int at_position, int new_element); 

	int  find_linear(int[], int, int);
	int  find_binary(int[], int, int, bool);

	void delete_item_position(int[], int *, int); 
	void delete_item_isbn(int mylist[], int *, int); 

	void sort_list_selection(int[], int);
	void sort_list_bubble(int[], int); 

	void print(int[], int);

private:
	bool sorted;
	int myList[20];
	int num_in_list;
}


