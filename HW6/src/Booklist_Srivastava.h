#ifndef BOOKLIST_H
#define BOOKLIST_H

class Booklist
{

public:
	Booklist();

	int getUserChoice();
	int getUserInput(bool);

	void insert(int);
	void insert_at(int, int); 

	int  find_linear(int);
	int  find_binary(int);

	void delete_item_position(int); 
	void delete_item_isbn(int); 

	void sort_list_selection();
	void sort_list_bubble(); 

	void print();

private:
	bool sorted;
	int mylist[20];
	int num_in_list;
};


#endif