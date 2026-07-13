<?php

class Student{
    public $name, $address, $email, $age;
    public function __construct($name, $address, $email, $age)
    {
        $this->name = $name;
        $this->address = $address;
        $this->email = $email;
        $this->age = $age;
         
    }
    public function display()
    {
        echo "My name is " . $this->name . " live in " .$this->address;
    }
}
    $st = new Student("Prajwal", "Thasikhel.", "prajwal@gmail.com", 22);
    $st->display();
