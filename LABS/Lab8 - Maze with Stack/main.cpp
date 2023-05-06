#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Maze
{
private:
    stack<pair<int, int>> path;
    pair<int, int> goal;
    vector<string> Map;
    int M; // MxN matrix
    int N;

    void move_right(int &i, int &j);
    void move_left(int &i, int &j);
    void move_up(int &i, int &j);
    void move_down(int &i, int &j);
    void move_back(int &i, int &j);

public:
    Maze();
    void solve_maze();
    void print_maze();
};

void Maze::move_right(int &i, int &j)
{
    j++;
    this->Map[i][j] = 'Y';
    this->path.push({i, j});
}

void Maze::move_left(int &i, int &j)
{
    j--;
    this->Map[i][j] = 'Y';
    this->path.push({i, j});
}

void Maze::move_down(int &i, int &j)
{
    i++;
    this->Map[i][j] = 'Y';
    this->path.push({i, j});
}

void Maze::move_up(int &i, int &j)
{
    i--;
    this->Map[i][j] = 'Y';
    this->path.push({i, j});
}

void Maze::move_back(int &i, int &j)
{
    this->Map[i][j] = 'R';
    this->path.pop();
    auto previous = this->path.top();
    i = previous.first;
    j = previous.second;
}

void Maze::print_maze()
{
    cout << endl;
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            cout << this->Map[i][j] << " ";
        }
        cout << endl;
    }
}

void Maze::solve_maze()
{
    // B stands for block
    // O stands for free space
    // R is no entry
    // column M
    // row N

    int i{0}, j{0};

    while (path.top() != this->goal)
    {
        if (j != this->N - 1 && this->Map[i][j + 1] != 'B' && this->Map[i][j + 1] != 'R' && this->Map[i][j + 1] != 'Y')
        {
            cout << "right" << endl;
            this->move_right(i, j);
        }
        else if (i != this->M - 1 && this->Map[i + 1][j] != 'B' && this->Map[i + 1][j] != 'R' && this->Map[i + 1][j] != 'Y')
        {
            cout << "down" << endl;
            this->move_down(i, j);
        }
        else if (j != 0 && this->Map[i][j - 1] != 'B' && this->Map[i][j - 1] != 'R' && this->Map[i][j - 1] != 'Y')
        {
            cout << "left" << endl;
            this->move_left(i, j);
        }
        else if (i != 0 && this->Map[i - 1][j] != 'B' && this->Map[i - 1][j] != 'R' && this->Map[i - 1][j] != 'Y')
        {
            cout << "up" << endl;
            this->move_up(i, j);
        }
        else
        {
            cout << "move back" << endl;
            this->move_back(i, j);
        }
    }
}

Maze::Maze()
{
    fstream maze_map;

    maze_map.open("maze.txt", ios::in);

    if (maze_map.is_open())
    {
        string temp;

        while (getline(maze_map, temp))
        {
            // cout << temp << endl;
            this->Map.push_back(temp);
        }

        this->N = temp.length();
    }
    maze_map.close();

    this->M = this->Map.size();

    this->goal.first = this->M - 1;
    this->goal.second = this->N - 1;

    this->path.push({0, 0});
    this->Map[0][0] = 'Y';

    cout << M << endl;
    cout << N << endl;
}

int main(void)
{
    Maze x;
    x.solve_maze();
    x.print_maze();

    return 0;
}