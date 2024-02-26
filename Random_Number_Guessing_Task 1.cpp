/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/
#include<bits/stdc++.h>
using namespace std;

class Game
{
public:
    void RandomNo_Generating()
    {
        int Difficulty_Level;
        while(true)
        {
            cout<<"\t Please Select 1 for the Easy Level\t"<<"\n";
            cout<<"\t Please Select 2 for the Medium Level\t"<<"\n";
            cout<<"\t Please Select 3 for the Hard Level\t"<<"\n";
            cout<<"\t Please Select 0 for End Level\t"<<"\n";

            cout<<"\t Enter the Level No.:\t";
            cin>>Difficulty_Level;

            if (Difficulty_Level == 0)
                break;

            GenerateRandomNo(Difficulty_Level);
        }
    }

    void GenerateRandomNo(int Difficulty_Level)
    {
        int N, Choices;
        int i;
        int User_No;
        if(Difficulty_Level == 1)
        {
            srand(time(0));
            N = 1 + (rand() % 100);
            Choices = 8;
            cout<<"\t This is the Easy Level\t"<<"\n";
            cout<<"\t You need to Guess the Random Number between 1 to 100\t"<<"\n";
            cout<<"\t You have 8 Chances to Guess the No and Win\t";
        }
        else if(Difficulty_Level == 2)
        {
            srand(time(0));
            N = 1 + (rand() % 1000);
            Choices = 7;
            cout<<"\t This is the Medium Level\t"<<"\n";
            cout<<"\t You need to Guess the Random Number between 1 to 1000\t"<<"\n";
            cout<<"\t You have 7 Chances to Guess the No and Win\t";
        }
        else if(Difficulty_Level == 3)
        {
            srand(time(0));
            N = 1 + (rand() % 1000);
            Choices = 5;
            cout<<"\t This is the Hard Level\t"<<"\n";
            cout<<"\t You need to Guess the Random Number between 1 to 1000\t"<<"\n";
            cout<<"\t You have 5 Chances to Guess the No and Win\t";
        }
        for(i = 1; i <= Choices; i++)
        {
            cout<<"\n";
            cout<<"\t Guess the No: ";
            cin>>User_No;
            if(i<Choices)
            {
                if(User_No>N)
                {
                    cout<<"\t The no is you Guessed is Greater than the Secret No\t"<<"\n";
                    cout<<"\t Now you have "<<Choices-i<<" chances to win\t"<<"\n";
                }
                else if(User_No<N)
                {
                    cout<<"\t The no is you Guessed is Lesser than the Secret No\t"<<"\n";
                    cout<<"\t Now you have "<<Choices-i<<" chances to win\t"<<"\n";
                }
                else
                {
                    cout<<"\t You have Guessed the Secret No\t"<<"\n";
                    cout<<"\t Congratulation You Have won\t"<<"\n";
                    break;
                }
            }
            else if(i == Choices)
            {
                cout<<"\t You Have Last Chance to win\t"<<"\n";
                if(User_No>N)
                {
                    cout<<"\t The no is you Guessed is Greater than the Secret No\t"<<"\n";
                    cout<<"\t You Have Lost the Game\t"<<"\n";
                    cout<<"\t Please Try Again\t"<<"\n";
                }
                else if(User_No<N)
                {
                    cout<<"\t The no is you Guessed is Lesser than the Secret No\t"<<"\n";
                    cout<<"\t You Have Lost the Game\t"<<"\n";
                    cout<<"\t Please Try Again\t"<<"\n";
                }
                else
                {
                    cout<<"\t You have Guessed the Secret No\t"<<"\n";
                    cout<<"\t Congratulation You Have won\t"<<"\n";
                }
            }
        }
    }
};

int main()
{
    cout<<"\t Welcome to the no Guessing Game\t"<<"\n";
    cout<<"\t You need to Guess the Random Number which is Generated based on the Difficulty Level\t"<<"\n";
    Game obj;
    obj.RandomNo_Generating();
    return 0;
}
