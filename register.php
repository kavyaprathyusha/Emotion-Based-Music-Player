<html>
<body>
<a href="index.html">Go back to Login Page.. </a>
</body>
</html>

<?php


$con=mysqli_connect("localhost","root","","emotion") or die ("Couldnt connect to server");


if(isset($_POST['Submit'])){
if(!empty($_POST)){
	$username=$_POST['Username'];
	$password=$_POST['Password'];
	$email=$_POST['Email'];
	$FirstName=$_POST['FirstName'];
	$LastName=$_POST['LastName'];
$user="user";


$reg=mysqli_query($con,"INSERT INTO login_table(Username,Password,LastName,FirstName,role,email)VALUES('$username','$password','$LastName','$FirstName','$user','$email')");

}
if($reg)
{
echo '<script language="javascript">';
echo 'alert("You have Successfully Registered, Please Login to Continue..")';
echo '</script>';
header('index.html');

}
else
echo "failed";
}
?>












