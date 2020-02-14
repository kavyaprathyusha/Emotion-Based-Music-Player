<html>
<body>
<script>
                        
alert("You have Successfully Logged out");
</script>
<a href="index.html">Go back to Home Page.. </a>

</body>
</html>
<?php
$con=mysqli_connect("localhost","root","","emotion") or die ("Couldnt connect to server");
if($con){
echo '<script language="javascript">';
echo 'alert("You have Successfully 
logged out")';
echo '</script>';
}


?>