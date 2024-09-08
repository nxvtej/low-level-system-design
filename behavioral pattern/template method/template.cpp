#include <iostream>

// Abstract class defining the template method for sending money
class MoneyTransfer
{
public:
    // Template method
    void transferMoney(double amount)
    {
        if (checkBalance(amount))
        {
            deductFromSender(amount);
            addToReceiver(amount);
            std::cout << "Transfer completed.\n";
        }
        else
        {
            std::cout << "Insufficient balance.\n";
        }
    }

protected:
    double balance = 1000.0; // Common balance for demonstration

    // Common method for checking balance
    bool checkBalance(double amount)
    {
        std::cout << "Checking balance...\n";
        return balance >= amount;
    }

    // Common method for deducting from sender
    void deductFromSender(double amount)
    {
        std::cout << "Deducting " << amount << " from sender's account...\n";
        balance -= amount;
    }

    // Abstract method for adding to receiver's account (to be overridden)
    virtual void addToReceiver(double amount) = 0;
};

// Concrete class for sending money to a friend
class SendToFriend : public MoneyTransfer
{
protected:
    void addToReceiver(double amount) override
    {
        std::cout << "Adding " << amount << " to friend's account.\n";
    }
};

// Concrete class for sending money to anyone else
class SendToAnyone : public MoneyTransfer
{
protected:
    void addToReceiver(double amount) override
    {
        std::cout << "Adding " << amount << " to the receiver's account.\n";
    }
};

// Main function
int main()
{
    SendToFriend friendTransfer;
    SendToAnyone anyoneTransfer;

    std::cout << "Sending to Friend:\n";
    friendTransfer.transferMoney(200); // Transfer to a friend

    std::cout << "\nSending to Anyone:\n";
    anyoneTransfer.transferMoney(500); // Transfer to someone else

    return 0;
}
