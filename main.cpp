#include<iostream>
#include<algorithm>
#include<string>
#include<iterator>
#include<bits/stdc++.h>

using namespace std;



map<int, map<string, string>> history;
// map<int, map<string, string>>::iterator itr;
// map<string, string>::iterator ptr;

int history_length = 0;
int balance = 0;
int income = 0;
int outcome = 0;

string username;

void MainMenu();
void InputIncome();
void InputOutcome();
void History();
void IncomeHistory();
void OutcomeHistory();
void AllTransactionHistory();

string CurrentDate(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%A %d %B %Y %X", &tstruct);

    return buf;
}

string Capitalize(string text) {

	for (int x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}

	return text;
}


int main(){
    cout << "\n\t >>> Welcome to our Program <<<\n\t >>>  E Saving & Expanses <<<" << endl;
    cout << "\nEnter your new username : " ; 
    getline(cin,username);
    username = Capitalize(username);

    cout << "\nWelcome, " << username << endl;
    MainMenu();
    
    // return 0;

}

void MainMenu(){
    int option;
    while (true)
    {
        /* code */
        cout << "\nYour Balance : Rp." << balance << ",00-" << endl;
        cout << "Your Income  : Rp." << income << ",00-" << endl;
        cout << "Your Outcome : Rp." << outcome << ",00-" << endl;

        cout << "----------------------------" << endl;
        cout << "Main Menu : " << endl;
        cout << "[1] Input Income" << endl;
        cout << "[2] Input Outcome" << endl;
        cout << "[3] History" << endl;
        cout << "[4] Exit" << endl;

        cout << "Enter menu (in number) : "; cin >> option;

        if(option == 1){
            InputIncome();
            // continue; // skip bawahnya
        }else if(option == 2){
            InputOutcome();
            // continue;
        }else if(option == 3){
            History();
            // continue;
        }else if(option == 4){
            cout << "All of your data deleted." << endl;
            cout << "Bye..." << endl;
            exit(0);
            break; // berhenti looping
        }else
        {
            cout << "Enter the menu correctly,please." << endl;
            continue;
        }
        
    }
    
    
}


void InputIncome(){
    int input_income;
    string input_income_source;
    
    while(true){
        cout << "\nEnter your income (in rupiah) : " ; cin >> input_income;

        if(input_income <= 0){
            cout << "The number you entered is less than 0. Make sure you enter your income correctly." << endl;
            continue;
        }

        cout << "Examples Source Income : Salary, Fiverr, etc" << endl;
        cout << "Enter one source income : "; 
        
        cin.ignore(); 
        getline(cin,input_income_source);

        input_income_source = Capitalize(input_income_source);

        income += input_income;
        balance += input_income;

        history[history_length].insert(make_pair("Type", "Income"));
        history[history_length].insert(make_pair("Nominal", to_string(input_income)));
        history[history_length].insert(make_pair("Balance", to_string(balance)));
        history[history_length].insert(make_pair("Source Income", input_income_source));
        history[history_length].insert(make_pair("Date Time", CurrentDate()));

        history_length++;

        cout << endl << "Your income added!" << endl;

        cout << "Now, your income is Rp." << income << ",00- and your balance is Rp." << balance << ",00-" << endl;
        MainMenu();
        break;

    };

}

void InputOutcome(){
    int input_outcome;
    string input_category;

    if(balance == 0){
        cout << "Your balance is Rp." << balance << ",00-" << endl;
        cout << "Back to Main Menu..." << endl;
        MainMenu();
    }

    while(true){
        cout << "\nEnter your outcome (in rupiah) : " ; cin >> input_outcome;

        if(input_outcome <= 0){
            cout << "The number you entered is less than 0. Make sure you enter your outcome correctly." << endl;
            continue;
        }

        if(input_outcome > balance){
            cout << "The number you entered is more than your balance. Make sure you enter your outcome correctly." << endl;
            continue;
        }

        cout << "Examples Category : Foods, Health, Entertainment, etc" << endl;
        
        cout << "Enter one category/new category name : ";
        cin.ignore();
        getline(cin,input_category);
        
        input_category = Capitalize(input_category);

        outcome += input_outcome;
        balance -= input_outcome;

        history[history_length].insert(make_pair("Type", "Outcome"));
        history[history_length].insert(make_pair("Nominal", to_string(input_outcome)));
        history[history_length].insert(make_pair("Balance", to_string(balance)));
        history[history_length].insert(make_pair("Category", input_category));
        history[history_length].insert(make_pair("Date Time", CurrentDate()));

        history_length++;

        cout << "\nYour outcome added!" << endl;

        cout << "Now, your outcome is Rp." << outcome << ",00- and your balance is Rp." << balance << ",00-" << endl;
        MainMenu();
        break;

    };
}

