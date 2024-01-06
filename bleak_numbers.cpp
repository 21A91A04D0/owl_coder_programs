// Given an integer, check whether it is Bleak or not.

// A number n is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.
#include<bits/stdc++.h>
using namespace std;

int power_fun(int n){
        int c = 1;
        int pow = -1;
        while(c <= n){
            c = c << 1;
            pow++;
        }
        return pow;
    }
    int set_bit_count(int n){
        int cnt = 0;
        while(n){
            if(n & 1 == 1){
                cnt++;
            }
            n = n >> 1;
        }
        return cnt;
    }
	int is_bleak(int n)
	{
	    // Code here.
	    int in = power_fun(n);
	    for(int i = n - in ; i <= n ; i++){
	        if(i + set_bit_count(i) == n){
	            return 0;
	        }
	    }
	    return 1;
	}
int main(){
    int n;
    cin >> n;
    cout << is_bleak(n);
}