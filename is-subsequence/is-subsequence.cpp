class Solution {
public:
//     vector<string> getsubsequence(string s){
//         if(s.size()==0){
//             vector<string> base_result={""};
//             return base_result;
//         }
//         char ch=s[0];
//         string rest_of_string = s.substr(1);
//         vector<string> recursion_result= getsubsequence(rest_of_string);
        
//         vector<string> myresult;
//         for(string string_recurion: recursion_result){
//             myresult.push_back(""+string_recurion);
//         }
//         for(string string_recurion: recursion_result){
//             myresult.push_back(ch+string_recurion);
//         }
//         return myresult;
//     }
//     bool isSubsequence(string s, string t) {
//         vector<string> gss=getsubsequence(t);
        
//         for(string mystr: gss){
//             if(mystr==s){
//                 return true;
//             }
//         }
//         return false;
//     }
    
    bool isSubsequence(string s, string t) {
        int i=0;
        for(char j: t){
            if(s[i]==j) i++;
        }
        if(i>=s.size()) return true;
        else return false;
    }
};