#include <iostream>
using namespace std;
int T, N;
class Node{
    public:
        int data;
        Node(int inputdata){
            this->data = inputdata;
        }
};
// Adgacent Matrix, Undirected graph
class graph{
    public:
        Node** Nodelist;
        int** edge;
        int capacity;
        graph(int NodeSize){
            Nodelist = new Node* [NodeSize];
            edge = new int*[NodeSize];
            for(int i=0; i<NodeSize; i++){
                edge[i] = new int[NodeSize];
            }
            capacity = NodeSize;
        }
        int find(int data){
            for(int i=0; i<capacity; i++)
                if(Nodelist[i]->data == data) return i;
            
            return -1;
        }

        bool insertEdge(int S, int D){
            int Sidx = find(S), Didx = find(D);
            if(Sidx == -1 || Didx == -1) return false;
            if(edge[Sidx][Didx]) return false;

            edge[Sidx][Didx] = 1;
            edge[Didx][Sidx] = 1;
            return true;
        }
        bool eraseEdge(int S, int D){
            int Sidx = find(S), Didx = find(D);
            if(Sidx == -1 || Didx == -1) return false;
            if(!edge[Sidx][Didx]) return false;

            edge[Sidx][Didx] = 0;
            edge[Didx][Sidx] = 0;
            return true;
        }
};
// Adjacent Matrix, Directed Graph
class graph2{
    public:
        Node** Nodelist;
        int** edge;
        int capacity;
        graph2(int NodeSize){
            Nodelist = new Node* [NodeSize];
            edge = new int*[NodeSize];
            for(int i=0; i<NodeSize; i++){
                edge[i] = new int[NodeSize];
            }
            capacity = NodeSize;
        }
        int find(int data){
            for(int i=0; i<capacity; i++)
                if(Nodelist[i]->data == data) return i;
            
            return -1;
        }

        bool insertEdge(int S, int D){
            int Sidx = find(S), Didx = find(D);
            if(Sidx == -1 || Didx == -1) return false;
            if(edge[Sidx][Didx]) return false;

            edge[Sidx][Didx] = 1;
            return true;
        }
        bool eraseEdge(int S, int D){
            int Sidx = find(S), Didx = find(D);
            if(!Sidx || !Didx) return false;
            if(!edge[Sidx][Didx]) return false;

            edge[Sidx][Didx] = 0;
            return true;
        }
};

// Adjacent list, directed graph
class vertex{
    public:
        int data;
        vertex* next;
        vertex* prev;
        vertex(int inputdata){
            this->data = inputdata;
            this->next = NULL;
            this->prev = NULL;
        }
};
class graph3{
    public:
        vertex** vertexlist; //Adjacent list
        int capacity;
        graph3(int vertexSize){
            vertexlist = new vertex* [vertexSize];
            capacity = vertexSize;
        }
        int find(int data){
            for(int i=0; i<capacity; i++)
                if(vertexlist[i]->data == data) return i;
            
            return -1;
        }
        bool insertEdge(int S, int D){
            int Sidx = find(S), Didx = find(D);
            if(Sidx == -1 || Didx == -1) return false;

            vertex* link = NULL;
            for(vertex* iter = this->vertexlist[Sidx]; iter != NULL; iter = iter->next){
                if(iter->data == D) return false;
                if(iter->next == NULL) link = iter;
            }
            vertex* newVertex = new vertex(D);
            link->next = newVertex;
            newVertex->prev = link;
            return true;
        }
        bool eraseEdge(int S, int D){
            int Sidx = find(S), Didx = find(D);
            if(Sidx == -1 || Didx == -1) return false;
             for(vertex* iter = this->vertexlist[Sidx]; iter != NULL; iter = iter->next){
                if(iter->data == D){
                    iter->prev->next = iter->next;
                    if(iter->next == NULL) return true;
                    iter->next->prev = iter->prev;
                    delete iter;
                    return true;
                }
            }
            
        }

};

int main(){
    cin>>T>>N;
    graph3 g(N);
    for(int i=0; i<N; i++){
        int input;
        cin>>input;
        // Node* newNode = new Node(input);
        // g.Nodelist[i] = newNode;

        // vertex* newVertex = new vertex(input);
        // g.vertexlist[i] = newVertex;
    }
    for(int i=0; i<N; i++)
        cout<<g.vertexlist[i]->data<<' ';
    cout<<endl;
    
        cout<<g.insertEdge(1, 2);
        cout<<g.insertEdge(3, 4);
        cout<<g.insertEdge(2, 3);
        cout<<g.insertEdge(1, 2);
    
    
}