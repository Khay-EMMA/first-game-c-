#pragma once
#include <string>

using FString =std::string;
using int32 = int;

struct FBullCowCount
{
		//all values initialized to zero
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus {
	Invalid_status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase
};

class FBullCowGame {
public:

	FBullCowGame(); //constructors

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const;//TODO make a more rich return value

	void Reset(); // TODO make a more rich return value
	// counts bulls and cows, increases try # assuming a vaild Guess
	FBullCowCount SubmitGuess(FString);


private:
	//see constructors for initialization
	int MyCurrentTry;
	int MyMaxTries;
	FString MyHiddenWord;
};