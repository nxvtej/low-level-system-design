#include <iostream>
#include <mutex>

class Singleton
{
private:
    static Singleton *instance;
    static std::mutex mtx; // Mutex for thread-safety

    // Private constructor to prevent instantiation
    Singleton()
    {
        std::cout << "Singleton instance created.\n";
    }

    // Deleted copy constructor and assignment operator
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    // Static method to provide global access to the Singleton instance
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {                                          // First check (no locking)
            std::lock_guard<std::mutex> lock(mtx); // Lock mutex
            if (instance == nullptr)
            {                               // Second check (after locking)
                instance = new Singleton(); // Lazy initialization
            }
        }
        return instance;
    }

    // Example method for demonstration
    void showMessage() const
    {
        std::cout << "Hello from Singleton!\n";
    }
};

// Initialize static members
Singleton *Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main()
{
    // Access the singleton instance
    Singleton *singleton1 = Singleton::getInstance();
    Singleton *singleton2 = Singleton::getInstance();

    // Call a method on the Singleton instance
    singleton1->showMessage();

    // Check if both references point to the same instance
    if (singleton1 == singleton2)
    {
        std::cout << "Both are the same instance.\n";
    }

    return 0;
}
