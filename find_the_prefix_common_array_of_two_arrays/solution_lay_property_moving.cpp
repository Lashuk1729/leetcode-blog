class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int counter = 0, size = A.size();
        vector <int> result(size, 0);
        vector <bool> A_bool(size, false);
        vector <bool> B_bool(size, false);
        for(int i = 0; i < size; i++) {
            A_bool[A[i] - 1] = true;
            B_bool[B[i] - 1] = true;
            
            if(A[i] != B[i]) {
                if(A_bool[A[i] - 1] == true && B_bool[B[i] - 1] == true && B_bool[A[i] - 1] == true && A_bool[B[i] - 1] == true) {
                    counter += 2;
                }
                
                else if(A_bool[A[i] - 1] == true && B_bool[A[i] - 1] == true){
                    counter += 1;
                }
                
                else if(B_bool[B[i] - 1] == true && A_bool[B[i] - 1] == true){
                    counter += 1;
                }
            }
            else {
                counter += 1;
            }
            result[i] = counter;
        }
        return result;
    }
};