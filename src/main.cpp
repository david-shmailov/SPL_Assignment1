#include <iostream>
#include "../headers/Session.h"
#include "../headers/json.hpp"

using namespace std;
using namespace nlohmann;
using json = nlohmann::json;

int main(int argc, char** argv){

    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;

        ifstream ifs("../config1.json");
        json jf = json::parse(ifs);

        return 0;
    }
    //Session sess(argv[1]);
    //sess.simulate();
    return 0;
    // TODO change headers folder to include before submission
}