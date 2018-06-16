#include <iostream>

int palen(char s[]){
    int i = 0; int j = strlen(s)-1;
    while(i < j){
        if(s[i] != s[j]) return 0;
        i++, j--;
    }   
    return strlen(s);
}

void lpsbrute(char str[], char buf[],int bi,int si,int size,int &maxL){
    static int index;
    if(si == size){
        buf[bi] = 0;
        std::cout << index << '\t' <<  buf << '\t' << bi << std::endl;
        index++;
        int len = palen(buf);
        if(maxL < len) maxL = len;
        return;
    }

    buf[bi] = str[si];
    lpsbrute(str,buf,bi+1,si+1,size,maxL);
    lpsbrute(str,buf,bi,si+1,size,maxL);
}

int lpsrec(char str[],int i, int j){
    if(i == j) return 1;
    if(i+1 == j){
        if(str[i] == str[j]){
            return 2;
        }
        return 1;
    } 
    if(str[i] == str[j]) return lpsrec(str,i+1,j-1)+2;
    return std::max(lpsrec(str,i+1,j),lpsrec(str,i,j-1)); 
}

#define MAX 50
int dp[MAX][MAX];

void print(int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            std::cout << dp[i][j] << ' ';
        } std::cout << std::endl;
    }
}

int lpstp(char str[],int i, int j){
    if(dp[i][j]) return dp[i][j];
    if(i == j) dp[i][j] = 1;
    else if(i+1 == j){
        if(str[i] == str[j]){
            dp[i][j] = 2;
        } else{
            dp[i][j] = 1;
        }
    } else{
        if(str[i] == str[j]){
            dp[i][j] = lpstp(str,i+1,j-1)+2;
        }
        else{
            dp[i][j] = std::max(lpstp(str,i+1,j),lpstp(str,i,j-1));
        }
    }
    return dp[i][j];
}

int lspbt(char str[]){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        dp[i][i] = 1;
    }
    for(int i = 0; i < len-1; i++){
        if(str[i] == str[i+1]) dp[i][i+1] = 2;
        else dp[i][i+1] = 1;
    }
    for(int l = 2; l < len; l++){
        for(int i = 0, j = i+l; j < len; i++,j++){
            if(str[i] == str[j]) dp[i][j] = dp[i+1][j-1]+2;
            else dp[i][j] = std::max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][len-1];
}


int main(){
    char str[] = "GEEKSFORGEEKS";
    char buf[100];
    int size = 0;
    lpsbrute(str, buf,0,0,strlen(str),size);
    std::cout << size << std::endl;
    std::cout << lpsrec(str,0,strlen(str)-1) << std::endl;
    std::cout << lpstp(str,0,strlen(str)-1) << std::endl;
    print(strlen(str));
    std::cout << lspbt(str) << std::endl;
    print(strlen(str));
    
    return 0;
}
