
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "WordTree.h"
#include <cassert>

using namespace std;
int main() {
    //things to test default constructor makes things just null
    WordTree k;
    //cout works with empty
    cout << k<< endl;
    assert(k.distinctWords() == 0);
    assert(k.totalWords() == 0);
    
    k.add("Kim");
    k.add("Kanye");
    k.add("Kanye");
    k.add("Kanye");
    
    //cout works with many
    cout << k << endl;
    
    assert(k.distinctWords() == 2);
    assert(k.totalWords() == 4);
    
    //insert works with 1 value
    //insert works with multiple values
    //insert works when adding the same value in more than once
    WordTree w;
    w.add("Harry");
    w.add("Niall");
    w.add("Niall");
    w.add("Liam");
    w.add("Louis");
    w.add("Harry");
    w.add("Niall");
    w.add("Zayn");

    cout << w;
    
    assert(w.distinctWords() == 5);
    assert(w.totalWords() == 8);
    
    
    //copy constructor null to null works
    WordTree empty;
    WordTree empty2(empty);
    cout << empty2 << endl;
    assert(empty2.distinctWords() == 0);
    assert(empty2.totalWords() == 0);
    
    //copy constructor one root works
    
    WordTree oneval;
    oneval.add("hi");
    
    WordTree oneval2(oneval);
    cout << oneval2 << endl;
    
    assert(oneval2.distinctWords() == 1);
    assert(oneval2.totalWords() == 1);
    
    //copy constructor full tree works
    WordTree OneDirection(w);
    //cout works properly if there is repeats of values
    cout << OneDirection << endl;
    assert(OneDirection.distinctWords() == 5);
    assert(OneDirection.totalWords() == 8);
    
    //assignment operator empty to empty works
    empty2 = empty;
    cout << empty2 << endl;
    assert(empty2.distinctWords() == 0);
    assert(empty2.totalWords() == 0);
    
    //assignment operator empty to root works
    WordTree empty3;
    
    empty3 = oneval2;
    //cout works with 1
    cout << empty3 << endl;
    assert(empty3.distinctWords() == 1);
    assert(empty3.totalWords() == 1);

    //assignemtn operator root to empty works
    empty3 = empty;
    assert(empty3.distinctWords() == 0);
    assert(empty3.totalWords() == 0);
  
    //assignment operator empty to full wroks
    empty3 = OneDirection;
    cout << OneDirection << endl;
    assert(empty3.distinctWords() == 5);
    assert(empty3.totalWords() == 8);
    
    //assignemtn operator full to empty works
    empty3 = empty;
    //distinct words work with 0 words
    //total words works with 0 works
    assert(empty3.distinctWords() == 0);
    assert(empty3.totalWords() == 0);
    
    //assignemnt opeator full to root works
    empty3 = OneDirection;
    empty3 = oneval2;
    cout << empty3 << endl;
    //distinct works with 1 words
    //total words with with 1 words
    assert(empty3.distinctWords() == 1);
    assert(empty3.totalWords() == 1);

    //assignemtn opeartor root to full works
    empty3 = OneDirection;
    cout << OneDirection << endl;
    //distinct works when have repeats of words
    //total works with repeats of words
    assert(empty3.distinctWords() == 5);
    assert(empty3.totalWords() == 8);
    
 
    
    
   
    WordTree oneTime;
    oneTime.add("ava");
    oneTime.add("lilly");
    oneTime.add("max");
    oneTime.add("luke");
    oneTime.add("mom");
    oneTime.add("dad");
    oneTime.add("fish");
    //distinct works with multiple words
    //totol words with with multiple words
    assert(oneTime.distinctWords() == 7);
    assert(oneTime.totalWords() == 7);
    


    

ifstream fin;
ofstream fout;
string filename;
cout << "Enter name of file with text to analyze: ";
cin >> filename;
fin.open(filename.c_str());
if (fin.fail()) {
cout << "Error opening file.\n";
exit(1);
}
cout << "\nAnalyzing " << filename << ".\n";
WordTree myTree;
// insert code here so need to insert code here to make it into a tree
    while(fin){
        std::string add;
        fin >> add;
        if(add != ""){
            myTree.add(add);
        }
        
    }
fin.close();
fout.open("results.txt");
cout << "\nWord counts:\n\n";
cout << myTree;
fout << myTree;
cout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
fout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
cout << "Number of distinct words appearing in text: "
<< myTree.distinctWords() << ".\n";
fout << "Number of distinct words appearing in text: "
<< myTree.distinctWords() << ".\n";
fout.close();
return 0;
}
