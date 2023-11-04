#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    vector<int> v1 = {0,1,2,3};

    cout << v1.size() << '\n';
    v1.push_back(4);

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << ' ';
    cout << '\n';
    v1.pop_back(); // 0 1 2 3

    v1.insert(v1.end()-1, 7); // 0 1 2 7 3

    v1.erase(v1.end() - 2); // 0 1 2 3

    for (auto temp : v1)
        cout << temp << ' ';
}