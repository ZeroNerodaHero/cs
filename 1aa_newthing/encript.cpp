#include <iostream>
#include <fstream>

char encrypt(char c, char key){
    return c ^ key;
}


int main(int argc, char *argv[], char *argp[]){
    for(int i = 0; i < argc; i++){
        std::cout << i << ' '  << argv[i] << std::endl;
    }
    for(int i = 0; argp[i] != NULL; i++){
        std::cout << i << ' '  << argp[i] << std::endl;
    }

    if(argc <= 3){
        std::cout << "ERROR\n";
        return 0;
    } 

    std::ifstream r (argv[2]);
    std::ofstream o (argv[3]);

    char c, key;
    key = argv[1][0];
    while(r.get(c)){
        o.put(encrypt(c, key));
    }   

    return 0;
}
