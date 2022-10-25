class BrowserHistory {
public:
     stack<string> pichwada,agada;
        // queue<string> agada;
    BrowserHistory(string homepage) {
        pichwada.push(homepage);
            agada=stack<string>();
    }
    
    void visit(string url) {
       pichwada.push(url);
            agada=stack<string>();
            
    }
    
    string back(int steps) {
        while(pichwada.size()>1 and steps--){
                string url=pichwada.top();
                pichwada.pop();
                agada.push(url);
                // steps--;
        }
            // return pichwada.top();
            return pichwada.empty()?"khali":pichwada.top();
    }
    
    string forward(int steps) {
                while(agada.size()>0 and steps--){
                string url=agada.top();
                agada.pop();
                pichwada.push(url);
        }
              return pichwada.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */