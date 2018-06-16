#include <iostream>
#include <string>

void print(const std::string& s, std::string& r, int id){
    if(s.size() == id){
        std::cout << r << std::endl;
        return;
    }

    print(s,r,id+1);
    r.push_back(s[id]);
    print(s,r,id+1);
    r.pop_back();   
}

void print(const std::string& s){
    for(int i = 0; i < 1<<s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if((i >> j)&1) std::cout << s[j];
        }
        std::cout << std::endl;
    }
}

int main(){
    std::string r;
    //print("abc",r,0);
    print("abc");
    return 0;
}
