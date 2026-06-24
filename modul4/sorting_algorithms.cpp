#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            m.comparisons++;
            if (data[j] > data[j + 1])
            {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            m.comparisons++;
            if (data[j] < data[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            std::swap(data[i], data[minIdx]);
            m.swaps++;
        }
    } 

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; i++)
    {
        int key = data[i];
        int j = i -1;

        while (j >= 0)
        {
            m.comparisons++;
            if (data[j] > key)
            {
                data[j + 1] = data[j];
                m.shifts++;
                j--;
            } else
            {
                break;
            }
        }
        if (j + 1 != i)
        {
            data[j + 1] = key;
            m.shifts++;
        }
        
    }
    
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void merge_sort_helper(std::vector<int>& data, int left, int right, Metrics& m)
{
    m.recursive_calls++;

    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort_helper(data, left, mid, m);
    merge_sort_helper(data, mid + 1, right, m);

    std::vector<int> temp;
    temp.reserve(right - left + 1);
 
    int i = left, j = mid + 1;
 
    while (i <= mid && j <= right)
    {
        m.comparisons++;
        if (data[i] <= data[j])
            temp.push_back(data[i++]);
        else
            temp.push_back(data[j++]);
    }
 
    while (i <= mid)   temp.push_back(data[i++]);
    while (j <= right) temp.push_back(data[j++]);
 
    for (int k = 0; k < (int)temp.size(); k++)
        data[left + k] = temp[k];
}
void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (!data.empty())
    merge_sort_helper(data, 0, (int)data.size() -1, m);
    
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

int partition(std::vector<int>& data, int low, int high, Metrics& m)
{
    int pivot = data[high];
    int i = low - 1;
 
    for (int j = low; j < high; j++)
    {
        m.comparisons++;
        if (data[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                std::swap(data[i], data[j]);
                m.swaps++;
            }
        }
    }
 
    if (i + 1 != high)
    {
        std::swap(data[i + 1], data[high]);
        m.swaps++;
    }
    return i + 1;
}
void quick_sort_helper(std::vector<int>& data, int low, int high, Metrics& m)
{
    m.recursive_calls++;
 
    if (low < high)
    {
        int pi = partition(data, low, high, m);
        quick_sort_helper(data, low, pi - 1, m);
        quick_sort_helper(data, pi + 1, high, m);
    }
}
void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (!data.empty())
    quick_sort_helper(data, 0, (int)data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void counting_sort_by_digit(std::vector<int>& data, int exp, Metrics& m)
{
    int n = data.size();
    std::vector<int> output(n);
    int count[10] = {0};
 
    for (int i = 0; i < n; i++)
    {
        int digit = (data[i] / exp) % 10;
        count[digit]++;
        m.array_accesses++;  
    }
 
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
        m.array_accesses++;  
    }
 
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (data[i] / exp) % 10;
        output[count[digit] - 1] = data[i];
        count[digit]--;
        m.array_accesses++;  
        m.array_accesses++;  
    }
 
    for (int i = 0; i < n; i++)
    {
        data[i] = output[i];
        m.array_accesses++;  
    }
}
void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int maxVal = data[0];
    for (int i = 1; i < (int)data.size(); i++)
        if (data[i] > maxVal) maxVal = data[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        counting_sort_by_digit(data, exp, m);
        
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}