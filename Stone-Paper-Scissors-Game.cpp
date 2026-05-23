#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int Rules(int PlayerChoice, int PcChoice)
{
    if (PlayerChoice == PcChoice)
    {
        return 0; 
    }

    switch (PlayerChoice)
    {
        case 1: 
            switch (PcChoice)
            {
                case 2: return 2; 
                case 3: return 1; 
            }
            break;

        case 2: 
            switch (PcChoice)
            {
                case 1: return 1; 
                case 3: return 2; 
            }
            break;

        case 3: 
            switch (PcChoice)
            {
                case 1: return 2; 
                case 2: return 1; 
            }
            break;
    }

    return -1; 
}

int RoundsNumber()
{
    int RNumber = 0;
    cout << "How many rounds do you want to play? (1-10): ";
    cin >> RNumber;
    return RNumber;
}

void Gamestart(int RNumber)
{
    int PlayerChoice = 0;
    int PcChoice = 0;
    int PlayerWins = 0;
    int PcWins = 0;
    int Deal = 0;
        
    cout << "\n";
    for (int i = 0; i < RNumber; i++)
    {
        cout << "-------------- Round " << i + 1 << " -------------" << endl;
        cout << "Rock [1], Paper [2], Scissors [3]" << endl;
        cout << "Your choice: ";
        cin >> PlayerChoice;

        if (PlayerChoice < 1 || PlayerChoice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
            i--;
            continue;
        }

        cout << "Computer choice: ";
        PcChoice = RandomNumber(1, 3);      
        cout << PcChoice << endl; 
        
        int RoundResult = Rules(PlayerChoice, PcChoice);

        if (RoundResult == 0)
        {
            cout << "Draw!" << endl;
            Deal++;
        }
        else if (RoundResult == 1)
        {
            cout << "You win!" << endl;
            PlayerWins++;
        }
        else
        {
            cout << "Pc win!" << endl;
            PcWins++;
        }
    }

    cout << "---------------------------------" << endl;
    cout << "Player wins : " << PlayerWins << endl; 
    cout << "Pc Wins : " << PcWins << endl;
    cout << "Draws : " << Deal << endl;
    cout << "---------------------------------" << endl;
}

int Repeat()
{
    int PlayAgain = 0;
    cout << "Do you want to play again? [1] Yes - [2] No: ";
    cin >> PlayAgain;
    return PlayAgain;
}

bool PlayAgainAnswer(int PlayAgain)
{
    if (PlayAgain == 1)
    {
        return true;
    }
    else 
        return false;
}

void TheGame()
{
    int RNumber = RoundsNumber();
    Gamestart(RNumber);
    
    if (PlayAgainAnswer(Repeat()))
    {
        TheGame();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    TheGame();
    return 0;
}
