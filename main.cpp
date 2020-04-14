/* -----------------------------------------------------------
   Program 5: Pentagon

   Class: CS 141, Spring 2022.  Tues 4pm lab, MWF 10am Lecture
   System: CLion
   Author: Krishna Chaitanya Bavana (Krish Bavana)
-----------------------------------------------------------
 */
#include <iostream>  // Needed to avoid compiler error for the exit() command
#include <cctype>    // For toupper()

using namespace std; //so I dont preface std every single time

class Board{ //Class contains all the pieces related to board, win, rotation of the board

    //-------------------------------------------------------------------------------------
    private: //five arrays, only to be accessed inside the class
        char quadOne[9]{};
        char quadTwo[9]{};
        char quadThree[9]{};
        char quadFour[9]{};
        char allQuads[36]{};

    //-------------------------------------------------------------------------------------
    public: //to access functions outside of the class
        Board(){ //constructor calls the makePiece and sets . in the board
            setterDotPiece();
        }

        //-------------------------------------------------------------------------------------
        //this is the setter method for the class which sets every piece in the array to . in the beginning of the game
        void setterDotPiece(){
            for(int i = 0; i<9; i++){
                quadOne[i] = '.';
                quadTwo[i] = '.';
                quadThree[i] = '.';
                quadFour[i] = '.';
            }
        }

        //-------------------------------------------------------------------------------------
        //this function is convert row and direction into upper case, so I don't have to check with both lower and upper case
        //char word is the parameter passed as a value
        char toUpperWord(char word){
            if(islower(word)) //if the word is lower
            {
                word = toupper(word);//convert into upper
            }
            return word; //return converted word
        }

        //-------------------------------------------------------------------------------------
        //This function is for checking weather the user input pieces are in range or not, the parameters are row, colC, quadC and direction
        //those four values are passed are value from user input, colC and quadC are char, they will converted into to check
        int perfectChecker(char row, char colC, char quadC, char direction){
            int col, quad;
            col = colC - '0'; //conversion to int
            quad = quadC - '0'; //conversion to int
            if((row >= 71) || (row <= 64)){ //checks rows
                return -2;
            }
            else if((col > 6) || (col < 1)){ //checks column
                return -1;
            }

            else if((quad < 1) || (quad > 4)){ //checks quads
                return -3;
            }
            else if((direction != 'R') && (direction != 'L')){ //check directions
                return -4;
            }
            return 0; //if everything is ok, it returns 0
        }

        //-------------------------------------------------------------------------------------
        //This function is for rotating all the Odd number to the right('r') direction, parameter is int quad passed value
        void rightRotOdd(int quad){
            if(quad == 1) {
                char temp; //char temp is not overlap the values and replicate same values
                temp = quadOne[1];
                quadOne[1] = quadOne[3];
                quadOne[3] = quadOne[7];
                quadOne[7] = quadOne[5];
                quadOne[5] = temp;
            }
            else if(quad == 2) { //repeated same for all four quads
                char temp;
                temp = quadTwo[1];
                quadTwo[1] = quadTwo[3];
                quadTwo[3] = quadTwo[7];
                quadTwo[7] = quadTwo[5];
                quadTwo[5] = temp;
            }
            else if(quad == 3) {
                char temp;
                temp = quadThree[1];
                quadThree[1] = quadThree[3];
                quadThree[3] = quadThree[7];
                quadThree[7] = quadThree[5];
                quadThree[5] = temp;
            }
            else{
                char temp;
                temp = quadFour[1];
                quadFour[1] = quadFour[3];
                quadFour[3] = quadFour[7];
                quadFour[7] = quadFour[5];
                quadFour[5] = temp;
            }
        }

        //-------------------------------------------------------------------------------------
        //This function is for rotating all the Even number to the right('r') direction,  parameter is int quad passed value
        void rightRotEven(int quad){
            if(quad == 1) {
                char temp;  //char temp is not overlap the values and replicate same values
                temp = quadOne[0];
                quadOne[0] = quadOne[6];
                quadOne[6] = quadOne[8];
                quadOne[8] = quadOne[2];
                quadOne[2] = temp;
            }
            else if(quad == 2) { //same for all four quads
                char temp;
                temp = quadTwo[0];
                quadTwo[0] = quadTwo[6];
                quadTwo[6] = quadTwo[8];
                quadTwo[8] = quadTwo[2];
                quadTwo[2] = temp;
            }
            else if(quad == 3) {
                char temp;
                temp = quadThree[0];
                quadThree[0] = quadThree[6];
                quadThree[6] = quadThree[8];
                quadThree[8] = quadThree[2];
                quadThree[2] = temp;
            }
            else {
                char temp;
                temp = quadFour[0];
                quadFour[0] = quadFour[6];
                quadFour[6] = quadFour[8];
                quadFour[8] = quadFour[2];
                quadFour[2] = temp;
            }
        }

