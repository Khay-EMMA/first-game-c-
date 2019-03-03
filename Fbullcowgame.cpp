#include "Fbullcowgame.h"
using int32 = int;
using FText = std::string;

FBullCowGame::FBullCowGame()
{
	Reset();

}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
	constexpr int32 MaxTries = 8;
	MyMaxTries = MaxTries;
	
	const FString HIDDEN_WORD = "donkey";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return ;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)//if the guess isnt an isogram
	{
		return EWordStatus::Not_Isogram;

	}
	else if(false)//if the guess isnt all lowercase
	{
		return EWordStatus::Not_LowerCase;

	}
	else if (Guess.length() != GetHiddenWordLength())//if the guess length is wrong
	{
		return EWordStatus::Wrong_Length;

	}
	else //otherwise 
	{
		return EWordStatus::OK;
	
	}
	
}

//recieves a valid guess, incriments
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{	//increment the turn number
	MyCurrentTry++;


	//setup a return variable
	FBullCowCount BullCowCount;


	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();



	for (int32 MHWchar = 0; MHWchar < HiddenWordLength; MHWchar++)
	{

		//compare letters against the hiddenword
		for (int GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			//if they math then
			if (Guess[GChar] == MyHiddenWord[MHWchar])
			{
				//incriment bulls if they're in the same place
				if (MHWchar == GChar)
				{
					BullCowCount.Bulls++; // incriment Bulls
				}
				else
				{
					BullCowCount.Cows++; //Must be a cow
				}

			}

		}

		}
	return BullCowCount;

}

