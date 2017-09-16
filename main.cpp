#include <iostream>
#include <functional>
#include <vector>

using namespace std;

bool isSorted(const vector<int>& values) {

    for(unsigned int i = 0; i < values.size()-1; i++){
        if(values[i] > values[i+1]){
            return false;
        }
    }

    return true;
}

void printVector(vector<int> values, int lowestIndex, int highestIndex){
    for(int i = lowestIndex; i <= highestIndex; i++){
        cout << values[i];
        unsigned int n = i;
        if(n != values.size()-1){
            cout << ", ";
        }
    }
    cout << endl;
}

void merge(vector<int>& values, int lowest, int highest, int middle){

    vector<int> newValues;

    int lowIndex = lowest;
    int midIndex = middle + 1;

    while(lowIndex <= middle && midIndex <= highest){

        if(values[lowIndex] < values[midIndex]){
            newValues.push_back(values[lowIndex]);
            lowIndex++;
        }
        else{
            newValues.push_back(values[midIndex]);
            midIndex++;
        }
    }

    while(lowIndex <= middle){
        newValues.push_back(values[lowIndex]);
        lowIndex++;
    }

    while(midIndex <= highest){
        newValues.push_back(values[midIndex]);
        midIndex++;
    }

    for (int i = lowest; i <= highest; i++){
        values[i] = newValues[i-lowest];
    }
}

void mergeSortRecursive(vector<int>& values, int lowestIndex, int highestIndex){

    int middleIndex;

    if(lowestIndex < highestIndex){
        middleIndex = (lowestIndex+highestIndex)/2;

        mergeSortRecursive(values, lowestIndex, middleIndex);
        mergeSortRecursive(values, middleIndex+1, highestIndex);

        merge(values, lowestIndex, highestIndex, middleIndex);
    }

}

void mergeSort(vector<int>& values){
    int lowestIndex = 0;
    int highestIndex = values.size()-1;

    mergeSortRecursive(values, lowestIndex, highestIndex);
}

class Thing{
public:
    int num;
    int id;
    Thing(int id);
};

Thing::Thing(int id) {
this->id = id;
}

bool compareThingsById(Thing a, Thing b){
    return a.id < b.id;
}

void merge(vector<Thing>& values, int lowest, int highest, int middle, function<bool(Thing a, Thing b)> comp){

    vector<int> newValues;

    int lowIndex = lowest;
    int midIndex = middle + 1;

    while(lowIndex <= middle && midIndex <= highest){

        if(comp(values[lowIndex], values[midIndex])){
            newValues.push_back(values[lowIndex]);
            lowIndex++;
        }
        else{
            newValues.push_back(values[midIndex]);
            midIndex++;
        }
    }

    while(lowIndex <= middle){
        newValues.push_back(values[lowIndex]);
        lowIndex++;
    }

    while(midIndex <= highest){
        newValues.push_back(values[midIndex]);
        midIndex++;
    }

    for (int i = lowest; i <= highest; i++){
        values[i] = newValues[i-lowest];
    }
}

void mergeSortRecursive(vector<Thing>& values, int lowestIndex, int highestIndex, function<bool(Thing a, Thing b)> comp){

    int middleIndex;

    if(lowestIndex < highestIndex){
        middleIndex = (lowestIndex+highestIndex)/2;

        mergeSortRecursive(values, lowestIndex, middleIndex, comp);
        mergeSortRecursive(values, middleIndex+1, highestIndex, comp);

        merge(values, lowestIndex, highestIndex, middleIndex, comp);
    }

}

void mergeSort(vector<Thing>& values, function<bool(Thing a, Thing b)> comp){
    int lowestIndex = 0;
    int highestIndex = values.size()-1;

    mergeSortRecursive(values, lowestIndex, highestIndex, comp);
}

int main(){

    vector<int> nums;
    for(int i = 0; i < 13; i++){
        nums.push_back(rand() % 11);
    }

    printVector(nums, 0, nums.size()-1);

    mergeSort(nums);
    printVector(nums, 0, nums.size()-1);
    /*
    mergeSort(nums);
    printVector(nums, 0, nums.size()-1);
    mergeSort(nums);
    printVector(nums, 0, nums.size()-1);
    mergeSort(nums);
    printVector(nums, 0, nums.size()-1);
    mergeSort(nums);
    printVector(nums, 0, nums.size()-1);
    */
}
