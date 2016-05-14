function isEmpty(str){
	return (!str || 0 === str.length || !str.trim());
}

function validateEmail(){
	var emailId = document.Login.Email.value;
	if(isEmpty(emailId)){
		alert("Email Id cannot be blank");
		document.Login.Email.focus();
		return false;
	}
	var atPos=emailId.indexOf("@");
	var dotPos=emailId.lastIndexOf(".");
	var lastIndex=emailId.length-1;
	if((atPos<1) || (dotPos-atPos<2) ||(dotPos==lastIndex)||(atPos==lastIndex)){
		alert("Invalid Email Id");
		document.Login.Email.focus();
		return false;
	}

	return true;
}

function validatePassword(){
	var password = document.Login.Password.value;
	if(isEmpty(password)){
		alert("Password cannot be blank");
		document.Login.Password.focus();
		return false;
	}
	var lengthPassword=password.length;
	if((lengthPassword<8) || (lengthPassword>12)){
		alert("Password must be between 8-12 characters");
		document.Login.Password.focus();
		return false;
	}
	return true;
}

function validateForm(){
	if(validateEmail() && validatePassword()){
		return true;
	}
	else{
		return false;
	}
}
