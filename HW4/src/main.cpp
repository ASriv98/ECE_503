#include <iostream>
#include <stdexcept>
#include <iomanip>

static int getUserChoice();
static int getUserInput(bool);

void insert(int mylist[], int num_in_list, int new_element);
void insert_at(int mylist[], int num_in_list, int at_position, int new_element); 

int  find_linear(int[], int, int);
int  find_binary(int[], int, int, bool);

void delete_item_position(int[], int *, int); 
void delete_item_isbn(int mylist[], int *, int); 

void sort_list_selection(int[], int);
void sort_list_bubble(int[], int); 

void print(int[], int);

void print(int mylist[], int num_in_list)
{
	std::cout << "Your book list is now: " << std::endl;
	if(num_in_list != 0)
	{
		for(int i = 0; i < num_in_list; i++)
		{
			std::cout << (i+1) << ". " << mylist[i] << std::endl;
		}
	}
	else {std::cout << "Empty." << std::endl;}
	std::cout << std::endl;
}

//Function to display menu and to get user's choice from the menu selection
int getUserChoice()
{
	int choice = 0;

	std::cout << "Welcome to the Book list program." << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "  1: Insert new element at end of the list" << std::endl;
	std::cout << "  2: Insert new element at a certain position" << std::endl;
	std::cout << "  3: Find an element(with its ISBN number and list its position) using linear search" << std::endl;
	std::cout << "  4: Find an element(with its ISBN number and list its position) of a sorted list using binary search" << std::endl;
	std::cout << "  5: Delete an element that is at a certain position" << std::endl;
	std::cout << "  6: Delete an element by using its ISBN number" << std::endl;
	std::cout << "  7: Sort the list by the ISBN numbers (using selection sort)" << std::endl;
	std::cout << "  8: Sort the list by the ISBN numbers (using bubble sort)" << std::endl;
	std::cout << "  9: Print out the list" << std::endl;
	std::cout << "  10: Quit Program" << std::endl;
	std::cout << "Enter your Choice" << std::endl;
	std::cin  >> choice;
	std::cin.ignore(1024, '\n');

	if((choice < 1) || (choice > 10))
	{
		throw std::invalid_argument("received invalid menu choice");
	}

	return choice;
}

//function to get input of ISBN number or position of the book
int getUserInput(bool ISBN)
{
	int num = 0;

	if(ISBN)
	{
		std::cout << "Please enter the ISBN number of the book: " << std::endl;
		std::cin  >> num;
	}
	else
	{
		std::cout << "Please enter the position" << std::endl;
		std::cin  >> num;
	} 
	return num;
}

void insert(int mylist[], int * num_in_list, int new_element)
{
	//increment the list count by 1 everytime a new element is inserted
	(*num_in_list) += 1;
	//shift the list backwards
	*(mylist + (*num_in_list) - 1) = new_element;
}


//insert book at any point in the list
void insert_at(int mylist[], int * num_in_list, int at_position, int new_element)
{
	//check to make sure book capacity has not been reached

	if((*num_in_list) > 20)
	{
		throw std::invalid_argument("The list of books is full.");
	}
	else
	{
		//check to make sure there are enough books to add at this position
		if((at_position >= 1) && (at_position <= (*num_in_list + 1)))
		{
			//sliding the books that are before the position back 
			for(int i = (*num_in_list); i >= at_position; i--)
			{
				*(mylist + i) = *(mylist + i - 1);	
			}
			(*num_in_list) += 1;		//keeping track of how many books are in the total booklist 
			*(mylist + at_position - 1) = new_element;	//adding the new element to the booklist
		}
		else
		{
			throw std::invalid_argument("There are not enough books to add a book at that position");
		}
	}
}

int find_linear(int mylist[], int num_in_list, int element, bool print)
{
	int position = -1;

	//iterate through the entire list
	for (int i = 0; i < num_in_list; i++)
		if(*(mylist + i) == element)
		{
			//once element is found, store the position (+1 because array starts at 0)
			position = i + 1;
			if(print)
				std::cout << "The book is in position " << position << std::endl;
			break;
		}

	if(position == -1)
	{
		std::cout << "Error. Book not found." << std::endl;
	}

	return position;
}

