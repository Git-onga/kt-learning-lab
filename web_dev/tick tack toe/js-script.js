let boardArr = ["","","","","","","","",""];                    //create an array of the board so as to assing index in js
const board = document.getElementById("board");                 //sets the element with id board to a var board so as to help in appending the div
let currentPlayer = "player";
let running = false;

boardArr.forEach((arr, index) => {                              //loops throught the board arr generating the divs
    const div = document.createElement("div");
    div.textContent = arr;
    div.setAttribute("data-index", index);

    board.appendChild(div);                                      //adds the divs to the element dynamocally

});     

const divs = document.querySelectorAll("#board > div");          //selects all the divs generated
const filledDivs = new Set();                                   //Track fields

playGame();

function playGame() {
    running = true;

    divs.forEach(div => div.addEventListener("click", cellClicked));
    const availableDivs = Array.from(divs).filter(div => !filledDivs.has(div.getAttribute('data-index')));

    changePlayer();

    //while(availableDivs.length != 0){
        playGame()
        computerMove(divs)
    //}

}

function cellClicked(){
    const boardArrIndex = this.getAttribute("data-index");

    if(boardArr[boardArrIndex] != "" || !running){
        return;
        
    }

    playerMove(this, boardArr, boardArrIndex);
}

function playerMove(div, index, boardArrIndex) {
    boardArr[index] = currentPlayer;
    div.textContent = "O";                            //places the 'O' on the randomly generated div index
    currentPlayer = "player";
    filledDivs.add(boardArrIndex);   
    //changePlayer();

}

function changePlayer(){
    currentPlayer = (currentPlayer == "player") ? "computer" : "player";
    if(currentPlayer == "player"){
        computerMove(availableDivs);
    } else {
        playerMove();
    }
    
}

function computerMove(availableDivs){
    boardArr[index] = currentPlayer;
    div.textContent = "O";                            //places the 'O' on the randomly generated div index
    currentPlayer = "player";
    filledDivs.add(boardArrIndex);   
}