void GoTo(){
    int option;
    cout << "-----------------------------------------" << endl;

    while (true)
    {
        cout << "\nBack to..." << endl;
        cout << "[1] Main Menu" << endl;
        cout << "[2] History Menu" << endl;
        cout << "Enter menu (in number) : "; cin >> option;

        if(option == 1){
            MainMenu();
            continue;
        }else if(option == 2){
            History();
            continue;
        }else{
            cout << "Enter the menu correctly,please." << endl;
            continue;
        }
    }
    
}

void IncomeHistory(){
    int count_income = 0;
    if(history_length > 0){
        for (int i=0; i < history_length; i++) {
            if(history[i]["Type"] == "Income"){
                cout << "-----------------------------------------" << endl;
                cout << "Type\t\t : " << history[i]["Type"] << endl;
                cout << "Nominal\t\t : " << "Rp." << history[i]["Nominal"] << ",00-" << endl;
                cout << "Balance\t\t : " << "Rp." << history[i]["Balance"] << ",00-" << endl;
                cout << "Source Income\t : " << history[i]["Source Income"] << endl;
                cout << "Date Time\t : " << history[i]["Date Time"] << endl;

                count_income++;
            }
        }
    }

    if(count_income == 0){
        cout << "No history found." << endl;
    }

    GoTo();
}

void OutcomeHistory(){
    int count_outcome = 0;
    if(history_length > 0){
        for (int i=0; i < history_length; i++) {
            if(history[i]["Type"] == "Outcome"){
                cout << "-----------------------------------------" << endl;
                cout << "Type\t\t : " << history[i]["Type"] << endl;
                cout << "Nominal\t\t : " << "Rp." << history[i]["Nominal"] << ",00-" << endl;
                cout << "Balance\t\t : " << "Rp." << history[i]["Balance"] << ",00-" << endl;
                cout << "Category\t : " << history[i]["Category"] << endl;
                cout << "Date Time\t : " << history[i]["Date Time"] << endl;

                count_outcome++;
            }
        }
    }

    if(count_outcome == 0){
        cout << "No history found." << endl;
    }

    GoTo();
}

void AllTransactionHistory(){

    if(history_length > 0){
        for (int i=0; i < history_length; i++) {
            cout << "-----------------------------------------" << endl;
            cout << "Type\t\t : " << history[i]["Type"] << endl;
            cout << "Nominal\t\t : " << "Rp." << history[i]["Nominal"] << ",00-" << endl;
            cout << "Balance\t\t : " << "Rp." << history[i]["Balance"] << ",00-" << endl;
            if(history[i]["Type"] == "Income"){
                cout << "Source Income\t : " << history[i]["Source Income"] << endl;
            }else{
                cout << "Category\t : " << history[i]["Category"] << endl;
            }
            cout << "Date Time\t : " << history[i]["Date Time"] << endl;
        }
    }else{
        cout << "No history found." << endl;
    }
    
    GoTo();

}

void History(){
    int option;

    if(history_length != 0){
        cout << "\nHistory : " << endl;
        cout << "[1] All Transaction" << endl;
        cout << "[2] Income" << endl;
        cout << "[3] Outcome" << endl;

        cout << "Enter menu (in number) : "; cin >> option;

        switch (option)
        {
            case 1:
                AllTransactionHistory();
                break;
            case 2:
                IncomeHistory();
                break;
            case 3:
                OutcomeHistory();
                break;
            
            default:
                break;
        }
    }else{
        cout << "No history found." << endl;
        GoTo();
    }
    



}

