class Solution {
public:
    void solveConfiguration(char arr[],int i,int j){
        if(arr[i]=='L' and arr[j]=='L'){
           for(int k=i+1;k<j;k++){
               arr[k]='L';
           } 
        }else if(arr[i]=='R' and arr[j]=='R'){
            for(int k=i+1;k<j;k++){
               arr[k]='R';
           } 
        }else if(arr[i]=='L' and arr[j]=='R'){
            
        }else if(arr[i]=='R' and arr[j]=='L'){
            int diff=j-i;
            int mid=(i+j)/2;
            if(diff%2==0){
//                even hai dots
                
                for(int k=i+1;k<mid;k++){
                    arr[k]='R';
                } 
                for(int k=mid+1;k<j;k++){
                    arr[k]='L';
                }
            }else{
                
                for(int k=i+1;k<=mid;k++){
                    arr[k]='R';
                }
                for(int k=mid+1;k<j;k++){
                    arr[k]='L';
                }
            }
        }
    }
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        char arr[100000+7];
        arr[0]='L';
        arr[n+1]='R';
        int j=0,k=1;
        for(int i=1;i<n+1;i++){
            arr[i]=dominoes[i-1];
        }
        while(j<n+2){
            while(arr[k]=='.'){
                k++;
            }
            if(k-j>1)
                solveConfiguration(arr,j,k);
            j=k;
            k++;
        }
        string result="";
        for(int i=1;i<n+1;i++){
            result+=arr[i];
        }
        return result;
    }
};