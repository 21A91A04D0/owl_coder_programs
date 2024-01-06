#include<bits/stdc++.h>
using namespace std;
vector<int> sieve(int a, int b){
    vector<int> A(b+1,true);
    A[0] = false;
    A[1] = false;
    for(int i = 2 ; i <= b ; i++){
        if(A[i]){
            for(int j = i + i ; j <= b ; j += i){
                if(j % i == 0) A[j] = false;
            }
        }
    }
    return A;
}
int main(){
    int a, b;
    cin >> a >> b;
    vector<int> A;
    A = sieve(a, b);
    for(int j = 0 ; j < A.size() ; j++){
        if(A[j]){
            cout << j << " ";
        }
        
    }
    cout << "\n";
}