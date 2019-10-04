#include <bits/stdc++.h>

using namespace std;

class PQ_maxHeap{
	private:
		priority_queue<int> pq;
	public:
		void insert(int val){
			pq.push(val);
      cout << "inserted " << val << endl;
		}
    
    int peek(){
      cout << "top is " << pq.top() << endl;
      return pq.top();
    }

    int getMax(){
			int ele = pq.top();
      cout << "removed " << ele << endl;
      pq.pop();
      return ele;
		}

    void showheap() {
      priority_queue<int> temp = pq;
      while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
      }
      cout <<endl;
    }
};