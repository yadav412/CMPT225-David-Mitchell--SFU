#include <iostream>
#include <vector>
#include <string>
#include <utility>  // for std::pair

using namespace std;

class IndPQ {
private:
    // Inner class representing the heap
    class Heap {
    public:
        vector<pair<int, string>> heapArray; // stores pairs (priority, taskID)

        // Helper functions for heap operations
        void percolate_up(int index) {
            int parent = (index - 1) / 2;
            while (index > 0 && heapArray[index].first < heapArray[parent].first) {
                swap(heapArray[index], heapArray[parent]);
                index = parent;
                parent = (index - 1) / 2;
            }
        }

        void percolate_down(int index) {
            unsigned int left = 2 * index + 1;
            unsigned int right = 2 * index + 2;
            unsigned int smallest = index;
            unsigned int indexcopy=index;

            if (left < heapArray.size() && heapArray[left].first < heapArray[smallest].first) {
                smallest = left;
            }

            if (right < heapArray.size() && heapArray[right].first < heapArray[smallest].first) {
                smallest = right;
            }

            if (smallest != indexcopy) {
                swap(heapArray[index], heapArray[smallest]);
                percolate_down(smallest);
            }
        }

        void insert(const std::string& taskid, int priority) {
            heapArray.push_back(std::make_pair(priority, taskid));
            percolate_up(heapArray.size() - 1);
        }

        string& deleteMin() {
            if (heapArray.empty()) {
                throw std::out_of_range("Heap is empty");
            }

            std::string& minTask = heapArray[0].second; // Get the task ID of the min task
            heapArray[0] = heapArray.back(); // Replace the root with the last element
            heapArray.pop_back();
            if (!heapArray.empty()) {
                percolate_down(0);
            }

            return minTask;
        }

        std::string& getMin() {
            if (heapArray.empty()) {
                throw std::out_of_range("Heap is empty");
            }
            return heapArray[0].second; // Return the task ID of the root element
        }
    };

    // Inner class representing the map
    class HMap {
    public:
        std::vector<std::pair<std::string, int>> map;  // Map of taskid to index

        int find(const std::string& taskid) {
            for (unsigned int i = 0; i < map.size(); ++i) {
                if (map[i].first == taskid) {
                    return i;  // Return index of task
                }
            }
            return -1;  // Task not found
        }

        void insert(const std::string& taskid, int index) {
            map.push_back(std::make_pair(taskid, index));
        }

        void remove(const std::string& taskid) {
            int index = find(taskid);
            if (index != -1) {
                map.erase(map.begin() + index);  // Remove the task from the map
            }
        }
    };

    Heap heap;  // Instance of the Heap class
    HMap map;   // Instance of the HMap class

public:
    IndPQ() {}

    void insert(const std::string& taskid, int priority) {
        heap.insert(taskid, priority);
        map.insert(taskid, heap.heapArray.size() - 1);
    }

    std::string& deleteMin() {
        std::string& minTask = heap.deleteMin();
        // After deleting, update map to reflect the changes
        map.remove(minTask);
        return minTask;
    }

    std::string& getMin() {
        return heap.getMin();
    }

    void updatePriority(const std::string& taskid, int newPriority) {
        int index = map.find(taskid);
        if (index != -1) {
            heap.heapArray[index].first = newPriority;
            if (newPriority < heap.heapArray[(index - 1) / 2].first) {
                heap.percolate_up(index);
            } else {
                heap.percolate_down(index);
            }
        }
    }

    void remove(const std::string& taskid) {
        int index = map.find(taskid);
        unsigned int index2 = map.find(taskid);
        if (index != -1) {
            std::swap(heap.heapArray[index], heap.heapArray.back());
            heap.heapArray.pop_back();
            map.remove(taskid);
            if (index2 < heap.heapArray.size()) {
                heap.percolate_down(index);
                heap.percolate_up(index);
            }
        }
    }

    bool isEmpty() {
        return heap.heapArray.empty();
    }

    int size() {
        return heap.heapArray.size();
    }

    void clear() {
        heap.heapArray.clear();
        map.map.clear();
    }

    void display() {
        if (isEmpty()) {
            std::cout << "The queue is empty." << std::endl;
            return;
        }

        std::cout << "Heap contents:" << std::endl;
        for (const auto& pair : heap.heapArray) {
            std::cout << "Task: " << pair.second << ", Priority: " << pair.first << std::endl;
        }
    }

    void ddisplay() {
        std::cout << "Heap contents:" << std::endl;
        for (const auto& pair : heap.heapArray) {
            std::cout << "Task: " << pair.second << ", Priority: " << pair.first << std::endl;
        }

        std::cout << "Map contents:" << std::endl;
        for (const auto& pair : map.map) {
            std::cout << "Task: " << pair.first << " -> Index: " << pair.second << std::endl;
        }
    }
};
