#include "LinkedList.h"
#include <iostream>
#include "LinkedList.h"
#include "Node.h"


int main()
{
	bool quit = false;
	int choice = 0;
	int productNo = 0;
	int deleteNumber = 0;
	LinkedList ll;
	std::string deleteProduct = "";
	std::string productName = "";
	Node * listNode = new Node(productName, productNo);


	std::cout << "Welcome to the shopping list program" << std::endl;

	while(!quit)
	{
		std::cout << "1. Add a new node at the beginning" << std::endl;
		std::cout << "2. Add a new node at the end" << std::endl;
		std::cout << "3. Remove the beginning node" << std::endl;
		std::cout << "4. Remove the end node" << std::endl;
		std::cout << "5. Remove a node from the list by entering an item number" << std::endl;
		std::cout << "6. Remove a node from the list by entering an item name" << std::endl;
		std::cout << "7. Print out the list" << std::endl;
		std::cout << "8. Quit the program" << std::endl;
		std::cout << "Please choose an option: ";
		std::cin >> choice;

		if(choice == 1 || choice == 2)
		{
			std::cout << "Please enter product number to insert at beginning" << std::endl;
			std::cin >> productNo;
			std::cout << "Please enter the name for the product" << std::endl;
			std::cin >> productName;

			listNode = new Node(productName, productNo);
		}

		else if(choice == 5)
		{
			std::cout << "Please enter product number to delete" << std::endl;
			std::cin >> deleteNumber;
		}

		else if(choice == 6)
		{
			std::cout << "Please enter name of product to delete" << std::endl;
			std::cin >> deleteProduct;
		}

		switch(choice)
		{
			case 1:
			ll.addToStart(listNode);
			ll.printList();
			break;
		case 2:
			ll.addToEnd(listNode);
			ll.printList();
			break;
		case 3:
			ll.removeFromStart();
			ll.printList();
			break;
		case 4:
			ll.removeFromEnd();
			ll.printList();
			break;
		case 5:
			ll.removeNodeFromList(deleteNumber);
			ll.printList();
			break;
		case 6:
			ll.removeNodeFromList(deleteProduct);
			ll.printList();
			break;
		case 7:
			ll.printList();
			break;
		case 8:
			quit = true; //quit
			break;

		default:
			std::cout << "Please enter a valid choice." << std::endl;
			std::cout << std::endl;
			break;

		}





	}



}