int find_binary(int mylist[], int num_in_list, int element, bool sorted)
{
	int position = -1;

	if(!sorted)
	{
		throw std::invalid_argument("This function is expecting a sorted list. List specified sorted.");
	}
	else
	//binary search algorithm 
	{
		int low = 0;
		int high = num_in_list - 1;
		int mid = (low+high)/2;

		while(low <= high)
		{
			if (element == *(mylist + mid))
			{
				position = mid+1;
				std::cout << "The book is in position " << position << std::endl;
				break;
			}
			else
			{
				if (element > *(mylist+mid))
				{
					low = mid+1;
					mid = (low+high)/2;
				}
				else
				{
					high = mid-1;
					mid = (low+high)/2;
				}
			}
 		}
		}

	if(position == -1)
	{
		std::cout << "Error. Book not found." << std::endl;
	}
	return position;
}

void delete_item_position(int mylist[], int * num_in_list, int position)
{
	if(*num_in_list == 0)
	{
		std::cout << "Error - book list is empty" << std::endl;
	}

	//check if a valid position (that a book exists that position)
	if((position < 1) || (position > (*num_in_list)))
	{
		std::cout << "Book does not exist in specified position" << std::endl;
	}
	else
	{
		//go to position, and shift over the rest of the elements after removing at given position
		for(int i = position; i < (*num_in_list); i++)
		{
			*(mylist + i - 1) = *(mylist + i);
		}
		//adjust list by decrementing after deleting the element
		(*num_in_list) -= 1;
	}
}

void delete_item_isbn(int mylist[], int * num_in_list, int element)
{
	if(*num_in_list == 0)
	{
		std::cout << "Error - book list is empty" << std::endl;
	}
	
	//find position using existing function and delete at position using existing function
	int position = find_linear(mylist, *(num_in_list), element, false);
	delete_item_position(mylist, num_in_list, position);
} 

void sort_list_selection(int mylist[], int num_in_list)
{
	int minpos = 0;
	int temp = 0;
	for(int i = 0; i < num_in_list - 1; i++)
	{	
		minpos = i;
		for(int j = i; j < num_in_list; j++)
		{
			//check to find a min element in the lis and shift it to the front
			if(*(mylist + j) < *(mylist + minpos))
			{
				minpos = j;
			}
		}
		//swap min element 
		temp = *(mylist + minpos);
		*(mylist + minpos) = *(mylist + i);
		*(mylist + i) = temp;
	}

}

void sort_list_bubble(int mylist[], int num_in_list)
{
	int temp = 0;
	for(int i = 0; i < num_in_list - 1; i++)
	{
		for (int j = 0; j < (num_in_list - i - 1); j++)
		{
			if (*(mylist + j) > * (mylist +j + 1))
			{	
				temp = *(mylist + j);
				*(mylist + j) = *(mylist + j + 1);
				*(mylist + j + 1) = temp;
			}
		}
	}
} 

int main()
{
	int ISBN     	= 0;
	int position 	= 0; 
	int num_in_list = 0;

	int mylist[20]  = {};
	bool exitStatus = true;
	bool sorted     = false;


	while(exitStatus)
	{
		int choice = getUserChoice();

		if((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4) || (choice == 6))
		{
			ISBN = getUserInput(true);
		}

		if((choice == 2) || (choice == 5))
		{
			position = getUserInput(false);
		}

		//switch cases going through menu choices
		switch(choice)
		{
			case 1:
				insert(mylist, &num_in_list, ISBN);
				print(mylist, num_in_list);
				break;

			case 2: 
				insert_at(mylist, &num_in_list, position, ISBN);
				print(mylist, num_in_list);
				break;
			
			case 3: 
				find_linear(mylist, num_in_list, ISBN, true);
				break;

			case 4: 
				find_binary(mylist, num_in_list, ISBN, sorted);
				break;

			case 5: 
				delete_item_position(mylist, &num_in_list, position);
				break;

			case 6: 
				delete_item_isbn(mylist, &num_in_list, ISBN);
				break;

			case 7: 
				sort_list_selection(mylist, num_in_list);
				sorted = true;
				break;

			case 8:
				sort_list_bubble(mylist, num_in_list);
				sorted = true;
				break;

			case 9:
				print(mylist, num_in_list);
				break;
			case 10:
				exitStatus = false;
				break;

			default:
				std::cout << "Please enter a valid menu choice! " << std::endl;
		}
	}

	return 0;
}