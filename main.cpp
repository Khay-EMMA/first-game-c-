/*This is the console executable, that makes use of the BullCow class
	This acts as the view in a MVC pattern, and is responsible for all user interaction. 
	For game logic see the FBullcowgame class

*/

#include <iostream>
#include <string>
#include "Fbullcowgame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; //instantiate

//the entrypoint of our application
int32 main()
{
	bool BPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		BPlayAgain =  AskToPlayAgain();

	} 
	while (BPlayAgain);
	
	return 0;// exit the application

	
}

void PrintIntro() {

	//introduce the game
	

	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	//loop for the number of tirns asking for guesses 
	//TODO change from FOR to While Loop once we are validating guess
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetValidGuess();

			
		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//Print number of bulls and cows

		std::cout << "Bulls =  " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
	}
	//TODO summarizae the game
}




FText GetValidGuess()

{
	int32 CurrentTry = BCGame.GetCurrentTry();


	//get a guess from the player
	std::cout << "Try " << CurrentTry << " Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	EWordStatus Status = EWordStatus::Invalid_status;
	do
	{

	std::getline(std::cin, Guess);
	 Status = BCGame.CheckGuessValidity(Guess);

	switch (Status)
	{
	case EWordStatus::Wrong_Length:
		std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " length word. \n";
		break;
	case EWordStatus::Not_Isogram:
		std::cout << "please enter Isogram " << std::endl;
		break;
	case EWordStatus::Not_LowerCase:
		std::cout << "please enter all Lowercase" << std::endl;
		break;
	default:
		return Guess;
		
	}

	} while (Status != EWordStatus::OK); //keep looping till we get no errors

}
	

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again y/n? ";
	FText Response = "";

	std::getline(std::cin, Response);

	return  (Response[0] == 'y') || (Response[0] == 'Y');
}

