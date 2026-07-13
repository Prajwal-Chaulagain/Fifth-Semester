<?php
$name = "nf";
$id = 100;
$pi = 3.14;
$countries = array("Nepal", "India", "USA", "UK", "Germany", "France");
echo "Name:" . $name;

class Employee
{
    public $name;
    public $id;
    function __construct($name, $id)
    {
        $this->name = $name;
        $this->id = $id;
    }
}
$emp = new Employee($name, $id);
echo"Employee Name:" . $emp->name . ", ID:" . $emp->id;
echo "". $emp->id ."";  
?>