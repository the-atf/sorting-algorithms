#include <iostream>
#include <vector>
#include <random>

std::vector<int> bubbleSort(std::vector<int> list) {

    int i = 0;
    int b = 0;

    while (true){

        if (list[i + 1] < list[i]){

            int o = list[i];
            int p = list[i + 1];

            list[i] = p;
            list[i + 1] = o;

            i++;

            b = 0;

        } else {
            i++;
            b++;
        }

        if (b >= list.size() - 1) {
            break;
        }

        if (i >= list.size() - 1) {
            i = 0;
        }

    }

    return list;
}

void quickSortHelper(std::vector<int>& list, int start, int end) {
    if (start < end) {
        int pivot = list[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (list[j] <= pivot) {
                i++;
                std::swap(list[i], list[j]);
            }
        }
        std::swap(list[i + 1], list[end]);
        int pivotIndex = i + 1;
        quickSortHelper(list, start, pivotIndex - 1);
        quickSortHelper(list, pivotIndex + 1, end);
    }
}

std::vector<int> quickSort(std::vector<int> list) {
    quickSortHelper(list, 0, list.size() - 1);
    return list;
}

int main() {

    std::vector<int> vec;
    std::random_device rd;
    std::mt19937_64 gen(rd());

    int selection;
    int varnum;

    std::cout << "How many elements do you want in the array?" << std::endl;
    std::cin >> varnum;

    std::uniform_int_distribution<> distr(1, varnum);
    int i = 0;

    std::cout << "Filling array with numbers... ";

    while (i < varnum) {

        vec.push_back(distr(gen));
        i++;

    }

    std::cout << "Done!" << std::endl;

    std::cout << "Which algorithm do you want to use?\n 1: Bubble sort\n 2: QuickSort" << std::endl;
    std::cin >> selection;

    if (selection == 1){

        char printask;

        std::cout << "Sorting... ";
        vec = bubbleSort(vec);
        std::cout << "Done!" << std::endl;

        std::cout << "Would you like to print out the sorted array? y/n" << std::endl;
        std::cin >> printask;

        if (printask == 'y'){

            for(int item : vec){
                std::cout << item << " ";
            }

        } else {
            return 0;
        }
    } else if (selection == 2){
        char printask;

        std::cout << "Sorting... ";
        vec = quickSort(vec);
        std::cout << "Done!" << std::endl;

        std::cout << "Would you like to print out the sorted array? y/n" << std::endl;
        std::cin >> printask;

        if (printask == 'y'){

            for(int item : vec){
                std::cout << item << " ";
            }

        } else {
            return 0;
        }
    }

}