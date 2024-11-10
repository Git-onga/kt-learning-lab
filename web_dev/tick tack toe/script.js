let boardArr = ['','','','','','','','',''];           //create an array of the board so as to assing index in js
const board = document.getElementById('board');                 //sets the element with id board to a var board so as to help in appending the div

boardArr.forEach((arr, index) => {                             //loops throught the board arr generating the divs
    const div = document.createElement('div');
    div.textContent = arr;
    div.setAttribute('data-index', index);

    board.appendChild(div);                                      //adds the divs to the element dynamocally
});        

const filledDivs = new Set();                                   //Track fields

document.querySelector('#start')
    .addEventListener('click', () => {

        //divs.forEach(div => (div.textContent = ''));                    //clears the previous no
    
        
        
        playGame();
        
        

    });
   
function playGame(){
    let gameStatus = true;
    const divs = document.querySelectorAll('#board > div');          //selects all the divs generated
    const availableDivs = Array.from(divs).filter(div => !filledDivs.has(div.getAttribute('data-index')));

    if (availableDivs.length === 0 ){
        alert('All divs are filled!');
        return;
    };

    console.log(availableDivs.length);
    /*
    while(availableDivs.length >= 0){
    
    };
    */
    computerMove(availableDivs);
    
    playerMove(availableDivs);


    console.log(filledDivs);
    console.log(`After calling the function the availableDivs`,availableDivs);
}

function computerMove(availableDivs) {
    //const divs = document.querySelectorAll('#board > div');          //selects all the divs generated

    /*
    const availableDivs = Array.from(divs).filter(div => !filledDivs.has(div.getAttribute('data-index')));

    if (availableDivs.length === 0 ){
        alert('All divs are filled!');
        return;
    }
    */

    const randomDiv = availableDivs[Math.floor(Math.random() * availableDivs.length)];                              //selects a random div from left available
    randomDiv.textContent = 'X';                            //places the 'X' on the randomly generated div index
    filledDivs.add(randomDiv.getAttribute('data-index'));                                               //mark div as filled
    console.log(`At start the availableDivs =`, availableDivs);
}


function playerMove(availableDivs){
    const randomDiv = availableDivs[Math.floor(Math.random() * availableDivs.length)];                              //selects a random div from left available
    randomDiv.textContent = 'O';                            //places the 'O' on the randomly generated div index
    filledDivs.add(randomDiv.getAttribute('data-index'));                                               //mark div as filled
    
}