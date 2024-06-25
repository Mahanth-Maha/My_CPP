#include <iostream>
#include <vector>
#include <stack>
#include <queue>

// #include <priority_queue>

using namespace std;

template <class T>
void display_stack(stack<T> s){
    stack<T> tmp ;
    while(! s.empty()){
        tmp.push(s.top());
        s.pop();
    }
    while(! tmp.empty()){
        cout << tmp.top() << " ";
        tmp.pop();
    }
}

template <class T>
void display_pq(priority_queue<T> s){
    priority_queue<T> tmp ;
    while(! s.empty()){
        tmp.push(s.top());
        s.pop();
    }
    while(! tmp.empty()){
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << "\n";
}

template <class T>
void display_pq2(priority_queue< T, vector<T> , greater<T> > s){
    priority_queue<T> tmp ;
    while(! s.empty()){
        tmp.push(s.top());
        s.pop();
    }
    while(! tmp.empty()){
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << "\n";
}

template <class T>
void display_queue(queue<T> q){
    queue<T> tmp ;
    while(! q.empty()){
        tmp.push(q.front());
        q.pop();
    }
    while(! tmp.empty()){
        cout << tmp.front() << " ";
        q.push(tmp.front());
        tmp.pop();
    }
}


int main(){
    
    // STACK
    
    stack<int> s;
    s.push(10);
    s.push(20);
    s.emplace(30);
    s.emplace(40);
    display_stack(s);
    cout << "\nPopping : " << s.top() << "\n";
    cout << "SIZE : " << s.size() << "\n";
    s.pop();
    display_stack(s);
    cout << "\nPopping : " << s.top() << "\n";
    s.pop();
    display_stack(s);
    cout << "\nPopping : " << s.top() << "\n";
    s.pop();
    display_stack(s);
    cout << "\nPushing 100 " << "\n";
    s.push(100);
    display_stack(s);
    cout << "\nPopping : " << s.top() << "\n";
    s.pop();
    display_stack(s);
    cout << "\nSIZE : " << s.size() << "\n";

    // QUEUE
    queue<int> q;
    //push in back && pop from front
    q.push(10);
    q.push(20);
    q.emplace(30);
    q.emplace(40);
    q.emplace(50);
    display_queue(q);
    cout << "\nfront: " << q.front() << "\tback : " << q.back() << "\n";
    q.pop();
    display_queue(q);
    cout << "\nfront: " << q.front() << "\tback : " << q.back() << "\n";
    cout << "size : " << q.size() << "\tIsEmpty : " << q.empty() << "\n";
    cout << "\n\nPQ\n";
    // PQ
    priority_queue<int> pq;
    pq.push(20);
    pq.push(10);
    pq.emplace(40);
    display_pq(pq);
    pq.push(30);
    pq.emplace(60);
    pq.emplace(50);
    display_pq(pq);
    cout << "\ttop :  " << pq.top() << "\n" ;
    cout << "\nPopping : " << pq.top() << "\n";
    pq.pop();
    display_pq(pq);
    cout << "\ttop :  " << pq.top() << "\n" ;
    cout << "\nsize : " << pq.size() << "\tIsEmpty : " << pq.empty() << "\n";
    pq.push(70);
    pq.emplace(80);
    pq.emplace(90);
    pq.push(35);
    display_pq(pq);
    cout << "\ttop :  " << pq.top() << "\n" ;
    cout << "\nPopping : " << pq.top() << "\n";
    pq.pop();
    display_pq(pq);
    cout << "\n\n\nMIN PQ\n\n";
    priority_queue<int,vector<int>, greater<int>> min_pq;
    min_pq.push(20);
    min_pq.push(10);
    min_pq.emplace(40);
    display_pq2(min_pq);
    min_pq.push(30);
    min_pq.emplace(60);
    min_pq.emplace(50);
    display_pq2(min_pq);
    cout << "\ttop :  " << min_pq.top() << "\n" ;
    cout << "\nPopping : " << min_pq.top() << "\n";
    min_pq.pop();
    display_pq2(min_pq);
    cout << "\ttop :  " << min_pq.top() << "\n" ;
    cout << "\nsize : " << min_pq.size() << "\tIsEmpty : " << min_pq.empty() << "\n";
    min_pq.push(70);
    min_pq.emplace(80);
    min_pq.emplace(90);
    min_pq.push(35);
    display_pq2(min_pq);
    cout << "\ttop :  " << min_pq.top() << "\n" ;
    cout << "\nPopping : " << min_pq.top() << "\n";
    min_pq.pop();
    display_pq2(min_pq);


    return 0;
}