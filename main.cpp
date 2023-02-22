#include <iostream>
#include <vector>
#include <random>

void bubbleSort(std::vector<int> list) {

    int i = 0;

    while (i < list.size()){
        if (list[i + 1] < list[i]){

            int o = list[i];
            int p = list[i + 1];

            list[i] = p;
            list[i + 1] = o;

            i++;

        } else {
            i++;
        }
    }
}

int main() {

    std::vector<int> vec;

    int i = 0;

    while (i < 1000) {

    }

    return 0;
}