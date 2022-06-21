#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0 ; i < s.size(); i++){
        stack<char> st;
        bool valid = true;
        for(int j = 0; valid && j < s.size(); j++){
            char c = s[(i+j)%s.size()];
            if(c == '('){
                st.push('(');
            } else if (c ==')'){
                if(st.empty() || st.top() != '(') valid = false;
                else st.pop();
            } else if(c == '['){
                st.push('[');
            } else if (c ==']'){
                if(st.empty() || st.top() != '[') valid = false;
                else st.pop();
            } else if(c == '{'){
                st.push('{');
            } else if (c =='}'){
                if(st.empty() || st.top() != '{') valid = false;
                else st.pop();
            }
        }
        if(!st.empty()) valid = false;
        if(valid) answer++;
    }
    return answer;
}