#include<bits/stdc++.h>
using namespace std;
int atMostSum(int arr[], int n, int k,int inj)
{
    int sum = 0;
    long long int mul=1;
    int cnt = 0, maxcnt = 0;
    for (int i = 0; i < n; i++) {
   
        if ((sum + arr[i]) <= k && (mul*arr[i])<=inj ) {
            sum += arr[i]; 
            mul*=arr[i];
            cnt++;
        } 
 
        else if(sum!=0)
        {
            sum = sum - arr[i - cnt] + arr[i];
            mul = (mul*arr[i])/arr[i-cnt];
        }
        maxcnt = max(cnt, maxcnt); 
    }
    return maxcnt;
}
int main()
{
	int n;
	cin>>n;
	int ar[n];
	int k=2000,inj=1000000;
	for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
	cout<<atMostSum(ar,n,k,inj);
}
