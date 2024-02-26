/*
Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.
*/

#include<bits/stdc++.h>
using namespace std;
class calculator
{
    public:
    long double Add(double Num1, double Num2)
    {
        double Addition = Num1+Num2;
        return Addition;
    }
    long double Sub(double Num1, double Num2)
    {
        double Subtraction = Num1-Num2;
        return Subtraction;
    }
    long double mul(double Num1, double Num2)
    {
        double Multiplication = Num1*Num2;
        return Multiplication;
    }
    long double Div(double Num1, double Num2)
    {
        double Division = Num1/Num2;
        return Division;
    }

}obj;

int main()
{
    long double Num1,Num2;
    int operation,i;
    int operation_count;
    cout<<"Enter the How many Operations you want to perform: ";
    cin>>operation_count;
    for(i=0; i<operation_count; i++)
    {
        cout<<"Enter the Number 1: ";
        cin>>Num1;
        cout<<"Enter the Number 2: ";
        cin>>Num2;
        cout<<"Enter which Operation you Want to Perform: "<<"\n";
        cout<<" Enter 1 for Addition"<<"\n";
        cout<<"Enter 2 for Subtraction"<<"\n";
        cout<<"Enter 3 for Multiplication"<<"\n";
        cout<<"Enter 4 for Division"<<"\n";
        cin>>operation;
        switch (operation)
        {
            case 1: {
                cout<<"The Addition of "<<Num1<<" and "<<Num2<<" is: ";
                long double ans1 = obj.Add(Num1,Num2);
                cout << ans1 << "\n"<<"\n";
                break;
            }
            case 2: {
                cout<<"The Subtraction of "<<Num1<<" and "<<Num2<<" is: ";
                long double ans2 = obj.Sub(Num1,Num2);
                cout << ans2 << "\n"<<"\n";
                break;
            }
            case 3: {
                cout<<"The Multiplication of "<<Num1<<" and "<<Num2<<" is: ";
                long double ans3 = obj.mul(Num1,Num2);
                cout << ans3 << "\n"<<"\n";
                break;
            }
            case 4: {
                cout<<"The Division of "<<Num1<<" and "<<Num2<<" is: ";
                long double ans4 = obj.Div(Num1,Num2);
                cout << ans4 << "\n"<<"\n";
                break;
            }
            default:
                cout<<" You have Enter the Wrong Operation Number"<<"\n"<<"\n";
                break;
        }
    }
}