        //-------------------------------------------------------------------------------------
        //This function is for rotating all the Odd number to the right('l') direction,  parameter is int quad passed value
        void leftRotOdd(int quad){
            if(quad == 1) {
                char temp; //char temp is not overlap the values and replicate same values
                temp = quadOne[1];
                quadOne[1] = quadOne[5];
                quadOne[5] = quadOne[7];
                quadOne[7] = quadOne[3];
                quadOne[3] = temp;
            }
            else if(quad == 2) { //same for all four quad
                char temp;
                temp = quadTwo[1];
                quadTwo[1] = quadTwo[5];
                quadTwo[5] = quadTwo[7];
                quadTwo[7] = quadTwo[3];
                quadTwo[3] = temp;
            }
            else if(quad == 3) {
                char temp;
                temp = quadThree[1];
                quadThree[1] = quadThree[5];
                quadThree[5] = quadThree[7];
                quadThree[7] = quadThree[3];
                quadThree[3] = temp;
            }
            else{
                char temp;
                temp = quadFour[1];
                quadFour[1] = quadFour[5];
                quadFour[5] = quadFour[7];
                quadFour[7] = quadFour[3];
                quadFour[3] = temp;
            }
        }

        //-------------------------------------------------------------------------------------
        //This function is for rotating all the Odd number to the right('l') direction,  parameter is int quad passed value
        void leftRotEven(int quad){
            if(quad == 1) {
                char temp; //char temp is not overlap the values and replicate same values
                temp = quadOne[0];
                quadOne[0] = quadOne[2];
                quadOne[2] = quadOne[8];
                quadOne[8] = quadOne[6];
                quadOne[6] = temp;
            }
            else if(quad == 2) { //same for four quads
                char temp;
                temp = quadTwo[0];
                quadTwo[0] = quadTwo[2];
                quadTwo[2] = quadTwo[8];
                quadTwo[8] = quadTwo[6];
                quadTwo[6] = temp;
            }
            else if(quad == 3) {
                char temp;
                temp = quadThree[0];
                quadThree[0] = quadThree[2];
                quadThree[2] = quadThree[8];
                quadThree[8] = quadThree[6];
                quadThree[6] = temp;
            }
            else{
                char temp;
                temp = quadFour[0];
                quadFour[0] = quadFour[2];
                quadFour[2] = quadFour[8];
                quadFour[8] = quadFour[6];
                quadFour[6] = temp;
            }
        }

        //-------------------------------------------------------------------------------------
        //This function is the base function to call both rightRotEven and rightRotOdd or leftRotEven or leftRotOdd
        void rotateBase(int quad, char direction){ //we pass both quad and direction, so we can move the required quad in required direction
            if(quad == 1){ //if quad is 1
                if(direction == 'R'){ //direction is R, then move both rightRotOdd and even
                    rightRotEven(quad);
                    rightRotOdd(quad);
                }
                else{
                    leftRotEven(quad); //if rotation is left, move them in left direction
                    leftRotOdd(quad);
                }
            }
            else if(quad == 2){ //same for all four quads
                if(direction == 'R'){
                    rightRotEven(quad);
                    rightRotOdd(quad);
                }
                else{
                    leftRotEven(quad);
                    leftRotOdd(quad);
                }
            }
            else if(quad == 3){
                if(direction == 'R'){
                    rightRotEven(quad);
                    rightRotOdd(quad);
                }
                else{
                    leftRotEven(quad);
                    leftRotOdd(quad);
                }
            }
            else if(quad == 4){
                if(direction == 'R'){
                    rightRotEven(quad);
                    rightRotOdd(quad);
                }
                else{
                    leftRotEven(quad);
                    leftRotOdd(quad);
                }
            }
        }

