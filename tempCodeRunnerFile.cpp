#include <iostream>
#include <vector>
using namespace std;

bool findThreeIndices(const vector<int>& arr, int n) {
    if(n<3)return false;
    for(int k=n-1;k>=0;k--){
       int i=0;
       int j=k-1;
       while(i<j){
        if(arr[i]+arr[j]==arr[k]){
            cout<<i<<j<<"equals "<<k<<endl;
            return true;
        }
        else if(arr[i]+arr[j]<arr[k]){
            i++;
        }
        else{
            j--;
        }

       }
    }
    return false;
}
   

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (!findThreeIndices(arr, n)) {
    cout << "No sequence found" << endl;
        } 
            
        
    }

    return 0;
}
