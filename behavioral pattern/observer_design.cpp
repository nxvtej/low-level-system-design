#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <map>
#include <set>
#include <list>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

#define pb push_back

#define qi queue<int>
#define qp queue<pair<int, int>>
#define ff front().first
#define fs front().second

using namespace std;

class Subscriber
{
public:
    virtual void notify(string &s) = 0;
};

class User : public Subscriber
{
private:
    int userId;

public:
    User(int userId)
    {
        this->userId = userId;
    }

    void notify(string &s)
    {
        cout << "User " << userId << " received message " << s << endl;
    }
};

class Group
{
private:
    string unsubscribe_message = "you unsubscribed";

    list<Subscriber *> subscribers;

public:
    void subscribe(Subscriber *subscribe)
    {
        subscribers.pb(subscribe);
    }

    void unsubscribe(Subscriber *subscribe)
    {
        subscribers.remove(subscribe);

        subscribe->notify(unsubscribe_message);
        delete subscribe;
    }

    void notify(string &message)
    {
        for (auto &subscriber : subscribers)
        {
            subscriber->notify(message);
        }
    }
};

int main()
{
    Group *group = new Group;

    // Add subscribers to the group
    User *user1 = new User(1);
    User *user2 = new User(2);
    User *user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    string message;
    cout << "enter message for subscribers: ";
    getline(cin, message);
    group->notify(message);

    // Unsubscribe a subscriber
    group->unsubscribe(user2);

    cout << "gift updated subscribers new laptop\n";
    getline(cin, message);
    group->notify(message);
    return 0;
}