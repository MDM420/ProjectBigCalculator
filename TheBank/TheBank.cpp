#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

class account {
public:
    //^^^Define una clase que es publica llamada account con tres variables: accountnumber, accountname y balance. 
    int accountnumber;
    string accountname;
    double balance;

    account(int accnum, string accname, double bal) : accountnumber(accnum), accountname(accname), balance(bal) {}
    //^^^Esto es un tipo de inicializacion, la linea esta asignando los valores pasados como parametros(accnum, accname y bal) a las variables correspondientes(accountnumber, accountname y balance).

    int getaccountnum() const {
        return accountnumber;
    }
    string accountname2() const {
        return accountname;
    }
    double getBalance() const {
        return balance;
    }
    //^^^Estas son funciones que devuelven el numero de cuenta, el nombre de la cuenta y el saldo de la cuenta, respectivamente.
    void deposit(double amount) {
        balance += amount;
        cout << "\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| Your amount has been deposited.      | \n";
        cout << "| New balance: > $" << balance << "    |" << '\n';
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Your amount has been withdrawn.      |\n";
            cout << "| New balance: > $" << balance << "    |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
            return true;
        }
        else {
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Insufficient balance.                |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
            return false;
        }
    }
};
//^^^Las funciones basicamente da el output de cada parte respectivamente, 
//donde dice balance ?? amount, el + aumento de balance, el > verifica si el balance actual es mayor o igual que la cantidad proporcionada y el -  disminuye el balance
class Bank {
public:
    //Como anterior, Esta parte define una clase que es publica llamada bank, con dos variables: account y nextaccountnum.
    vector<account> accounts;
    int nextaccountnum;

    Bank() : nextaccountnum(rand() % 9999 + 1000) {}
    //^^^El rand ayuda a crear un numero de cuenta random.
    void processtransaction(int accnumber, double amount, const string transactiontype) {
        auto it = find_if(accounts.begin(), accounts.end(), [accnumber](const account acc) {
            return acc.getaccountnum() == accnumber;
            });
        //^^^Processtransaction se encarga de realizar una transaccion en una cuenta. Para hacerlo, recibe informacion: 
        //el numero de cuenta (accnumber), la cantidad de dinero involucrada en la transaccion (amount) y el tipo de transaccion (transactiontype), que puede ser deposit o withdraw.
        //El find_if para buscar en la lista de cuentas (accounts) aquella que coincida con el numero de cuenta proporcionado.
        //acc.getaccountnum() == accnumber, compara el numero de cuenta de acc con el numero de cuenta pasado como parametro. Si son iguales, la expresion devuelve true, de lo contrario devuelve false.
        if (it != accounts.end()) {
            if (transactiontype == "deposit") {
                it->deposit(amount);
            }
            else if (transactiontype == "withdraw") {
                it->withdraw(amount);
            }
            //^^^Verifica si se encontro una cuenta con el numero de cuenta especificado.
            //El tipo de transaccion es deposit, se ejecuta la primera parte del bloque(it->deposit(amount)), que realiza un deposito en la cuenta.
            //El tipo de transacci�n es withdraw, se ejecuta la segunda parte del bloque(it->withdraw(amount)), que realiza un retiro de la cuenta.
        }
        else {
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Error: Account doesn't exist.       |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }

    void createaccount(const string& name, double initialDeposit) {
        accounts.push_back(account(nextaccountnum++, name, initialDeposit));
        cout << "\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| Account created                      |\n";
        cout << "| Account Number: > " << nextaccountnum << "               |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
//^^^La funcion le dice al usuario que creo una cuenta y le da su numero, el push_back agrega un nuevo objeto de tipo account a la lista accounts. 
    void accountdetail(int accnumber) {
        auto it = find_if(accounts.begin(), accounts.end(), [accnumber](const account& acc) {
            return acc.getaccountnum() == accnumber;
            });
        //^^^Accountdetail se encarga de buscar una cuenta. Para hacerlo, recibe informacion: 
        //el numero de cuenta (accnumber), la cantidad de dinero involucrada en la transaccion (amount) y el tipo de transaccion (transactionType), que puede ser deposit o withdraw.
        //El find_if para buscar en la lista de cuentas (accounts) aquella que coincida con el numero de cuenta proporcionado.
        //acc.getaccountnum() == accnumber, compara el numero de cuenta de acc con el numero de cuenta pasado como parametro. Si son iguales, la expresion devuelve true, de lo contrario devuelve false.
        if (it != accounts.end()) {
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Account Number: >                    |" << it->getaccountnum() << endl;
            cout << "| Account Holder Name: >               |" << it->accountname2() << endl;
            cout << "| Balance: > $                         |" << it->getBalance() << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
        else {
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Error, account doesn't exists.       |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }

    void closeaccount(int accnumber) {
        auto it = find_if(accounts.begin(), accounts.end(), [accnumber](const account& acc) {
            return acc.getaccountnum() == accnumber;
            });
        //^^^closeaccount se encarga de cerrar una cuenta. Para hacerlo, recibe informacion: 
        //el numero de cuenta (accnumber), la cantidad de dinero involucrada en la transaccion (amount) y el tipo de transaccion (transactionType), que puede ser deposit o withdraw.
        //El find_if para buscar en la lista de cuentas (accounts) aquella que coincida con el numero de cuenta proporcionado.
        //acc.getaccountnum() == accnumber, compara el numero de cuenta de acc con el numero de cuenta pasado como parametro. Si son iguales, la expresion devuelve true, de lo contrario devuelve false.
        if (it != accounts.end()) {
            accounts.erase(it);
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Account closed.                      |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
        else {
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Error, account doesn't exists.       |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }
};

int main() {
    Bank bank;
    int accnumber, option;
    string name;
    double initialdeposit, amount;

    do {
        cout << "\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| 1. Create Account                    |\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| 2. Deposit                           |\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| 3. Withdraw                          |\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| 4. Check Balance                     |\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| 5. Close Account                     |\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| 6. Exit                              |\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Select your choice: ";
        //^^^Este es el menu de opciones.
        /*************************************************************/
        //Esta parte se utilizo ai(chatgbt), la razon que solo se ponga un numero no letra.
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Invalid, please choose 1-6 only.     |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            continue;
        }
        /*****************************************************************/
        switch (option) {
        case 1: {
            cout << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Put account holder name: > ";
            cin >> name;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "| Put initial deposit amount: > ";
            cin >> initialdeposit;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            bank.createAccount(name, initialdeposit);
            break;
        }
        case 2: {
            cout << "Put account number: > ";
            cin >> accnumber;
            cout << "Put deposit amount: > ";
            cin >> amount;
            bank.processtransaction(accnumber, amount, "deposit");
            break;
        }
        case 3: {
            cout << "Put account number: > ";
            cin >> accnumber;
            cout << "Put withdrawal amount: > ";
            cin >> amount;
            bank.processtransaction(accnumber, amount, "withdraw");
            break;
        }
        case 4: {
            cout << "Put account number: > ";
            cin >> accnumber;
            bank.accountDetail(accnumber);
            break;
        }
        case 5: {
            cout << "Put account number to close: > ";
            cin >> accnumber;
            bank.closeAccount(accnumber);
            break;
        }
        case 6:
            cout << "Exiting, the program will no longer keep going." << endl;
            break;
        default:
            cout << "Invalid, please choose 1-6 only." << endl;
        }
        //^^^Da el output de la opcion que eligio, bank...(accnumber) hace que llame la funcion de la clase que esta localizada.
    } while (option != 6);

    return 0;
}
