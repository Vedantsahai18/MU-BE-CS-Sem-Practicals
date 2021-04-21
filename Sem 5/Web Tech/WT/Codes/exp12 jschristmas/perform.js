function checkDate(){
    var inputDate = new Date(document.getElementById("udate").value);
    var year = inputDate.getFullYear();
    var outputDays = document.getElementById("output");
    
    var days = calcDays(inputDate, year);
    if(days > 0){
        year += 1
        days = calcDays(inputDate, year);
    }
    days = -days;
    outputDays.innerHTML = "There are approximately " + days + " day(s) left for Christmas!!";
}

function calcDays(inputDate, year){
    var christmasDate = new Date('25 December, ' + year.toString());
    var difference = inputDate - christmasDate;
    console.log(christmasDate, difference);
    var oneDay = 1000 * 60 * 60 * 24;
    var days = Math.round(difference / oneDay);
    console.log(days);
    return days
}
