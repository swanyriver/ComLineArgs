/*
 * ArgReader.hpp
 *
 *  Created on: Jul 15, 2014
 *      Author: Brandon
 */

#ifndef ARGREADER_HPP_
#define ARGREADER_HPP_

#include <string>
#include <set>
#include <list>
#include <iostream> // for testing

using namespace std;

class ARGinAttor {
public:

   struct ControlFlag {
      string argument;
      bool *controlFlag;
   };

   bool ArgumentPassedIn ( string argument );

private:
   set<string> arguments;

   void CheckFlag ( ControlFlag flag ) {
      cout << "checking flag " << flag.argument << endl;
      if ( ArgumentPassedIn( flag.argument ) ){
         cout << "  is there" << endl;
         *flag.controlFlag = true;
      }
      else
         *flag.controlFlag = false;
   }

   void Initialize ( int argc , char* argv[] );
   void Initialize ( int argc , char* argv[] , list<ControlFlag> flags );

public:
   ARGinAttor ( int argc , char* argv[] , bool InitonConstruction = true ) {

      if ( InitonConstruction )
         Initialize( argc , argv );
   }

   ARGinAttor ( int argc , char* argv[] , list<ControlFlag> flags ,
         bool InitonConstruction = true ) {

      if ( InitonConstruction )
         Initialize( argc , argv , flags);
   }

};

void ARGinAttor::Initialize ( int argc , char* argv[] ) {
   cout << "hello welcome to the  ARGinAttor constructor";

   cout << "we got this many args:" << argc << endl;

   for ( int index = 0 ; index < argc ; index++ ) {
      string nextArg( argv[index] );
      cout << "trying to insert:" << nextArg << endl;
      arguments.insert( nextArg );
   }

   //for testing output set contents
   set<string>::iterator lookup = arguments.begin();
   for ( int index = 0 ; index < arguments.size() ; index++ ) {
      cout << "arg " << index << ":" << *lookup << endl;
      lookup++;
   }

   cout << "we have this many args in the set:" << arguments.size() << endl;
   cout << "Goodbye, Leaving constructor";

}

void ARGinAttor::Initialize ( int argc , char* argv[] ,
      list<ControlFlag> flags ) {

   //cout << "entering flag constructor" << endl;

   Initialize(argc, argv);

   while ( !flags.empty() ) {
      //cout << "going through flags:" << flags.back().argument << endl;
      CheckFlag( flags.back() );
      flags.pop_back();
   }
}

bool ARGinAttor::ArgumentPassedIn ( string argument ) {
   if ( arguments.count( argument ) > 0 )
      return true;
   else
      return false;
}


#endif /* ARGREADER_HPP_ */
