const leftButton = document.getElementById('left');
const rightButton = document.getElementById('right');
const upButton = document.getElementById('up');
const downButton = document.getElementById('down');
const stopButton = document.getElementById('stop');

leftButton.addEventListener('click', () => moveDirection('left'));
rightButton.addEventListener('click', () => moveDirection('right'));
upButton.addEventListener('click', () => moveDirection('up'));
downButton.addEventListener('click', () => moveDirection('down'));
stopButton.addEventListener('click', () => moveDirection('stop'));

function moveDirection(direction) {

    console.log(`Moving ${direction}`);
}

document.getElementById("powerButton").addEventListener("click", function() {
    alert("Power button clicked");
});
  
document.getElementById("volumeUpButton").addEventListener("click", function() {
    alert("Volume Up button clicked");
});
  
document.getElementById("volumeDownButton").addEventListener("click", function() {
    alert("Volume Down button clicked");
});
