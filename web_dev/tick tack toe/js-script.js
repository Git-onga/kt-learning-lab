let boardArr = ['','','','','','','','',''];                    //create an array of the board so as to assing index in js
const board = document.getElementById('board');                 //sets the element with id board to a var board so as to help in appending the div
const player = 'X';
const computer = 'O';

boardArr.forEach((arr, index) => {                              //loops throught the board arr generating the divs
    const div = document.createElement('div');
    div.textContent = arr;
    div.setAttribute('data-index', index);

    board.appendChild(div);                                      //adds the divs to the element dynamocally
});        

function playgame() {
    playerMover();
}

function playerMover() {
    
}

function computerMove(){

}

function checkWinner() {

}

function checkTie(){

}