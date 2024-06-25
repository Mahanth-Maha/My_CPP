#include <iostream>
#include <vector>

using namespace std;
template<class T> 
void dv(const vector<T> &v){
    for(auto &it: v ){
        cout << it << " ";
    }
    cout << "\n";
}
template<class T> 
void dpv(const vector<T> &v){
    for(auto &it: v ){
        cout << it.first << ":" << it.second << "\n";
    }
    cout << "\n";
}

int main(){
    pair<int , int> p = {1,4};
    cout << p.first << p.second  << endl;

    vector<int> v = {1,2,35,6,22,4,51,435,673,67,46,85,3};

    dv(v);
    v.push_back(100); // slower than emplace
    dv(v);
    v.emplace_back(200);
    dv(v);

    vector<pair<int,int>> v2 ;

    v2.push_back(make_pair(1,2));
    v2.push_back({2,2});
    v2.emplace_back(4,5);
    dpv(v2);

    vector<int> v3(10,-1);
    dv(v3);
    vector<int> copy_v3(v3);
    dv(v3);

    //Access

    cout << v[6] << "\n";
    // or with at function
    cout << v.at(6) << "\n";
    // or with iterators

    vector<int>::iterator it = v.begin();
    cout << *(it + 6) << endl;
    v = {1,2,3,4,5,6,7,8,9,10};
    dv(v);
    
    cout << "iterator begin  \t"<< *v.begin() << "\t\tit++ = " << *(v.begin()+1) << endl;
    cout << "iterator end   \t"<< *(v.end() ) << "\t\tit-- = " << *(v.end()-1)  << endl;
    cout << "iterator rbegin  \t"<< *v.rbegin()<< "\t\tit++ = " << *(v.rbegin()+1)  << endl;
    cout << "iterator rend   \t"<< *(v.rend() )<< "\t\tit-- = " << *(v.end()-1) << endl;
    
    cout << "c == constant\n\n" ;
    cout << "iterator cbegin  \t"<< *v.cbegin() << "\t\tit++ = " << *(v.cbegin()+1) << endl;
    cout << "iterator cend   \t"<< *(v.cend())<< "\t\tit-- = " << *(v.cend()-1) << endl;
    cout << "iterator crbegin  \t"<< *v.crbegin() << "\t\tit++ = " << *(v.crbegin()+1) << endl;
    cout << "iterator crend   \t"<< *(v.crend() ) << "\t\tit-- = " << *(v.crend()-1) << endl << endl;
    dv(v);
    cout <<"\nlast element : " << v.back() << endl;

    // loop

    for(vector<int>::iterator it = v.begin(); it < v.end(); it++){
        cout << *it << " ";
    }
    cout <<endl;
    //short way
    for(auto it = v.begin(); it < v.end(); it++){
        cout << *it << " ";
    }
    cout <<endl;

    //minium way
    for(auto it :v){
        it = it*10;     // not inplace
        cout << it << " ";
    }
    cout <<endl;
    dv(v);
    for(auto &it :v){
        it = it*10;     // inplace by using &
        cout << it << " ";
    }
    cout <<endl;
    dv(v);

    //delete element
    v.erase(v.begin()+5); //delete 60
    dv(v);
    
    //insert element
    v.insert(v.begin()+5, 60); //insert 60 back
    dv(v);
    
    //delete elements
    v.erase(v.begin()+5 , v.begin() + 9); //delete 60 - 90  [Start, end)
    dv(v);
    
    //insert same elements
    v.insert(v.begin()+5, 4, -1); //insert -1s for 60 - 90 back
    dv(v);
    v.erase(v.begin()+5 , v.begin() + 9); //delete 60 - 90  [Start, end)
    //insert Actual elements 
    v.insert(v.begin()+5 ,{60,70,80,90});
    dv(v);
    
    vector<int> ins = {51,52,53,54,55,56,57,58,59};
    v.insert(v.begin()+5 ,ins.begin(), ins.begin()+7);
    dv(v);

    vector<int> app = {110,120,130,140,150,160,170,180,190,200};
    v.insert(v.end(),app.begin(), app.end());    
    dv(v);

    cout << "v.size():\t" << v.size() << "\n";
    cout << "v.pop_back():\n";
    v.pop_back();
    dv(v);
    cout << "v.size():\t" << v.size() << "\n";

    vector<int> s1 = {2,4,6,8,10},s2 = {1,3,5,7,9};
    dv(s1);
    dv(s2);
    cout << "swapping" <<"\n";
    s1.swap(s2);
    dv(s1);
    dv(s2);

    cout << "s1.size():\t" << s1.size() << "\n";
    s1.clear();
    cout << "Clear cleares -> s1.clear():\t" << s1.size() << "\n";
    
    cout << "s2 : ";
    dv(s2);
    cout << "swap 0 ,1 st values\n";
    swap(s2[0],s2[1]);
    cout << "s2 : ";
    dv(s2);
    cout << "\n\n\n v :";
    dv(v);
    cout << "v.front() : " << v.front() << "\n";
    cout << "v.back() : " << v.back() << "\n";
    cout << "v.data() : " << *v.data() << "\n";
    cout << "v.empty() : " << v.empty() << " \t checks if v is empty\n";
    cout << "v.size() : " << v.size() << " \t give actual size\n";
    cout << "v.capacity() : " << v.capacity() << " \t give max possible size without increasing\n";
    cout << "v.max_size() : " << v.max_size() << " \t give max possible overall\n";
    cout << "v.shrink_to_fit() : " << " \t shrinks v to fit exactly\n";
    v.shrink_to_fit() ;
    vector<int> d1 = {1,2,3,4,5,6};
    vector<int> d2 = {1,2,3,4,5,6};
    cout << "d1 : ";
    dv(d1);
    cout << "d2 : ";
    dv(d2);
    cout << "d1<d2 : " << (d1<d2) << "\n";
    cout << "d1<=d2 : " << (d1<=d2) << "\n";
    cout << "d1>d2 : " << (d1>d2) << "\n";
    cout << "d1>=d2 : " << (d1>=d2) << "\n";
    cout << "d1==d2 : " << (d1==d2) << "\n";
    cout << "d1!=d2 : " << (d1!=d2) << "\n\n\n";

    d1 = {11,12,13,14,15,16};
    cout << "d1 : ";
    dv(d1);
    cout << "d2 : ";
    dv(d2);
    cout << "d1<d2 : " << (d1<d2) << "\n";
    cout << "d1<=d2 : " << (d1<=d2) << "\n";
    cout << "d1>d2 : " << (d1>d2) << "\n";
    cout << "d1>=d2 : " << (d1>=d2) << "\n";
    cout << "d1==d2 : " << (d1==d2) << "\n";
    cout << "d1!=d2 : " << (d1!=d2) << "\n\n\n";
    d1 = {11,12,13,-4,-5,-6};
    cout << "d1 : ";
    dv(d1);
    cout << "d2 : ";
    dv(d2);
    cout << "d1<d2 : " << (d1<d2) << "\n";
    cout << "d1<=d2 : " << (d1<=d2) << "\n";
    cout << "d1>d2 : " << (d1>d2) << "\n";
    cout << "d1>=d2 : " << (d1>=d2) << "\n";
    cout << "d1==d2 : " << (d1==d2) << "\n";
    cout << "d1!=d2 : " << (d1!=d2) << "\n";

    return 0;
}