document.querySelector('.js-button')
    addEventListener('click', () => {
        setValue();

    })

const signUpbtn = document.querySelector('.js-button')
const btntext = document.querySelector('.btn-text');

signUpbtn.addEventListener('click',(e) => {
    e.preventDefault()

    signUpbtn.classList.add('Loading');

    setTimeout(() => {
        signUpbtn.classList.remove('Loading');
        signUpbtn.classList.add('Success');

        btntext.innerHTML = 'Sign-Up successful' 
    }, 4000);

})

function setValue(){
    const firstElement = document.getElementsByClassName("input1")[0];
    const firstName = firstElement.value;
    const lastElement = document.getElementsByClassName("input2")[0];
    const lastName = lastElement.value;
    const emailElement = document.getElementsByClassName("input3")[0];
    const email = emailElement.value;
    const passElement = document.getElementsByClassName("input4")[0];
    const password = passElement.value;
    console.log(firstName);    
    console.log(lastName);    
    console.log(email);    
    console.log(password);    

}
