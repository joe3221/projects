//
//  main.cpp
//  A3
//
//  Created by Joe Smissen on 12/2/19.
//smiss003@cougars.csusm.edu

#include "University.h"


using namespace std;


int main()
{
    University csusm;
    csusm.ProcessTransactionFile("transaction.txt");
    cout << "Hello" << endl;
    system("pause");
}
//----------------------------------------------------------------------------

