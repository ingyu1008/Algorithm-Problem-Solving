#include <fstream>

int main(void){
    std::ifstream in;
    in.open("input.txt");

    std::ofstream out;
    out.open("output.txt");

    int T;
    in >> T;

    int N;
    std::string s;
    int L, R, l, r;

    for(int t = 1; t <= T; t++){
        out << "Case #" << t << ": ";
        
        in >> N >> s;

        L = 0;
        R = 0;

        for(int i = 0; i < N; i++){
            l = 1e9;
            r = 1e9;

            if(s[i] != 'O'){
                l = std::min(L, R+1);
            }
            if(s[i] != 'X'){
                r = std::min(L+1, R);
            }

            L = l;
            R = r;        
        }

        out << std::min(L, R) << "\n";
    }

    in.close();
    out.close();
}