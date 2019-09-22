#include <iostream>

int main()
{
	//number of students in class
	int numStudents = 20;
	int studentVotes[numStudents] = {0};

	int winningCandidate = -1;
	int maxVotes = 0;

	//iterate over the number of students in the class, and collect vote for each student in the class
	for(int i = 0; i < numStudents; i++)
	{
		//userCheck will verify that the user entered the correct candidate that they intended
		bool userCheck = false;

		//userCheckString is used to verify that the user is happy with their response. will later be checked by the keyword 'yes'
		std::string userCheckString;

		//keep repeating for each student until their response is confirmed
		while(userCheck == false)
		{

			bool validVote = false;

			//keep repeating gathering vote to make sure it is a valid vote (candidate #1-5 that is entered)
			while(validVote == false)
			{
				//Prompt user for their vote and collect their vote
				std::cout << "Student: " << i + 1 << " Please enter your vote. Vote between 1-5 representing candidate 1-5" << std::endl;
				std::cin  >> studentVotes[i];

			//Confirm that the vote is between the specification of 1 through 5 (representing candidates 1 through 5)
			if((studentVotes[i] >= 1) && (studentVotes[i] <= 5))
			{
				validVote = true;
			}
			else 
			{
				validVote = false;
				std::cout << "Invalid input entered... " << std::endl;
			}

			//Repeat this in a loop until there is a valid number entered for the vote.
		}

		//make sure the user is confirming that they entered the proper vote that they entered
		std::cout << "Please confirm your vote: " << studentVotes[i] << ". Please enter 'yes' to confirm... " << std::endl;
		std::cin  >> userCheckString;

		if(userCheckString == "yes")
		{
			userCheck = true;
		}
		else 
		{
			userCheck = false;
		}
		}
	}

		int candidateCount[5] = {0};

		//tally up all of the votes of the candidates by iterating through the array of student votes
		for(int i = 0; i < numStudents; i++)
		{
			candidateCount[studentVotes[i] - 1]++;
		}


		//Report votes for all the candidates, and keep track of a max to determine if there is a winner
		for(int i = 0; i < 5; i++)
		{
			std::cout << "Candidate " << i+1 << " received this many votes: " << candidateCount[i] << std::endl;
			
			//if a candidate has more votes than a previous he is the current max and current winner. Iterate through whole list to find the winner
			if(candidateCount[i] > maxVotes)
			{
				maxVotes = candidateCount[i];
				winningCandidate = i+1;
			}

			//if there is a tie between 2 candidates, winningCandidate = -1 to signify that there is no winner
			else if(candidateCount[i] == maxVotes)
			{
				winningCandidate = -1;
			}

		}

		//output result
		if(winningCandidate != -1)
		{
			std::cout << "The winning candidate is: " << winningCandidate << std::endl;
		}

		else
		{
			std::cout << "There is no winning candidate!" << std::endl;
		}

		return 0;

	}
