#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int x, n;
string s[10];

int f(int a) {
	if(a==0)
		return 1;
	return a*f(a-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> n;
	for(int i=0; i<n; ++i)
		cin >> s[i];
	int ans=0;
	for(int i=0; i<n; ++i) {
		int l=53, cnt=0, w=0;
		for(int j=0; j<36; ++j) {
			if ((j+1)%4==0) {
				for(int k=3; k>=0; --k)
					cnt+=s[i][j-k]=='0';
				cnt+=s[i][l]=='0';
				cnt+=s[i][l-1]=='0';
				if(cnt>=x)
					w+=(f(cnt)/(f(x)*f(cnt-x)));
				cnt=0;
				l-=2;
			}
		}
		ans+=w;
	}
	cout << ans << "\n";
}
