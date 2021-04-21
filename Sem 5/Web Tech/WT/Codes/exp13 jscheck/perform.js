function checkBoolean(value){
    if(typeof value === 'boolean'){
        console.log("Value is boolean");
    }
    else{
        console.log("Value is not a boolean");
    }
}


function checkError(value){
    if(value instanceof Error){
        console.log("Value is of type Error");
    }
    else{
        console.log("Value is not of type Error");
    }
}

function checkNaN(value){
    if(isNaN(value)){
        console.log("Value is NaN");
    }
    else{
        console.log("Value is a number");
    }
}

function checkNull(value){
    if(value){
        console.log("Value is not null");
    }
    else{
        console.log("Value is null");
    }
}

function checkNumber(value){
    if(typeof value == 'number'){
        console.log("Value is a number");
    }
    else{
        console.log("Value is NaN");
    }
}

function checkObject(value){
    if(typeof value == 'object'){
        console.log("Value is a object");
    }
    else{
        console.log("Value is not an object");
    }
}

function checkRegex(value){
    if(value instanceof RegExp){
        console.log("Value is a RegExp");
    }
    else{
        console.log("Value is not a RegExp");
    }
}

function checkChar(value){
    if(typeof value == 'string' && value.length == 1){
        console.log("It is a character");
    }
    else{
        console.log("It is not a character");
    }
}

function checkType(value1, value2){
    // To check if same type of object then
    // value1 instanceof value2
    if(typeof value1 == typeof value2){
        console.log("Both are of same type");
    }
    else{
        console.log("Both are of different types");
    }
}



checkBoolean(true);
checkBoolean("False");

checkError(new Error("Error"));
checkError("No Error");

checkNaN("NaN");
checkNaN(5);

checkNull(null);
checkNull("Not null");

checkNumber(5);
checkNumber("NaN");

checkObject(null); // Null is an object of type object
checkObject("Object"); // Strings are of type string
checkObject(new String("Object")); // Now this is a object
// Objects are usually defined by the new keyword

checkRegex(new RegExp("[a-z]"));
checkRegex("[a-z]");

checkChar("a");
checkChar("aaaaaAAAAAAAAAAAAA");

checkType(5, 6);
checkType(5, "5");