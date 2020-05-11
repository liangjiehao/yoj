#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[200000],n,cnt,front;
	cin>>n;
	for (int i=0;i<=n-1;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	front=arr[0];
	cnt=1;
	for (int i=1;i<=n-1;i++){
		//cout<<arr[i]<<' ';
		if (arr[i]!=front){
			cout<<front<<' '<<cnt<<endl;
			cnt=0;
			front=arr[i];
		}
		
		cnt++;
		
	}
	cout<<front<<' '<<cnt;
	
	
	return 0;
}
