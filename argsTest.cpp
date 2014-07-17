#include <iostream>
#include "ArgReader.hpp"
#include "BlackBoxTesters.hpp"
#include <list>

using namespace std;

void outputResults(string argument);
ARGinAttor *mine;

int main(int argc , char* argv[]){

   //bool mycontrolflag;
   //ArgReader::Flag myFlag = {"-m",*mycontrolflag};
   //ArgReader::Flag flags[] = {myFlag};

   cout << "before construcor is evoked" << endl;

   //ArgReader myReader(int argc , char* argv[]);
   //myReader.amIHere();

   ARGinAttor localArg(argc,argv);
   mine = &localArg;

   cout << "after Constructor is done" << endl;



   string arg1 = "hello";
   string arg2 = "-h";
   string arg3 = "goodbye";
   string arg4 = "6";

   /*list<string> testItems;
   testItems.push_back(arg1);
   testItems.push_back(arg2);
   testItems.push_back(arg3);
   testItems.push_back(arg4);

   testItems.push_back("giggle");

   OverAll<string> tester(testItems);
   tester.setEnumerated(true);

   tester.Add("thank you");
   tester.Go(outputResults);*/

   OverAll<string> tester(true);
   tester.Add("hello");
   tester.Add("goodbye");
   tester.Add("farewell");


   list<string> testItems;
   testItems.push_back(arg1);
   testItems.push_back(arg2);
   testItems.push_back(arg3);
   testItems.push_back(arg4);

   tester.Go(outputResults);
   tester.Go(outputResults,testItems);
}

void outputResults(string argument){
   cout << endl << argument <<
        ( (mine->ArgumentPassedIn(argument))? " was passed" : " was not passed");
}