        //-------------------------------------------------------------------------------------
        //This is a bool function that returns where the piece is placed or not
        //this function take five parameter row, col, quad, direction and letter
        bool boardSetPiece(char row, int col, int quad, char direction, char letter){
            col = col - '0'; //conversion col char to int
            quad = quad - '0'; //conversion quad char to int

            int incrementer = 0;
            if(col >= 1 && col <= 3 && row >= 65 && row <= 67){ //to check it between col 1 and 3 and row 65 and 67
                for(int rowF = 65; rowF<68; rowF++){ //nested for loop to check every array in the first quad
                    for(int colF = 1; colF < 4; colF++){
                        incrementer++;
                        if(row*col == rowF * colF){
                            int n = ((row*col)%rowF)+(incrementer-1); //algorithmic formula to find the position
                            if(quadOne[n] == '.'){
                                quadOne[n]= letter; //change to X or O
                                rotateBase(quad, direction); //call rotateBase to change to the required direction
                                return true; //return true if everything is set
                            }
                            else{
                                return false;//else false
                            }
                        }
                    }
                }
            }
            else if(col >= 4 && col <= 6 && row >= 65 && row <= 67) { //to check it between col 4 and 6 and row 65 and 67
                for(int rowF = 65; rowF<68; rowF++){
                    for(int colF = 4; colF < 7; colF++){//same methodology used for all four loop
                        incrementer++;
                        if (row * col == rowF * colF) {
                            int n = ((row * col) % rowF) + (incrementer - 1);
                            if (quadTwo[n] == '.') {
                                quadTwo[n] = letter;
                                rotateBase(quad, direction);
                                return true;
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
            else if(col >= 1 && col <= 3 && row >= 68 && row <= 70){ //to check it between col 1 and 3 and row 68 and 70
                for(int rowF = 68; rowF<71; rowF++){
                    for(int colF = 1; colF < 4; colF++){ //same methodology used for all four loop
                        incrementer++;
                        if(row*col == rowF * colF){
                            int n = ((row*col)%rowF)+(incrementer-1);
                            if (quadThree[n] == '.') {
                                quadThree[n] = letter;
                                rotateBase(quad, direction);
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                }
            }
            else if(col >= 4 && col <= 6 && row >= 68 && row <= 70){ //to check it between col 4 and 6 and row 68 and 70
                for(int rowF = 68; rowF<71; rowF++){
                    for(int colF = 4; colF < 7; colF++){ //same methodology used for all four loop
                        incrementer++;
                        if(row*col == rowF * colF){
                            int n = ((row*col)%rowF)+(incrementer-1);
                            if (quadFour[n] == '.') {
                                quadFour[n] = letter;
                                rotateBase(quad, direction);
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                }
            }
            return false;
        }

        //-------------------------------------------------------------------------------------
        //this function is to display the board with all pieces in it, used in the main to call the board multiple times
        //prints the board in the right direction and with right positions
        void displayBoard(){
            cout<<"    1   2   3   4   5   6   \n";
            cout<<"  1-----------------------2 \n";
            cout<<"A | "<<quadOne[0]<<"   "<<quadOne[1]<<"   "<<quadOne[2]<<" | "<<quadTwo[0]<<"   "<<quadTwo[1]<<"   "<<quadTwo[2]<<" | A"<<endl;
            cout<<"  |           |           | "<<endl;
            cout<<"B | "<<quadOne[3]<<"   "<<quadOne[4]<<"   "<<quadOne[5]<<" | "<<quadTwo[3]<<"   "<<quadTwo[4]<<"   "<<quadTwo[5]<<" | B"<<endl;
            cout<<"  |           |           | "<<endl;
            cout<<"C | "<<quadOne[6]<<"   "<<quadOne[7]<<"   "<<quadOne[8]<<" | "<<quadTwo[6]<<"   "<<quadTwo[7]<<"   "<<quadTwo[8]<<" | C"<<endl;
            cout<<"  |-----------+-----------| "<<endl;
            cout<<"D | "<<quadThree[0]<<"   "<<quadThree[1]<<"   "<<quadThree[2]<<" | "<<quadFour[0]<<"   "<<quadFour[1]<<"   "<<quadFour[2]<<" | D"<<endl;
            cout<<"  |           |           | "<<endl;
            cout<<"E | "<<quadThree[3]<<"   "<<quadThree[4]<<"   "<<quadThree[5]<<" | "<<quadFour[3]<<"   "<<quadFour[4]<<"   "<<quadFour[5]<<" | E"<<endl;
            cout<<"  |           |           | "<<endl;
            cout<<"F | "<<quadThree[6]<<"   "<<quadThree[7]<<"   "<<quadThree[8]<<" | "<<quadFour[6]<<"   "<<quadFour[7]<<"   "<<quadFour[8]<<" | F"<<endl;
            cout<<"  3-----------------------4  \n"
                  "    1   2   3   4   5   6   "<<endl;

        }

        //-------------------------------------------------------------------------------------
        //this method is to make another array with thirty 36 array size
        //this method is used to make win
        void allPieceBoard() {
            int k,l,m,n;
            k=l=m=n=0;
            for (int i = 0; i < 18; i += 6) { //goes thru every element in the individual quads and assign them to the big array
                for (int j = 0; j < 3; j++) {
                    allQuads[i + j] = quadOne[m];
                    m++;
                }
            }
            for (int i = 3; i < 18; i += 6) { //goes thru every element in the individual quads and assign them to the big array
                for (int j = 0; j < 3; j++) {
                    allQuads[i + j] = quadTwo[n];
                    n++;
                }
            }
            for (int i = 18; i < 35; i += 6) { //goes thru every element in the individual quads and assign them to the big array
                for (int j = 0; j < 3; j++) {
                    allQuads[i + j] = quadThree[k];
                    k++;
                }
            }
            for (int i = 21; i < 35; i += 6) {//goes thru every element in the individual quads and assign them to the big array
                for (int j = 0; j < 3; j++) {
                    allQuads[i + j] = quadFour[l];
                    l++;
                }
            }
        }

        //-------------------------------------------------------------------------------------
        //this method is used for checking the win and return true or false
        //it have two parameter both of them are reference, so take the values and checks them in the main
        bool winChecker(int &tracker, char &pieceFinalMaker){
            allPieceBoard(); //calling the allPieceBoard(), so it is all set to go
            int max = 4;
            int max2 = 24;
            int max3 = 28;
            int max4 = 25;
            for(int i = 0; i < 35; i+=6){ //nested for loop to check the horizonal wins
                for(int k = i; k<=(i+max); k++) {
                    if((allQuads[k] == allQuads[k+1] || allQuads[i+max] == allQuads[i+max+1]) &&
                       (allQuads[k+1] == allQuads[k+2]) &&
                       (allQuads[k+2] == allQuads[k+3]) &&
                       (allQuads[k+3] == allQuads[k+4]) &&
                       (allQuads[k+4] != '.')){
                        pieceFinalMaker = allQuads[k];
                        tracker++; //tracker to find who won
                    }
                }
            }
            for(int i = 0; i < 6; i++){ //nested for loop to check the vertical wins
                for(int k = i; k<=(i+max2); k+=6) {
                    if((allQuads[k] == allQuads[k+6] || allQuads[k+24] == allQuads[k+30]) &&
                       (allQuads[k+6] == allQuads[k+12]) &&
                       (allQuads[k+12] == allQuads[k+18]) &&
                       (allQuads[k+18] == allQuads[k+24]) &&
                       (allQuads[k+24] != '.')){
                        pieceFinalMaker = allQuads[k];
                        tracker++;
                    }
                }
            }
            for(int i = 0; i < 2; i++){ //nested for loop to check the diagonal wins from right
                for(int k = i; k<=(i+max3); k+=7) {
                    if((allQuads[k] == allQuads[k+7] || allQuads[k+28] == allQuads[k+35]) &&
                       (allQuads[k+7] == allQuads[k+14]) &&
                       (allQuads[k+14] == allQuads[k+21]) &&
                       (allQuads[k+21] == allQuads[k+28]) &&
                       (allQuads[k+28] != '.')){
                        pieceFinalMaker = allQuads[k];
                        tracker++;
                    }
                }
            }
            for(int i = 5; i < 12; i+=6){
                for(int k = i; k<=31; k+=5) { //nested for loop to check the diagon wins from left
                    if((allQuads[k] == allQuads[k+5] || allQuads[max4-i] == allQuads[max4+5]) &&
                       (allQuads[k+5] == allQuads[k+10]) &&
                       (allQuads[k+10] == allQuads[k+15]) &&
                       (allQuads[k+15] == allQuads[k+20]) &&
                       (allQuads[k+20] != '.')){
                        pieceFinalMaker = allQuads[k];
                        tracker++;
                    }
                }
            }
            if(tracker >= 1){ //if the tracker is 1, one player has one the game, if it is two both them have won the game
                return true; //returns true, if atleast one won
            }
            return false;
        }//end winChecker()
};//end of Board Class

//-------------------------------------------------------------------------------------
void displayInstructions() //if the user inputs (i or I), then it will calls this function
{
    cout << "\n"
         << "Play the two-player game of Pentago. Be the first to get 5 in a row. \n"
         << "                                                                 \n"
         << "Pentago is played on a 6 by 6 board, divided into four 3 by 3    \n"
         << "quadrants.  There are two players, X and O, who alternate turns. \n"
         << "The goal of each player is to get five of their pieces in a row, \n"
         << "either horizontally, vertically, or diagonally.                  \n"
         << "                                                                 \n"
         << "Players take turns placing one of their pieces into an empty     \n"
         << "space anywhere on the board, then choosing one of the four       \n"
         << "board quadrants to rotate 90 degrees left or right.              \n"
         << "                                                                 \n"
         << "If both players get five in a row at the same time, or the       \n"
         << "last move is played with no five in a row, the game is a tie.    \n"
         << "If a player makes five a row by placing a piece, there is no need\n"
         << "to rotate a quadrant and the player wins immediately.            \n"
         << "                                                                 \n"
         << "     Play online at:  https://perfect-pentago.net                \n"
         << "     Purchase at:     www.mindtwisterusa.com                     \n"
         << "                                                                 \n"
         << "For each move provide four inputs:                               \n"
         << "   row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R) \n"
         << "For instance input of B32R places the next piece at B3 and then  \n"
         << "would rotate quadrant 2 (upper-right) to the right (clockwise).  \n"
         << "                                                                 \n"
         << "At any point enter 'x' to exit the program or 'i' to display instructions." << endl;
} // end displayInstructions()

//-------------------------------------------------------------------------------------
int main() { //main
    Board theBoard; //calling the Board in the main
    char userRow = 'k';
    char userCol;
    char userQuad;
    char userDirection;
    int player = 1;
    int tracker = 0;
    char pieceFinalMaker;
    char letter;
    bool winValue = false;
    cout<<"Welcome to Pentago, where you try to get 5 of your pieces in a line.\n"
          "At any point enter 'x' to exit or 'i' for instructions. "<<endl;
    theBoard.displayBoard();
    while(userRow != 'x') { //to rotate players
        if(player%2 == 0){
            letter = 'O';
        }
        else{
            letter = 'X';
        }
        cout <<player<<". Enter row, column, quadrant, direction for "<<letter<<" :" << endl;
        cin >> userRow;
        userRow = theBoard.toUpperWord(userRow); //convert input into upper
        if (userRow == 'I') {
            displayInstructions();     // Display game instructinos
            theBoard.displayBoard(); //display board
            continue;
        } else if (userRow == 'X') {
            cout <<  "Exiting program... " << endl; //to exit the program
            exit(-1);
        }
        cin >> userCol;
        cin >> userQuad;
        cin >> userDirection;
        userDirection = theBoard.toUpperWord(userDirection);

        if(theBoard.perfectChecker(userRow, userCol, userQuad, userDirection) == -1){ //calls perfect checker to check
            cout<<"*** Invalid move column.  Please retry."<<endl;                    //weather everything is pefect or not
            theBoard.displayBoard();                                                 //this is for checking Column
        }
        else if(theBoard.perfectChecker(userRow, userCol, userQuad, userDirection) == -2){ //calls perfect checker to check
            cout<<"*** Invalid move row.  Please retry."<<endl;                             //weather everything is pefect or not
            theBoard.displayBoard();                                                       //this is for checking Row
        }
        else if(theBoard.perfectChecker(userRow, userCol, userQuad, userDirection) == -3){
            cout<<" *** Selected quadrant is invalid.  Please retry. "<<endl; //this is for checking Quad
            theBoard.displayBoard();
        }
        else if(theBoard.perfectChecker(userRow, userCol, userQuad, userDirection) == -4){
            cout<<" *** Quadrant rotation direction is invalid.  Please retry. "<<endl; //this is for checking direction
            theBoard.displayBoard();
        }
        else{ //if all inputs are right
            if(theBoard.boardSetPiece(userRow, userCol, userQuad, userDirection, letter)){//places the pieces
                player++; //if placed the piece, then the player will be incremented
            }
            else {
                cout << "    *** That board location is already taken.  Please retry." << endl; //if position is filled
            }
            if(player >= 37){ //if player filled
                if(!theBoard.winChecker(tracker, pieceFinalMaker)){ //and no one won the game
                    cout<<"*** No one has won.  Game is a tie."<<endl; //then it is a tie
                    winValue = true;
                }
            }
            if(theBoard.winChecker(tracker, pieceFinalMaker)){
                if(tracker == 1) { //if one person wins
                    cout<<"      *** "<<pieceFinalMaker<<" has won the game! "<<endl;
                }
                else{ //if both of them won
                    cout<<"   *** Both X and O have won.  Game is a tie."<<endl;
                }
                winValue = true;
            }

            if(winValue){ //if win value is true
                theBoard.displayBoard();
                cout<<"Thanks for playing.  Exiting... "<<endl; //exits the game
                exit(-1);
            }
            theBoard.displayBoard();//if no one won, game continoues till board is filled
        }
    }
    return 0; //to satisfy C++
} //end main()
