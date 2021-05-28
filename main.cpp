#include<iostream>
#include<algorithm>
#include<iterator>
#include<bits/stdc++.h>

using namespace std;

string username;
string categories[] = { "Foods", "Health", "Transportation", "Entertainment", "Savings", "Groceries", "Gas", "Giving" };

int balance = 0;
int income = 0;
int outcome = 0;


void MainMenu(string username);
void InputIncome();
void InputOutcome();
void History();

int main(){
    cout << "Enter your new username : " ; cin >> username;

    MainMenu(username);

}

void MainMenu(string username){

    int option;

    cout << "Welcome, " << username << endl;
    cout << "Your Balance : Rp." << balance << ",00-" << endl;
    cout << "Your Income : Rp." << income << ",00-" << endl;
    cout << "Your Outcome : Rp." << outcome << ",00-" << endl;

    cout << "----------------------------" << endl;
    cout << "Main Menu : " << endl;
    cout << "[1] Input Income" << endl;
    cout << "[2] Input Outcome" << endl;
    cout << "[3] History" << endl;

    cout << "Enter menu (in number) : "; cin >> option;

    switch (option)
    {
    case 1:
        InputIncome();
        break;
    case 2:
        InputOutcome();
        break;
    case 3:
        History();
        break;
    
    default:
        cout << "Enter the menu correctly,please." << endl;
        break;
    }
    
}


void InputIncome(){
    int categories_length = sizeof(categories) / sizeof(categories[0]);
    int input_income;
    string input_category;
    
    while(true){
        cout << "Enter your income (in rupiah) : " ; cin >> input_income;
        
        cout << input_income << endl;

        if(input_income <= 0){
            cout << "The number you entered is less than 0. Make sure you enter your income correctly." << endl;
            continue;
        }

        cout << "Categories that already defined : ";
        for(int i = 0; i < categories_length; i++){
            if(i == categories_length-1){
                cout << categories[i] << ".";
            }else{
                cout << categories[i] << ", ";
            }
        }

        cout << endl;
        cout << "Enter one category/new category name : "; cin >> input_category;
       
        cout << input_income << endl;

        income += input_income;
        balance += input_income;

        cout << "Your income added!" << endl;

        cout << "Now, your income is " << income << " and your balance is " << balance << endl;
        MainMenu(username);
        break;

    };

        

}

void InputOutcome(){
    int input_outcome;
    // string category;
}

void History(){

}





