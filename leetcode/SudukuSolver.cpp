#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    // ���ص�һ���հ׵�λ�ã����û�ҵ��ͷ��� (-1, -1)
    pair<int, int> findFirstEmpty(const vector< vector<char> >& board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.') return make_pair(i, j);
        return make_pair(-1, -1);
    }

    // ��������� 9 �������Ƿ���Ч
    bool isValid(const vector<char>& vec) {
        vector<bool> occur(9, false);
        for (int i = 0; i < 9; ++i) {
            if (isdigit(vec[i])) {
                if (occur[vec[i]-'1']) return false;
                else occur[vec[i]-'1'] = true;
            }
        }
        return true;
    }

    // �����ĳ��λ������һ����֮������ board �Ƿ���Ч��ֻ��Ҫ���ǵ�ǰ�С�
    // ��ǰ�к����������ָ�
    bool isValidBoard(const vector< vector<char> >& board, pair<int, int> pos) {
        // ��鵱ǰ���Ƿ���Ч
        if (!isValid(board[pos.first])) return false;

        // ��鵱ǰ���Ƿ���Ч
        vector<char> column(9);
        for (int i = 0; i < 9; ++i)
            column[i] = board[i][pos.second];
        if (!isValid(column)) return false;

        // ������ڵ����ָ��Ƿ���Ч
        int block_row = pos.first / 3;
        int block_col = pos.second / 3;
        vector<char> block;
        for (int i = block_row * 3; i < block_row * 3 + 3; ++i)
            for (int j = block_col * 3; j < block_col * 3 + 3; ++j)
                block.push_back(board[i][j]);
        if (!isValid(block)) return false;

        // ������϶���Ч���򷵻� true
        return true;
    }

    // ���ӵ�ǰ���濪ʼ�Ƿ��ܹ��õ����պϷ���Ч�Ľ�
    bool solveSudokuHelper(vector<vector<char> >& board) {
        // ���û���ҵ��հ׵ĸ��ӣ�˵���Ѿ������ˣ��ɹ�����
        pair<int, int> pos = findFirstEmpty(board);
        if (pos.first == -1 && pos.second == -1)
            return true;
        // �������γ�������ǰ�������������� 1-9�����ж��ܷ�õ����еĽ�
        for (int i = 1; i <= 9; ++i) {
            board[pos.first][pos.second] = i + '0';
            if (isValidBoard(board, pos) && solveSudokuHelper(board))
                return true;
            // �ָ�ԭ��
            board[pos.first][pos.second] = '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char> >& board) {
        solveSudokuHelper(board);
    }
};

class Solution2 {
public:
    void solveSudoku(vector<vector<char> > &board) {
        dfs(board);
    }
private:
    bool dfs(vector<vector<char> >& board){
        bool find = false;
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++)
                if(board[i][j] == '.'){
                    find = true;
                    vector<bool> num(9,true);
                    for(int k = 0;k < 9;k++){
                        if(board[i][k] != '.')
                            num[board[i][k] - '1'] = false;
                        if(board[k][j] != '.')
                            num[board[k][j] - '1'] = false;
                    }
                    int m = i / 3 * 3;
                    int n = j / 3 * 3;
                    for(int ii = m;ii < m + 3;ii++)
                        for(int jj = n;jj < n + 3;jj++)
                            if(board[ii][jj] != '.')
                                num[board[ii][jj] - '1'] = false;
                    bool flag = false;
                    for(int k = 1;k <= 9;k++)
                        if(num[k - 1]){
                            flag = true;
                            board[i][j] = k + '0';
                            if(dfs(board))
                                return true;
                            board[i][j] = '.';
                        }
                    return false;
                }
        }
        if(!find)
            return true;
    }
};

int main(){
	vector<vector<char> >board;
	string line[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	for(int i = 0;i < 9;i++){
		vector<char> tmp;
		for(int j = 0;j < 9;j++)
			tmp.push_back(line[i][j]);
		board.push_back(tmp);
	}
	Solution2* s = new Solution2();
	s->solveSudoku(board);
	return 0;
}
