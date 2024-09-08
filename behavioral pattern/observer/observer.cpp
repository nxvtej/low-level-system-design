#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Subscriber class (Observer)
class Subscriber
{
private:
    std::string name;

public:
    Subscriber(const std::string &name) : name(name) {}

    void update(const std::string &article)
    {
        std::cout << name << " received new article: " << article << std::endl;
    }
};

// Publisher class (Subject)
class Publisher
{
private:
    std::vector<Subscriber *> subscribers;
    std::string latestArticle;

public:
    void subscribe(Subscriber *subscriber)
    {
        subscribers.push_back(subscriber);
    }

    void unsubscribe(Subscriber *subscriber)
    {
        subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
    }

    void notify()
    {
        for (Subscriber *subscriber : subscribers)
        {
            subscriber->update(latestArticle);
        }
    }

    void publishArticle(const std::string &article)
    {
        latestArticle = article;
        notify();
    }
};

// Main function
int main()
{
    Publisher publisher;

    Subscriber alice("Alice");
    Subscriber bob("Bob");

    publisher.subscribe(&alice);
    publisher.subscribe(&bob);

    publisher.publishArticle("Breaking News: Observer Pattern Simplified!");

    publisher.unsubscribe(&alice);

    publisher.publishArticle("Update: Subscriber Alice Unsubscribed!");

    return 0;
}
