document.addEventListener('DOMContentLoaded', () => {
    const grid = document.querySelector('.grid')
    let squares = Array.from(document.querySelectorAll('.grid div'))
    const scoreDisplay = document.querySelector('#score')
    const startBtn = document.querySelector('#start-button')
    const width = 10
    let nextRandom = 0
    let timerId
    let score = 0
    const colors = [
        'orange',
        'red',
        'purple',
        'green',
        'blue'
    ]


    //The lTeramino 
    const lTetromino = [
        [1, width+1, width*2+1, 2],
        [width, width+1, width+2, width*2+2],
        [1, width+1, width*2+1, width*2],
        [width, width*2, width*2+1, width*2+2]
    ]

    //The zTeramino
    const zTetromino = [
        [0, width, width+1, width*2+1],
        [width+1, width+2, width*2, width*2+1],
        [0, width, width+1, width*2+1],
        [width+1, width+2, width*2, width*2+1]
    ]

    //The tTeramino
    const tTetromino = [
        [1, width, width+1,width*2+1],
        [1,width+1, width+2,width*2+1],
        [width, width+1,width+2,width*2+1],
        [1, width, width+1,width*2+1],
        
    ]

    //The oTeramino
    const oTetromino = [
        [0,1,width,width+1],
        [0,1,width,width+1],
        [0,1,width,width+1],
        [0,1,width,width+1],
    ]

    //The iTeramino
    const iTetromino = [
        [1,width+1,width*2+1,width*3+1],
        [width,width+1,width+2,width+3],
        [1,width+1,width*2+1,width*3+1],
        [width,width+1,width+2,width+3],
    ]

    const theTetrominoes = [lTetromino, oTetromino, zTetromino, iTetromino, tTetromino]

    let currentPosition = 4
    let currentRotation = 0

    //randomly select a Tetromino and it's first rotation
    let random = Math.floor(Math.random() * theTetrominoes.length)
    let current = theTetrominoes[random][0]

    //draw Tetromino 
    function draw() {
        current.forEach(index => {
            squares[currentPosition + index].classList.add('tetromino')
            squares[currentPosition + index].style.backgroundColor = colors[random]
        })
    }

    //undraw Teramino
    function undraw() {
        current.forEach(index => {
            squares[currentPosition + index].classList.remove('tetromino')
            squares[currentPosition + index].style.backgroundColor = ''
        })
    }

    //make the tetromine move down every second
    //timerId = setInterval(moveDown, 1000)

    //assign function to keyCodes
    function control(e) {
        if(e.keyCode === 37) {
            moveLeft()
        } else if(e.keyCode === 38) {
            rotate()
        } else if(e.keyCode === 39) {
            moveRight()
        } else if(e.keyCode === 40) {
            moveDown()
        }
    }
    document.addEventListener('keyup', control)

    //move down function
    function moveDown() {
        undraw()
        currentPosition += width
        draw()
        freeze()
    }

    //freeze function
    function freeze() {
        if(current.some(index => squares[currentPosition + index + width].classList.contains('taken'))) {
            current.forEach(index => squares[currentPosition + index].classList.add('taken'))
            //start a new tetromino falling
            random = nextRandom
            nextRandom = Math.floor(Math.random() * theTetrominoes.length)
            current = theTetrominoes[random][currentRotation]
            currentPosition = 4
            draw()
            displayShape()
            addScore()
            gameOver()
        }
    }

    //move the tetromino left, unless is at the edge or there is a blockage
    function moveLeft() {
        undraw()
        const isAtLeftEdge = current.some(index => [currentPosition + index] % width === 0)

        if(!isAtLeftEdge) currentPosition -=1

        if(current.some(index => squares[currentPosition + index].classList.contains('taken'))) {
            currentPosition += 1
        }
        draw()
    }
    
    //move right function
    function moveRight() {
        undraw()
        const isAtRightEdge = current.some(index => [currentPosition + index] % width === width -1)

        if(!isAtRightEdge) currentPosition +=1

        if(current.some(index => squares[currentPosition + index].classList.contains('taken'))) {
            currentPosition -= 1
        }
        draw()
    }

    //rotate the tetromino
    function rotate() {
        undraw()
        currentRotation ++
        if(currentRotation === current.length) { //if current rotation === 4 make it =0
            currentRotation = 0

        }
        current = theTetrominoes[random][currentRotation]
        draw()
    }

    //show next tetromino in mini-grid
    const displaySquares = document.querySelectorAll('.mini-grid div')
    const displaywidth = 4
    const displayIndex = 0

    //the first teromino rotation
    const upNexTetrominoes = [
        [1, displaywidth+1, displaywidth*2+1,2], //ltetromino
        [0, displaywidth, displaywidth+1, displaywidth*2+1], //ztetromino
        [1, displaywidth, displaywidth+1,displaywidth*2+1], // ttetromino
        [0,1,displaywidth,displaywidth+1], // otetromino
        [1,displaywidth+1,displaywidth*2+1,displaywidth*3+1],
    ]

    //display functio in the mini-grid dispaly
    function displayShape() {
        // remove any trace of a tetromino from the entire grid
        displaySquares.forEach(squares => {
            squares.classList.remove('tetromino')
            squares.style.backgroundColor = ''
        })
        upNexTetrominoes[nextRandom].forEach(index => {
            displaySquares[displayIndex + index].classList.add('tetromino')
            displaySquares[displayIndex + index].style.backgroundColor = colors[nextRandom]
        })
    }

    //add functionality to the button
    startBtn.addEventListener('click', () => {
        if (timerId) {
            clearInterval(timerId)
            timerId = null
        } else {
            draw()
            timerId = setInterval(moveDown, 1000)
            nextRandom = Math.floor(Math.random()*theTetrominoes.length)
            displayShape()
        }
    })

    //add score
    function addScore() {
        for(let i=0; i < 199; i +=width) {
            const row = [i, i+1, i+2, i+3, i+4, i+5, i+6, i+7, i+8]

            if(row.every(index => squares[index].classList.contains('taken'))) {
                score += 10
                scoreDisplay.innerHTML = score
                row.forEach(index => {
                    squares[index].classList.remove('taken')
                    squares[index].classList.remove('tetromino')
                    squares[index].style.backgroundColor = ''
                })
                const squaresRemoved = squares.splice(1, width)
                squares = squaresRemoved.concat(squares)
                squares.forEach(cell => grid.appendChild)
            }
        }
    }

    //gameover
    function gameOver() {
        if(current.some(index => squares[currentPosition + index].classList.contains('taken'))) {
            scoreDisplay.innerHTML = 'end'
            clearInterval(timerId)
        }
    }
})  


