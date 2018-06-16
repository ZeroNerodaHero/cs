#include <iostream>
#include <stack>
class que{
 public:
    void push(const int & val) {s1.push(val);}
    void pop(){
        transfer();
        s2.pop();
    }

    int &front(){
        transfer();
        return s2.top();
    }

    bool empty(){return(s1.empty() && s2.empty());}
    
    int size(){return s1.size()+s2.size();}
 private:
    void transfer(){
        if(s2.empty()){
            while(!s1.empty()){
                int n = s1.top();
                s1.pop();
                s2.push(n);
            }
        }
    }
    std::stack<int> s1, s2;
};

int main(){
    que que1;
    que1.push(1);
    que1.push(3);
    que1.push(2);
    return 0;
}
