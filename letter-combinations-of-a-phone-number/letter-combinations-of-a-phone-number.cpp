class Solution {
public:
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;        
	string combination = "";
	helper(digits, 0, combination);
	return ans; 
}
//                  passing by reference ⬇️ so copies are not made at each function call
void helper(string &digits, int i, string &combi){
	if(i == size(digits)) {
		ans.push_back(combi);    
		return;
	}
	for(auto c : mappings[digits[i] - '2']){
		combi.push_back(c);            // add a character from mappings for current position,
		helper(digits, i + 1, combi);  // and recurse for next positions
		combi.pop_back();              // backtrack
	}   
}
};

/*
vector<string> codes = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string str) {
    
    if(str.size()==0){
        vector<string> base_result={""};
        return base_result;
    }
    int ch = str[0] - '0';
    string rest_of_string = str.substr(1);
    vector<string> result_recursion = letterCombinations(rest_of_string);
    vector<string> myresult;
    
    string code= codes[ch];
    for(int i=0;i<code.size();i++){
        for(string recursive_string : result_recursion){
            myresult.push_back(code[i] + recursive_string);
            
        }
    }
    return myresult;
    }
*/