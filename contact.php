<html>
<title> Contact </title>
<body>

</body>
</html>
<?php


$con=mysqli_connect("localhost","root","","emotion") or die ("Couldnt connect to server");
if(isset($_POST['submit'])){
if(!empty($_POST)){
$name=$_POST['name'];
	$phone=$_POST['phone'];
	$email=$_POST['email'];
	$msg=$_POST['message'];
	$reg=mysqli_query($con,"INSERT INTO contact(name,email,phone,message)VALUES('$name','$email','$phone','$msg)");
	if($reg)
{
echo '<script language="javascript">';
echo 'alert("Thanks for the feedback!")';
echo '</script>';
header('index.html');

}
else
echo "failed";
}
?>
