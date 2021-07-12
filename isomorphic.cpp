#include <stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.size()!= t.size()) return false;
    int arr1[26];
    int arr2[26];

    memset(arr1, -1, sizeof(arr1));
    memset(arr2, -1, sizeof(arr2));

    for(int i=0;i<s.size();i++){
        int index1=s[i]-'a';
        int index2=t[i]-'a';
        
        arr2[index2]=index1;
        arr1[index1]=index2;
    }
    for(int i=0;i<26;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<26;i++){
        cout<<arr2[i]<<" ";
    }
    return true;
}

int main(){
    string s="paper";
    string t="title";
    cout<<isIsomorphic(s,t);
}
    
/*
bool isIsomorphic(string s, string t) {
    std::map<char,char> mp;
    if(s.size()!= t.size()) return false;
    for(int i=0;i<s.size();i++){
        if(mp.find(s[i])==mp.end()){
            mp[s[i]]=t[i];
            mp[t[i]]=s[i];
        }
        else if (mp.find(s[i])!=mp.end() and mp.find(t[i])!=mp.end()){
            if(mp[s[i]]!=t[i] and mp[t[i]]!=s[i]) return false;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return true;
}
*/