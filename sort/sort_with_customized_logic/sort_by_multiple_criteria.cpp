//sort(v.begin(), v.end()) sorts a vector v
//sort(arr, arr+N, cmp); cmp is a function that defines customized order

#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7;

struct Person {
    public:
    Person(int h, int w){
        height = h;
        weight = w;
    }
    int height;
    int weight;
};

bool cmp(Person a, Person b) {
    if(a.height == b.height) {
        return a.weight < b.weight;
    }
    return a.height < b.height;
}
int main() {
    Person arr[SIZE] = {
        Person(175,75), Person(185, 76),Person(190, 80),Person(164,60),
        Person(173,90), Person(176, 67), Person(179,81)
    };

    sort(arr, arr+SIZE, cmp); // sorts the array in ascending order by height and
//then weight if the heights are equal 
    for (Person p: arr)
    {
        cout << p.height << endl;
    }
}