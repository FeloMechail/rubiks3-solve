#include <iostream>

#include "CubeParser.hpp"
#include "FaceletCube.hpp"
#include "RubiksCube.hpp"
#include "Solver.hpp"

using namespace std;
void input( string *inpu );

int main(int argc, char *argv[]) {
    unsigned int status;
    int mov;
    
    string Array[6];
    string *p;
    p = Array;
    
    cout << "Minimum moves: ";
    cin >> mov;
    //input(p);
    
    
    
    string faceletStrings[6] = {
       "U:RWGGWRWWW", "D:YBGGYYBOW", "F:RRROBYRWW", "B:OOYOGROYY", "L:GWBGOBOYB", "R:GBYRRGOBB"
    };
    
    //string faceletStrings[6] = {
      //  "U:WWRWWRWWR", "D:YYOYYOYYO", "F:RRYRRYRRY", "B:WOOWOOWOO", "L:GGGGGGGGG", "R:BBBBBBBBB"
   // };
    
    // Parse the input and initialize FaceletCube
    FaceletCube faceletCube;
    CubeParser cubeParser;
    if((status = cubeParser.parseFacelets(faceletStrings, faceletCube)) != CubeParser::VALID) {
        cout << cubeParser.ErrorText(status) << endl;
        return 1;
    }
    
    // Validate the FaceletCube
    RubiksCube cube;
    if((status = faceletCube.Validate(cube)) != FaceletCube::VALID) {
        cout << faceletCube.ErrorText(status) << endl;
        return 1;
    }
    
    // Cube is in a valid configuration at this point
    
    // Initialize tables and solve
    Solver solver;
    solver.InitializeTables();
    solver.Solve(cube, mov);
    
    cout << "DONE" << endl;
    return 0;
}	

//function to recieve custom rubiks input
void input( string *inpu ){
    string U, D, F, B, L, R;
    cout << "Enter Rubiks cube" << endl;
    cout << "U: ";
    cin >> U;
    U = "U:" + U;
    cout << "D: ";
    cin >> D;
    D = "D:" + D;
    cout << "F: ";
    cin >> F;
    F = "F:" + F;
    cout << "B: ";
    cin >> B;
    B = "B:" + B;
    cout << "L: ";
    cin >> L;
    L = "L:"+ L;
    cout << "R: ";
    cin >> R;
    R = "R:" + R;
    
    
    *(inpu + 0) = U;
    *(inpu + 1) = D;
    *(inpu + 2) = F;
    *(inpu + 3) = B;
    *(inpu + 4) = L;
    *(inpu + 5) = R;

}
    
