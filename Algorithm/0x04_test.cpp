#include <list>
#include <iostream>

using namespace std;

int main(void)
{
    //// 1. list 초기화와 auto 순회
    list<int> L1 = {1,2, 3};

    for (auto temp : L1)
        cout << temp << ' ';
    cout << '\n'; // 1 2 3

    //// 2. iterator 초기화와 push_front와 iterator 순회
    list<int>::iterator t1 = L1.begin();
    auto t2 = L1.end();

    cout << "t1 : " << *t1 << " ," << "t2 : " << *t2 << '\n'; // t1 : 1, t2 : 3
    cout << "L1 size : " << L1.size() << '\n'; // L1 size : 3

    L1.push_front(7);

    for (list<int>::iterator ptr = L1.begin(); ptr != L1.end(); ptr++)
        cout << *ptr << ' '; // 7 1 2 3
    cout << '\n';
    
    //// 3. push_back과 insert함수 

    L1.push_back(100); // 7 1 2 3 100

    L1.insert(t1, 88); // iterator가 들어가야 함. L1.begin()이나 L1.end()로 초기화된!

    for (auto temp : L1) 
        cout << temp << ' '; // 7 88 1 2 3 100
    cout << '\n';
    cout << "insert후 t1이 가리키는 곳 : " << *t1 << '\n';

    //// 4. std::list를 이용한 iterator 위치 지정

    /* std::list는 더하기 연산을 지원하지 않으니, 
    std::next함수(첫번째 인수로 전달된 반복자에서 두 번째 인수로 전달된 개수만큼 떨어진 위치의 반복자 반환) 이용!*/

    auto t3 = next(L1.begin(), 1); // auto t3 = L1.begin() + 1은 지원 안함
   
    //// 5. erase함수의 반환값
    t3 = L1.erase(t3); // erase함수는 삭제한 원소의 다음 위치를 반환!
     cout << "\n삭제 후 t3 : " << *t3 << '\n';
    for (auto temp : L1)
        cout << temp << ' '; // 7 1 2 3 100
    


}