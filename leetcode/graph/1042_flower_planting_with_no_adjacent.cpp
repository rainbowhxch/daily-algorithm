#include <vector>

using std::vector;

class Solution {
private:
    class Graph{
        private:
            class Node{
                public:
                    int id;
                    int flower;
                    vector <Node *> *children;

                    Node(int id){
                        this->id = id;
                        this->flower = 0;
                        children = new vector <Node *>;
                    }

                    void addChild(Node *n){
                        children->push_back(n);
                    }
            };

        public:
            vector <Node *> *nodes;

            Graph(){
                this->nodes = new vector <Node *>;
            }

            void addNode(int id){
                Node *n = new Node (id);
                nodes->push_back(n);
            }

            void setNodesConnection(int id1, int id2){
                Node *n1 = nodes->at(id1 - 1);
                Node *n2 = nodes->at(id2 - 1);

                n1->addChild(n2);
                n2->addChild(n1);
            }

            vector <int> setFlowers(){
                bool validFlower;
                Node *curr;
                vector <int> res(nodes->size());

                for(int i = 0; i < nodes->size(); i++){
                    curr = nodes->at(i);
                    curr->flower = 1;
                    validFlower = false;

                    if(curr->children->size() > 0){
                        while(!validFlower){
                            int j;
                            for(j = 0; j < curr->children->size(); j++){
                                if(curr->flower == curr->children->at(j)->flower){
                                    curr->flower++;
                                    break;
                                }
                            }

                            if(j == curr->children->size()){
                                validFlower = true;
                            }
                        }
                    }
                    res[i] = curr->flower;
                }
                return res;

            }
    };

public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        Graph graph;
        vector <int>  res;

        if(paths.empty()){
            vector <int> aux (N,1);
            return aux;
        }

        for(int i = 0; i < N; i++){
            graph.addNode(i);
        }

        for(int i = 0; i < paths.size(); i++){
            graph.setNodesConnection(paths[i][0], paths[i][1]);
        }

        res = graph.setFlowers();

        return res;

    }
};
