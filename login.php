<?php


$con=mysqli_connect("localhost","root","","emotion") or die ("Couldnt connect to server");
if(!empty($_POST))
{
$username=$_POST['Username'];
$password=$_POST['Password'];
$rolequery=mysqli_query($con,"Select role from login_table where Username='$username' and Password='$password' ");

    if($rolequery)
  {
    global $retval,$userid;
    $retval=mysqli_fetch_object($rolequery)->role;
    $retval=trim($retval);
    echo $retval;

    $uidquery=mysqli_query($con,"Select user_id from login_table where Username='$username' and role='$retval'");
    $userid=mysqli_fetch_object($uidquery)->user_id;
    echo $userid;

    if($retval=="admin"){
  header('Location: admin.php');
  session_start();
  $_SESSION['uid_travel_admin']=$userid;
  
  }
  else if($retval=="user"){
    header('Location: user.php');
    session_start();
    $_SESSION['uid_travel_user']=$userid;
    
  }
  
  }
}
 



?>