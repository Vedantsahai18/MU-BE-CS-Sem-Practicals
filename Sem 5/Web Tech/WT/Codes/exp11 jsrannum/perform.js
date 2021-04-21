var ranNum = Math.ceil((Math.random() * 10));
console.log(ranNum);

function checkNumber(){
    var number = document.getElementById("guess").value;
    number = parseInt(number);
    var outputTag = document.getElementById("output");
    if(number == ranNum){
        outputTag.innerHTML = "Good Work";
    }
    else if(number < 1 || number > 10 || isNaN(number)){
        outputTag.innerHTML = "Please choose a number between 1 and 10";
    }
    else if(number > ranNum){
        outputTag.innerHTML = "Too High";
    }
    else if(number < ranNum){
        outputTag.innerHTML = "Too Low";
    }
}