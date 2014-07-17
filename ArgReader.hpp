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
#include <ostream>
#include <iostream> // for testing

using namespace std;

class ARGinAttor{

private:
   set <string> arguments;

public:

   struct ControlFlag{
      string argument;
      bool *controlFlag; //figure out how to pass in a bool pointer, is this side meant to just be
      //a pointer and i pass in a normal bool?
   };

   ARGinAttor (int argc , char* argv[]){

      cout << "hello welcome to the  ARGinAttor constructor";

      cout << "we got this many args:" << argc << endl;

      for (int index = 0;  index < argc; index++) {
         string nextArg(argv[index]);
         cout << "trying to insert:" << nextArg << endl;
         arguments.insert(nextArg);
      }

      //for testing output set contents
      set<string>::iterator lookup = arguments.begin();
      for (int index = 0;  index < arguments.size(); index++) {
         cout << "arg " << index << ":" << *lookup << endl;
         lookup++;
      }

      cout << "we have this many args in the set:" << arguments.size() << endl;
      cout << "Goodbye, Leaving constructor";
   }

   bool ArgumentPassedIn(string argument){
      if(arguments.count(argument)>0) return true;
      else return false;
   }

};


/*class ArgReader{
private:
   //set<char*> arguments; //this need to be string, write swansonstring::cstring to string
   //or abbandon set and try using my template contains method. //no, not working for cstring
   //make the cstring to string function for exercise and add it to swansonstring::
   set <string> arguments;
public:
   struct Flag{
      string argument;
      bool *controlFlag; //figure out how to pass in a bool pointer, is this side meant to just be
      //a pointer and i pass in a normal bool?
   };

   ArgReader(int argc , char* argv[]){
      //add all args to set

      cout << "hello welcome to the constructor";

      for (int index = 0;  index < argc; index++) {
         string insert(argv[index]);
         cout << "trying to insert:" << insert << endl;
         arguments.insert(string(argv[index]));
      }

      //for testing output set contents
      set<string>::iterator lookup = arguments.begin();
      for (int index = 0;  index < arguments.size(); index++) {
         cout << "arg " << index << ":" << *lookup;
         lookup++;
      }

      cout << "we got this many args:" << arguments.size() << endl;
      cout << "Goodbye, Leaving constructor";


      //set pointed bools accordingly
   }

   void amIHere(){
      cout << "where is my object";
   }

};*/

/*
class Arginator {
public:
   Arginator(int val){
      cout << "welcome to the arginator";
   }
   void test(){
      cout << "love";
   }
};
*/


#endif /* ARGREADER_HPP_ */
