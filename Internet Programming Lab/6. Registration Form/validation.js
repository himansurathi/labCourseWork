window.onload = init;

function init() {
	document.getElementsByName("UserId").value="";
	document.getElementsByName("Password").value="";
	document.getElementsByName("RetypePassword").value="";
	document.getElementsByName("FullName").value="";
	document.getElementsByName("FatherName").value="";
	document.getElementsByName("DateOfBirth").value="";
	document.getElementsByName("Email").value="";
	document.getElementsByName("PhoneNumber").value="";
}

function isEmpty(str){
	return (!str || 0 === str.length || !str.trim());
}

function validateEmail(){
	var message = document.getElementById('emailMessage');
	var emailId = document.Registration.Email.value;
	if(isEmpty(emailId)){
		message.innerHTML="Email Id cannot be blank";
		document.Registration.Email.focus();
		return false;
	}
	var atPos=emailId.indexOf("@");
	var dotPos=emailId.lastIndexOf(".");
	var lastIndex=emailId.length-1;
	if((atPos<1) || (dotPos-atPos<2) ||(dotPos==lastIndex)||(atPos==lastIndex)){
		message.innerHTML="Invalid Email Id";
		document.Registration.Email.focus();
		return false;
	}
	message.innerHTML="";
	return true;
}

function validatePassword(){
	var message = document.getElementById('passwordMessage');
	var password = document.Registration.Password.value;
	if(isEmpty(password)){
		message.innerHTML="Password cannot be blank";
		document.Registration.Password.focus();
		return false;
	}
	var lengthPassword=password.length;
	if((lengthPassword<8) || (lengthPassword>12)){
		message.innerHTML="Password must be between 8-12 characters";
		document.Registration.Password.focus();
		return false;
	}
	message.innerHTML="";
	return true;
}

function checkRetypePassword(){
	var message = document.getElementById('confirmPasswordMessage');
	var password = document.Registration.Password.value;
	var retypepassword = document.Registration.RetypePassword.value;
	if((isEmpty(retypepassword)) ||(password!=retypepassword)){
		message.innerHTML="Password do not match";
		document.Registration.RetypePassword.focus();
		return false;	
	}
	message.innerHTML="";
	return true;
}

function validateUserId(){
	var message = document.getElementById('userMessage');
	var username=document.Registration.UserId.value;
	if(isEmpty(username)){
		message.innerHTML="Username cannot be blank";
		document.Registration.UserId.focus();
		return false;
	}
	var re=/^[a-z0-9_-]{3,15}$/;
	if(username.search(re)==-1){
		message.innerHTML="Invalid User Id";
		document.Registration.UserId.focus();
		return false;	
	}
	message.innerHTML="";
	return true;
}

function validateFullName(){
	var message = document.getElementById('nameMessage');
	var name=document.Registration.FullName.value;
	if(isEmpty(name)){
		message.innerHTML="Name cannot be blank";
		document.Registration.FullName.focus();
		return false;
	}
	var re=/^[a-zA-z ]{1,40}$/;
	if(name.search(re)==-1){
		message.innerHTML="Invalid Name";
		document.Registration.FullName.focus();
		return false;	
	}
	message.innerHTML="";
	return true;
}

function validateFatherName(){
	var message = document.getElementById('fatherMessage');
	var fathername=document.Registration.FatherName.value;
	if(isEmpty(fathername)){
		message.innerHTML="Father's Name cannot be blank";
		document.Registration.FatherName.focus();
		return false;
	}
	var re=/^[a-zA-z ]{1,40}$/;
	if(fathername.search(re)==-1){
		message.innerHTML="Invalid Father's Name";
		document.Registration.FatherName.focus();
		return false;	
	}
	message.innerHTML="";
	return true;
}

function validatePhoneNumber(){
	var message = document.getElementById('phoneMessage');
	var phonenumber=document.Registration.PhoneNumber.value;
	var re=/^[0-9]{8,11}$/;
	if(phonenumber.search(re)==-1){
		message.innerHTML="Invalid Phone Number";
		document.Registration.PhoneNumber.focus();
		return false;	
	}
	message.innerHTML="";
	return true;	
}

function validateDate(){
    var message = document.getElementById('dateMessage');
    var date=document.Registration.DateOfBirth.value;

    // regular expression to match required date format
    var re = /^(\d{1,2})[-\/](\d{1,2})[-\/](\d{4})$/;

    if(isEmpty(date)) {
      message.innerHTML = "Empty date not allowed!";
      document.Registration.DateOfBirth.focus();
	  return false;	
	} 

	if(regs = date.match(re)) {
		var day=regs[1];
		var month=regs[2]-1;
		var year=regs[3];
		var composedDate=new Date(year,month,day);
		
		if( (composedDate.getDate() != day) ||
            (composedDate.getMonth() != month) ||
            (composedDate.getFullYear() != year)){

	          message.innerHTML = "Invalid date entered(dd/mm/yyyy)";
		      document.Registration.DateOfBirth.focus();
			  return false;	
		}
      } 
      else {
          message.innerHTML = "Invalid date format(dd/mm/yyyy)";
	      document.Registration.DateOfBirth.focus();
		  return false;	
      }
    message.innerHTML ="";
    return true;
}

function uploadImage(){
	var fileId=document.Registration.FileName.value;
	var imageId=document.getElementById("image");
	imageId.src=fileId;
}


function validateForm(){
	if(validateUserId() && validatePassword() && checkRetypePassword()
	   && validateFullName() && validateFatherName() && validateEmail()
	   && validatePhoneNumber() && validateDate()){
		return true;
	}
	else{
		return false;
	}
}