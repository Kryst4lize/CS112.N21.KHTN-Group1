#include <bits/stdc++.h>
using namespace std;

#define matrix vector<vector<uint64>>

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

uint64 MOD = 1000000007;

bool checkMatrix(matrix mat) {
    if (mat.size() == 0) {
        return true;
    }

    int n_row_element = mat[0].size();
    for (int i=1; i<mat.size(); i++) {
        if(mat[i].size() != n_row_element) {
            return false;
        }
    }
    return true;
}

matrix matrixMul(matrix mat1, matrix mat2) {
    if ((!checkMatrix(mat1) || !checkMatrix(mat2)) || (mat1[0].size() != mat2.size())) {
        return matrix{};
    }
    matrix mat_ans;
    for (int i=0; i<mat1.size();i++) {
        vector<uint64> temp;
        for (int j=0; j<mat2[0].size(); j++) {
            uint64 value = 0;
            for (int k=0; k<mat1[0].size(); k++) {
                value += mat1[i][k] * mat2[k][j];
                value %= MOD;
            }
            temp.push_back(value);
        }
        mat_ans.push_back(temp); 
    }
    return mat_ans;
}

matrix matrixPow(matrix mat, uint64 n) {
    if (!checkMatrix(mat) || mat.size() == 0 || mat.size() != mat[0].size()) {
        return {};
    }

    matrix mat_ans;
    if (n == 0) {
        for (int i=0; i<mat.size(); i++) {
            vector<uint64> temp;
            for (int j=0; j<mat.size(); j++) {
                if (i != j) {
                    temp.push_back(0);
                } else {
                    temp.push_back(1);
                }
            }
            mat_ans.push_back(temp);
        }
        return mat_ans;
    }
    if (n == 1) {
        return mat;
    }

    auto mat_temp = matrixPow(mat, n/2);
    mat_ans = matrixMul(mat_temp, mat_temp);

    if (n % 2 == 1) {
        return matrixMul(mat_ans, mat);
    }
    return mat_ans;
}

uint64 calFibo(uint64 n) {
    if (n == 0) {
        return 0;
    }
    matrix coe_matrix = {{1, 1}, {1,  0}};
    matrix start = {{1}, {0}};

    coe_matrix = matrixPow(coe_matrix, n-1);

    return matrixMul(coe_matrix, start)[0][0] % MOD;
}
int main() {
    uint64 n; cin >> n;
    cout << calFibo(n) << '\n';
    return 0;
}