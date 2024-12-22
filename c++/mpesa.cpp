#include <iostream>
#include <iomanip>
using namespace std;

double sendMoney (double balanceAmnt);
double withdraw(double balanceAmnt);
double buyAirtime(double balanceAmnt);
double loansSaving(double balanceAmnt, double loansAmnt);
double lipaMpesa (double balanceAmnt);
void myAcc(double balanceAmnt);

int main () {
    int choice;
    double balanceAmnt = 500;
    double loansAmnt = 0.0;

    cout << "---------M-Pesa----------\n";

    do {
        cout <<"Select an option\n" <<"\n";
        cout << "1.Send Money\n" << "2.Withdraw Cash\n" <<"3.Buy Airtime\n"
        <<"4.Loans and Savings\n" <<"5.Lipa na MPesa\n" <<"6.My Account\n";
        cout << "7.Exit\n";
        cout << "___________________\n";
        cin >> choice;

        cin.clear();

        switch (choice)
        {
        case 1: balanceAmnt = sendMoney(balanceAmnt);
                break;
        case 2:  balanceAmnt = withdraw(balanceAmnt);
                break;  
        case 3: balanceAmnt = buyAirtime(balanceAmnt);
                break;
        case 4: balanceAmnt = loansSaving(balanceAmnt, loansAmnt);
                break;
        case 5: balanceAmnt = lipaMpesa(balanceAmnt);
                break;
        case 6: myAcc(balanceAmnt);
                break;
        case 7: cout <<"Thanks for using Mpesa\n";
                break;
        default: cout <<"Invalid option";
                break;
        }

    } while (choice != 7);

    return 0;
}

double sendMoney(double balanceAmnt)  {
    string mobileNo;
    double amount;
    int choice;

    cout << "Enter Mobile Number: \n";
    cin >> mobileNo;

    cout << "Enter Amount: \n";
    cin >> amount;

    cout <<"----------------------------\n";
    cout << "Confirm you want to send ksh." <<amount <<std::setprecision(2) <<fixed << " to "<<mobileNo <<"\n" <<"1.Yes\n" <<"2.No\n";
    cin >> choice;

    if(balanceAmnt >= amount){
        switch (choice) {
            case 1: cout <<"----------------------------\n";
                    cout <<"ksh." <<amount <<std::setprecision(2) <<std::fixed <<" sent to " <<mobileNo <<'\n'; 
                    cout <<"----------------------------\n";
                    balanceAmnt -= amount;
                    break;
            case 2: cout <<"----------------------------\n";
                    cout <<"You have stopped payments of ksh." <<amount <<std::setprecision(2) <<std::fixed <<" to "<<mobileNo;
                    cout <<"----------------------------\n";
                    break;
        }
    } else {
        cout << "//////////////////////////\n";
        cout <<"Insufficient Funds\n";
        cout << "/////////////////////////\n";
    } 

    return balanceAmnt;
}

double withdraw(double balanceAmnt) {
    int choice;
    string agentNo;
    double amount;
    string storeNo;
    string atmNO;

    cout << "withdraw cash\n";
    cout << "1.ATM\n" <<"2.Agent\n";
    cin >> choice;
     
    if(choice == 1){
        cout << "Enter Atm Number\n";
        cin >> atmNO;

        cout << "Enter Amount\n";
        cin >>amount;

        if(balanceAmnt >= amount){
            cout <<"----------------------------\n";
            cout << "Confirm withdrawal of " <<amount <<std::setprecision(2) <<std::fixed << " from " <<atmNO <<endl <<"1.Yes\n" <<"2.No\n";
            cin >> choice;

            switch (choice) {
            case 1: cout <<"////////////////////////////\n";
                    cout <<"ksh." <<amount <<std::setprecision(2) <<std::fixed <<" sent to " <<atmNO <<'\n'; 
                    cout <<"////////////////////////////\n";
                    balanceAmnt -= amount;
                    break;
            case 2: cout <<"////////////////////////////\n";
                    cout <<"You have stopped payments of ksh." <<amount <<std::setprecision(2) <<std::fixed <<" to "<<agentNo;
                    cout <<"////////////////////////////\n";
                    break;
            }
        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }
    } else if(choice == 2){
        cout << "Enter Agent Number\n";
        cin >> agentNo;

        cout <<"Enter Store Number\n";
        cin >> storeNo;

        cout << "Enter Amount\n";
        cin >>amount;

        if(balanceAmnt >= amount){
            cout <<"----------------------------\n";
            cout << "Confirm withdrawal of " <<amount <<std::setprecision(2) <<std::fixed << " from " <<agentNo <<endl <<"1.Yes\n" <<"2.No\n";
            cin >> choice;

            switch (choice) {
            case 1: cout <<"////////////////////////////\n";
                    cout <<"ksh." <<amount <<std::setprecision(2) <<std::fixed <<" sent to " <<agentNo <<'\n'; 
                    cout <<"////////////////////////////\n";
                    balanceAmnt -= amount;
                    break;
            case 2: cout <<"////////////////////////////\n";
                    cout <<"You have stopped payments of ksh." <<amount <<std::setprecision(2) <<std::fixed <<" to "<<agentNo;
                    cout <<"////////////////////////////\n";
                    break;
            }

        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }
    } else {
        cout <<"////////////////////////////\n";
        cout << "Invalid choice";
    }


    return balanceAmnt;
}

