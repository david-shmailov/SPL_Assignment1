#include <iostream>
#include "../include/Session.h"
#include <fstream>



//using namespace std;

int main(int argc, char** argv){

    if(argc != 2) {
        std::cout << "usage cTrace <config_path>" << std::endl;

    Session sess(argv[1]);
    sess.simulate();
    return 0;
}


  //

