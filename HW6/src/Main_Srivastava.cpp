#include <iostream>
#include "Booklist_Srivastava.h"

int main()
{

	std::cout << "made it" << std::endl;
	Booklist<std::string> booklist;
	bool exitStatus = true;
	std::string ISBN = "";
	int position;


	booklist.print();

	while(exitStatus)
	{
		int choice = booklist.getUserChoice();

		if((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4) || (choice == 6))
		{
			ISBN = booklist.getUserISBN();
		}

		if((choice == 2) || (choice == 5))
		{
			position = booklist.getPosition();
		}

		//switch cases going through menu choices
		switch(choice)
		{
			case 1:
				booklist.insert(ISBN);
				booklist.print();
				break;

			case 2: 
				booklist.insert_at(position, ISBN);
				booklist.print();
				break;
			
			case 3: 
				booklist.find_linear(ISBN);
				break;

			case 4: 
				booklist.find_binary(ISBN);
				break;

			case 5: 
				booklist.delete_item_position(position);
				break;

			case 6: 
				booklist.delete_item_isbn(ISBN);
				break;
			case 7: 
				booklist.sort_list_selection();
				break;

			case 8:
				booklist.sort_list_bubble();
				break;

			case 9:
				booklist.print();
				break;
			case 10:
				exitStatus = false;
				break;

			default:
				std::cout << "Please enter a valid menu choice! " << std::endl;
		}
	}



}