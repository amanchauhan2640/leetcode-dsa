class Bank {
private:
    vector<long long> balance; // store account balances

    // helper to check if an account number is valid
    bool isValid(int account) {
        return account >= 1 && account <= balance.size();
    }

public:
    // Constructor
    Bank(vector<long long>& initialBalance) {
        balance = initialBalance; // store initial balances
    }
    
    // Transfer money from account1 to account2
    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2)) return false;
        if (balance[account1 - 1] < money) return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    // Deposit money into an account
    bool deposit(int account, long long money) {
        if (!isValid(account)) return false;

        balance[account - 1] += money;
        return true;
    }
    
    // Withdraw money from an account
    bool withdraw(int account, long long money) {
        if (!isValid(account)) return false;
        if (balance[account - 1] < money) return false;

        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */