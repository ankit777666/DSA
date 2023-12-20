/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void inserting(stack<int> &s, int element){
    if(s.size() == 0 || s.top() <= element){
        s.push(element);
        return;
    } 
    int val = s.top();
    s.pop();
    inserting(s, element); 
    s.push(val);
}
void sorting(stack<int>&s) {
    if(s.size()==1)
        return ;
    int temp=s.top();
    s.pop();
    sorting(s);
    inserting(s, temp);
}
void SortedStack :: sort()
{
   //Your code here
   sorting(s);
   
   
}