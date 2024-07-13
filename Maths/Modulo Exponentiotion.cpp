// https://www.naukri.com/code360/problems/modular-exponentiation_1082146?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_7&leftPanelTabValue=PROBLEM


#include <bits/stdc++.h>
long long int expo(long long int x,int n,int m){
	if(n==0) return 1;
	else if(n&1) return (expo(((x)%m)*((x)%m)%m,n>>1,m)*x)%m;
	else return expo(((x)%m)*((x)%m)%m,n>>1,m)%m;
}
long long int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	return expo(x,n,m);

}