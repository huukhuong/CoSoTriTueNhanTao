#include <bits/stdc++.h>
using namespace std;
 int n;
 vector<string> v;
    void docFile(){
        ifstream ifs("NOTE.INP");

        if(!ifs){
            cerr << "Error: file not opened." << endl;
            return ;
        }
        
        string str;
       
        ifs  >> str;
        while(ifs  >> str){ 
           // cout << str << endl;
            v.push_back(str);
        }
        
    }
    
    void ghiFile(string s)
    {
         ofstream f2("NOTE.OUT");
	    f2<<s;
	    f2.close();

    }
    
    string alienOrder(vector<string>& words)
    {
        map<char, int> degree;
        map<char, vector<char> > graph;
        int n = words.size();
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                degree[words[i][j]] = 0;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int l = min((int)words[i].size(), (int)words[i + 1].size());
            for (int j = 0; j < l; j++) {
                char x = words[i][j];
                char y = words[i + 1][j];
                if (x != y) {
                    graph[x].push_back(y);
                    degree[y]++;
                    break;
                }
            }
        }
        string ret = "";
        queue<char> q;
        map<char, int>::iterator it = degree.begin();
        while (it != degree.end()) {
            if (it->second == 0) {
                q.push(it->first);
            }
            it++;
        }
        while (!q.empty()) {
            char x = q.front();
            q.pop();
            ret += x;
            vector<char>::iterator sit = graph[x].begin();
            while (sit != graph[x].end()) {
                degree[*sit]--;
                if (degree[*sit] == 0) {
                    q.push(*sit);
                }
                sit++;
            }
        }
        return ret.size() == degree.size() ? ret : "";
    }
    
int main()
{
    
     //vector<string> v = { "svxngqqnsnvqv", "svxngqqnsnvqv", "svxngqqnsnvqv", "qqns", "qnvq", "nsxnxnvsqsvvs", "nqg", "nn", "xsgvsgggqvsqqsxgv", "xxgxxggsvnxsnxsnqq" };
    docFile();
    cout<<alienOrder(v);
    ghiFile(alienOrder(v));
    
    
}
