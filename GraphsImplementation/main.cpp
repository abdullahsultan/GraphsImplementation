#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int vertex;
    bool visited;
    Node()
    {
        vertex=0;
        visited=false;
    }
};

Node vertArr[5][5];

void displayMatrix()
{
    int i, j;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            cout << vertArr[i][j].vertex << " ";
        }
        cout << endl;
    }
}

void reset()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            vertArr[i][j].visited = false;
        }
    }
}

void add_edge(int u, int v)
{
    vertArr[u][v].vertex = 1;
    vertArr[v][u].vertex = 1;
}

void breathFirstSearch()
{
    queue <int> my_quee;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout<<i<<" is connected to ";
            if(vertArr[i][j].vertex == 1 && vertArr[i][j].visited != true)
            {
              my_quee.push(i);
              vertArr[i][j].visited=true;
              cout<<j<<" , ";
            }
            cout<<endl;
            my_quee.pop();
            i=my_quee.front();
            if(my_quee.empty())
                break;
        }
    }
}


int main()
{
        add_edge(0, 4); add_edge(0, 3); add_edge(1, 2);  add_edge(1, 4); add_edge(1, 5); add_edge(2, 3); add_edge(2, 5); add_edge(5, 3); add_edge(5, 4);
        displayMatrix();
        cout<<endl<<"DFS"<<endl;
        breathFirstSearch();

    return 0;
}
