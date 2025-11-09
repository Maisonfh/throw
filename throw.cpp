#include <iostream>
#include <thread>
using namespace std;

int arr[20];
int index = 0; 

void producer() {
    for (int i = 1; i <= 20; i++) {
        arr[index] = i; 
        index++; 
        cout << "Виробник Додав: " << i << endl;

  
        for (volatile int j = 0; j < 10000000; j++);
    }
}

void consumer() {
    int consumed = 0;
    while (consumed < 20) {
        if (consumed < index) {
            cout << "Взяв: " << arr[consumed] << endl;
            consumed++;
        }
    }
}

int main() {
	setlocale(LC_ALL, "Ukr");
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    cout << endl << "Програма завершена" << endl;
}