double buyAirtime(double balanceAmnt) {
    int choice; 
    double amount;
    string mobileNO;

    cout << "1.My Phone\n" <<"2.Others\n";
    cin >> choice;

    if(choice == 1) {
        cout << "Amount";
        cin >> amount;

        if(balanceAmnt >= amount){
            balanceAmnt -= amount;
        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }

    } else if (choice == 2) {
        cout << "Enter Phone Number\n";
        cin >> mobileNO;

        cout << "Enter Amount\n";
        cin >> amount;

        if(balanceAmnt >= amount) {
            cout <<"----------------------------\n";
            cout << "Buy airtime of ksh." <<amount <<std::setprecision(2) <<std::fixed <<" for " <<mobileNO <<endl <<"1.Yes\n2.No\n";
            cin >> choice;

            switch (choice) {
                case 1: cout <<"////////////////////////////\n";
                        cout << "You have bought airtime ksh." <<amount <<std::setprecision(2) <<std::fixed <<" for "<<mobileNO <<endl;
                        cout <<"////////////////////////////\n";
                        balanceAmnt -= amount;
                        break;
                case 2: cout <<"////////////////////////////\n";
                        cout <<"You have cancelled airtime of "<<amount <<std::setprecision(2) <<std::fixed <<" for "<<mobileNO <<endl;
                        cout <<"////////////////////////////\n";
                        break;
            }
            
        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }

    } else{
        cout <<"////////////////////////////\n";
        cout << "Invalid Option";
    }

    return balanceAmnt;
}

double loansSaving(double balanceAmnt, double loansAmnt) {
    int choice;
    double amount;

    cout << "1.Mshwari\n2.KCB\n"; 
    cin >> choice;

    if(choice == 1) {
        cout <<"Enter amount\n";
        cin >> amount;

        if (balanceAmnt >= amount) {
            cout <<"----------------------------\n";
            cout <<"Confirm "<<amount <<std::setprecision(2) <<std::fixed <<" sent to your Mshwari account\n1.Yes\n2.No";
            cin >> choice;
            cout <<"----------------------------\n";

            switch (choice) {
                case 1: cout <<"////////////////////////////\n";
                        cout <<"ksh."<<amount <<std::setprecision(2) <<std::fixed <<" sent to your acccount" <<endl;
                        balanceAmnt -= amount;
                        loansAmnt += amount;
                        cout << "Savings Amount ksh." <<loansAmnt <<endl;
                        cout <<"////////////////////////////\n";
                        break;
                case 2: cout <<"////////////////////////////\n";
                        cout <<"You have cancelled transation of amount "<<amount <<std::setprecision(2) <<std::fixed <<" to your account\n";
                        cout <<"////////////////////////////\n";
                        break;
                default:cout <<"////////////////////////////\n";
                        cout << "Invalid\n";
                    break;
            }
        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }
    } else if (choice == 2) {
        cout <<"Enter amount\n";
        cin >> amount;

        if(balanceAmnt >= amount) {
            cout <<"----------------------------\n";
            cout <<"Confirm "<<amount <<std::setprecision(2) <<std::fixed <<" sent to your KCB account\n1.Yes\n2.No";
            cin >> choice;
            cout <<"----------------------------\n";

            switch (choice) {
                case 1: cout <<"////////////////////////////\n";
                        cout <<"ksh."<<amount <<std::setprecision(2) <<std::fixed <<" sent to your acccount";
                        cout <<"////////////////////////////\n";
                        balanceAmnt -= amount;
                        break;
                case 2: cout <<"////////////////////////////\n";
                        cout <<"You have cancelled transation of amount "<<amount <<std::setprecision(2) <<std::fixed <<" to your account\n";
                        cout <<"////////////////////////////\n";
                        break;
                default:cout <<"////////////////////////////\n";
                        cout << "Invalid\n";
                    break;
            }
        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }
    } else {
        cout <<"////////////////////////////\n";
        cout <<"Invalid option\n";
    }

    return balanceAmnt;
};

