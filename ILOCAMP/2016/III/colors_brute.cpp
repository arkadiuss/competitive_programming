#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int old[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	loop(i,0,n){
		cin>>old[i];
		old[i]--;
	}
	int mini=INFTY;
	loop(k,0,n){
		loop(j,0,n){
			if(k!=j){
				int act=0;
				loop(i,0,n){
					if(i%2==0){
						if(old[i]!=k) act++;
					}else{
						if(old[i]!=j) act++;
					}
					
				}
				mini=min(mini,act);
			}
		}
	}
	cout<<mini;
}
