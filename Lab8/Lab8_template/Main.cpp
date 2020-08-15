#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<cstring>
#define INFINITY 10000
using namespace std;

vector<vector<char>> GetMazeInfo(fstream& file, pair<int, int>& StartPos, pair<int, int>& EndPos) {
	vector<vector<char>> Maze;

	int mazeRowSize, mazeColSize;
	file >> mazeRowSize >> mazeColSize;

	for (int i = 0; i < mazeRowSize; i++) {
		vector<char> row;
		for (int j = 0; j < mazeColSize; j++) {
			char temp;
			file >> temp;

			row.push_back(temp);

			if (temp == 'S') {
				StartPos.first = i;
				StartPos.second = j;
			}
			if (temp == 'E') {
				EndPos.first = i;
				EndPos.second = j;
			}
		}
		Maze.push_back(row);
	}

	return Maze;
}

vector<vector<int>> DistanceInfo(const vector<vector<char>>& Maze) {
	// TODO:
	// Create a 2D vector to store the corresponding distance of the maze.
	// Initialize the distance to infinity
}

bool inbound(pair<int,int> p,int r,int c)
{
	return 
	p.first>=0 && p.second>=0 &&
	p.first<r && p.second<c;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	fstream  file;
	file.open("input.txt");
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return 0;
	}

	int TestCase = 0;
	file >> TestCase;
	while (TestCase) {
		pair<int, int> StartPos, EndPos;
		vector<vector<char>> Maze = GetMazeInfo(file, StartPos, EndPos);
		vector<vector<pair<int,int>>> where_it_come_from;
		where_it_come_from.resize(Maze.size());
		for(int i=0;i<where_it_come_from.size();i++)
		{
			where_it_come_from[i].resize(Maze[0].size());
			for(int j=0;j<Maze[0].size();j++)
				where_it_come_from[i][j]=pair<int,int>(-1,-1);
		}
		// Calculate the shortest path of the starting point and the ending point
		// You should print something out here according to the output sample format .
		queue<pair<int,int>> togo;
		bool complete_flg=false;
		togo.push(StartPos);
		where_it_come_from[StartPos.first][StartPos.second]=pair<int,int>(-2,-2);

		const int m[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
		while(!togo.empty())
		{
			pair<int,int> pos=togo.front();
			togo.pop();

			if(pos==EndPos)
			{
				complete_flg=true;
				pair<int,int> t=pos;
				while(t!=pair<int,int>(-2,-2))
				{
					Maze[t.first][t.second]='o';
					t=where_it_come_from[t.first][t.second];
				}
				Maze[StartPos.first][StartPos.second]='o';
				break;
			}
			for(int i=0;i<4;i++)
			{
				pair<int,int> tmp=pos;
				tmp.first+=m[i][0];
				tmp.second+=m[i][1];
				if(inbound(tmp,Maze.size(),Maze[0].size())&&
				where_it_come_from[tmp.first][tmp.second]==pair<int,int>(-1,-1)&&
				Maze[tmp.first][tmp.second]!='#'
				)
				{
					where_it_come_from[tmp.first][tmp.second]=pos;
					togo.push(tmp);
				}
			}
		}
		TestCase--;
		if(complete_flg==true)
		{
			for(int i=0;i<Maze.size();i++)
			{
				for(int j=0;j<Maze[0].size();j++)
				{
					cout<<Maze[i][j];
				}
				cout<<'\n';
			}
		}
		else
		{
			cout<<"Trapped!\n";
		}
		cout<<'\n';
	}
	return 0;

}