#include<iostream>
#include<queue>            //Header-file for queue
using namespace std;
 
int main()
{
    cout << "++++++++++++++ int ++++++++++++++" << endl;
    priority_queue<int> p1;
    p1.push(35);              // inserting element in a queue
    p1.push(40);
    p1.push(95);

    while (!p1.empty())
    {
        cout << ' ' << p1.top();  //printing elements of queue
        p1.pop();
    }
    cout << endl;

    cout << "++++++++++++++ string ++++++++++++++" << endl;
    priority_queue<string> q1;
    q1.emplace("Ankit");
    q1.emplace("Ved");
    q1.emplace("Nikita");
    q1.emplace("Shaurya");
    q1.emplace("Anokhi");
     
    while (!q1.empty())  
    {  
        cout<<" "<<q1.top() << " ";  
        q1.pop(); 
    }  
    cout << endl;

    return 0; 
}
