class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int num=0,n=0;
       
        for (int i=0; i<str.size(); i++){
            if(!isdigit(str[i]) && i!=0 || isalpha(str[i])){
                return -1;
            }
           if(isdigit(str[i])){
               num=num*10+(str[i]- '0');
           }
        }
       
        if(str[0]=='-'){
            num=num*-1;
        }
        return num;
    }
};