double lipaMpesa (double balanceAmnt){
    double amount ;
    int choice;
    string payBill;
    string accNo;
    string till;

    cout << "1.Paybil\n2.Buy Goods\n3.Pochi La Biashara\n";
    cin>> choice;

    if (choice == 1) {
        cout <<"Enter Paybill\n";
        cin >> payBill;

        cout <<"Enter Account Number\n";
        cin >> accNo;

        cout << "Enter Amount\n";
        cin >> amount;

        if (balanceAmnt >= amount) {
            cout <<"----------------------------\n";
            cout << "Confirm Payment of "<<amount <<std::setprecision(2) <<std::fixed << " to" <<payBill <<endl <<"1.Yes\n" <<"2.No";
            cin >> choice;
            cout <<"----------------------------\n";

            switch(choice) {
                case 1: cout <<"////////////////////////////\n";
                        cout <<"Payments of "<<amount <<std::setprecision(2) <<std::fixed <<" made to "<<payBill <<endl;
                        balanceAmnt -= amount;
                        cout <<"////////////////////////////\n";
                        break;
                case 2: cout <<"////////////////////////////\n";
                        cout << "You have cancel payments of "<<amount <<std::setprecision(2) <<std::fixed <<" made to " <<payBill;
                        break;
            }

        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }
    } else if(choice == 2) {
        cout << "Enter Till\n";
        cin >> till;

        cout << "Enter Amount\n";
        cin >> amount;

        if(balanceAmnt >= amount) {
            cout <<"----------------------------\n";
            cout << "Confirm Payments of "<<amount <<std::setprecision(2) <<std::fixed <<" made to "<<till <<endl <<"1.Yes\n" <<"2.No\n";
            cin >> choice;
            cout <<"----------------------------\n";

            switch (choice)
            {
            case 1: cout <<"////////////////////////////\n";
                    cout <<"Payments of " <<amount <<std::setprecision(2) <<std::fixed <<" made to "<<till;
                    cout <<"////////////////////////////\n";
                    balanceAmnt -= amount;
                    break;
            case 2: cout <<"////////////////////////////\n";
                    cout <<"You have Canceled Payments of ksh."<<amount <<std::setprecision(2) <<std::fixed <<" for "<<till;
                    break;
            }
        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }
    } else if(choice == 3) {
        string mobileNo;

        cout <<"Enter Phone Number\n";
        cin >> mobileNo;

        cout <<"Enter Amount\n";
        cin >> amount;

        if (balanceAmnt >= amount) {
            cout <<"----------------------------\n";
            cout <<"Confirm Payments of "<<amount <<std::setprecision(2) <<std::fixed <<" to "<<mobileNo <<endl <<"1.Yes\n2.No\n";
            cin >> choice;
            cout <<"----------------------------\n";

            switch (choice){
                case 1: cout <<"////////////////////////////\n";
                        cout <<"Payments of ksh."<<amount <<std::setprecision(2) <<std::fixed <<" made to "<<mobileNo;
                        cout <<"////////////////////////////\n";
                        balanceAmnt -= amount;
                        break;
                case 2: cout <<"////////////////////////////\n";
                        cout <<"You have cancelled payments of ksh."<<amount <<std::setprecision(2) <<std::fixed <<" for "<<mobileNo;
                        break;
            }
        } else {
            cout <<"////////////////////////////\n";
            cout << "Insufficient Funds\n";
            cout <<"////////////////////////////\n";
        }
    } else {
        cout <<"////////////////////////////\n";
        cout <<"Invalid option";
    }
    return balanceAmnt;
}

void myAcc(double balanceAmnt) {

    cout <<"////////////////////////////\n";
    cout << "Your is Balance ksh." << balanceAmnt <<endl;
    cout <<"////////////////////////////\n";
    
};
