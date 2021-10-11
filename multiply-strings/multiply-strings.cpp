class Solution {
public:
    string multiply(string num1, string num2) {
        int ans[200+200]={0};
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                
                int idx1=i+j;
                int idx2=i+j+1;
                
                int val=(num1[i]-'0')*(num2[j]-'0');
                // cout<<val<<endl;
                val+=ans[idx2];
                
                int quo=val/10;
                int rem=val%10;
                
                ans[idx2]= rem;
                ans[idx1]+=quo;
            }
        }
        string sb="";
        // for(int i=0;i<num1.size()+num2.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        for(int i=0;i<num1.size()+num2.size();i++){
            if(sb.size()==0 and ans[i]==0){ continue;}
            
            sb+=(ans[i]+'0');
        }
        if(sb.size()==0) return "0";
        return sb;
    }
};