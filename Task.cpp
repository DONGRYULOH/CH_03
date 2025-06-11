#include <iostream>
#include <algorithm> // sort()를 위해 필요
using namespace std;
   
template<typename T>
class SimpleVector {
public:
    SimpleVector() : curCapacity(10), curSize(0) {
        data = new T[10];        
    }

    SimpleVector(int capacity) {
        data = new T[capacity];
        curCapacity = capacity;
        curSize = 0;
    }

    ~SimpleVector() {
        delete[] data;
    }

    // 복사 생성자
    SimpleVector(const SimpleVector& other) {
        data = new T[other.curCapacity]; // 깊은 복사
        curSize = other.curSize;
        curCapacity = other.curCapacity;

        // 데이터 복사
        for (int i = 0; i < other.curSize; i++) {
            data[i] = other.data[i];
        }
    }

public:
    void memoryExpansion(int capacity) {
        T* newArr = new T[capacity];
        for (int i = 0; i < curSize; i++) {
            newArr[i] = data[i];
        }
        delete[] data;
        data = newArr;
    }

    void push_back(const T& val) {
        // 1.원소 개수가 Capacity만큼 차면 용량 증설
        if (curSize == curCapacity) {
            curCapacity += 5;
            memoryExpansion(curCapacity);
        }

        // 2.push
        data[curSize++] = val;
    }

    void pop_back() {
        if (curSize > 0) {
            --curSize;
        }
    }

    int size() {
        return curSize;
    }

    int capacity() {
        return curCapacity;
    }

    void resize(int newCapacity) {
        if (newCapacity <= curCapacity) return;
        memoryExpansion(newCapacity);        
    }

    void sortData() {
        sort(data, data + curSize);
    }

    void printData() {
        for (int i = 0; i < curSize; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

public:
    T* data;
    int curSize;
    int curCapacity;
};

int main()
{
    cout << "===vector1 생성===" << endl;
    SimpleVector<int> vector1;
    vector1.push_back(10);
    vector1.push_back(30);
    vector1.push_back(20);
    vector1.sortData();
    vector1.printData();

    cout << "===vector2 복사 생성자===" << endl;
    SimpleVector<int> vector2 = vector1;    
    vector2.push_back(50);
    vector2.push_back(60);
    vector2.push_back(70);
    vector2.push_back(80);
    vector2.push_back(90);
    vector2.push_back(100);
    vector2.push_back(110);
    cout << vector2.capacity() << endl;
    vector2.printData();

    vector2.push_back(120); // capacity가 증설되면 vector1에 영향이 끼치는 이유는?
    cout << vector2.capacity() << endl;
    vector2.printData();

    cout << "===vector1 데이터 출력==" << endl;
    vector1.printData();
}
