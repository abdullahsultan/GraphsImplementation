#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    int vertex;
    bool visited;
    Node()
    {
        vertex=0;
        visited=false;
    }
};

Node vertArr[6][6];

void displayMatrix()
{
    int i, j;
    cout<<"    ";
    for(i = 0; i < 6; i++)
        cout<<i<<" ";
    cout<<endl<<endl;
    for(i = 0; i < 6; i++)
    {
        cout<<i<<"   ";
        for(j = 0; j < 6; j++)
        {
            cout << vertArr[i][j].vertex << " ";
        }
        cout << endl;
    }
}

void reset()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
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
    my_quee.push(0);
    for(int i = 0; i < 6;)
    {
        cout<<i<<" is connected to ";
        for(int j = 0; j < 6; j++)
        {
            if(vertArr[i][j].vertex == 1 )
            {
                if(!vertArr[i][j].visited)
                {
                    my_quee.push(j);
                    vertArr[i][j].visited=true;
                    vertArr[j][i].visited=true;
                }
                cout<<j<<" , ";
            }
        }
        cout<<endl;
        my_quee.pop();
        i=my_quee.front();
        if(my_quee.empty())
            break;
    }
    reset();
}

void depthFirstSearch()
{
    stack<int> my_stack;
    my_stack.push(0);
    for(int i = 0;;)
    {
        cout<<i<<" is connected to ";
        for(int j = 0; j < 6; j++)
        {
            if(vertArr[x][y] == 1)
            {
                cout<<j<<" , ";
                if(!vertArr[i][j].visited)
                {
                    my_stack.push(i);   i=my_stack.back();
                    vertArr[i][j].visited=true;
                    vertArr[j][i].visited=true;
                    break;
                }
            }
            elseif(j==5)
            {

            }


        }
    }
}


int main()
{
    add_edge(0, 4);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(1, 4);
    add_edge(2, 3);
    add_edge(3, 5);
    add_edge(1, 5);
    add_edge(4, 5);
    displayMatrix();
    cout<<endl<<"BFS"<<endl;
    breathFirstSearch();

    return 0;
}
