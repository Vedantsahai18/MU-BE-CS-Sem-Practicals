function checkIP(IP){
    var error = "";
    var octets = IP.split(".");
    if(octets.length < 4){
        error += "Invalid IP, must have 4 octets\n";
    }
    for(var oct of octets){
        var intVal = parseInt(oct);
        if(intVal > 255 || intVal < 0){
            error += "Invalid range [0-255]\n";
            break;
        }
        if(isNaN(intVal)){
            error += "IP is NaN\n";
            break;
        }
    }
    console.log(octets);
    if(error == ""){
        error = "Valid IP address";
    }
    console.log(error);
}

checkIP("56.123.112.1");