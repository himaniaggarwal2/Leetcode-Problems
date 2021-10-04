class Solution {
public:
    string reverseWords(string s) {
        int count=0,prev=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
              std::reverse(s.begin()+prev,s.begin()+count);  
                prev=count;
                prev++;
            }
            count++;
        }
        std::reverse(s.begin()+prev,s.begin()+count);
        return s;
    }
};