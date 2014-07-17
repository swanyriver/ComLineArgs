#include <iostream>
#include "ArgReader.hpp"
#include "BlackBoxTesters.hpp"
#include <list>

using namespace std;


int main(int argc , char* argv[]){


   bool hellorecieved;
   bool hrecieved;
   bool goodbyerecieved;
   bool sixrecievd;
   list<ARGinAttor::ControlFlag> myFlags;
   ARGinAttor::ControlFlag hello = {"hello",&hellorecieved};
   ARGinAttor::ControlFlag h = {"-h",&hrecieved};
   ARGinAttor::ControlFlag goodbye = {"goodbye",&goodbyerecieved};
   ARGinAttor::ControlFlag six = {"6",&sixrecievd};

   myFlags.push_back(hello);
   myFlags.push_back(h);
   myFlags.push_back(goodbye);
   myFlags.push_back(six);

   ARGinAttor localArg(argc,argv,myFlags);

   //testing control flag, pointed bool assignment
   cout << "\n\n  we have finised construction, now testing \n \n";
   cout << "hello:" << hellorecieved << endl;
   cout << "-h:" << hrecieved << endl;
   cout << "goodbye:" << goodbyerecieved << endl;
   cout << "6:" << sixrecievd << endl;

   //testing anytime retrieval of args recieved
   cout << "-v " << ((localArg.ArgumentPassedIn("-v"))? "YES, was received": " NOPE") << endl;
   cout << "-b " << ((localArg.ArgumentPassedIn("-b"))? "YES, was received": " NOPE") << endl;
   cout << "marry " << ((localArg.ArgumentPassedIn("marry"))? "YES, was received": " NOPE") << endl;
   cout << "bob " << ((localArg.ArgumentPassedIn("bob"))? "YES, was received": " NOPE") << endl;
   cout << "hello " << ((localArg.ArgumentPassedIn("hello"))? "YES, was received": " NOPE") << endl;





}


