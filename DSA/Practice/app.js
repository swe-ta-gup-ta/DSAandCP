const button = document.querySelector('button');
const h1 = document.querySelector('h1');
button.addEventListener('click', function() {
    
    const r = Math.floor(Math.random() * 256);
    const g = Math.floor(Math.random() * 256);
    const b = Math.floor(Math.random() * 256);
    const newc = `rgb(${r}, ${g}, ${b})`
    document.body.style.backgroundColor = newc;
    h1.innerText = newc;
})