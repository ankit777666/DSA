class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1==sentence2) return true;

        vector<string>arr1,arr2;
        string longest=sentence1;
        string shortest=sentence2;
        if(sentence1.size()<sentence2.size()) {
            longest=sentence2;
            shortest=sentence1;

        }
        string word="";
        for(int i=0; i<longest.size(); i++) {
            if(longest[i]==' ') {
                arr1.push_back(word);
                word="";
                continue;
            }
            word.push_back(longest[i]);
        }
        arr1.push_back(word);

        word="";
        for(int i=0; i<shortest.size(); i++) {
            if(shortest[i]==' ') {
                arr2.push_back(word);
                word="";
                continue;
            }
            word.push_back(shortest[i]);
        }
        arr2.push_back(word);

        int start1=0, start2=0;
        int end1=arr1.size()-1, end2=arr2.size()-1;
        while(start1<=end1 && start2<=end2) {
            if(arr1[start1]==arr2[start2])
                start1++,start2++;
            else if(arr1[end1]==arr2[end2])
                end1--,end2--;
            else
                return false;
        }
        return true;



    }
};