#include <iostream>
#include <deque> 
using namespace std;

int*  printKMax(int arr[], int n, int k,int *arrfinal){
	//Write your code here.
    for(int i = 0;i<=n-k;i++){
        int max = arr[i];
        for(int j = 1;j<k;j++){
            if(arr[i+j]>max){
                max = arr[i+j];
            }
        }
        arrfinal[i] = max; 

    }
    return arrfinal;
}

void printUsingDeque(int arr[],int n,int k){
    deque<int>Q(k);
    int i;
    for( i = 0;i<k;++i){
        while(!Q.empty() && arr[i]>=arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }

    cout<<arr[Q.front()]<<" ";
    for(;i<n;++i){
        while(!Q.empty() && Q.front()<= i-k){
            Q.pop_front();
        }
        while(!Q.empty() && arr[i]>=arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
        cout<<arr[Q.front()]<<" ";
    }

}



int main(){
    
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++){
            cin >> arr[i];
        }
        int arrfinal[n-k];
      		
    	// int* ptr;
        // ptr = printKMax(arr, n, k,arrfinal);
        // for(int j=0;j<=n-k;j++){
        //     cout<<ptr[j]<<" ";
        // }
        
        printUsingDeque(arr,n,k);
        cout<<endl;


    	t--;
  	}
  	return 0;
}