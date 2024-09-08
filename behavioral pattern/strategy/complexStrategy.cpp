#include <iostream>
#include <vector>

// Strategy Interface
class SortingStrategy
{
public:
    virtual void sort(std::vector<int> &data) = 0; // Pure virtual function
    virtual ~SortingStrategy() {}
};

// Concrete Strategy 1: Bubble Sort
class BubbleSort : public SortingStrategy
{
public:
    void sort(std::vector<int> &data) override
    {
        int n = data.size();
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (data[j] > data[j + 1])
                {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
        std::cout << "Sorted using Bubble Sort\n";
    }
};

// Concrete Strategy 2: Quick Sort
class QuickSort : public SortingStrategy
{
private:
    int partition(std::vector<int> &data, int low, int high)
    {
        int pivot = data[high];
        int i = (low - 1);
        for (int j = low; j < high; ++j)
        {
            if (data[j] < pivot)
            {
                ++i;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return (i + 1);
    }

    void quickSort(std::vector<int> &data, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(data, low, high);
            quickSort(data, low, pi - 1);
            quickSort(data, pi + 1, high);
        }
    }

public:
    void sort(std::vector<int> &data) override
    {
        quickSort(data, 0, data.size() - 1);
        std::cout << "Sorted using Quick Sort\n";
    }
};

// Context class
class SortContext
{
private:
    SortingStrategy *strategy;

public:
    SortContext(SortingStrategy *strategy) : strategy(strategy) {}

    void setStrategy(SortingStrategy *strategy)
    {
        this->strategy = strategy;
    }

    void executeStrategy(std::vector<int> &data)
    {
        strategy->sort(data);
    }
};

// Main function
int main()
{
    std::vector<int> data = {34, 7, 23, 32, 5, 62};

    // Use Bubble Sort
    SortContext context(new BubbleSort());
    context.executeStrategy(data);

    // Output sorted array
    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Use Quick Sort
    context.setStrategy(new QuickSort());
    context.executeStrategy(data);

    // Output sorted array
    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
