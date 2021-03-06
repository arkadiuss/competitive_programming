#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
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
int n;
string wrds[MAX];
ll countSH(string w){
	ll SH=0;
	ll S=0;
	loop(i,0,SIZE(w)){
		if(w[i]=='s') S++;
		else SH+=S;
	}
	return SH;
}
bool sortW(string a,string b){
	return countSH(a+b)>countSH(b+a);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>wrds[i];
	}
	sort(wrds,wrds+n,sortW);
	ll sum=0;
	ll sumS=0;
	loop(i,0,n){
		//ps(wrds[i]);
		loop(j,0,SIZE(wrds[i])){
			if(wrds[i][j]=='h') sum+=sumS;
			else sumS++;
		}
	}
	pln(sum);
}
