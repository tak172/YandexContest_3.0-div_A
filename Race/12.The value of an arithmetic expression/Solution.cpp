#include <vector>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

void Create(string& str, vector<string>& ans);
int Convert(string& s);
int Check(vector<string>& ans);

int main() {
	string str;
	getline(cin, str);
    	vector<string> ans, ans2;
	
    	Create(str, ans);
	
   	if (!Check(ans)) {
		cout << "WRONG";
        	return 0;
    	}
	
    	if ((ans[0] == "+" || ans[0] == "*" || ans[0] == "-") || (ans[ans.size() - 1] == "+" || ans[ans.size() - 1] == "*" || ans[ans.size() - 1] == "-")) {
	        cout << "WRONG";
	        return 0;
    	}
	
    	for (int i = 0; i < ans.size()-1; i++) {
		
        	if (ans[i] == "(" && (ans[i + 1] == "+" || ans[i + 1] == "*" || ans[i + 1] == "-")) {
            		cout << "WRONG";
            		return 0;
        	}
		
        	if (ans[i + 1] == ")" && (ans[i] == "+" || ans[i] == "*" || ans[i] == "-")) {
        		cout << "WRONG";
            		return 0;
        	}
		
        	if ((ans[i] == "+" || ans[i] == "*" || ans[i] == "-") && (ans[i + 1] == "+" || ans[i + 1] == "*" || ans[i + 1] == "-")) {
            		cout << "WRONG";
            		return 0;
        	}
		
    	}

    	stack<string> temp;
	
    	for (int i = 0; i < (int)ans.size(); i++) {
        	if (ans[i][0] >= '0' && ans[i][0] <= '9') {
			ans2.push_back(ans[i]);
		}
        	else {
            		if (ans[i] == "+" || ans[i] == "-") {
                		while ((!temp.empty()) && (temp.top() == "+" || temp.top() == "-" || temp.top() == "*")) {
                    			ans2.push_back(temp.top());
                    			temp.pop();
                		}
                		temp.push(ans[i]);
                		continue;
            		}
			
            		if (ans[i] == "*") {
                		while ((!temp.empty()) && temp.top() == "*") {
                    			ans2.push_back(temp.top());
                    			temp.pop();
                		}
	                	temp.push(ans[i]);
	                	continue;
            		}
			
            		if (ans[i] == "(") {
                		temp.push(ans[i]);
                		continue;
            		}
			
            		if (ans[i] == ")") {
                		while ((!temp.empty()) && temp.top() != "(") {
                    			ans2.push_back(temp.top());
                    			temp.pop();
                		}
                		temp.pop();
                		continue;
            		}
			
            		cout << "WRONG";
            		return 0;
        	}
	}
	
    	while (!temp.empty()) {
        	ans2.push_back(temp.top());
        	temp.pop();
    	}
	
    	int count;
    	stack<int> steck;
	
    	for (int i = 0; i < ans2.size(); i++) {
        	if (ans2[i][0] >= '0' && ans2[i][0] <= '9') {
			steck.push(Convert(ans2[i]));
		}
        	else {
            		if (ans2[i] == "+") {
                		count = steck.top();
                		steck.pop();
                		count += steck.top();
                		steck.pop();
                		steck.push(count);
            		}
			
            		if (ans2[i] == "*") {
                		count = steck.top();
                		steck.pop();
                		count *= steck.top();
                		steck.pop();
                		steck.push(count);
            		}
            		if (ans2[i] == "-") {
                		int tmp = steck.top();
                		steck.pop();
                		count = steck.top();
                		steck.pop();
                		steck.push(count - tmp);
            		}
        	}
    	}
    	if (steck.size() > 1)
		cout << "WRONG";
    	else 
		cout << steck.top();
	
	return 0;
}

void Create(string& str, vector<string>& ans) {
    	string temp = "";
	
	for (int i = 0; i < (int)str.size(); i++) {
        	if (str[i] >= '0' && str[i] <= '9')
			temp += str[i];
        	else {
            		if (temp != "") {
                		ans.push_back(temp);
                		temp = "";
            		}
			
            		if (str[i] != ' ') {
                		temp += str[i];
                		ans.push_back(temp);
                		temp = "";
           		}
        	}
    	}
	
    	if (temp != "")
		ans.push_back(temp);
	
}

int Convert(string &s) {
	
    int a = 0, j = 1;
	
    for (int i = (int)s.size()-1; i >= 0 ; i--) {
        a += (s[i] - 48) * j;
        j *= 10;
    }
	
    return a;
	
}

int Check(vector<string>& ans) {
    	stack<char> sk;
	
    	for (int i = 0; i < ans.size(); i++) {
		
        	if (ans[i] == "(") {
			sk.push('(');
		}
		
        	if (ans[i] == ")") {
            		if (!sk.empty()) sk.pop();
            		else return 0;
        	}
		
    	}
	
    return sk.empty();
	
}
