// efficient way for the prime factorization

//first reduce the number with 2 multiples remove all the even numbers
// next start the loop from the 3 means next odd numbers to sqrt(n) and increment 2
// if n is a prime number and is greater than 2 n will not become 1 by the above 2 steps. so print n if it is greater than 2;
#include<bits/stdc++.h>
using namespace std;
int prime_factorization(int n){
    int cnt = 0;
    while(n % 2 == 0){
        cnt++;
        n = n / 2;
    }
    for(int i = 3 ; i <= sqrt(n) ; i+= 2){
        while(n % i == 0){
            cnt++;
            n = n / i;
        }
        
    }
    if(n > 2){
        cnt++;
    }

    return cnt;
}
int main(){
    int n;
    cin >> n;
    cout << prime_factorization(n);
}