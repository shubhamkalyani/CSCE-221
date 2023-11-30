#include <CSCE221H/queue.hpp>
#include <cassert>

int main(int argc, char **argv) {
  
    CSCE221H::queue<int> que;

    assert(que.size() == 0);    
    que.push(1);
    assert(que.size() == 1);
    assert(que.front() == 1);
    que.push(2);
    assert(que.size() == 2);
    assert(que.front() == 1);
    assert(que.back() == 2);
    que.pop();
    assert(que.size() == 1);
    assert(que.front() == 2);

    que.clear();
    assert(que.size() == 0);
    que.push(1);
    assert(que.size() == 1);
    assert(que.front() == 1);
    que.push(2);
    assert(que.size() == 2);
    assert(que.front() == 1);
    assert(que.back() == 2);
    que.pop();
    assert(que.size() == 1);
    assert(que.front() == 2);

    CSCE221H::queue<int> s1;
    CSCE221H::queue<int> s2;

    s1.push(1);
    s1.push(1);
    s1.push(1);
    s2.push(2);
    s2.push(2);
    s2.push(2);
    s2.push(2);
    s2.push(2);
    assert(s1.size() == 3);
    assert(s1.front() == 1);
    assert(s2.size() == 5);
    assert(s2.front() == 2);

    s1.swap(s2);

    assert(s1.size() == 5);
    assert(s1.front() == 2);
    assert(s2.size() == 3);
    assert(s2.front() == 1);

    s1.pop();
    assert(s1.size() == 4);
    assert(s1.front() == 2);

    s1.pop();
    assert(s1.size() == 3);
    assert(s1.front() == 2);

    s1.pop();
    assert(s1.size() == 2);
    assert(s1.front() == 2);

    s1.pop();
    assert(s1.size() == 1);
    assert(s1.front() == 2);

    s1.pop();
    assert(s1.size() == 0);
 
    return 0;
}