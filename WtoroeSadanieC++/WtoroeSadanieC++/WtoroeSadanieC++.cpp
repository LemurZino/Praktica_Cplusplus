#include <iostream>
#include <map>

using namespace std;

void remove_all(multimap<int, string> myMap) {


    for (auto it = (++myMap.begin()); it != myMap.end();it++) {
        if (it->second == "Vasya") {
            it = myMap.erase(it);
            continue;
        }
        cout << it->first << " : " << it->second << endl;
    }
}

int main()
{
    multimap<int, string> myMap = { {1, "Vasya"},
                                       {2, "Vasya"},
                                       {3, "Vasya"},
                                       {4, "Nikita"},
                                       {5, "Kolya"},
                                       {6, "Katya"},
                                       {7, "Tanja"},
                                       {8, "Ilja"},
                                       {9, "Sergey"},
                                       {10, "Mitrofan"} };
    remove_all(myMap);
}





