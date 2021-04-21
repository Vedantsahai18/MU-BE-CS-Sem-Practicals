#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void print(vector<vector<char>> &MAT, int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << " ";
        for (int j = 0; j < n; j++)
            cout << MAT[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

bool valid(int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main()
{
    // { left, bottomleft, bottomright, right, topright, topleft }
    int dI[6] = {0, 1, 1, 0, -1, -1};

    // dJ[0] is for even row, dJ[1] is for odd row
    int dJ[2][6] = {{-1, 0, 1, 1, 1, 0}, {-1, -1, 0, 1, 0, -1}};

    int n, b, i, j, r, c, ci, cj;
    cout << "Enter size of matrix, number of base cells and i, j \n";
    cin >> n >> b >> i >> j;
    cout << "Enter centerI and centerJ \n";
    cin >> ci >> cj;

    vector<vector<char>> MAT(n, vector<char>(n, '0'));
    MAT[ci][cj] = 'C';

    // Find cocells
    for (int itr = 0; itr < 6; itr++)
    {
        int tempI = ci, tempJ = cj;
        for (int dir = 0; dir < i; dir++)
        {
            tempJ += dJ[(tempI % 2)][itr];
            tempI += dI[itr];
        }
        for (int dir = 0; dir < j; dir++)
        {
            tempJ += dJ[(tempI % 2)][(itr + 1) % 6];
            tempI += dI[(itr + 1) % 6];
        }
        if (valid(tempI, tempJ, n))
            MAT[tempI][tempJ] = 'X';
    }

    int wrong = 3, score = 0;
    while (wrong > 0 && score < 6)
    {
        cout << "Enter i and j to guess\n";
        cin >> r >> c;
        if (valid(r, c, n) && MAT[r][c] == 'X')
        {
            cout << "Correct!\n";
            score++;
        }
        else
        {
            cout << "Wrong!\n";
            wrong--;
        }
    }
    print(MAT, n);
    cout << "You scored " << score << " points\n";
    return 0;
}

/*
Output

Enter size of matrix, number of base cells and i, j 
5 4 1 1
Enter centerI and centerJ 
2 2
Enter i and j to guess
0 2
Correct!
Enter i and j to guess
2 3
Wrong!
Enter i and j to guess
1 1
Correct!
Enter i and j to guess
4 1
Wrong!
Enter i and j to guess
3 2
Wrong!

 0 0 X 0 0
0 X 0 0 X
 0 0 C 0 0
0 X 0 0 X
 0 0 X 0 0

You scored 2 points
*/