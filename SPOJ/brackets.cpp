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
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//-----------------------------------------
struct node{
	int d;
	int val;
};
node tree[MAX];
int D;
void countD(int n){
	D=1;
	while(D<=n){
		D*=2;
	}
}
void update(int i){
	i=i/2;
	while(i>0){
		tree[i].val=min(tree[2*i].val,tree[2*i+1].val)+tree[i].d;
		i=i/2;
	}
}
void add(int L,int R,int v){
	L=L+D;
	R=R+D;
	while(L<R){
		if(L%2==1){
			tree[L].d+=v;
			tree[L].val+=v;
			update(L);
		}
		if(R%2==0){
			tree[R].d+=v;
			tree[R].val+=v;
			update(R);
		}
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R){
		tree[L].d+=v;
		tree[L].val+=v;
		update(L);
	}
}
int read(){
	return tree[1].val;
}
int createTree(string s,int n){
	int sum=0;
	loop(i,D,2*D){
		if(i-D<n){
			if(s[i-D]=='(') sum++;
			else sum--;
			tree[i].val=sum;
		}else{
			tree[i].val=INFTY;
		}
		tree[i].d=0;
	}
	loopback(i,D-1,1){
		tree[i].val=min(tree[2*i].val,tree[2*i+1].val);
		tree[i].d=0;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	int t=10;
	int n,m,k,last;
	string s;
	while(t--){
		cin>>n;
		countD(n);
		cin>>s;
		last=createTree(s,n);
		cout<<"Test "<<10-t<<":\n";
		cin>>m;
		while(m--){
			
			cin>>k;
			if(k==0){
				//ps(read());pln(last);
				if(read()>=0&&last==0) pln("YES");
				else pln("NO");
			}else{
				
				if(s[k-1]=='('){ 
					s[k-1]=')';
					add(k-1,n-1,-2);
					last-=2;
				}else{ 
					s[k-1]='(';
					add(k-1,n-1,2);
					last+=2;
				}
			}
			//loop(i,1,2*D) ps(tree[i].val);
			//entr;
		}
		//entr;
	}
}
